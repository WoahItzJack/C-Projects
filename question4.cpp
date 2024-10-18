#include <iostream>
#include <string>
#include <limits>

void createAccount(std::string &name, int &accountNumber, double &balance) {
    std::cout << "Enter your name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // To ignore leftover newline character
    std::getline(std::cin, name);

    std::cout << "Enter account number: ";
    while(!(std::cin >> accountNumber)) {
        std::cout << "Invalid input. Please enter a valid account number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    do {
        std::cout << "Enter initial deposit (must be greater than 0): ";
        std::cin >> balance;
        if (balance <= 0) {
            std::cout << "Initial deposit must be greater than 0. Please try again.\n";
        }
    } while (balance <= 0);
}

void depositMoney(double &balance) {
    double deposit;
    do {
        std::cout << "Enter deposit amount (must be greater than 0): ";
        std::cin >> deposit;
        if (deposit <= 0) {
            std::cout << "Deposit amount must be greater than 0. Please try again.\n";
        }
    } while (deposit <= 0);
    balance += deposit;
}

void withdrawMoney(double &balance) {
    double withdrawal;
    do {
        std::cout << "Enter withdrawal amount (must be greater than 0 and not exceed current balance): ";
        std::cin >> withdrawal;
        if (withdrawal <= 0) {
            std::cout << "Withdrawal amount must be greater than 0. Please try again.\n";
        } else if (withdrawal > balance) {
            std::cout << "Withdrawal amount cannot exceed current balance. Please try again.\n";
        }
    } while (withdrawal <= 0 || withdrawal > balance);
    balance -= withdrawal;
}

void checkBalance(const double &balance) {
    std::cout << "Current balance: R" << balance << '\n';
}

void displayAccountDetails(const std::string &name, const int &accountNumber, const double &balance) {
    std::cout << "Account Holder: " << name << '\n';
    std::cout << "Account Number: " << accountNumber << '\n';
    std::cout << "Current Balance: R" << balance << '\n';
}

void manageStudentScores() {
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
}

int main() {
    std::string name;
    int accountNumber;
    double balance;

    createAccount(name, accountNumber, balance);

    int choice;
    do {
        std::cout << "\nBank Account Management System\n";
        std::cout << "1. Deposit Money\n";
        std::cout << "2. Withdraw Money\n";
        std::cout << "3. Check Balance\n";
        std::cout << "4. Display Account Details\n";
        std::cout << "5. Manage Student Scores\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        while(!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number between 1 and 6: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                depositMoney(balance);
                break;
            case 2:
                withdrawMoney(balance);
                break;
            case 3:
                checkBalance(balance);
                break;
            case 4:
                displayAccountDetails(name, accountNumber, balance);
                break;
            case 5:
                manageStudentScores();
                break;
            case 6:
                std::cout << "Exiting system. Thank you!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}
