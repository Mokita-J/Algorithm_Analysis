## Edmonds-Karp (May 2020)

## About
This program calculates the maximum number of citizens that can reach a supermarket without coming into contact with another citizen. All of the citizens and the supermarkets are randomly located in different cells of a grid and none of the citizens' path can intersect with each others. In order to simplify this problem, the grid was represented as a weighted graph with each edge's capacity as 1, all of the citizens became one source vertex and all of the supermarkets became one sink vertex. Thus, making this a Max-Flow problem, which solved using Edmonds-Karp Algorithm.

## Requirements
C++ Compiler
Python 3 (for the test generator)

## Compile & Run
```
g++ project.cpp -o project
./project < {input file}
```
Input file can be generated using tests_generator.cc by typing:
```
python tests_generator.py -n 3 -m 3 -s 2 -c 3 -N 5 -M 5 -S 4 -C 5 -Z 4
```
- -n: Minimum number of streets (default=1)
- -m: Minimum number of avenues (default=1)
- -s: Minimum number of supermarkets (default=1)
- -c: Minimum number of houses (default=1)
- -N: Maximum number of streets (default=1)
- -M: Maximum number of avenues (default=1)
- -S: Maximum number of supermarkets (default=1)
- -C: Maximum number of houses (default=1)
- -Z: Seed for the rng (default=None)

This project was in cooperation with [@MargaridaMoreira](https://github.com/MargaridaMoreira). :wink: Check her out!
