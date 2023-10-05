#include <ctime>
#include <iostream>

using namespace std;

void draw_basic_field() {
  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 9; x++) {
      cout << "\033[1;30m"
           << "#"
           << "\033[0m"
           << " ";
    }
    cout << endl;
  }
}

int main() {
  srand(time(0));

  int coords[9][2] = {};
  char map[9][9] = {};

  // // Generate bombs coords
  // for (int i = 0; i < 9; i++) {
  //   coords[i][0] = rand() % 9;
  // }

  // // Render map
  // for (int y = 0; y < 9; y++) {
  //   for (int x = 0; x < 9; x++) {
  //     if (coords[y][0] == x - 1) {
  //       map[y][x] = '1';
  //     } else if (coords[y][0] == x + 1) {
  //       map[y][x] = '1';
  //     } else {
  //       if (coords[y][0] == x) {
  //         coords[y][1] = y;
  //         map[y][x] = 'x';
  //         cout << "\x1b[31m"
  //              << "x "
  //              << "\x1b[0m";
  //       } else {
  //         map[y][x] = '#';
  //         cout << "# ";
  //       }
  //     }
  //   }
  //   cout << endl;
  // }

  // Generate bombs coords and build NUMBER grid
  for (int y = 0; y < 9; y++) {
    coords[y][0] = rand() % 9;

    for (int x = 0; x < 9; x++) {
      if ((coords[y][0] == x - 1) || (coords[y][0] == x + 1)) {
        map[y][x] = '1';
      } else {
        if (coords[y][0] == x) {
          coords[y][1] = y;
          map[y][x] = 'x';
        } else {
          map[y][x] = '#';
        }
      }
    }
  }

  draw_basic_field();

  while (true) {
    int firstDigit, secondDigit;

    std::cout << "Enter coord X & Y: ";
    std::cin >> firstDigit >> secondDigit;

    firstDigit -= 1;
    secondDigit -= 1;

    system("clear");

    if (map[secondDigit][firstDigit] == 'x') {
      for (int y = 0; y < 9; y++) {
        for (int x = 0; x < 9; x++) {
          if (map[y][x] == 'x' && firstDigit != x && secondDigit != y) {
            cout << "\x1b[31m"
                 << "*"
                 << "\x1b[0m"
                 << " ";
          } else if (firstDigit == x && secondDigit == y) {
            cout << "\x1b[41m"
                 << "x"
                 << "\x1b[0m"
                 << " ";
          } else if (map[y][x] == '1') {
            cout << "\x1b[34m"
                 << "1"
                 << "\x1b[0m"
                 << " ";
          } else {
            cout << "\033[1;30m"
                 << "#"
                 << "\033[0m"
                 << " ";
          }
        }
        cout << endl;
      }
      cout << endl << "YOU LOSE!" << endl;
      return 0;
    } else {
      draw_basic_field();
    }
  }
}