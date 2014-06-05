package core;

import junit.framework.TestCase;

public class MemoryTest extends TestCase {

	public static void incFoo(StructFoo arg) {
		arg.v++;
	}

	public void testMalloc() {
		// StructFoo *s1 = malloc(1)
		StructFoo s1 = new StructFoo();
		// s1->v = 10
		s1.v = 10;
		incFoo(s1);
		assertTrue(s1.v == 11);
	}

}
