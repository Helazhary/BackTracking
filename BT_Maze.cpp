#include <bits/stdc++.h>
using namespace std;

// global variables
vector<int> sol; // solution vector
int start = 0;   // starting node
int esc = 8;     // escape node
bool visited[9]; // array to keep track of visited nodes

// recursive backtracking function to solve the maze
bool SolveMaze(vector<vector<int>> &maze, int source, bool visited[])
{
    if (source == esc) // if the current node is the escape node
    {
        sol.push_back(source); // add the escape node to the solution vector
        return true;           // return true to indicate that the maze has been solved (reached end node)
    }
    visited[source] = true;                       // mark the current node as visited
    for (int i = 0; i < maze[source].size(); i++) // for each neighbor of the current node
    {
        int neighbor = maze[source][i]; // get the neighbor
        if (!visited[neighbor])         // if the neighbor has not been visited
        {
            if (SolveMaze(maze, neighbor, visited)) // recursively call the function for the neighbor
            {
                sol.push_back(source); // if the neighbor leads to the escape node, add the current node to the solution vector
                return true;           // return true to indicate that the maze has been solved
            }
        }
    }
    return false; // if no neighbor leads to the escape node, return false
}

int main()
{
    // define the maze as a vector of vectors
    vector<vector<int>> maze = {
        {1, 3},    // neighbors of node 0
        {0, 2},    // neighbors of node 1
        {1},       // neighbors of node 2
        {0, 4, 6}, // neighbors of node 3
        {3, 5, 7}, // neighbors of node 4
        {4},       // neighbors of node 5
        {3},       // neighbors of node 6
        {4, 8},    // neighbors of node 7
        {7}        // neighbors of node 8
    };

    SolveMaze(maze, start, visited); // solve the maze starting from the start node 0

    // print the solution vector
    for (int i = sol.size() - 1; i >= 0; i--) // iterate backwards from the end of the solution vector
    {
        cout << sol[i] << " "; // print the node
    }
}
