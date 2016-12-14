#include <iostream>
#include <vector>
#include <sstream>

int main() {
  std::string s;
  std::cin >> s;
  while (s != "END") {
    std::vector<int> charcount(26, 0);
    std::vector< std::vector<int> > max(5, std::vector<int>(2, 0));
    for (int i = 0; i < (s.size() - 7); i++)
      if (s[i] >= 'a' && s[i] <= 'z')
        charcount[s[i] - 'a']++;
    for (int i = 25; i >= 0; i--)
      for (int j = 0; j < 5; j++)
        if (charcount[i] >= max[j][1]) {
          for (int k = 4; k > j; k--)
            max[k] = max[k - 1];
          max[j][0] = i + 'a';
          max[j][1] = charcount[i];
          break;
        }
    std::stringstream ss;
    std::string topchars;
    ss << (char)max[0][0] << (char)max[1][0] << (char)max[2][0] << (char)max[3][0] << (char)max[4][0];
    ss >> topchars;
    if (s.substr(s.size() - 6, 5) == topchars) {
      int rot = atoi(s.substr(s.size() - 10, 3).c_str());
      for (int i = 0; i < s.size() - 11; i++)
        if (s[i] >= 'a' && s[i] <= 'z')
          s[i] = (char)((((s[i] - 'a') + rot) % 26) + 'a');
      if (s.substr(0, 5) == "north")
        std::cout << s << std::endl;
    }
    std::cin >> s;
  }
  return 0;
}
