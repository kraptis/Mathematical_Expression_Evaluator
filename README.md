#Mathematical Expression Evaluator
============================



A Mathematical Expression Evaluator is actually a calculator for basic math expressions such as 3 * 5 + 2. Two different approaches for solving this problem are implemented. One approach is based on a stack while the other one is based on a tree. In addition, a different approach of the stack implementation is introduced using the Flyweight Pattern. While for the Tree based implementation a new approach is introduced with an alternative Visitor Pattern and a different approach of the Tree building and evaluation. All algorithms are implemented in C++ with various Patterns such as Abstract Factory, Iterator and Command Pattern for the stack implementation while Visitor, Composite and Builder Patterns are used for the tree based implementation. The input for all algorithms is an infix expression with a space between every string, for instance 3 + 4 * ( 4 % 2). The operators that the algorithms can evaluate are +,-,*,/ and % while the numbers must be integers, negative or positive.

#Visitor Pattern

Represent an operation to be performed on the elements of an object structure. 
it lets you define a new operation without changing the classes of the elements on which it operates

#Composite Pattern

Compose objects into tree structures to represent part-whole hierarchies. It lets clients treat individual objects and compositions of objects uniformly.

#Builder Pattern

Seperate the construction of a complex object from its representation so that the same construction process can create different representations.

#Abstract Factory

Provide an interface for creating families of related or dependent objects without specifying their classes.

#Iterator Pattern

Provide a way to access the elements of an aggregate object sequentially without exposing its underlying representation.

#Command Pattern

Encapsulate a request as an object, thereby letting you parameterize clients with different requests, queue or log requests, and support undoable operations.

#Flyweight Pattern

Use sharing to support large numbers of fine-grained objects efficiently.

#Requirements

Red Hat 6.x, gcc 4.8. 
To produce different expressions run the create_expressions.py (tested with python 2.7).
To create the makefiles you need the MPC https://github.com/objectcomputing/MPC . An awesome open source software for assisting the maintaining software designed to build on many platforms.

The main class is the driver.cpp.












