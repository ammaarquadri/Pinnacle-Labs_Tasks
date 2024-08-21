#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Calendar {
private:
    int year, month;
    map<int, vector<string>> events;

    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int getDaysInMonth(int month, int year) {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
            case 4: case 6: case 9: case 11: return 30;
            case 2: return isLeapYear(year) ? 29 : 28;
            default: return 0;
        }
    }

    int getStartDayOfMonth(int month, int year) {
        int day = 1;
        int y = year - (14 - month) / 12;
        int m = month + 12 * ((14 - month) / 12) - 2;
        return (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12) % 7;
    }

    void printMonthHeader() {
        cout << "\n    " << getMonthName(month) << " " << year << endl;
        cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;
    }

    string getMonthName(int month) {
        const string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
        return months[month - 1];
    }

public:
    Calendar(int m, int y) : month(m), year(y) {}

    void displayCalendar() {
        printMonthHeader();
        int startDay = getStartDayOfMonth(month, year);
        int daysInMonth = getDaysInMonth(month, year);

        int dayCounter = 1;
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 7; ++j) {
                if (i == 0 && j < startDay) {
                    cout << "     ";
                } else if (dayCounter <= daysInMonth) {
                    cout << setw(5) << dayCounter;
                    dayCounter++;
                } else {
                    cout << "     ";
                }
            }
            cout << endl;
        }
    }

    void addEvent(int day, const string& event) {
        if (day > 0 && day <= getDaysInMonth(month, year)) {
            events[day].push_back(event);
            cout << "Event added successfully on " << day << " " << getMonthName(month) << ", " << year << endl;
        } else {
            cout << "Invalid day!" << endl;
        }
    }

    void viewEvents(int day) {
        if (events.find(day) != events.end()) {
            cout << "\nEvents on " << day << " " << getMonthName(month) << ", " << year << ":\n";
            for (const auto& event : events[day]) {
                cout << "- " << event << endl;
            }
        } else {
            cout << "No events on this day." << endl;
        }
    }
};

void displayMenu() {
    cout << "\n--- Calendar Menu ---" << endl;
    cout << "1. Display Calendar" << endl;
    cout << "2. Add Event" << endl;
    cout << "3. View Events" << endl;
    cout << "4. Exit" << endl;
    cout << "Choose an option (1-4): ";
}

int main() {
    int month, year;
    cout << "Enter month (1-12): ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    Calendar calendar(month, year);
    int choice, day;
    string event;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                calendar.displayCalendar();
                break;
            case 2:
                cout << "Enter day of the month: ";
                cin >> day;
                cout << "Enter event description: ";
                cin.ignore();
                getline(cin, event);
                calendar.addEvent(day, event);
                break;
            case 3:
                cout << "Enter day of the month: ";
                cin >> day;
                calendar.viewEvents(day);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }
}
