#include <iostream>
#include <vector>
using namespace std;

// Check if a queen can be placed at row i and column j without conflicts with other queens
bool isQueenPlacementValid(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        int placedQueenCol = board[i];
        // Check for horizontal and diagonal conflicts with previously placed queens
        if (placedQueenCol == col || placedQueenCol - col == i - row || placedQueenCol - col == row - i) {
            return false; // A conflict was found
        }
    }
    return true; // No conflicts were found
}

// Place queens recursively, starting from row i
void placeQueens(vector<int>& board, int row, int& count) {
    int n = board.size();
    // If all queens have been placed successfully on the board, increment the solution count and return
    if (row == n) {
        count++;
        return;
    }
    // Try placing the queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isQueenPlacementValid(board, row, col)) {
            board[row] = col; // Place a queen in the current row and column
            placeQueens(board, row + 1, count); // Recursively place the remaining queens
            board[row] = -1; // Backtrack by removing the queen from the current row and column
        }
    }
}

int main() {
    int n = 8; // The size of the chessboard
    vector<int> board(n, -1); // Initialize the board with no queens placed

    int count = 0; // The number of valid solutions found
    placeQueens(board, 0, count); // Place queens recursively, starting from row 0

    cout << count << " solutions." << "\n";
    
}
