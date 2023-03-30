#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(NULL)); // initialize random seed
    
    int number = rand() % 100 + 1; // generate random number between 1 and 100
    
    int guess; // initialize variable for user's guess
    
    int attempts = 0; // initialize variable for number of attempts
    
    cout << "Welcome to the number guessing game!" << endl;
    
    while (guess != number) {
        cout << "Enter your guess (1-100): ";
        cin >> guess;
        
        if (guess < number) {
            cout << "Your guess is too low. Try again." << endl;
            attempts++;
        }
        else if (guess > number) {
            cout << "Your guess is too high. Try again." << endl;
            attempts++;
        }
        else {
            cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }
    }
    
    return 0;
}
