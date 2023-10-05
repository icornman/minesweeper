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

  // for (int y = 0; y < 9; y++) {
  //   bombs[y][0] = rand() % 9;

  //   for (int x = 0; x < 9; x++) {
  //     if ((bombs[y][0] == x - 1) || (bombs[y][0] == x + 1)) {
  //       board[y][x] = '1';
  //     } else {
  //       if (bombs[y][0] == x) {
  //         bombs[y][1] = y;
  //         board[y][x] = 'x';
  //       } else {
  //         board[y][x] = '.';
  //       }
  //     }
  //   }
  // }
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

  // // Generate bombs bombs
  // for (int i = 0; i < 9; i++) {
  //   bombs[i][0] = rand() % 9;
  // }

  // // Render board
  // for (int y = 0; y < 9; y++) {
  //   for (int x = 0; x < 9; x++) {
  //     if (bombs[y][0] == x - 1) {
  //       board[y][x] = '1';
  //     } else if (bombs[y][0] == x + 1) {
  //       board[y][x] = '1';
  //     } else {
  //       if (bombs[y][0] == x) {
  //         bombs[y][1] = y;
  //         board[y][x] = 'x';
  //         cout << "\x1b[31m"
  //              << "x "
  //              << "\x1b[0m";
  //       } else {
  //         board[y][x] = '#';
  //         cout << "# ";
  //       }
  //     }
  //   }
  //   cout << endl;
  // }

  // Generate bombs bombs and build NUMBER grid

  placeBombs();

  printBoard();
}

// draw_basic_field();

// while (true) {
//   int firstDigit, secondDigit;

//   std::cout << "Enter coord X & Y: ";
//   std::cin >> firstDigit >> secondDigit;

//   firstDigit -= 1;
//   secondDigit -= 1;

//   system("clear");

//   if (board[secondDigit][firstDigit] == 'x') {
//     for (int y = 0; y < 9; y++) {
//       for (int x = 0; x < 9; x++) {
//         if (board[y][x] == 'x' && firstDigit != x && secondDigit != y) {
//           cout << "\x1b[31m"
//                << "*"
//                << "\x1b[0m"
//                << " ";
//         } else if (firstDigit == x && secondDigit == y) {
//           cout << "\x1b[41m"
//                << "x"
//                << "\x1b[0m"
//                << " ";
//         } else if (board[y][x] == '1') {
//           cout << "\x1b[34m"
//                << "1"
//                << "\x1b[0m"
//                << " ";
//         } else {
//           cout << "\033[1;30m"
//                << "#"
//                << "\033[0m"
//                << " ";
//         }
//       }
//       cout << endl;
//     }
//     cout << endl << "YOU LOSE!" << endl;
//     return 0;
//   } else {
//     draw_basic_field();
//   }
// }
