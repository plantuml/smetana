package core;

import junit.framework.TestCase;

public class PlusplusTest extends TestCase {
	
	public void testPlusPlus01() {
		StarStar<String> foo = (StarStar<String>) Memory.mallocStarStar(String.class,10,false);
		assertSame(foo, foo.plus(0));
		assertSame(foo.plus(1), foo.plus(1));
		assertSame(foo.plus(1).plus(2), foo.plus(3));
	}

	public void testPlusPlus02() {
		StarDouble foo = Memory.mallocDouble(10);
		assertSame(foo, foo.plus(0));
		assertSame(foo.plus(1), foo.plus(1));
		assertSame(foo.plus(1).plus(2), foo.plus(3));
	}

	public void testPlusPlus03() {
		StarInt foo = Memory.mallocInt(10);
		assertSame(foo, foo.plus(0));
		assertSame(foo.plus(1), foo.plus(1));
		assertSame(foo.plus(1).plus(2), foo.plus(3));
	}

	public void testPlusPlus04() {
		StarChar foo = Memory.mallocStarChar(10);
		assertSame(foo, foo.plus(0));
		assertSame(foo.plus(1), foo.plus(1));
		assertSame(foo.plus(1).plus(2), foo.plus(3));
	}

	public void testPlusPlus05() {
		StarStarChar foo = Memory.mallocStarStarChar(10);
		assertSame(foo, foo.plus(0));
		assertSame(foo.plus(1), foo.plus(1));
		assertSame(foo.plus(1).plus(2), foo.plus(3));
	}

}