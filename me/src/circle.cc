#include <cmath>
#include <cstdint>
#include <iostream>
#include <vector>

const char* RESET = "\033[0m";

const char* BLACK = "\033[30m";
const char* RED = "\033[31m";
const char* GREEN = "\033[32m";
const char* YELLOW = "\033[33m";
const char* BLUE = "\033[34m";
const char* MAGENTA = "\033[35m";
const char* CYAN = "\033[36m";
const char* WHITE = "\033[37m";

const char* BLACK_BG = "\033[40m";
const char* RED_BG = "\033[41m";
const char* GREEN_BG = "\033[42m";
const char* YELLOW_BG = "\033[43m";
const char* BLUE_BG = "\033[44m";
const char* MAGENTA_BG = "\033[45m";
const char* CYAN_BG = "\033[46m";
const char* WHITE_BG = "\033[47m";

using Bitmap = std::vector<std::vector<bool>>;

struct Point {
  Point(int x_in, int y_in) : x(x_in), y(y_in) {}

  int x = 0;
  int y = 0;
};

int squared(int x) { return x * x; }

// x^2 + y^2 = r^2
// y^2 = r^2 - x^2
// y = sqrt(r^2 - x^2)

Bitmap draw_circle(std::size_t radius) {
  Bitmap result(radius * 2, std::vector<bool>(radius * 2));
  Point pen_tip = {static_cast<int>(radius - 1), 0};

  while (pen_tip.x >= pen_tip.y) {
    result.at((radius - 1) + pen_tip.x).at((radius - 1) + pen_tip.y) = true;
    result.at((radius - 1) + pen_tip.y).at((radius - 1) + pen_tip.x) = true;

    result.at((radius - 1) + pen_tip.x).at((radius - 1) - pen_tip.y) = true;
    result.at((radius - 1) + pen_tip.y).at((radius - 1) - pen_tip.x) = true;

    result.at((radius - 1) - pen_tip.x).at((radius - 1) + pen_tip.y) = true;
    result.at((radius - 1) - pen_tip.y).at((radius - 1) + pen_tip.x) = true;

    result.at((radius - 1) - pen_tip.x).at((radius - 1) - pen_tip.y) = true;
    result.at((radius - 1) - pen_tip.y).at((radius - 1) - pen_tip.x) = true;

    pen_tip.y++;
    pen_tip.x =
        (std::sqrt(squared(radius - 1) - squared(pen_tip.y)) * 2 + 1) / 2;
  }

  return result;
}

void print_square_bitmap(Bitmap square_bitmap) {
  if (square_bitmap.size() != square_bitmap[0].size()) {
    std::cerr << RED << "[ERROR " << __FILE__ << " " << __LINE__ << "]: "
              << "print_square_bitmap was passed a non-square bitmap." << RESET
              << std::endl;
    exit(1);
  }
  std::size_t side_len = square_bitmap.size();
  for (std::size_t row = 0; row < side_len; row++) {
    for (std::size_t col = 0; col < side_len; col++) {
      std::cout << ' ';
      std::cout << static_cast<char>(
                       square_bitmap.at(col).at((side_len - 1) - row) * '#')
                << static_cast<char>(
                       !square_bitmap.at(col).at((side_len - 1) - row) * ' ');
    }
    std::cout << std::endl;
  }
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cout << "Usage: circle <radius>" << std::endl;
    exit(0);
  }

  const int RADIUS = atoi(argv[1]);
  print_square_bitmap(draw_circle(RADIUS));

  return 0;
}
