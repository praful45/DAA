//6.4 n queen problem

#include <chrono> // for measuring time
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check if there is a queen in the upper-right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // If no conflicts, it's safe to place a queen here
    return true;
}
bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    // Base case: all queens have been placed
    if (row == N) {
        return true;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;

            // Recursive call to place queens in the next row
            if (solveNQueens(board, row + 1, N)) {
                return true;
            }

            // Backtrack: remove the queen and try the next column
            board[row][col] = 0;
        }
    }

    // If no queen can be placed in this row, backtrack
    return false;
}

void printBoard(vector<vector<int>>& board,int N){
            // Print the board with queens
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (board[i][j] == 1) {
                        cout << "Q ";
                    } else {
                        cout << ".  ";
                    }
                }
                cout << endl;
            }
}

int main() {
    cout << "------------------------------------------------\n";

    for (int N = 1; N <= 15; N++) {
        auto start_time = chrono::high_resolution_clock::now(); // start measuring time

        vector<vector<int>> board(N, vector<int>(N, 0)); // Initialize the board with all zeros

        if (solveNQueens(board, 0, N)) {
            printBoard(board,N);
        } else {
            cout << "Solution doesn't exist for chessboard with N=" << N << endl;
        }

        auto end_time = chrono::high_resolution_clock::now(); // end measuring time
        auto time_ms = chrono::duration<double,std::milli>(end_time - start_time); // calculate time in milliseconds

        cout << "N=" << N << "\t" << setw(15) << "time="<< time_ms.count()<<"ms" << endl;
        cout << "------------------------------------------------\n\n";
    }

    return 0;
}


