#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

/*Forward declare*/
void SCC(int* G, int n); //Strongly Connected Component
void DFS(int source, int* G, int size, bool indicate); //Depth First Search

void showStack(stack <int> s); //Show Content of a Stack
void computeTranspose(int* pointer, int n);//Compute a Transpose Matrix
void display(int* n, int s); //Display a Matrix

int* ptr_T;//Initialize a Pointer to a Transpose Matrix
int* visited; //Array Stored Visited Nodes
stack<int> s; //A Stack Stores Node from DFS

string components = "";



int main()
{
    char stop_program;
    int n;//Number of of row and column of a matrix
    int* G; //Create a Pointer to A Graph

    while (true) {
        char choice;  

        cout << "Please enter the number of rows and columns of a square matrix: ";
        cin >> n;
        int i, j, r, c = 0;

        G = new int[n * n];
        ptr_T = new int[n * n];
        visited = new int[n];

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                G[i * n + j] = 0;
            }
        }

        for (i = 0; i < n; i++) {
            cout << "Direction FROM " << i << " TO: ";
            cin >> c;
            G[i * n + c] = 1;
        }
        while (true) {
            cout << "More directions? (Y/N) ";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
                choice = true;
            }
            else if (choice == 'N' || choice == 'n') {
                break;
            }
            else {
                cout << "Please enter Y or N. " << endl;
                continue;
            }
            cout << "How many more direction do you need? ";
            int numOfDirection = 0;
            cin >> numOfDirection;
            for (int i = 0; i < numOfDirection; i++) {
                cout << "Direction FROM: ";
                cin >> r;
                cout << "TO: ";
                cin >> c;
                G[r * n + c] = 1;
            }

        }

        SCC(G, n);

        cout << "Do you want to try another graph? (Y/N) ";
        cin >> stop_program;
        if (stop_program == 'Y' || stop_program == 'y') {
            stop_program = true;
        }
        else if (stop_program == 'N' || stop_program == 'n') {
            break;
        }
        else {
            cout << "Please enter Y or N. " << endl;
            continue;
        }

        delete[] G;
        delete[] ptr_T;
        delete[] visited;

    }

    return 0;

}

/*Strongly Connected Component*/
void SCC(int* G, int n) {

    /*Mark all nodes as not visited*/
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    /*Call Depth First Search*/
    DFS(0, G, n, true);
    for (int k = 0; k < n; k++) {
        while (!visited[k]) {
            DFS(k, G, n, true);
        }
    }

    /*Mark all nodes as not visited for the transpose graph*/
    for (int j = 0; j < n; j++) {
        visited[j] = 0;
    }

    /*Compute a transpose graph*/
    computeTranspose(G, n);

    /*Call Depth First Search for a transpose Graph*/
    while (!s.empty()) {
        while (!visited[s.top()]) {
            DFS(s.top(), ptr_T, n, false);
        }
        s.pop();
        components += ",";
        cout << endl;
    }
}

/*Depth First Search*/
void DFS(int i, int* ptr, int n, bool indicate)
{
    int j;
    visited[i] = 1;
    for (j = 0; j < n; j++)
        if (!visited[j] && ptr[i * n + j] == 1)//Discover a unvisited node
            DFS(j, ptr, n, indicate);
      if (j == n) {
          if (indicate) {
              s.push(i); //push a node in a stack when finish
          }
          else {
              components += std::to_string(i) + " ";
              cout <<i << " ";
          }
        }

}

/*Compute a Transpose Matrix*/
void computeTranspose(int* ptr, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            ptr_T[j * n + i] = ptr[i * n + j];
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


/*Display content of a Matrix*/
void display(int* n, int s)
{
    int i;
    for (i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            cout << n[i * s + j] << "";
        }
    }
}
