/* ========================================================================
 * PlantUML : a free UML diagram generator
 * ========================================================================
 *
 * (C) Copyright 2009-2017, Arnaud Roques
 *
 * Project Info:  http://plantuml.sourceforge.net
 * 
 * This file is part of PlantUML.
 *
 * PlantUML is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * PlantUML distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
 * License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 *
 * [Java is a trademark or registered trademark of Sun Microsystems, Inc.
 * in the United States and other countries.]
 *
 * Original Author:  Arnaud Roques
 * 
 */
package demo.graphic;

import h.Agedge_s;
import h.Agedgeinfo_t;
import h.Agnode_s;
import h.Agnodeinfo_t;
import h.bezier;
import h.splines;

import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

import smetana.core.Macro;
import smetana.core.__ptr__;

public class Graphic {

	private Graphics2D g;
	private BufferedImage bi;

	public Graphic(int width, int height) {
		bi = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
		g = bi.createGraphics();
	}

	public void addSplines(Agedge_s e) {
		final Agedgeinfo_t data = (Agedgeinfo_t) Macro.AGDATA(e).castTo(Agedgeinfo_t.class);
		final splines splines = (splines) data.getPtr("spl");
		addSplines(splines);
	}

	private void addSplines(splines splines) {
		final bezier beziers = (bezier) splines.getPtr("list");
		for (int i = 0; i < beziers.getInt("size"); i++) {
			final __ptr__ pt = beziers.getPtr("list").plus(i).getPtr();
			addPoint(pt.getDouble("x"), pt.getDouble("y"));
		}

	}

	private void addPoint(double x, double y) {
		// System.err.println("POINT " + x + " " + y);
		g.setColor(Color.BLUE);
		g.fillRect((int) (x - 1), (int) (y - 1), (int) (3), (int) (3));
	}

	public void drawTo(File out) {
		try {
			ImageIO.write(bi, "png", out);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public void addNode(Agnode_s n) {
		final Agnodeinfo_t data = (Agnodeinfo_t) Macro.AGDATA(n).castTo(Agnodeinfo_t.class);
		// System.err.println("width=" + data.getDouble("width"));
		// System.err.println("height=" + data.getDouble("height"));
		final double ht = data.getDouble("ht");
		final double lw = data.getDouble("lw");
		final double rw = data.getDouble("rw");
		double x = data.getStruct("coord").getDouble("x");
		double y = data.getStruct("coord").getDouble("y");

		g.setColor(Color.GREEN);
		g.drawRect((int) (x - 2), (int) (y - 2), (int) 5, (int) 5);

		g.setColor(Color.RED);
		g.drawRect((int) (x - ht / 2), (int) (y - lw / 2), (int) ht, (int) lw);

	}
}
