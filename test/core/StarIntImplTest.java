package core;

import junit.framework.TestCase;

public class StarIntImplTest extends TestCase {

	private StarInt foo;

	@Override
	protected void setUp() throws Exception {
		foo = Memory.mallocInt(100);
		foo.set(42);
		assertTrue(foo.get() == 42);
		foo = foo.plus(1);
		foo.set(43);
		assertTrue(foo.get() == 43);
		foo = foo.plus(-1);
		assertTrue(foo.get() == 42);
	}

	public void testBracket() {
		assertTrue(foo.bracket(0) == 42);
		assertTrue(foo.bracket(1) == 43);
	}

	public void testSetBracket() {
		foo.setBracket(1, 100);
		assertTrue(foo.bracket(1) == 100);
		assertTrue(foo.plus(1).get() == 100);
		foo = foo.plus(1);
		assertTrue(foo.bracket(0) == 100);
		assertTrue(foo.plus(0).get() == 100);
	}

	public void testCompare() {
		foo = Memory.mallocInt(100);
		assertTrue(foo.compareTo(foo)==0);
		assertTrue(foo.compareTo(foo.plus(1))<0);
		assertTrue(foo.plus(2).compareTo(foo.plus(1))>0);
	}
	
	public void testPlusPlus() {
		assertSame(foo, foo.plus(0));
		assertSame(foo.plus(1), foo.plus(1));
		assertSame(foo.plus(1).plus(2), foo.plus(3));
	}
}
