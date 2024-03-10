#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Function to get the user's choice
char getUserChoice() {
    char choice;
    cout << "Enter your choice (R for Rock, P for Paper, S for Scissors): ";
    cin >> choice;
    return toupper(choice);  // Convert to uppercase for case-insensitivity
}

// Function to generate the computer's choice
char getComputerChoice() {
    // Generate a random number between 0 and 2
    int randomNum = rand() % 3;

    // Map the random number to R, P, or S
    switch (randomNum) {
        case 0:
            return 'R';
        case 1:
            return 'P';
        case 2:
            return 'S';
        default:
            return ' ';  // This should not happen, but added for completeness
    }
}

// Function to determine the winner
void determineWinner(char userChoice, char computerChoice) {
    cout << "Computer's choice: " << computerChoice << endl;

    if (userChoice == computerChoice) {
        cout << "It's a tie!" << endl;
    } else if ((userChoice == 'R' && computerChoice == 'S') ||
               (userChoice == 'P' && computerChoice == 'R') ||
               (userChoice == 'S' && computerChoice == 'P')) {
        cout << "You win!" << endl;
    } else {
        cout << "Computer wins!" << endl;
    }
}

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    char userChoice = getUserChoice();
    char computerChoice = getComputerChoice();

    determineWinner(userChoice, computerChoice);

    return 0;
}