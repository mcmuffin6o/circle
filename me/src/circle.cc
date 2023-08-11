#include <array>
#include <cmath>
#include <cstdint>
#include <iostream>

template <std::size_t N>
using Bitmap = std::array<std::array<bool, N>, N>;

// template <std::size_t N>
// struct Bitmap {
//   bool& operator()(int x, int y) {
//     return data.at((N - 1) - y).at(x);
//   }
//   std::array<std::array<bool, N>, N> data = {};
// };

struct Point {
  Point(int x_in, int y_in) : x(x_in), y(y_in) {}

  int x = 0;
  int y = 0;
};

int squared(int x) { return x * x; }

// x^2 + y^2 = r^2
// y^2 = r^2 - x^2
// y = sqrt(r^2 - x^2)

template <std::size_t N>
Bitmap<2 * N> draw_circle() {
  Bitmap<2 * N> result = {};
  Point pen_tip = {static_cast<int>(N - 1), 0};

  while (pen_tip.x >= pen_tip.y) {
    result.at((N - 1) + pen_tip.x).at((N - 1) + pen_tip.y) = true;
    result.at((N - 1) + pen_tip.y).at((N - 1) + pen_tip.x) = true;

    result.at((N - 1) + pen_tip.x).at((N - 1) - pen_tip.y) = true;
    result.at((N - 1) + pen_tip.y).at((N - 1) - pen_tip.x) = true;

    result.at((N - 1) - pen_tip.x).at((N - 1) + pen_tip.y) = true;
    result.at((N - 1) - pen_tip.y).at((N - 1) + pen_tip.x) = true;

    result.at((N - 1) - pen_tip.x).at((N - 1) - pen_tip.y) = true;
    result.at((N - 1) - pen_tip.y).at((N - 1) - pen_tip.x) = true;

    pen_tip.y++;
    pen_tip.x = (std::sqrt(squared(N - 1) - squared(pen_tip.y)) * 2 + 1) / 2;
  }

  return result;
}

template <std::size_t N>
void print_bitmap(Bitmap<N> bitmap) {
  for (std::size_t i = 0; i < N; i++) {
    for (std::size_t j = 0; j < N; j++) {
      std::cout << ' ';
      std::cout << static_cast<char>( bitmap.at(j).at((N - 1) - i) * '#')
                << static_cast<char>(!bitmap.at(j).at((N - 1) - i) * ' ');
    }
    std::cout << std::endl;
  }
}

int main() {
  const int RADIUS = 5;
  // Point center(0, 0);
  print_bitmap(draw_circle<RADIUS>());

  return 0;
}
