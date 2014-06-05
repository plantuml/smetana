package core;

import junit.framework.TestCase;

public class StdlibTest extends TestCase {

	public void testStrlen() {
		assertEquals(0, Stdlib.strlen(JUtils.asStarChar("")));
		assertEquals(1, Stdlib.strlen(JUtils.asStarChar("A")));
	}

	public void testStrcpy() {
		StarChar toto = JUtils.asStarChar("toto");
		assertEquals("toto\\0", toto.asString());
		StarChar titi = JUtils.asStarChar("titi");
		assertEquals("titi\\0", titi.asString());
		Stdlib.strcpy(titi, toto);
		assertEquals("toto\\0", titi.asString());
	}

	public void testStrcpy1() {
		StarChar toto = JUtils.asStarChar("toto");
		StarChar titi = Memory.mallocStarChar(5);
		Stdlib.strcpy(titi, toto);
		assertEquals("toto\\0", toto.asString());
		assertEquals("toto\\0", titi.asString());
	}

	public void testStrcpy2() {
		StarChar toto = JUtils.asStarChar("toto");
		StarChar titi = Memory.mallocStarChar(5);
		StarChar titi1 = titi;
		Stdlib.strcpy(titi, toto);
		assertEquals("toto\\0", toto.asString());
		assertEquals("toto\\0", titi.asString());
		assertEquals("toto\\0", titi1.asString());
	}

	public void testStrcpy3() {
		StarChar toto = JUtils.asStarChar("toto");
		StarChar titi = Memory.mallocStarChar(5);
		StarChar titi1 = titi;
		titi1 = titi1.plus(1);
		Stdlib.strcpy(titi, toto);
		assertEquals("toto\\0", toto.asString());
		assertEquals("toto\\0", titi.asString());
		assertEquals("oto\\0", titi1.asString());
	}

	public void testStrcmp() {
		assertEquals(0, Stdlib.strcmp(JUtils.asStarChar("toto"), JUtils.asStarChar("toto")));
		assertEquals(1, Stdlib.strcmp(JUtils.asStarChar("B"), JUtils.asStarChar("A")));
		assertEquals(1, Stdlib.strcmp(JUtils.asStarChar("totoB"), JUtils.asStarChar("totoA")));
		assertEquals(-1, Stdlib.strcmp(JUtils.asStarChar("totoB"), JUtils.asStarChar("totoC")));
	}

	public void testSprintf() {
		int cpt = 3;
		StarChar key = Memory.mallocStarChar(2);
		Stdlib.sprintf(key, "%d", cpt++);
		assertEquals("3\\0", key.asString());
		assertEquals(4, cpt);
	}

	public void testSprintf2() {
		int cpt = 3;
		StarChar key = Memory.mallocStarChar(2);
		Stdlib.sprintf(key, "%d", ++cpt);
		assertEquals("4\\0", key.asString());
		assertEquals(4, cpt);
	}

	public void testPlusplus() {
		StarChar s1 = JUtils.asStarChar("123");
		assertEquals('1', s1.get());
		assertEquals('1', s1.bracket(0));
		assertEquals('2', s1.bracket(1));
		assertEquals('3', s1.bracket(2));
		assertEquals("123\\0", s1.asString());
		assertEquals(3, Stdlib.strlen(s1));

		s1 = s1.plus(1);
		assertEquals("23\\0", s1.asString());
		assertEquals('2', s1.get());
		assertEquals('2', s1.bracket(0));
		assertEquals('3', s1.bracket(1));
		assertEquals(2, Stdlib.strlen(s1));
	}

	public void testStrnstr() {
		StarChar s1 = JUtils.asStarChar("123456789");
		StarChar s2 = Memory.mallocStarChar(5);
		assertEquals("123456789\\0", s1.asString());

		assertEquals("\\0\\0\\0\\0\\0", s2.asString());
		StarChar s2bis = Stdlib.strncpy(s2, s1, 3);
		assertEquals(s2, s2bis);
		assertEquals("123\\0\\0", s2.asString());

		assertEquals("9\\0", s1.plus(8).asString());
		Stdlib.strncpy(s2, s1.plus(8), 3);
		assertEquals("9\\0\\0\\0\\0", s2.asString());
		
		Stdlib.strncpy(s2, s1, 3);
		assertEquals("123\\0\\0", s2.asString());
		Stdlib.strncpy(s2, s1, 1);
		assertEquals("123\\0\\0", s2.asString());
		Stdlib.strncpy(s2, JUtils.asStarChar("1"), 2);
		assertEquals("1\\03\\0\\0", s2.asString());
		Stdlib.strncpy(s2, JUtils.asStarChar("1"), 3);
		assertEquals("1\\0\\0\\0\\0", s2.asString());

	}
	
	public void testAtof() {
		StarChar s = JUtils.asStarChar("1.5");
		assertEquals("1.5\\0", s.asString());
		assertEquals(1.5, Stdlib.atof(s), 0.001);
		
		assertEquals(0.5, Stdlib.atof(JUtils.asStarChar("0.5")), 0.001);
		assertEquals(0.5, Stdlib.atof(JUtils.asStarChar(".5")), 0.001);
		assertEquals(-0.5, Stdlib.atof(JUtils.asStarChar("-0.5")), 0.001);
		assertEquals(-0.5, Stdlib.atof(JUtils.asStarChar("-.5")), 0.001);
	}
	
//	public void testSscanf() {
//		// int r = sscanf("42.42", "%f", &myFoo)
//		double myFoo = 0;
//		StarDouble myFoo__;
//		
//		int r = F(Stdlib.sscanf(JUtils.asStarChar("42.3"), "%f", myFoo__ = REF(myFoo)), myFoo = myFoo__.get());
//		assertEquals(1, r);
//		assertEquals(42.3, myFoo, .001);
//	}
	
	
//	public void ztestSscanf2() {
//		double xf = 0;
//		double yf = 0;
//		char c = 0;
//		StarDouble xf__, yf__; StarChar c__;
//		
//		int r = F(Stdlib.sscanf(JUtils.asStarChar("42.3,14Z"), "%lf,%lf%c"
//				, xf__ = REF(xf), yf__ = REF(yf), c__ = REF(c))
//				, xf = xf__.get(), yf = yf__.get(), c = c__.get());
//		assertEquals(3, r);
//		assertEquals(42.3, xf, .001);
//		assertEquals(16, yf, .001);
//		assertEquals('Z', c);
//	}
	
	

}
