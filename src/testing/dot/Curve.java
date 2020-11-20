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

import h.ST_Agedgeinfo_t;
import h.ST_bezier;
import h.ST_pointf;
import h.ST_splines;
import h.ST_textlabel_t;

import java.awt.Graphics2D;
import java.awt.geom.GeneralPath;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;
import java.util.List;

public class Curve {

	private final List<Point2D> points = new ArrayList<Point2D>();
	private double maxX, maxY;
	private ST_textlabel_t label;

	public Curve(ST_Agedgeinfo_t data) {
		final ST_splines splines = data.spl;
		final ST_bezier beziers = splines.list.get__(0);
		for (int i = 0; i < beziers.size; i++) {
			final Point2D pt = getPoint(splines, i);
			maxX = Math.max(maxX, pt.getX());
			maxY = Math.max(maxY, pt.getY());
			points.add(pt);
		}

		label = (ST_textlabel_t) data.label;

		if (label != null) {
			final Rectangle2D rect = getLabelRectangle();
			maxX = Math.max(maxX, rect.getMaxX());
			maxY = Math.max(maxY, rect.getMaxY());
		}

	}

	private Point2D getPoint(ST_splines splines, int i) {
		final ST_bezier beziers = splines.list.get__(0);
		final ST_pointf pt = beziers.list.get__(i);
		return new Point2D.Double(pt.x, pt.y);
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
		final ST_pointf dimen = (ST_pointf) label.dimen;
		final ST_pointf space = (ST_pointf) label.space;
		final ST_pointf pos = (ST_pointf) label.pos;
		final double x = pos.x;
		final double y = pos.y;
		final double width = dimen.x;
		final double height = dimen.y;
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
