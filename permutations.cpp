#include <iostream>
#include <vector>
#include <algorithm>

enum OrbType {
    QUAS,
    WEX,
    EXHORT
};

// Function to generate all unique permutations of orbs
void generateOrbPermutations(std::vector<std::vector<OrbType>>& permutations, std::vector<OrbType>& currentPermutation, int orbsLeft) {
    if (orbsLeft == 0) {
        permutations.push_back(currentPermutation);
        return;
    }

    for (int i = 0; i < 3; ++i) {
        currentPermutation.push_back(static_cast<OrbType>(i));
        generateOrbPermutations(permutations, currentPermutation, orbsLeft - 1);
        currentPermutation.pop_back();
    }
}

// Function to check if two combinations share the same number of orbs
bool shareSameOrbCount(const std::vector<OrbType>& combo1, const std::vector<OrbType>& combo2) {
    int quasCount1 = std::count(combo1.begin(), combo1.end(), QUAS);
    int wexCount1 = std::count(combo1.begin(), combo1.end(), WEX);
    int exhortCount1 = std::count(combo1.begin(), combo1.end(), EXHORT);

    int quasCount2 = std::count(combo2.begin(), combo2.end(), QUAS);
    int wexCount2 = std::count(combo2.begin(), combo2.end(), WEX);
    int exhortCount2 = std::count(combo2.begin(), combo2.end(), EXHORT);

    return (quasCount1 == quasCount2) && (wexCount1 == wexCount2) && (exhortCount1 == exhortCount2);
}

int main() {

    // Initialize vectors
    std::vector<std::vector<OrbType>> permutations;
    std::vector<OrbType> currentPermutation;
    std::vector<std::vector<OrbType>> uniquePermutations;

    // Generate all permutations
    generateOrbPermutations(permutations, currentPermutation, 3);

    // Iterate through permutations
    for (const auto& currentCombo : permutations) {
        bool isUnique = true;

        // Compare with uniquePermutations
        for (const auto& uniqueCombo : uniquePermutations) {
            if (shareSameOrbCount(currentCombo, uniqueCombo)) {
                isUnique = false;
                break;
            }
        }

        // Add to uniquePermutations if not already present
        if (isUnique) {
            uniquePermutations.push_back(currentCombo);
        }
    }
    
    std::string comboString = "";
    // Output unique permutations
    for (const auto& combo : uniquePermutations) {
        for (const auto& orb : combo) {
            switch (orb) {
                case QUAS:
                    std::cout << "quas ";
                    comboString += 'q';
                    break;
                case WEX:
                    std::cout << "wex ";
                    comboString += 'w';
                    break;
                case EXHORT:
                    std::cout << "exhort ";
                    comboString += 'e';
                    break;
            }
        }
        comboString += "rd";
        std::cout << std::endl;
    }

    std::cout << "Full combo: " << comboString << std::endl;
    return 0;
}