#include <iostream>
#include <sstream>

int main() {
    int currPosX = 0;
    int currPosY = 0;
    int currAxis = 1; // 0 = X-axis 1 = Y-axis
    int currAxisDir = 1; // -1 = neg 1 = pos
    std::string endSeq = "END";
    std::string seq;

    std::cin >> seq;


    while (endSeq.compare(seq) != 0) {
        std::cout << seq << " ";
        // If turn Left and current axis is Y
        if (seq[0] == 'L' && currAxis == 1)
            currAxisDir = currAxisDir * -1;
        else if (seq[0] == 'R' && currAxis == 0)
            currAxisDir = currAxisDir * -1;
        currAxis = currAxis ? 0 : 1;

        int dist;
        std::string distStr = "";
        for (int i = 1; i < seq.size() - 1; i++) {
            distStr += seq[i];
        }
        dist = std::atoi(distStr.c_str());
        std::cout << dist << " ";
        // If on y axis
        if (currAxis)
            currPosY = currPosY + (currAxisDir * dist);
        else
            currPosX = currPosX + (currAxisDir * dist);
        std::cin >> seq;
    }

    if (currPosX < 0)
        currPosX = currPosX * -1;
    if (currPosY < 0)
        currPosY = currPosY * -1;
    std::cout << std::endl;
    std::cout << currPosX + currPosY << std::endl;
}
