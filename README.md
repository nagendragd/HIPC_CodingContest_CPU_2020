# Security Puzzle
This repo contains the problem specification and evaluation code for a security puzzle.

src/ folder contains the victim code and the attacker template. You will have to develop the attack within this template.

inc/ folder contains header files for the sources.

example/ folder contains a full working example of an attack. In this (trivial) attack, the attacker estimates the size of a square matrix.
The attacker does so by measuring the total time taken by the victim -- a matrix-vector multiplication routine.

build/ contains a Makefile that builds everything. It assumes that your installation contains g++.

To build everything:

    - cd build
    - make

## About the Example
The example/ folder contains a sample demonstration of mounting a timing-based side-channel attack.
In this example, the victim runs a dense matrix-vector multiplication algorithm.
The attacker's goal is to estimate the size of the matrix (number of rows).
(For simplicity, we assume a square matrix)

The attack proceeds in two phases.
In the first phase, the attacker calibrates the time taken by the victim on several matrix sizes.
The attacker buulds a timings table recording the average time taken for every considered matrix size.

In the second phase, the attacker is tested on matrices of random sizes.
A number of tests are performed in this phase, and for each test, the attacker's success or failure at
guessing the size correctly is recorded.

Finally, the program outputs the attacker's success rate: 
Of the total number of tests conducted, how many times did the attacker succeed?

To run the example:

    - cd build
    - ./example

Sample output written to console:
    - ./example
Calibrating execution time for different matrix sizes..
Done calibrating ...
Ready for mounting timing-based attack ...
Running 100 tests ...
Done running tests ...
Num Tests: 100
Num Correct: 77
% Correct:  77
