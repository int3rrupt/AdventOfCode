#include <iostream>
#include <math.h>

int main() {
  std::string endInput = "END";
  int pos = 0x10;
  std::string inst;
  std::cin >> inst;
  while (endInput.compare(inst) != 0) {
    for (int i = 0; i < inst.size(); i++) {
      switch (inst[i]) {
        case 'U': {
          if (pos > 4)
            pos = pos >> 3;
          break;
        }
        case 'D': {
          if (pos < 64)
            pos = pos << 3;
          break;
        }
        case 'L': {
          if ((pos & 0x1b6) > 0)
            pos = pos >> 1;
          break;
        }
        case 'R': {
          if ((pos & 0x0db) > 0)
            pos = pos << 1;
          break;
        }
      }
    }
    std::cout << "position stop " << log2(pos) + 1 << std::endl;
    std::cin >> inst;
  }
  return 0;
}
