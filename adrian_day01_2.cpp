#include <iostream>
#include <vector>
#include <sstream>

struct line {
    int start;
    int end;
    int plevel;
};

int main() {
    std::vector<line> xlist;
    std::vector<line> ylist;
    int posX = 0;
    int posY = 0;
    int prevX;
    int prevY;
    int axis = 1; // 0 = X-axis 1 = Y-axis
    int axisDir = 1; // -1 = neg 1 = pos
    std::string endSeq = "END";
    std::string seq;

    std::cin >> seq;


    while (endSeq.compare(seq) != 0) {
        std::cout << seq << " ";
        // If turn Left and current axis is Y
        if (seq[0] == 'L' && axis == 1)
            axisDir = axisDir * -1;
        else if (seq[0] == 'R' && axis == 0)
            axisDir = axisDir * -1;
        axis = axis ? 0 : 1;
        // Parse distance
        int dist;
        std::string distStr = "";
        for (int i = 1; i < seq.size() - 1; i++) {
            distStr += seq[i];
        }
        dist = std::atoi(distStr.c_str());
        std::cout << dist << " ";


        // Create new line
        line nline;
        int prevPos;
        // If on y axis
        if (axis) {
            std::cout << "from ( " << posX << " , " << posY << " ) to ( " << posX;
            prevPos = posY;
            posY = posY + (axisDir * dist);
            nline.start = posY < prevPos ? posY : prevPos;
            std::cout << " , " << posY << " )" << std::endl;
            nline.end = posY > prevPos ? posY : prevPos;
            nline.plevel = posX;

            // Check if lines crossed
            for (int i = 0; i < xlist.size(); i++) {
                if (nline.start < xlist[i].plevel && xlist[i].plevel < nline.end &&
                    xlist[i].start < nline.plevel && nline.plevel < xlist[i].end) {
                        std::cout << "X: " << nline.plevel << " Y: " << xlist[i].plevel << std::endl;
                        return 0;
                }
            }
            std::cout << "adding to y list: ( " << nline.start << " , " << nline.end << " ) " << nline.plevel << std::endl;
            ylist.push_back(nline);
        }
        else {
            std::cout << "from ( " << posX << " , " << posY << " ) to ( ";
            prevPos = posX;
            posX = posX + (axisDir * dist);
            nline.start = posX < prevPos ? posX : prevPos;
            std::cout << posX << " , " << posY << " )" << std::endl;
            nline.end = posX > prevPos ? posX : prevPos;
            nline.plevel = posY;

            // Check if lines crossed
            for (int i = 0; i < ylist.size(); i++) {
                if (nline.start < ylist[i].plevel && ylist[i].plevel < nline.end &&
                    ylist[i].start < nline.plevel && nline.plevel < ylist[i].end) {
                        std::cout << "X: " << ylist[i].plevel << " Y: " << nline.plevel << std::endl;
                        return 0;
                }
            }
            std::cout << "adding to x list: ( " << nline.start << " , " << nline.end << " ) " << nline.plevel << std::endl;
            xlist.push_back(nline);
        }

        std::cin >> seq;
    }

    // if (posX < 0)
    //     posX = posX * -1;
    // if (posY < 0)
    //     posY = posY * -1;
    // std::cout << std::endl;
    // std::cout << posX + posY << std::endl;

    return 0;
}
