# Important Notice

(Copied from [the legacy branch](https://github.com/plantuml/smetana/tree/legacy))

This project is not updated anymore because it is now integrated into the main stream of PlantUML.

Code is hosted there :

* https://github.com/plantuml/plantuml/tree/master/src/gen
* https://github.com/plantuml/plantuml/tree/master/src/smetana/core
* https://github.com/plantuml/plantuml/tree/master/src/h

The initial goal of the project was to test and prove the feasability of the C to Java port.
This goal has been achieved, as the portability is working.

So the work is going on into PlantUML itself.
See https://github.com/plantuml/plantuml/discussions/1346 if you want to discuss or contribute

Tell us if this port is important for you !

# Run GraphViz in pure Java!

Smetana is a partial translation of Graphviz/Dot sources from C to Java. More precisely, the intent is to create a Java library (and not a program) like http://www.graphviz.org/doc/libguide/libguide.pdf .

The idea is to translate each C function to a Java static method. Each C struct is also translated to a Java class. If it works in C, it should work in Java (that’s the theory).
A special thanks to Peter Kümmel which provide a CMake friendly version of libcgraphviz (https://github.com/syntheticpp/libcgraphviz)!

Right now, the main work is [hosted in V2_38 branch](https://github.com/plantuml/smetana/tree/V2_38).

## Historic

It takes several pass and steps to have something working.
We keep [the legacy branch](https://github.com/plantuml/smetana/tree/legacy) in case we need to go back to previous works.
This should not be needed anymore.
