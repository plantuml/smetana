/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * Project Info:  http://plantuml.com
 * 
 * This file is part of Smetana.
 * Smetana is a partial translation of Graphviz/Dot sources from C to Java.
 *
 * (C) Copyright 2009-2020, Arnaud Roques
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
package testing.dot;

import static gen.lib.cgraph.attr__c.agget;

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

import h.ST_Agedge_s;
import h.ST_Agedgeinfo_t;
import h.ST_Agnode_s;
import h.ST_Agnodeinfo_t;
import h.ST_Agraph_s;
import h.ST_Agraphinfo_t;
import h.ST_boxf;
import h.ST_field_t;
import smetana.core.CString;
import smetana.core.Macro;

public class Graphic {

	private final double margin = 20;

	private final List<ST_Agnode_s> nodes = new ArrayList<ST_Agnode_s>();
	private final List<Curve> curves = new ArrayList<Curve>();
	private final List<ST_Agraph_s> clusters = new ArrayList<ST_Agraph_s>();
	private double maxX, maxY;

	public void addEdge(ST_Agedge_s e) {
		final ST_Agedgeinfo_t data = (ST_Agedgeinfo_t) Macro.AGDATA(e).castTo(ST_Agedgeinfo_t.class);
		addSplines(data);
	}

	public void addNode(ST_Agnode_s n) {
		nodes.add(n);
		final ST_Agnodeinfo_t data = (ST_Agnodeinfo_t) Macro.AGDATA(n).castTo(ST_Agnodeinfo_t.class);
		final double width = data.width * 72;
		final double height = data.height * 72;
		final double x = data.coord.x;
		final double y = data.coord.y;
		maxX = Math.max(maxX, x + width / 2);
		maxY = Math.max(maxY, y + height / 2);

	}

	private void addSplines(ST_Agedgeinfo_t data) {
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
		for (ST_Agraph_s c : clusters) {
			drawCluster(g, c);
		}

		for (ST_Agnode_s n : nodes) {
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

	private void drawCluster(Graphics2D g, ST_Agraph_s c) {
		final ST_Agraphinfo_t data = (ST_Agraphinfo_t) Macro.AGDATA(c).castTo(ST_Agraphinfo_t.class);
		final ST_boxf bb = (ST_boxf) data.bb;
		double llx = bb.LL.x;
		double lly = bb.LL.y;
		double urx = bb.UR.x;
		double ury = bb.UR.y;
		g.draw(new Rectangle2D.Double(llx, lly, urx - llx, ury - lly));

	}

	private void drawNode(Graphics2D g, ST_Agnode_s n) {
		final ST_Agnodeinfo_t data = (ST_Agnodeinfo_t) Macro.AGDATA(n).castTo(ST_Agnodeinfo_t.class);
		final double width = data.width * 72;
		final double height = data.height * 72;
		double x = data.coord.x;
		double y = data.coord.y;

		final CString shape = agget(n, new CString("shape"));

		g.setColor(Color.BLUE);
		if (shape != null && "box".equalsIgnoreCase(shape.getContent())) {
			g.draw(new Rectangle2D.Double(x - width / 2, y - height / 2, width, height));
		} else if (shape != null && "record".equalsIgnoreCase(shape.getContent())) {
			// g.draw(new Rectangle2D.Double(x - width / 2, y - height / 2, width, height));
		} else if (shape != null && "ellipse".equalsIgnoreCase(shape.getContent())) {
			g.draw(new Ellipse2D.Double(x - width / 2, y - height / 2, width, height));
		} else {
			g.draw(new Ellipse2D.Double(x - width / 2, y - height / 2, width, height));
		}

		if (Macro.ND_shape_info(n) instanceof ST_field_t) {
			final ST_field_t info = (ST_field_t) Macro.ND_shape_info(n);
			g.setColor(Color.GREEN);
			drawRecords(g, x, y, info);
		}
	}

	private void drawRecords(Graphics2D g, double x, double y, ST_field_t info) {
		for (int i = 0; i < info.n_flds; i++) {
			final ST_field_t record = info.fld.get_(i);
			final double width = record.size.x;
			final double height = record.size.y;
			double llx = record.b.LL.x;
			double lly = record.b.LL.y;

			double urx = record.b.UR.x;
			double ury = record.b.UR.y;

			System.err.println("record.b.UR.y="+record.b.UR.y);
			System.err.println(String.format("dim=%f %f %f %f", llx, lly, urx, ury));
			g.draw(new Rectangle2D.Double(x + llx, y + lly, urx - llx, ury - lly));
			
			for (int j=0; i<info.n_flds; j++) {
				ST_field_t child = info.fld.get_(j);
				drawRecords(g, x, y, child);
			}
		}
	}

	public void addCluster(ST_Agraph_s c) {
		clusters.add(c);
	}

}
