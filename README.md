# C coding kata template

A simple template project for C coding katas. Comes with minimal dependencies, no autotools, no advanced build system.
Provides integration for *check* as a unit testing framework. Builds a shared library (currently a dylib, so OS X only),
a program binary and a check binary.

 - `make` to build the whole project
 - `make kata` to build the kata binary only
 - `make testsuite` to build the testsuite
 - `make test` to run the testsuite
 - `./kata` to run the program
 - `./testsuite` to run the checks
