#include <iostream>

int main() {
    int x1, x2, x3, y1, y2, y3, z1, z2, z3, count = 0;
    std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;
    while (x1 != -11 && y1 != -11 && x1 != -11) {
        if (((x1 + x2) > x3) && ((x1 + x3) > x2) && ((x2 + x3) > x1))
            count++;
        if (((y1 + y2) > y3) && ((y1 + y3) > y2) && ((y2 + y3) > y1))
            count++;
        if (((z1 + z2) > z3) && ((z1 + z3) > z2) && ((z2 + z3) > z1))
            count++;
        std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;
    }
    std::cout << count << std::endl;
    return 0;
}
