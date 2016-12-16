#include <iostream>

int checkmirror(std::string s, int origin, int count) {
  if (((origin - count) >= 0) && (((origin + 1) + count) <= (s.size() - 1)))
    if (s[origin - count] == s[(origin + 1) + count]) return checkmirror(s, origin, count + 1);
  return count - 1;
}

int main() {
  int count = 0;
  std::string s;
  std::cin >> s;
  while (s != "END") {
    bool inhypernet = false, hypernetpassed = true;
    int tmpcount = 0;
    for (int i = 1; i < s.size() - 1; i++) {
      if (s[i] == '[') inhypernet = true;
      if (s[i] == ']') inhypernet = false;
      if ((s[i] == s[i + 1]) && (s[i - 1] != s[i]) )
        if (checkmirror(s, i, 1) > 0) {
          if (inhypernet) {
            hypernetpassed = false;
            continue;
          }
          else tmpcount++;
        }
    }
    if ((tmpcount > 0) && hypernetpassed) count++;
    std::cin >> s;
  }
  std::cout << count << std::endl;
  return 0;
}
