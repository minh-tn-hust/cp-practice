#include <iostream>
#include <vector>
#include <sstream>
#include <unordered_map>

struct CubeCount {
    int red = 0;
    int green = 0;
    int blue = 0;
};

bool isPossibleGame(const CubeCount& target, const CubeCount& revealed) {
    return target.red >= revealed.red && target.green >= revealed.green && target.blue >= revealed.blue;
}

int main() {
    int possibleGamesSum = 0;
    CubeCount targetCount{12, 13, 14};

    std::string input;
    while (std::getline(std::cin, input)) {
        std::istringstream iss(input);

        // Read game ID
        int gameId;
        char colon;
        iss >> std::skipws >> std::noskipws >> gameId >> colon;

        // Read and process revealed cubes
        CubeCount revealedCount;
        std::string subset;
        while (iss >> subset) {
            char color;
            int count;
            std::istringstream subsetIss(subset);
            subsetIss >> count >> color;

            switch (color) {
                case 'r':
                    revealedCount.red += count;
                    break;
                case 'g':
                    revealedCount.green += count;
                    break;
                case 'b':
                    revealedCount.blue += count;
                    break;
            }
        }

        // Check if the game is possible
        if (isPossibleGame(targetCount, revealedCount)) {
            possibleGamesSum += gameId;
        }
    }

    std::cout << possibleGamesSum << std::endl;

    return 0;
}
