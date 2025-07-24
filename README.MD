# Clox

> [!WARNING]
> This is a toy compiler and is not meant for production grade code!

A compiler for the Lox programming language written in C while following along 
with Robert Nystrom's "Crafting Interpreters".

# Implementation

The Clox compiler gives Lox scripts a bytecode representation which is then
stored in a stack based virtual machine that runs the code. Some of the algorithms
used in the project include a Pratt Parser for dealing with parse precedence, Mark-Sweep
Garbage Collection, and many more.

# Features

* Comments (//)
* Dynamiclly typed variables (integers, floats, doubles)
* Assignment operator (=)
* Math operators (+, -, *, /)
* Builtins (print, clock)
* Functions with parameters (fun)
* Closures
* Classes (class, inheiritance, this, super, constructor)
* Garbage Collecter

# Optimizations

Clox saw runtime improvements of 90% or more in many intensive functions
over the Java implementation of Lox (Jlox). Some of the optimizations include:

* Pratt Parser instead of recursive depth parsing
* Faster hash table probing
* NaN boxing
* Bytecode representation over Abstract Syntax Tree
* More compact data dtructures
* Less memory used in storing closure data

# Example

> See [test](/test) folder for more examples.

```c
// This is how you leave a comment.

class A {
	start() {
		print "This string came from a.";
	}
}

class B < A {
	finish() {
		print "This string came from b.";
	}
}

var klass = B();
klass.start();
klass.finish();

fun fib(n) {
	if (n < 2) return n;
	return fib(n - 2) + fib(n - 1);
}

var start = clock();
print fib(35);
print clock() - start;
```
