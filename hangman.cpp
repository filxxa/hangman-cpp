#include <iostream>
#include<string>
#include<conio.h>
#include<ctime>
#include<cstdlib>
using namespace std;
int main() {
    cout<<"===HANGMAN==="<<endl;
    cout<<"Press any key to start"<<endl;
    getch();
    cout<<"Game start"<<endl;
    srand(time(0));
    string words[] = {"technology", "student", "education", "university", "programming"};
    int wordCount = 5;
    string word = words[rand() % wordCount];
    string guessed(word.length(), '_');
    int attempts = 7;
    char guess;
    cout<<"Guess the word: " << guessed << endl;
    while (attempts > 0 && guessed != word) {
        cout << "Enter a letter: ";
        cin >> guess;
        bool correct = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                correct = true;
            }
        }
        if (correct) {
            cout<<"Correct!" << endl;
        } else {
            attempts--;
            cout << "Wrong guess! Attempts left: " << attempts << endl;
        }
        cout << "Current word: " << guessed << endl;
    }
    return 0;
}