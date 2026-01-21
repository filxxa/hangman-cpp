#include <iostream>
#include<string>
#include<conio.h>
#include<ctime>
#include<cstdlib>
#include<windows.h>
using namespace std;
//text color 
void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//hangman figure
void displayhangman(int attempts){
    setColor(12);
	cout<<"\n";
	switch(attempts){
		case 7:
			cout<<"        +---+\n"
			   	"	    |\n"
				"  	    |\n"
				"	    |\n"
				"	   ===\n";
			break;
		case 6:
			cout<<"	+---+\n"
			   	"	O   |\n"
				"  	    |\n"
				"	    |\n"
				"	   ===\n";
			break;
		case 5:
			cout<<"	+---+\n"
			   	"	O   |\n"
				"  	|   |\n"
				"	    |\n"
				"	   ===\n";
			break;
		case 4:
			cout<<"	+---+\n"
			   	"	O   |\n"
				"       /|   |\n"
				"	    |\n"
				"	   ===\n";
			break;
		case 3:
			cout<<"	+---+\n"
			   	"	O   |\n"
				"       /|\\  |\n"
				"	    |\n"
				"	   ===\n";
			break;
		case 2:
			cout<<"	+---+\n"
			   	"	O   |\n"
				"       /|\\  |\n"
				"       /    |\n"
				"	   ===\n";
			break;
		case 1:
			cout<<"	+---+\n"
			   	"	O   |\n"
				"       /|\\  |\n"
				"       / \\  |\n"
				"	   ===\n";
			break;
	}
}
int main() {
    setColor(13);
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
    setColor(1);
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
        displayhangman(attempts);
        setColor(14);
        cout<<"Word: "<<guessed<<endl;
        setColor(10);
        cout<<"Attempts left: "<<attempts<<endl;
        setColor(1);
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
            setColor(10);
            cout<<"Correct!" << endl;
        } else {
            setColor(12);
            attempts--;
            cout << "Wrong guess! Attempts left: " << attempts << endl;
        }
        cout << "Current word: " << guessed << endl;
        if(guessed == word){
            setColor(2);
            cout<<"You won!"<<endl;
        }
        else if (attempts == 0){
            setColor(4);
            cout<<"Game over!"<<endl;
        }
    }
    return 0;
}