#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
bool verifyPIN(int enteredPIN, int correctPIN);
void displayMenu();
void checkBalance(double balance);
void deposit(double& balance);
void withdraw(double& balance);
int generateOTP();
bool verifyOTP(int generatedOTP, int enteredOTP);

int main() {
    const int correctPIN = 1234; // Example PIN, in a real-world application, use secure methods
    int enteredPIN;
    double balance = 1000.0; // Example initial balance
    int choice;

    cout << "Welcome to the ATM\n";
    cout << "Please enter your PIN: ";
    cin >> enteredPIN;

    if (!verifyPIN(enteredPIN, correctPIN)) {
        cout << "Incorrect PIN. Exiting...\n";
        return 1;
    }

    int generatedOTP = generateOTP();
    int enteredOTP;
    cout << "An OTP has been sent to your device. Please enter the OTP: ";
    cin >> enteredOTP;

    if (!verifyOTP(generatedOTP, enteredOTP)) {
        cout << "Incorrect OTP. Exiting...\n";
        return 1;
    }

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            checkBalance(balance);
            break;
        case 2:
            deposit(balance);
            break;
        case 3:
            withdraw(balance);
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice != 4);

    return 0;
}

bool verifyPIN(int enteredPIN, int correctPIN) {
    return enteredPIN == correctPIN;
}

void displayMenu() {
    cout << "\nATM Menu:\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit\n";
    cout << "3. Withdraw\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

void checkBalance(double balance) {
    cout << "Your current balance is: $" << balance << "\n";
}

void deposit(double& balance) {
    double amount;
    cout << "Enter the amount to deposit: ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        cout << "Deposited $" << amount << ". New balance is: $" << balance << "\n";
    }
    else {
        cout << "Invalid amount. Transaction cancelled.\n";
    }
}

void withdraw(double& balance) {
    double amount;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        cout << "Withdrew $" << amount << ". New balance is: $" << balance << "\n";
    }
    else if (amount > balance) {
        cout << "Insufficient funds. Transaction cancelled.\n";
    }
    else {
        cout << "Invalid amount. Transaction cancelled.\n";
    }
}

int generateOTP() {
    srand(time(0)); // Seed the random number generator
    int otp = rand() % 9000 + 1000; // Generate a 4-digit OTP
    cout << "Generated OTP: " << otp << " (for demonstration purposes)\n"; // In a real application, send this to the user securely
    return otp;
}

bool verifyOTP(int generatedOTP, int enteredOTP) {
    return generatedOTP == enteredOTP;
}