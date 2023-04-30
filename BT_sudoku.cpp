#include <bits/stdc++.h>
using namespace std;
#define N 9

bool findemptyslot(int grid[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool plausablerow(int grid[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return false;
    return true;
}

bool plausablecol(int grid[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (grid[row][col] == num)
            return false;
    return true;
}

bool plausablesubgrid(int grid[N][N], int boxrow, int boxcol, int num)
{
    for (int row = 0; row < N; row++)
        for (int col = 0; col < N; col++)
            if (grid[boxrow + row][boxcol + col] == num)
                return true;
    return false;
}

bool plausable(int grid[N][N], int row, int col, int num)
{
    return (
        plausablerow(grid, row, num) &&
        plausablecol(grid, col, num) &&
        plausablesubgrid(grid, row - row % 3, col - col % 3, num) &&
        grid[row][col] == 0);
}

bool SolveSudoku(int grid[N][N])
{
    int row, col;

    if (!findemptyslot(grid, row, col))
        return true;
    for (int num = 1; num <= N; num++)
    {
        if (plausable(grid, row, col, num))
        {
            grid[row][col] = num;
            if (SolveSudoku(grid))
                return true;
            grid[row][col] = 0;
        }
    }
    return false;
}

void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
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
