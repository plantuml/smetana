# Important Notice

Code is hosted there :

* https://github.com/plantuml/plantuml/tree/master/src/gen
* https://github.com/plantuml/plantuml/tree/master/src/smetana/core
* https://github.com/plantuml/plantuml/tree/master/src/h

The initial goal of the project was to test and prove the feasability of the C to Java port.
This goal has been achieved, as the portability is working.

There are now some issues in some cases. We are working hard to fix them.


# Explanation

Smetana is a partial translation of Graphviz/Dot sources from C to Java. More precisely, the intent is to create a Java library (and not a program) like http://www.graphviz.org/doc/libguide/libguide.pdf .

The idea is to translate each C function to a Java static method. Each C struct is also translated to a Java class. If it works in C, it should work in Java (that’s the theory).
A special thanks to Peter Kümmel which provide a CMake friendly version of libcgraphviz (https://github.com/syntheticpp/libcgraphviz)!

Even if this is a library, a minimal program is included to demonstrate the capabilities of the library. You can invoke the program on the command line: `java -jar jdot.jar`

Example:`java -jar jdot.jar foo1.dot foo1.png`

`foo1.dot`beeing the following file:                 
```
digraph foo {
 subgraph cluster02 {
 cl1 [shape=box, width=2.9, height=1.7];
 cl2;
 cl4 [width=0.6, height=0.6];
 cl2->cl1;
 cl1->cl4;
 cl2->cl4;
 }
 subgraph cluster01 {
   in1;
   in2;
   in1 -> in2 [minlen=0];
 }
 N1;
 N2;
 N3;
 N1->N2 [minlen=0];
 N2->N3;
}
```
The input file is a regular DOT language file, although only a tiny portion of DOT language is supported. The included parser is really simple (and again just written for demonstration).

As you can see, output from regular GraphViz/Dot and Smetana library are close:
![Smetana output](https://raw.githubusercontent.com/plantuml/smetana/legacy/foo1.png)
![Graphviz output](https://raw.githubusercontent.com/plantuml/smetana/legacy/foo1_graphviz.png)


