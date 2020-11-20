# Run GraphViz in pure Java!

Smetana is a partial translation of Graphviz/Dot sources from C to Java. More precisely, the intent is to create a Java library (and not a program) like http://www.graphviz.org/doc/libguide/libguide.pdf .

The idea is to translate each C function to a Java static method. Each C struct is also translated to a Java class. If it works in C, it should work in Java (that’s the theory).
A special thanks to Peter Kümmel which provide a CMake friendly version of libcgraphviz (https://github.com/syntheticpp/libcgraphviz)!

Right now, the main work is [hosted in V2_38 branch](https://github.com/plantuml/smetana/tree/V2_38).

## Historic

It takes several pass and steps to have something working.
We keep [the legacy branch](https://github.com/plantuml/smetana/tree/legacy) in case we need to go back to previous works.
This should not be needed anymore.
