## Tarjan Modified(March 2020)

## About
This program predicts every students maximum grades according to each individuals network(sub-network). Every input network was represented as a graph in order to simplify the problem and the connections each student had (sub-network) were represented as strongly connected components. This prediction consists in giving each student connected the maximum grade in his/hers connections. This was solved using a customized of Tarjan's Algorithm.

## Requirements
C++ Compiler

## Compile & Run
```
g++ project.cpp -o project
./project < {input file}
```
Input file can be generated using tests_generator.cc by typing:
```
g++ testGenerator.cc -o generator
./generator #S #C #SubN #m #M seed > {input file}
```
- #S: number of students
- #C: number of connections between students
- #SubN: number of sub-networks
- #m: minimum number of students in each sub-network(optional, default: 1)
- #M: maximum number of students in each sub-network (optional, default: 10)
- seed: seed for the random generator (optional, default: 0)

This project was in cooperation with [@MargaridaMoreira](https://github.com/MargaridaMoreira). :wink: Check her out!
