#include <iostream>
#include <vector>
#include <map>
using namespace std;

void countFrequencyBruteForce(const vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        // On vérifie si on a déjà compté ce nombre
        bool alreadyCounted = false;
        for (int j = 0; j < i; j++) {
            if (numbers[i] == numbers[j]) {
                alreadyCounted = true;
                break;
            }
        }
        if (alreadyCounted) continue;

        // On compte combien de fois le nombre apparaît
        int count = 0;
        for (int num : numbers) {
            if (num == numbers[i]) count++;
        }
        cout << numbers[i] << " : " << count << " times" << endl;
    }
}

map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map<int, int> frequencyMap;
    for (int num : numbers) {
        frequencyMap[num]++;
    }
    return frequencyMap;
}

int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};

    // Test countFrequencyBruteForce
    cout << "Frequency (Brute Force): " << endl;
    countFrequencyBruteForce(numbers);

    // Test countFrequencyOptimal
    cout << "\nFrequency (Optimal): " << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << " : " << entry.second << " times" << endl;
    }

    return 0;
}