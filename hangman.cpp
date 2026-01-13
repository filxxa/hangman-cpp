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
    string education[] = {"technology", "student", "engineering", "university", "programming"};
    string animals[] = {"rhinoceros", "vulture", "whale", "peacock", "ostrich"};
    string flowers[] = {"hibiscus", "jasmine", "daffodil", "dandelion", "orchid"};
    int educationCount = 5;
    int animalsCount = 5;
    int flowersCount = 5;
    int theme;
    cout<<"Choose a theme: "<<endl;
    cout<<"1: Education"<<endl;
    cout<<"2: Animals"<<endl;
    cout<<"3: Flowers"<<endl;
    cin>>theme;
    srand(time(0));
    string word;
    switch (theme) {
        case 1: 
            word = education[rand() % educationCount];
            break;
        case 2: 
            word = animals[rand() % animalsCount];
             break;
        case 3: 
            word = flowers[rand() % flowersCount];
    }
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