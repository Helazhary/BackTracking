#include <bits/stdc++.h>
using namespace std;
#define N 9  // Size of the Sudoku grid

// Function to find an empty slot in the Sudoku grid
bool findemptyslot(int grid[N][N], int &row, int &col)
{
    // Loop through all the rows and columns of the grid
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            // If an empty slot is found, return true
            if (grid[row][col] == 0)
                return true;
        }
    }
    // If no empty slot is found, return false
    return false;
}

// Function to check if a number can be placed in a particular row
bool plausablerow(int grid[N][N], int col, int num)
{
    // Loop through all the rows of the grid
    for (int row = 0; row < N; row++)
        // If the number already exists in the row, return false
        if (grid[row][col] == num)
            return false;
    // If the number can be placed in the row, return true
    return true;
}

// Function to check if a number can be placed in a particular column
bool plausablecol(int grid[N][N], int row, int num)
{
    // Loop through all the columns of the grid
    for (int col = 0; col < N; col++)
        // If the number already exists in the column, return false
        if (grid[row][col] == num)
            return false;
    // If the number can be placed in the column, return true
    return true;
}

// Function to check if a number can be placed in a particular 3x3 subgrid
bool plausablesubgrid(int grid[N][N], int boxrow, int boxcol, int num)
{
    // Loop through all the cells of the subgrid
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            // If the number already exists in the subgrid, return false
            if (grid[boxrow + row][boxcol + col] == num)
                return false;
    // If the number can be placed in the subgrid, return true
    return true;
}

// Function to check if a number can be placed in a particular cell
bool plausable(int grid[N][N], int row, int col, int num)
{
    // Check if the number can be placed in the row, column, and subgrid of the cell
    return (
        plausablerow(grid, col, num) &&
        plausablecol(grid, row, num) &&
        plausablesubgrid(grid, row - row % 3, col - col % 3, num) &&
        grid[row][col] == 0);
}

// Function to solve the Sudoku grid using backtracking
bool SolveSudoku(int grid[N][N])
{
    int row, col;

    // Find an empty slot in the grid
    if (!findemptyslot(grid, row, col))
        // If there are no empty slots, the Sudoku is solved
        return true;

    // Loop through all the numbers from 1 to N
    for (int num = 1; num <= N; num++)
    {
        // If the number can be placed in the current cell
        if (plausable(grid, row, col, num))
        {
            // Try placing the number in the current cell
            grid[row][col] = num;
            
            // Recursively call SolveSudoku on the updated grid
            if (SolveSudoku(grid))
                // If a solution is found, return true
                return true;

            // If a solution is not found, backtrack and try the next number
            grid[row][col] = 0;
        }
    }
    
    // If no solution is found, return false
    return false;
}

// This function takes a 2D array representing a Sudoku grid and prints it to the console.
void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            // Print the value of the cell followed by a space
            cout << grid[row][col] << " ";
        
        // Print a new line character after each row
        cout << endl;
    }
}

int main()
{
    // 0 means unassigned cells
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (SolveSudoku(grid) == true)
        printGrid(grid);
    else
        cout << "No solution exists";

    return 0;
}
