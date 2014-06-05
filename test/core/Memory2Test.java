package core;

import junit.framework.TestCase;

public class Memory2Test extends TestCase {

	public static void incFoo(StructFoo arg) {
		arg.v++;
	}

	public void testMalloc() {
		// StructFoo **s1 = malloc(1)
		StarStar<StructFoo> s1 = (StarStar<StructFoo>) Memory.mallocStarStar(StructFoo.class, 1, false);

		// *s1 = malloc(1)
		s1.set(new StructFoo());

		// // (*s1)->v = 10
		s1.get().v = 10;

		// incFoo(*s1)
		incFoo(s1.get());
		assertTrue(s1.get().v == 11);
	}

}
