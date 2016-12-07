#include <iostream>
#include <math.h>

int main() {
  std::string endInput = "END";
  int pos = 0x10;
  std::string inst;
  std::cin >> inst;
  while (endInput.compare(inst) != 0) {
    for (int i = 0; i < inst.size(); i++) {
      if ((inst[i] == 'U') && (pos > 4))
        pos = pos >> 3;
      else if ((inst[i] == 'D') && (pos < 64))
        pos = pos << 3;
      else if ((inst[i] == 'L') && ((pos & 0x1b6) > 0))
        pos = pos >> 1;
      else if ((inst[i] == 'R') && ((pos & 0x0db) > 0))
        pos = pos << 1;
    }
    std::cout << log2(pos) + 1 << std::endl;
    std::cin >> inst;
  }
  return 0;
}
