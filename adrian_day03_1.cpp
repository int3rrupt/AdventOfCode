#include <iostream>

int main() {
    int x, y, z, count = 0;
    std::cin >> x >> y >> z;
    while (x != -11 && y != -11 && x != -11) {
        if (((x + y) > z) && ((x + z) > y) && ((y + z) > x))
            count++;
        std::cin >> x >> y >> z;
    }
    std::cout << count << std::endl;
    return 0;
}
