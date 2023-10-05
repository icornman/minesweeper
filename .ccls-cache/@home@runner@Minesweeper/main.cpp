#include <ctime>
#include <iostream>

using namespace std;

const int boardSize = 9;
const int numBombs = 10;

char board[9][9] = {{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};
bool revealed = false;

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
      if (revealed) {
        if (board[row][col] == 'x') {
          cout << "\x1b[31m"
               << "*"
               << "\x1b[0m"
               << " ";
        } else {
          cout << "\033[1;30m"
               << "."
               << "\033[0m"
               << " ";
        }
      } else {
        cout << "\033[1;30m"
             << "."
             << "\033[0m"
             << " ";
      }
    }
    cout << endl;
  }
}

int main() {
  srand(time(0));

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

    if (board[row][col] == 'x') {
      revealed = true;
      printBoard();
      cout << endl << "YOU LOSE!" << endl;
      return 0;
    }
  }
}