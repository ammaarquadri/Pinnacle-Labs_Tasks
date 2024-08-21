#include <iostream>
#include <iomanip>

using namespace std;

void displayMenu() {
    cout << "\n----------------------------" << endl;
    cout << "       CALCULATOR       " << endl;
    cout << "----------------------------" << endl;
    cout << "Choose an operation:" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Exit" << endl;
    cout << "----------------------------" << endl;
    cout << "Enter your choice: ";
}

void performOperation(int choice) {
    double num1, num2, result;
    
    cout << fixed << setprecision(2);
    
    if (choice >= 1 && choice <= 4) {
        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;
    }

    switch(choice) {
        case 1:
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case 2:
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case 3:
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Error: Division by zero is undefined." << endl;
            }
            break;
        case 5:
            cout << "Exiting calculator..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;
        if (choice != 5) {
            performOperation(choice);
        }
    } while (choice != 5);
    
    return 0;
}
