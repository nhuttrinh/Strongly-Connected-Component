#include<stdio.h>
#include<iostream>
#include<list>
#include <stack>
using namespace std;

/*Forward declare*/
void SCC(int *G, int n); //Strongly Connected Component
void DFS(int source, int *G, int size); //Depth First Search
void DFS_T(int source, int *G, int size);//Depth Frist Search for Transpose Matrix
void showStack(stack <int> s); //Show Content of a Stack
void computeTranspose(int *pointer, int n);//Compute a Transpose Matrix
void display(int *n, int s); //Display a Matrix

int *ptr_T = new int [6*6];//Initialize a Pointer to a Transpose Matrix
int visited[6]; //Array Stored Visited Nodes
stack<int> s; //A Stack Stores Node from DFS


int main()
{
    int *G = new int[6*6]; //Create a Pointer to A Graph
    int  n = 6;
    int i,j;

     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            G[i*n+j] = 0;
            }
       }

    G[0*n+1] = 1;
    G[1*n+2] = 1;
    G[2*n+3] = 1;
    G[3*n+1] = 1;
    G[3*n+4] = 1;
    G[4*n+5] = 1;
    G[5*n+4] = 1;

    SCC(G,6);

return 0;

}

/*Strongly Connected Component*/
void SCC(int *G, int n){

  /*Mark all nodes as not visited*/
  for(int i=0;i<n;i++){
        visited[i]=0;
    }

    /*Call Depth First Search*/
    DFS(0,G,n);
    for(int k =0;k<n;k++){
    while(!visited[k]){
     DFS(k,G,n);
    }
    }

    /*Mark all nodes as not visited for the transpose graph*/
    for(int j=0;j<n;j++){
        visited[j]=0;
    }

    /*Compute a transpose graph*/
    computeTranspose(G,n);

   /*Call Depth First Search for a transpose Graph*/
   while(!s.empty()){
     while(!visited[s.top()]){
     DFS_T(s.top(),ptr_T,n);
     }
     s.pop();
     cout<<endl;
    }
}

/*Depth First Search*/
void DFS(int i, int *ptr, int n)
{

     int j;
     visited[i]=1;
     for(j=0;j<n;j++)
        if(!visited[j] &&ptr[i*n+j]==1)//Discover a unvisited node
            DFS(j,ptr,n);
            if(j==n){
              s.push(i); //push a node in a stack when finish

            }

}

/*Depth First Search for Transpose Matrix*/
void DFS_T(int i, int *ptr_T, int n)
{
     int j;
     visited[i]=1;
     for(j=0;j<n;j++)
        if(!visited[j] &&ptr_T[i*n+j]==1)
            DFS_T(j,ptr_T,n);
            if(j==n){
              cout<<i<<",";
            }

}

/*Function to test a Stack*/
void showStack(stack<int> s)
{
    while (!s.empty())
    {
      cout << s.top();
        s.pop();

    }

}

/*Compute a Transpose Matrix*/
void computeTranspose(int *ptr, int n){
   for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            ptr_T[j*n+i]=ptr[i*n+j];
        }
}

/*Display content of a Matrix*/
void display(int *n, int s)
{
int i;
for(i=0; i<s; i++){
    for(int j = 0;j<s;j++){
    cout << n[i*s+j] << "";
}
}
}
