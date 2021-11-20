//coded by Collin Morrison starting at 11:40AM and ending at 2:30PM on 11/20/2021

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void CheckGuess (string currentWord, char userGuess){
    string tempWord = currentWord;
    int totalNumGuesses = 0;
    int numCorrectGuesses = 0;
    int numIncorrectGuesses = 0;
    bool guessCorrect = false;
    vector<char> incorrectGuesses(0);
    for (int i = 0; i < currentWord.size(); ++i){
        currentWord.at(i) = '_';
    }

    do {
        for (int i = 0; i < currentWord.size(); ++i) {
            if (userGuess == tempWord.at(i)) {
                currentWord.at(i) = tempWord.at(i);
                guessCorrect = true;
                ++numCorrectGuesses;
                ++totalNumGuesses;
            }
        }
        if (!guessCorrect) {
            ++numIncorrectGuesses;
            ++totalNumGuesses;
        }
        cout << currentWord << endl << endl;
        if (guessCorrect && numCorrectGuesses != currentWord.size()) {
            cout << "Good guess! " << endl;
            cout << endl << "Number of correct guesses: " << numCorrectGuesses << endl;
            cout << "Number of incorrect guesses: " << numIncorrectGuesses << endl;
            cout << "Total number of guesses: " << totalNumGuesses << endl;
            cout << endl << "Make another guess: " << endl;
            cin >> userGuess;
            cout << endl;
        } else if (!guessCorrect){
            cout << endl << userGuess << " was not in the word." << endl;
            incorrectGuesses.push_back(userGuess);
            cout << endl << "Number of correct guesses: " << numCorrectGuesses << endl;
            cout << "Number of incorrect guesses: " << numIncorrectGuesses << endl;
            cout << "Total number of guesses: " << totalNumGuesses << endl;
            cout << endl << "Your incorrect guesses so far: " << endl;
            for (int i = 0; i < incorrectGuesses.size(); ++i) {
                cout << incorrectGuesses.at(i);
            }
                cout << endl << "Make another guess: " << endl;
                cin >> userGuess;
                cout << endl;
        }
        guessCorrect = false;
    } while (numCorrectGuesses < currentWord.size());
    cout << "Congratulations, you correctly guessed the word!" << endl;
    cout << "It took you " << totalNumGuesses << " guesses to correctly guess the word." << endl << endl;

}


int main() {
    //declare / initialize variables
    srand(time(0));
    vector<string> listOfWords(10);
    listOfWords.at(0) = "chocolate";
    listOfWords.at(1) = "melon";
    listOfWords.at(2) = "run";
    listOfWords.at(3) = "swim";
    listOfWords.at(4) = "elephant";
    listOfWords.at(5) = "rivers";
    listOfWords.at(6) = "canada";
    listOfWords.at(7) = "rubber";
    listOfWords.at(8) = "backpack";
    listOfWords.at(9) = "homework";
    string currentWord = " ";
    char userGuess = ' ';
    string repeatGame = " ";

    /* TEST VECTOR
    for (int i = 0; i < listOfWords.size(); ++i){
        cout << listOfWords.at(i) << endl;
    } */

    //welcome to the game
    cout << endl << "Welcome to Hangman!" << endl;
    cout << "A word will be chosen at random, and you should try to guess the word one character at a time." << endl;
    cout << "To begin the game, type \"yes\" and press enter." << endl << endl;
    cin >> repeatGame;

    while (repeatGame == "yes") {
        //random word selected and declared, guess made
        currentWord = listOfWords.at(rand() % 10);
        cout << "The word has " << currentWord.size() << " letters." << endl;
        cout << "Make your first guess. To make a guess, type any letter and press enter." << endl;
        cin >> userGuess;
        cout << endl;


    //check guess

       CheckGuess(currentWord, userGuess);

       cout << "Would you like to play again?" << endl << endl;
       cout << "Type \"yes\" and press enter if you would like to play again." << endl;
       cout << "If you would like to end the game, type any character and press enter." << endl;
       cin >> repeatGame;
   }
    cout << "Thank you for playing!" << endl;



    return 0;
}
