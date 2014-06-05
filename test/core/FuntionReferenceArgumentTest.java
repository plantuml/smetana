package core;

import junit.framework.TestCase;

public class FuntionReferenceArgumentTest extends TestCase {
	
	public static int function1(StarStar<StructFoo> foo) {
		foo.set(null);
		return 17;
	}

	public static int function2(StarInt foo) {
		foo.set(42);
		return 0;
	}

	public static int function3(StarStar<StructFoo> foo) {
		foo.set(null);
		return 18;
	}

//	public void testWithFoo() {
//		StructFoo myFoo = new StructFoo();
//
//		assertNotNull(myFoo);
//
//		// int r = function1(&myFoo)
//		int r = function1(JUtils.REF(myFoo, new SETTER(){
//			public void set(StructFoo value) {
//				myFoo = value;
//			}}));
//		
//		assertNull(myFoo);
//		assertEquals(17, r);
//	}

	public void testWithFoo2() {
		StructFoo myFoo[] = new StructFoo[]{new StructFoo()};

		assertNotNull(myFoo[0]);

		// int r = function1(&myFoo)
		int r = function3(JUtils.ASREF(myFoo));
		
		assertNull(myFoo[0]);
		assertEquals(18, r);
	}

//	public void testWithInt() {
//		int dummy = 16;
//		StarInt dummy_;
//
//		assertEquals(16, dummy);
//		
//		// int r = function1(&myFoo)
//		int r = F(function2(dummy_ = REF(dummy)), dummy = dummy_.get());
//		
//		assertEquals(42, dummy);
//	}

}
