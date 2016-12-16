#include <iostream>
#include <vector>
#include <climits>

int main() {
  std::string s;
  std::cin >> s;
  int width = s.size();
  std::vector< std::vector<int> > counts(width, std::vector<int>(26, 0));
  while (s != "END") {
    for (int i = 0; i < width; i++)
      counts[i][s[i] - 'a']++;
    std::cin >> s;
  }
  for (int i = 0; i < width; i++) {
      int minind = 0;
      for (int j = 0; j < 26; j++)
        if((counts[i][j] > 0) && (counts[i][j] < (counts[i][minind] > 0 ? counts[i][minind] : INT_MAX)))
          minind = j;
      std::cout << (char)(minind + 'a');
  }
  std::cout << std::endl;
  return 0;
}
