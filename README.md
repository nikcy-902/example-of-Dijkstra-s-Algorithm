This program applies the shortest cost path algorithm by Dijkstra using C++ to determine the shortest path between two nodes in a weighted graph. An unordered map represents the graph and each node maps to a list of neighbors with the corresponding weight of the edge between the two. The examples nodes in this graph are denoted as A-E and all the edge weights are positive numbers as required by the algorithm.
The main part of the implementation is managed by the findMinimumRoute function. It explores the nodes with the help of a priority queue whereby the shortest known distance to the source is used. To every node, the algorithm adjusts the distances to its neighbors in case there are shorter routes through it. In the process, it also captures the route followed to reach every node allowing the program to display the entire path on completion of computation.
The main function checks the input of the user to make sure that he/she enters valid nodes of the predefined graph. Once the start label and the end node label are inputted into the program, the shortest path will be computed and the overall cost of the shortest path will be shown. In case there is no such path, it explains the same to the user.
In general, this implementation is an efficient method of calculating the shortest path in a fixed negative-weight graph-free graph. It shows how priority queues in greedy algorithms can be used to obtain optimized traversal and pathfinding (which makes it applicable to route planning problems and network analysis problems).


A description of the challenges encountered.

During the process of testing the program with an online compiler, there were some errors associated with the weights of the edges in the graph. In particular, I wrongly applied negative weights as opposed to positive weights. This generated the wrong behavior and processing errors in the computer code since the Dijkstra Algorithm uses non-negative edge weights.

forgot to check if node has already been visited, could revisit nodes endlessly

reversed comparison operator breaks priority ordering
        
