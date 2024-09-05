#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <random>
#include <cctype>
#include "colormod.h"
using namespace std;

string selectRandomWord() {
    // Initializing wordlist.txt
    vector<string> words;
    ifstream file("wordlist.txt");
    string word;
    while (getline(file, word)) words.push_back(word);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, words.size() - 1);
    string randomWord = words[dis(gen)];
    return randomWord;
} 

/* bool isGuessLengthValid(string guess) {
    if (guess.length() != 5) {
        cout << "Invalid guess. Please enter a 5-letter word." << endl;
        return false;
    } else {
        return true;
    }
} */

/* bool isGuessInDictionary(string guess) {
    ifstream file("wordlist.txt");
    string word;
    while (getline(file, word)) {
        if (guess == word) return true;
    }
    cout << "Invalid guess. Please enter a valid word." << endl;
    return false;
} */

int main() {
    // Initializing variables
    int numberOfGuesses = 0;
    char playAgain;
    string letterBox = "[]";
    string randomWord = selectRandomWord();
    string guessedWord;

    // Terminal box colors
    Color::Modifier gray(Color::BG_DEFAULT);
    Color::Modifier green(Color::FG_GREEN);
    Color::Modifier yellow(Color::FG_LIGHTYELLOW);

    cout << "Welcome to Wordle!" << endl;

    // Game loop
    do {
        cout << "Enter your guess: ";
        cin >> guessedWord;
        numberOfGuesses++;
        
        // Iterates through the letters and checks if any letters in the guessed word match
        for (int i = 0; i < 5; i++) {
            if (randomWord[i] == guessedWord[i]) {
                cout << green << letterBox;
            }
        }

        // Win sequence
        cout << "You have successfully guessed the word!" << endl;
        cout << "Do you want to play again? (y/n)";
        cin >> playAgain;
    } while (numberOfGuesses != 5 && playAgain == 'y' || 'Y'); 

    return 0;
}   