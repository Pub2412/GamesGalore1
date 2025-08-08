#include <iostream>
using namespace std;

int main() {
    const int QUESTIONS = 5; // Total number of questions
    string questions[QUESTIONS] = {
        "1. What is the capital of France?\n0. Berlin\n1. Paris\n2. Madrid\n",
        "2. What is 2 + 2?\n0. 3\n1. 4\n2. 5\n",
        "3. What is the color of the sky?\n0. Blue\n1. Green\n2. Red\n",
        "4. What gas do plants absorb?\n0. Oxygen\n1. Nitrogen\n2. Carbon Dioxide\n",
        "5. What is the largest planet in our solar system?\n0. Earth\n1. Jupiter\n2. Mars\n"
    };

    int answers[QUESTIONS] = {1, 1, 0, 2, 1}; // Correct answers for each question
    int userAnswer, score = 0;

    cout << "Welcome to the Quiz Game!\n";

    for (int i = 0; i < QUESTIONS; i++) {
        cout << questions[i];
        cout << "Your answer: ";
        cin >> userAnswer;

        if (userAnswer == answers[i]) {
            score++; // Increment score for a correct answer
            cout << "Correct!\n";
        } else {
            cout << "Wrong! The correct answer was: " << answers[i] << endl;
        }
    }

    cout << "\nYour total score: " << score << " out of " << QUESTIONS << endl;

    return 0;
}
