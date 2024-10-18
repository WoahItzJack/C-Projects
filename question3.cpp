#include <iostream>
#include <limits>

int main() {
    const int num_students = 5;
    int scores[num_students];
    int sum = 0;
    int highest = std::numeric_limits<int>::min();
    int lowest = std::numeric_limits<int>::max();

    // Input scores and calculate sum, highest, and lowest score
    for (int i = 0; i < num_students; ++i) {
        std::cout << "Enter score for student " << i + 1 << ": ";
        std::cin >> scores[i];
        sum += scores[i];
        if (scores[i] > highest) {
            highest = scores[i];
        }
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }

    // Calculate average score
    double average = static_cast<double>(sum) / num_students;

    // Display the scores in the order they were entered
    std::cout << "\nScores entered:\n";
    for (int i = 0; i < num_students; ++i) {
        std::cout << "Student " << i + 1 << ": " << scores[i] << "\n";
    }

    // Display average, highest, and lowest scores
    std::cout << "\nAverage score: " << average << "\n";
    std::cout << "Highest score: " << highest << "\n";
    std::cout << "Lowest score: " << lowest << "\n";

    return 0;
}
