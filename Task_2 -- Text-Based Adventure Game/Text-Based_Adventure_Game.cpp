#include <iostream>
#include <string>

using namespace std;

void startAdventure();
void encounterDragon();
void encounterWizard();
void encounterTreasure();
void gameOver();
void victory();

void printDivider() {
    cout << "\n-------------------------------------------------" << endl;
}

int main() {
    startAdventure();
    return 0;
}

void startAdventure() {
    string choice;

    printDivider();
    cout << "       Welcome to the Enchanted Forest Adventure!       " << endl;
    printDivider();
    cout << "You find yourself standing at the edge of a dark forest." << endl;
    cout << "Do you want to enter the forest? (yes/no): ";
    cin >> choice;

    if (choice == "yes") {
        printDivider();
        cout << "You step into the forest. The trees are thick and the path is unclear." << endl;
        cout << "Suddenly, you hear a noise. Do you want to investigate or continue walking? (investigate/walk): ";
        cin >> choice;

        if (choice == "investigate") {
            printDivider();
            cout << "You follow the sound and come across a mysterious figure." << endl;
            cout << "Do you want to approach the figure or hide? (approach/hide): ";
            cin >> choice;

            if (choice == "approach") {
                encounterWizard();
            } else {
                printDivider();
                cout << "You hide behind a tree. After a while, the noise stops, and you decide to leave the forest." << endl;
                gameOver();
            }

        } else {
            printDivider();
            cout << "You walk deeper into the forest and eventually find a fork in the path." << endl;
            cout << "Do you want to take the left path or the right path? (left/right): ";
            cin >> choice;

            if (choice == "left") {
                encounterDragon();
            } else {
                encounterTreasure();
            }
        }

    } else {
        printDivider();
        cout << "You decide not to enter the forest. Perhaps another time." << endl;
        gameOver();
    }
}

void encounterDragon() {
    string choice;

    printDivider();
    cout << "You find yourself face-to-face with a fearsome dragon!" << endl;
    cout << "Do you want to fight the dragon or try to escape? (fight/escape): ";
    cin >> choice;

    if (choice == "fight") {
        printDivider();
        cout << "You bravely fight the dragon, but it's too powerful." << endl;
        cout << "Unfortunately, you are defeated." << endl;
        gameOver();
    } else {
        printDivider();
        cout << "You manage to escape the dragon and find yourself back at the forest's edge." << endl;
        cout << "You can either try the forest again or leave. (try/leave): ";
        cin >> choice;

        if (choice == "try") {
            startAdventure();
        } else {
            gameOver();
        }
    }
}

void encounterWizard() {
    string choice;

    printDivider();
    cout << "The mysterious figure is a wise old wizard." << endl;
    cout << "The wizard offers you a choice: a magical potion or a map." << endl;
    cout << "Do you want to take the potion or the map? (potion/map): ";
    cin >> choice;

    if (choice == "potion") {
        printDivider();
        cout << "You drink the potion and feel a surge of power. You are granted magical abilities." << endl;
        victory();
    } else {
        printDivider();
        cout << "You take the map and follow it to a hidden treasure chest." << endl;
        cout << "You open the chest and find a large amount of gold!" << endl;
        victory();
    }
}

void encounterTreasure() {
    printDivider();
    cout << "You follow the path and discover a hidden treasure chest!" << endl;
    cout << "You open it and find it filled with gold and precious gems." << endl;
    victory();
}

void gameOver() {
    printDivider();
    cout << "                   GAME OVER                    " << endl;
    printDivider();
    cout << "Thank you for playing the Enchanted Forest Adventure!" << endl;
}

void victory() {
    printDivider();
    cout << "                 CONGRATULATIONS!                 " << endl;
    printDivider();
    cout << "You've achieved victory in the Enchanted Forest Adventure!" << endl;
    cout << "Thank you for playing!" << endl;
}
