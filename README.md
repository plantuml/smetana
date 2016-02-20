Smetana is a partial translation of Graphviz/Dot sources from C to Java. More precisely, the intent is to create a Java library (and not a program) like http://www.graphviz.org/doc/libguide/libguide.pdf .

The idea is to translate each C function to a Java static method. Each C struct is also translated to a Java class. If it works in C, it should work in Java (that’s the theory).

Because even if C and Java syntaxes are somehow close, many C features do not exist in Java. A low layer has then been written to mimic/emulate some C features (pointer arithmetic, casting…). This layer is far from perfect (for example, it does treat union as struct, which is not correct), but it seems close enough to give working results with Graphviz/dot.

Even if this is a library, a minimal program is included to demonstrate the capabilities of the library. You can invoke the program on the command line: `java -jar jdot.jar`

Example:`java -jar jdot.jar foo1.dot foo1.png`

`foo1.dot`beeing the following file:                 
```
digraph { 
 cl0001 [shape=box, width=7.9, height=4.7]
 cl0002 [shape=box, width=0.6, height=0.6]
 cl0004 [shape=box, width=0.6, height=0.6]
 cl0002->cl0001
 cl0001->cl0004
 cl0002->cl0004
}
```
The input file is a regular DOT language file, although that only a tiny portion of DOT language is supported. The included parser is really simple (and again just written for demonstration).

Right now, you cannot put attributes on edges, and the only attributes for nodes are “shape” (with only box and ellipse values allowed), width and height. Clusters are not supported, neither texts or edges decorations. So few features… but it works!

Performance are quite bad because C structures are interpreted in Java and that slows down the whole execution. Another reason is that the standard “qsort” function has been implemented as a bubble sort (for simplicity, but this could and will be easily change to the standard Collections.sort() method in some future version).

Some refactoring will be started in some future when the translation will be complete enough. The idea is to have regular Java class and to throw away the C emulation layer.

**Stay tuned!**

