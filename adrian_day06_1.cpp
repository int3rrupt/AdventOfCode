#include <iostream>
#include <vector>

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
      int maxind = 0;
      for (int j = 0; j < 26; j++)
        if(counts[i][j] > counts[i][maxind])
          maxind = j;
      std::cout << (char)(maxind + 'a');
  }
  std::cout << std::endl;
  return 0;
}
