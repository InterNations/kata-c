# C coding kata template

A simple template project for C coding katas. Comes with minimal dependencies, no autotools, no advanced build system.
Provides integration for *check* as a unit testing framework. Builds a shared library (currently a dylib, so OS X only),
a program binary and a check binary.

 - `make` to build the whole project
 - `make kata` to build the kata executable only
 - `make checks` to build project tests
 - `make check` to run the tests
 - `./kata` to run the program
 - `./checks` to run the checks
