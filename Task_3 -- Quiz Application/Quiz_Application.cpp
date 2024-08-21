#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

struct Question {
    string questionText;
    vector<string> options;
    char correctAnswer;
};

void printDivider() {
    cout << "\n-------------------------------------------------" << endl;
}

void displayWelcomeMessage() {
    printDivider();
    cout << "           Welcome to the Ultimate Quiz Game!           " << endl;
    printDivider();
    cout << "You will be presented with several questions about India and computers. Try to answer them correctly!" << endl;
    cout << "Note: You have a limited time to answer each question." << endl;
    cout << "Let's begin!" << endl;
    printDivider();
}

void displayQuestion(const Question& q, int questionNumber) {
    cout << "\nQuestion " << questionNumber << ": " << q.questionText << endl;
    for (size_t i = 0; i < q.options.size(); ++i) {
        cout << char('A' + i) << ": " << q.options[i] << endl;
    }
}

bool checkTimeLimit(clock_t startTime, double timeLimit) {
    clock_t currentTime = clock();
    double timeTaken = double(currentTime - startTime) / CLOCKS_PER_SEC;
    return timeTaken <= timeLimit;
}

void runQuiz(const vector<Question>& quizQuestions, double timeLimit) {
    int score = 0;
    for (size_t i = 0; i < quizQuestions.size(); ++i) {
        displayQuestion(quizQuestions[i], i + 1);
        
        clock_t startTime = clock();
        char answer;
        cout << "Your answer (A/B/C/D): ";
        cin >> answer;
        answer = toupper(answer);

        if (!checkTimeLimit(startTime, timeLimit)) {
            cout << "Time's up! Moving to the next question." << endl;
        } else if (answer == quizQuestions[i].correctAnswer) {
            cout << "Correct!" << endl;
            score++;
        } else {
            cout << "Wrong! The correct answer was: " << quizQuestions[i].correctAnswer << endl;
        }
        printDivider();
    }

    cout << "Quiz Over! You scored " << score << " out of " << quizQuestions.size() << "!" << endl;
}

int main() {
    vector<Question> quizQuestions = {
        {"What is the capital of India?", {"Delhi", "Mumbai", "Kolkata", "Chennai"}, 'A'},
        {"Who is known as the father of the Indian computer industry?", {"Dr. A.P.J. Abdul Kalam", "N.R. Narayana Murthy", "C. N. R. Rao", "Vikram Sarabhai"}, 'B'},
        {"Which Indian city is known as the Silicon Valley of India?", {"Delhi", "Bangalore", "Hyderabad", "Pune"}, 'B'},
        {"What was the first Indian supercomputer?", {"PARAM 8000", "Cray-1", "IBM Blue Gene", "Eka"}, 'A'},
        {"Which Indian IT company is known for its software services and consulting?", {"TCS", "Infosys", "Wipro", "All of the above"}, 'D'}
    };

    double timeLimit = 15.0; // Time limit for each question in seconds

    displayWelcomeMessage();
    runQuiz(quizQuestions, timeLimit);

    return 0;
}
