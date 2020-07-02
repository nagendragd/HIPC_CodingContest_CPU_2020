# Security Puzzle
This repo contains the problem specification and evaluation code for a security puzzle.

src/ folder contains the victim code and the attacker template. You will have to develop the attack within this template.

inc/ folder contains header files for the sources.

example/ folder contains a full working example of an attack. In this (trivial) attack, the attacker estimates the size of a square matrix.
The attacker does so by measuring the total time taken by the victim -- a matrix-vector multiplication routine.

build/ contains a Makefile that builds everything. It assumes that your installation contains g++.

To build everything:
    **cd build**

    **make**

