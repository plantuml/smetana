package smetana;

import java.util.Iterator;
import java.util.NoSuchElementException;

public class RemoveSpaceIterator implements Iterator<String> {

	private String next;
	private final Iterator<String> it;

	public RemoveSpaceIterator(Iterator<String> it) {
		this.it = it;
		goOneStep();
	}

	public boolean hasNext() {
		return next != null;
	}

	public String next() {
		if (next == null) {
			throw new NoSuchElementException();
		}
		final String result = next;
		goOneStep();
		return result;
	}

	private void goOneStep() {
		while (it.hasNext()) {
			next = it.next();
			final char c = next.charAt(0);
			if (Character.isWhitespace(c) == false) {
				return;
			}
		}
		next = null;
	}

	public void remove() {
		throw new UnsupportedOperationException();
	}

}
