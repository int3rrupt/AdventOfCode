#include <iostream>
#include <math.h>

int main() {
  std::string endInput = "END";
  int pos = 0x10;
  std::string inst;
  std::cin >> inst;
  while (endInput.compare(inst) != 0) {
    for (int i = 0; i < inst.size(); i++) {
      if ((inst[i] == 'U') && (pos & 0x1EE4) > 0)
        pos = pos >> ((pos > 8) && (pos < 4096) ? 4 : 2);
      else if ((inst[i] == 'D') && (pos & 0x04EF) > 0)
        pos = pos << ((pos > 1) && (pos < 512) ? 4 : 2);
      else if ((inst[i] == 'L') && (pos & 0x0DEC) > 0)
        pos = pos >> 1;
      else if ((inst[i] == 'R') && (pos & 0x06F6) > 0)
        pos = pos << 1;
    }
    std::cout << ((log2(pos) > 8) ? (char)((log2(pos) - 9) + 'A') : (char)(log2(pos) + '1')) << std::endl;
    std::cin >> inst;
  }
  return 0;
}
