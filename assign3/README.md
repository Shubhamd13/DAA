# Compile using following command
```
gcc da3.c
```
## Output  

```
shubham@shubham:~/github/daa/assign3$ ./a.out
Enter no. of vertices: 4
Enter graph in matrix form:
5 6 1 9
2 6 8 9
4 5 10 3
11 4 7 2
Enter source: 1
Vertex 1 -> cost = 0 parent = 0
Vertex 2 -> cost = 6 parent = 1
Vertex 3 -> cost = 1 parent = 1
Vertex 4 -> cost = 4 parent = 3

No negative weight cycle

shubham@shubham:~/github/daa/assign3$ ./a.out
Enter no. of vertices: 2
Enter graph in matrix form:
0 -3
2 0
Enter source: 1

Negative weight cycle exists

```
