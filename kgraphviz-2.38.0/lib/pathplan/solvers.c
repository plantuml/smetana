#line 1 "graphviz-2.38.0\\lib\\pathplan\\solvers.c" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/



#line 1 "graphviz-2.38.0\\lib\\pathplan\\solvers.c" 1

#line 1 "graphviz-2.38.0\\lib\\pathplan\\solvers.c" 1
#line 1 "graphviz-2.38.0\\lib\\pathplan\\solvers.h" 1
/* $Id$ $Revision$ */
/* vim:set shiftwidth=4 ts=8: */

/*************************************************************************
 * Copyright (c) 2011 AT&T Intellectual Property 
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors: See CVS logs. Details at http://www.graphviz.org/
 *************************************************************************/










    extern int solve3(double *, double *);
    extern int solve2(double *, double *);
    extern int solve1(double *, double *);






#line 19 "graphviz-2.38.0\\lib\\pathplan\\solvers.c" 2















int solve3(double *coeff, double *roots)
{
    double a, b, c, d;
    int rootn, i;
    double p, q, disc, b_over_3a, c_over_a, d_over_a;
    double r, theta, temp, alpha, beta;

    a = coeff[3], b = coeff[2], c = coeff[1], d = coeff[0];
    if ((((a) < 1E-7) && ((a) > -1E-7)))
	return solve2(coeff, roots);
    b_over_3a = b / (3 * a);
    c_over_a = c / a;
    d_over_a = d / a;

    p = b_over_3a * b_over_3a;
    q = 2 * b_over_3a * p - b_over_3a * c_over_a + d_over_a;
    p = c_over_a / 3 - p;
    disc = q * q + 4 * p * p * p;

    if (disc < 0) {
	r = .5 * sqrt(-disc + q * q);
	theta = atan2(sqrt(-disc), -q);
	temp = 2 * ((r < 0) ? (-1*pow(-r, 1.0/3.0)) : pow (r, 1.0/3.0));
	roots[0] = temp * cos(theta / 3);
	roots[1] = temp * cos((theta + 3.14159265358979323846 + 3.14159265358979323846) / 3);
	roots[2] = temp * cos((theta - 3.14159265358979323846 - 3.14159265358979323846) / 3);
	rootn = 3;
    } else {
	alpha = .5 * (sqrt(disc) - q);
	beta = -q - alpha;
	roots[0] = ((alpha < 0) ? (-1*pow(-alpha, 1.0/3.0)) : pow (alpha, 1.0/3.0)) + ((beta < 0) ? (-1*pow(-beta, 1.0/3.0)) : pow (beta, 1.0/3.0));
	if (disc > 0)
	    rootn = 1;
	else
	    roots[1] = roots[2] = -.5 * roots[0], rootn = 3;
    }

    for (i = 0; i < rootn; i++)
	roots[i] -= b_over_3a;

    return rootn;
}

int solve2(double *coeff, double *roots)
{
    double a, b, c;
    double disc, b_over_2a, c_over_a;

    a = coeff[2], b = coeff[1], c = coeff[0];
    if ((((a) < 1E-7) && ((a) > -1E-7)))
	return solve1(coeff, roots);
    b_over_2a = b / (2 * a);
    c_over_a = c / a;

    disc = b_over_2a * b_over_2a - c_over_a;
    if (disc < 0)
	return 0;
    else if (disc == 0) {
	roots[0] = -b_over_2a;
	return 1;
    } else {
	roots[0] = -b_over_2a + sqrt(disc);
	roots[1] = -2 * b_over_2a - roots[0];
	return 2;
    }
}

int solve1(double *coeff, double *roots)
{
    double a, b;

    a = coeff[1], b = coeff[0];
    if ((((a) < 1E-7) && ((a) > -1E-7))) {
	if ((((b) < 1E-7) && ((b) > -1E-7)))
	    return 4;
	else
	    return 0;
    }
    roots[0] = -b / a;
    return 1;
}
