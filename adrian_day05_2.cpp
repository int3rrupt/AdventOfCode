#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <openssl/md5.h>

int main() {
  unsigned char digest[MD5_DIGEST_LENGTH];
  long long index = 0, pcount = 0;
  std::string input, s;
  std::vector<char> p(8, '_');
  std::cin >> input;
  while (pcount < 8) {
    std::stringstream ssinput, sspass;
    ssinput << input << index;
    ssinput >> s;
    char chars[s.size()], mdString[33];
    strcpy(chars, s.c_str());
    MD5((unsigned char*)&chars, strlen(chars), (unsigned char*)&digest);
    if (digest[0] == 0 && digest[1] == 0 && digest[2] < 8 && p[digest[2]] == '_'){
      p[digest[2]] = ((digest[3] >> 4) < 10 ? (char)((digest[3] >> 4) + '0') : (char)(((digest[3] >> 4) - 10) + 'a'));
      std::cout << p[0] << p[1] << p[2] << p[3] << p[4] << p[5] << p[6] << p[7] << std::endl;
      pcount++;
    }
    index++;
  }
  return 0;
}
