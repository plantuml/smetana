package core;

import junit.framework.TestCase;

public class StarImplTest extends TestCase {

	public void testCompareTo() {
		// char **s = malloc(10*4);
		// StarStarImpl<String> s = StarStarImpl.malloc(String.class, 10);
		StarStar<String>  s = (StarStar<String>) Memory.mallocStarStar(String.class,10,false);
		assertTrue(s.compareTo(s) == 0);

		// char **s1 = s+1
		StarStar<String> s1 = s.plus(1);
		// s1>s
		assertTrue(s1.compareTo(s) > 0);
		assertTrue(s.compareTo(s1) < 0);

		s = s.plus(1);
		assertTrue(s.compareTo(s1) == 0);
		assertTrue(s.equals(s1));

		s = s.plus(1);
		assertFalse(s.equals(s1));
		// s1<s
		assertTrue(s.compareTo(s1) > 0);
		assertTrue(s1.compareTo(s) < 0);
	}
	
	public void testPlusPlus() {
		StarStar<String> foo = (StarStar<String>) Memory.mallocStarStar(String.class,10,false);
		assertSame(foo, foo.plus(0));
		assertSame(foo.plus(1), foo.plus(1));
		assertSame(foo.plus(1).plus(2), foo.plus(3));
	}

}