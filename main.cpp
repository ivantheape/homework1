#include <iostream>
#include <vector>
#include <algorithm>

// Function to find indexes where maximum damage was inflicted
std::vector<int> maxDamageIndexes(const std::vector<int>& damage) {
    int maxDamage = *std::max_element(damage.begin(), damage.end());
    std::vector<int> indexes;
    for (int i = 0; i < damage.size(); ++i) {
        if (damage[i] == maxDamage) {
            indexes.push_back(i);
        }
    }
    return indexes;
}

// Function to find indexes where minimum damage was inflicted
std::vector<int> minDamageIndexes(const std::vector<int>& damage) {
    int minDamage = *std::min_element(damage.begin(), damage.end());
    std::vector<int> indexes;
    for (int i = 0; i < damage.size(); ++i) {
        if (damage[i] == minDamage) {
            indexes.push_back(i);
        }
    }
    return indexes;
}

// Function to find indexes where healing was received
std::vector<int> healingIndexes(const std::vector<int>& damage) {
    std::vector<int> indexes;
    for (int i = 0; i < damage.size(); ++i) {
        if (damage[i] < 0) { // Negative values represent healing
            indexes.push_back(i);
        }
    }
    return indexes;
}

// Function to calculate total damage or healing
int totalDamageOrHealing(const std::vector<int>& damage, bool isDamage) {
    int total = 0;
    for (int value : damage) {
        if (isDamage && value > 0) { // Sum damage if 'isDamage' is true
            total += value;
        }
        else if (!isDamage && value < 0) { // Sum healing if 'isDamage' is false
            total += value;
        }
    }
    return total;
}

// Function to check if there's anyone who didn't do anything
bool hasZeroDamage(const std::vector<int>& damage) {
    for (int value : damage) {
        if (value == 0) {
            return true;
        }
    }
    return false;
}


int main() {
    std::vector<int> damageValues; // Store damage or healing values
    int inputValue; // Temporary variable to store user input

    std::cout << "Enter numbers representing damage (positive) or healing (negative).\n";
    std::cout << "Enter 0 to finish input.\n";

    // Loop to read user input
    while (true) {
        std::cout << "Enter a number: ";
        std::cin >> inputValue;
        if (inputValue == 0) { // Check for input termination
            break;
        }
        damageValues.push_back(inputValue); // Add the entered number to the vector
    }

    // Output collected data
    std::cout << "You entered the following damage/healing values:\n";
    for (int damage : damageValues) {
        std::cout << damage << "\n";
    }

    return 0;
}
