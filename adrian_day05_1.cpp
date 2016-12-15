#include <iostream>
#include <sstream>
#include <string.h>
#include <openssl/md5.h>

int main() {
  unsigned char digest[MD5_DIGEST_LENGTH];
  int index = 0;
  std::string input, s, p;
  std::cin >> input;
  while (p.size() < 8) {
    std::stringstream ssinput, sspass;
    ssinput << input << index;
    ssinput >> s;
    char chars[s.size()], mdString[33];
    strcpy(chars, s.c_str());
    MD5((unsigned char*)&chars, strlen(chars), (unsigned char*)&digest);
    if (digest[0] == 0 && digest[1] == 0 && digest[2] < 16){
      sspass << p << (digest[2] < 10 ? (char)(digest[2] + '0') : (char)((digest[2] - 10) + 'a'));
      sspass >> p;
      std::cout << p << std::endl;
    }
    index++;
  }
  return 0;
}
