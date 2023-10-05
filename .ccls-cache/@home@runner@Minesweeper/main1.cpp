#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

const int boardSize = 8;
const int numBombs = 10;

vector<vector<char>> board(boardSize, vector<char>(boardSize, ' '));
vector<vector<bool>> revealed(boardSize, vector<bool>(boardSize, false));

void placeBombs() {
    int bombsPlaced = 0;
    while (bombsPlaced < numBombs) {
        int row = rand() % boardSize;
        int col = rand() % boardSize;
        if (board[row][col] != 'x') {
            board[row][col] = 'x';
            bombsPlaced++;
        }
    }
}

void printBoard() {
    cout << "  ";
    for (int col = 0; col < boardSize; col++) {
        cout << col << " ";
    }
    cout << "\n";

    for (int row = 0; row < boardSize; row++) {
        cout << row << " ";
        for (int col = 0; col < boardSize; col++) {
            if (revealed[row][col]) {
                cout << board[row][col] << " ";
            } else {
                cout << ". ";
            }
        }
        cout << "\n";
    }
}

void openCell(int row, int col) {
    if (row < 0 || row >= boardSize || col < 0 || col >= boardSize || revealed[row][col]) {
        return;
    }

    revealed[row][col] = true;

    if (board[row][col] == 'x') {
        cout << "Game Over! You hit a bomb." << endl;
        // You can handle game over logic here.
    } else if (board[row][col] == ' ') {
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        for (int i = 0; i < 8; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            if (newRow >= 0 && newRow < boardSize && newCol >= 0 && newCol < boardSize && !revealed[newRow][newCol]) {
                openCell(newRow, newCol);
            }
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    placeBombs();
    printBoard();

    while (true) {
        int row, col;
        cout << "Enter row and column to open (e.g., 0 0): ";
        cin >> row >> col;

        if (row < 0 || row >= boardSize || col < 0 || col >= boardSize) {
            cout << "Invalid input. Try again." << endl;
            continue;
        }

        if (!revealed[row][col]) {
            openCell(row, col);
            printBoard();
        } else {
            cout << "Cell already revealed. Try again." << endl;
        }
    }

    return 0;
}
