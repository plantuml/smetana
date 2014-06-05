package smetana;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

public class Extern {

	private final List<String> raw = new ArrayList<String>();

	public Extern(String s, Iterator<String> it) {
		raw.add(s);
		while (it.hasNext()) {
			s = it.next();
			raw.add(s);
			if (s.equals(";")) {
				return;
			}
		}

	}

}
