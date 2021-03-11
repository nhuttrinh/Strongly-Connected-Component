# Strongly-Connected-Component
Identify strongly connected components of a graph using DFS

Mark all nodes as unvisited,
Using DFS to traverse the graph until there is no more unvisited node.
Push the last visited node(s) to the stack.
Transpose the graph (change direction of the graph)
Mark all nodes as unvisited
Using DFS starting from the top of the stack.
Pop the stack when there is no more unvisited node

Example:
0->1->2->3->4->5 and 3->0
start from 0. DFS till 5, there is no more unvisited node, push 5 to the stack.
then 4, 3, and so forth. 
The stack will be: top:0,1,2,3,4,5:bottom
Transpose the graph: 0<-1<-2<-3<-4<-5 and 0->3
Starting from the top of stack which is 0, DFS till there is no more unvisited node.
Pop 0,1,2,3
From 4, there is no more unvisited node, pop 4
From 5,there is no more unvisited node, pop 5
 There are 3 strongly connected components: 0,1,2,3  4 and 5
