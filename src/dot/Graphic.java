/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * Project Info:  http://plantuml.com
 * 
 * This file is part of Smetana.
 * Smetana is a partial translation of Graphviz/Dot sources from C to Java.
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * This translation is distributed under the same Licence as the original C program.
 * 
 * THE ACCOMPANYING PROGRAM IS PROVIDED UNDER THE TERMS OF THIS ECLIPSE PUBLIC
 * LICENSE ("AGREEMENT"). [Eclipse Public License - v 1.0]
 * 
 * ANY USE, REPRODUCTION OR DISTRIBUTION OF THE PROGRAM CONSTITUTES
 * RECIPIENT'S ACCEPTANCE OF THIS AGREEMENT.
 * 
 * You may obtain a copy of the License at
 * 
 * http://www.eclipse.org/legal/epl-v10.html
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
package dot;

import static gen.lib.cgraph.attr__c.agget;
import h.Agedge_s;
import h.Agedgeinfo_t;
import h.Agnode_s;
import h.Agnodeinfo_t;
import h.Agraph_s;
import h.Agraphinfo_t;
import h.boxf;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.geom.AffineTransform;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Rectangle2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import javax.imageio.ImageIO;

import smetana.core.CString;
import smetana.core.Macro;
import smetana.core.__ptr__;
import smetana.core.__struct__;

public class Graphic {

	private final double margin = 20;

	private final List<Agnode_s> nodes = new ArrayList<Agnode_s>();
	private final List<Curve> curves = new ArrayList<Curve>();
	private final List<Agraph_s> clusters = new ArrayList<Agraph_s>();
	private double maxX, maxY;

	public void addEdge(Agedge_s e) {
		final Agedgeinfo_t data = (Agedgeinfo_t) Macro.AGDATA(e).castTo(Agedgeinfo_t.class);
		addSplines(data);
	}

	public void addNode(Agnode_s n) {
		nodes.add(n);
		final Agnodeinfo_t data = (Agnodeinfo_t) Macro.AGDATA(n).castTo(Agnodeinfo_t.class);
		final double width = data.getDouble("width") * 72;
		final double height = data.getDouble("height") * 72;
		final double x = data.getStruct("coord").getDouble("x");
		final double y = data.getStruct("coord").getDouble("y");
		maxX = Math.max(maxX, x + width / 2);
		maxY = Math.max(maxY, y + height / 2);

	}

	private void addSplines(Agedgeinfo_t data) {
		final Curve curve = new Curve(data);
		maxX = Math.max(maxX, curve.getMaxX());
		maxY = Math.max(maxY, curve.getMaxY());
		curves.add(curve);
	}

	public void drawTo(File out) {

		final double totalWidth = maxX + 2 * margin;
		final double totalHeight = maxY + 2 * margin;
		final BufferedImage image = new BufferedImage((int) totalWidth, (int) totalHeight, BufferedImage.TYPE_INT_RGB);
		final Graphics2D g = image.createGraphics();

		g.setColor(Color.WHITE);
		g.fill(new Rectangle2D.Double(0, 0, totalWidth, totalHeight));

		// g.setTransform(AffineTransform.getTranslateInstance(margin, margin));
		AffineTransform at = AffineTransform.getScaleInstance(1, -1);
		at.concatenate(AffineTransform.getTranslateInstance(margin, margin - totalHeight));
		g.setTransform(at);

		g.setColor(Color.RED);
		for (Agraph_s c : clusters) {
			drawCluster(g, c);
		}
		g.setColor(Color.BLUE);
		for (Agnode_s n : nodes) {
			drawNode(g, n);
		}
		g.setColor(Color.BLACK);
		for (Curve c : curves) {
			c.drawCurve(g);
		}

		try {
			ImageIO.write(image, "png", out);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private void drawCluster(Graphics2D g, Agraph_s c) {
		final __ptr__ data = Macro.AGDATA(c).castTo(Agraphinfo_t.class);
		final __struct__<boxf> bb = data.getStruct("bb");
		double llx = bb.getStruct("LL").getDouble("x");
		double lly = bb.getStruct("LL").getDouble("y");
		double urx = bb.getStruct("UR").getDouble("x");
		double ury = bb.getStruct("UR").getDouble("y");
		g.draw(new Rectangle2D.Double(llx, lly, urx - llx, ury - lly));

	}

	private void drawNode(Graphics2D g, Agnode_s n) {
		final Agnodeinfo_t data = (Agnodeinfo_t) Macro.AGDATA(n).castTo(Agnodeinfo_t.class);
		final double width = data.getDouble("width") * 72;
		final double height = data.getDouble("height") * 72;
		double x = data.getStruct("coord").getDouble("x");
		double y = data.getStruct("coord").getDouble("y");

		final CString shape = agget(n, new CString("shape"));

		if (shape != null && "box".equalsIgnoreCase(shape.getContent())) {
			g.draw(new Rectangle2D.Double(x - width / 2, y - height / 2, width, height));
		} else {
			g.draw(new Ellipse2D.Double(x - width / 2, y - height / 2, width, height));
		}

	}

	public void addCluster(Agraph_s c) {
		clusters.add(c);
	}

}
