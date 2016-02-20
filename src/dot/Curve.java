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

import h.Agedgeinfo_t;
import h.bezier;
import h.pointf;
import h.splines;
import h.textlabel_t;

import java.awt.Graphics2D;
import java.awt.geom.GeneralPath;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;
import java.util.List;

import smetana.core.__ptr__;
import smetana.core.__struct__;

public class Curve {

	private final List<Point2D> points = new ArrayList<Point2D>();
	private double maxX, maxY;
	private textlabel_t label;

	public Curve(Agedgeinfo_t data) {
		final splines splines = (splines) data.getPtr("spl");
		final bezier beziers = (bezier) splines.getPtr("list");
		for (int i = 0; i < beziers.getInt("size"); i++) {
			final Point2D pt = getPoint(splines, i);
			maxX = Math.max(maxX, pt.getX());
			maxY = Math.max(maxY, pt.getY());
			points.add(pt);
		}

		label = (textlabel_t) data.getPtr("label");

		if (label != null) {
			final Rectangle2D rect = getLabelRectangle();
			maxX = Math.max(maxX, rect.getMaxX());
			maxY = Math.max(maxY, rect.getMaxY());
		}

	}

	private Point2D getPoint(splines splines, int i) {
		final bezier beziers = (bezier) splines.getPtr("list");
		final __ptr__ pt = beziers.getPtr("list").plus(i).getPtr();
		return new Point2D.Double(pt.getDouble("x"), pt.getDouble("y"));
	}

	public void drawCurve(Graphics2D g) {
		GeneralPath path = new GeneralPath();
		path.moveTo(points.get(0).getX(), points.get(0).getY());
		for (int i = 1; i < points.size(); i += 3) {
			final Point2D pt2 = points.get(i);
			final Point2D pt3 = points.get(i + 1);
			final Point2D pt4 = points.get(i + 2);
			path.curveTo(pt2.getX(), pt2.getY(), pt3.getX(), pt3.getY(), pt4.getX(), pt4.getY());
		}
		g.draw(path);

		if (label != null) {
			final Rectangle2D rect = getLabelRectangle();
			g.draw(rect);
		}

	}

	private Rectangle2D getLabelRectangle() {
		final __struct__<pointf> dimen = label.getStruct("dimen");
		final __struct__<pointf> space = label.getStruct("space");
		final __struct__<pointf> pos = label.getStruct("pos");
		final double x = pos.getDouble("x");
		final double y = pos.getDouble("y");
		final double width = dimen.getDouble("x");
		final double height = dimen.getDouble("y");
		final Rectangle2D rect = new Rectangle2D.Double(x - width / 2, y - height / 2, width, height);
		return rect;
	}

	public double getMaxX() {
		return maxX;
	}

	public double getMaxY() {
		return maxY;
	}

}
