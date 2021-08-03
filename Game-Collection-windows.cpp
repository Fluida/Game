#include <iostream>
#include <limits>
#include <vector>
#include <array>
#include <ctime>
#include <limits>
#include <fstream>
#include <windows.h>


using namespace std;

//Game 1
std::string highnlow(int guess, int answer) {

    std::string y;
    if(guess < answer) {

        y = "low";
    } else if(guess > answer) {

        y = "high";
    }
    return y;
}

void game1() {

    std::string again;
    int guess;
    int answer = (rand() % 10) + 1;
    int chance = 3;
    cout << "Guess a number from 1-10 and You have 3 chances : ";
    cin >> guess;

    while(chance >= 0) { 

        if(chance == 100) {
        cout << "Guess a number from 1-10 and You have 3 chances : ";
        answer = (rand() % 10) +1;
        chance = 3;
        cin >> guess;
        }

        if(guess == answer) {
            cout << "Congrats!! You're right!!! " << "\nWant to play again? ";
            cin >> again;

            if(again == "Y" || again == "y") {

                chance = 100;
            } else if(again == "N" || again == "n") {

                cout << "Interesting answer you have there, now GET LOST" << endl;
                chance = -100;
            }
        } else if(guess != answer) {
            chance--;
            if(chance > 0) {
            cout << "Nope. you're wrong. Your number is too " << highnlow(guess, answer) << ".\n" << "Chances left : " << chance << endl;
            cout << "Guess a number from 1-10 and You have " << chance << " chances : ";
            cin >> guess;
            } else if(chance == 0) {

                cout << "Unfortunately you lose. The answer is " << answer << ". Now GET LOST\nor play again? ";
            cin >> again;

            if(again == "Y" || again == "y") {

                chance = 100;
            } else if(again == "N" || again == "n") {

                cout << "Interesting answer you have there, now GET LOST";
                chance = -100;
            }
        } else {

            cout << "Excuse me but your number is invalid.";
        }
    }
    }
}

//___________________________________________________________________________________________________
//___________________________________________________________________________________________________
//___________________________________________________________________________________________________

//Game 2
//This below is for printing the previous answer either wrong or right
void guesshistory(vector<int>data) {

    int count = 0;
    char pressanything;

    if(data.size() == 1) {

        cout << "Congratulations!! You don't have any wrong answer!";
    } else {
        cout << "The wrong answer that has been inputed are : ";

        for(int i = 0; i < data.size(); i++) {

            count++;

            if(i == data.size() - 1) {
                count = count - 1;
                break;
            }
            cout << data[i] << "  ";
        }
    }

    int best_score;
    ifstream input("score_for_GameColl.txt");

    input >> best_score;

    ofstream output("score_for_GameColl.txt");

    if(best_score > count) {

        output << count;    
    } else {

        output << best_score;
    }
    output.close();

    ifstream input_after("score_for_GameColl.txt");

    input_after >> best_score;
    
    cout << "\nYour score : " << count << endl << "Best score : " << best_score << endl << "*Note that fewer number means greater score";
    Sleep(3000);
    cout << endl << endl << "Press anything to continue.......";
    cin >> pressanything;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
}

//This below is the main game
void game2() {

    while(true) {
    string yn;
    int guess;
    int count = 0;
    short answer = (rand() % 100) + 1;
    vector<int>guesses;
    char pressanything;

    cout << "Enter a number from 1 to 100 : ";

    while(cin >> guess) {

        guesses.push_back(guess);

        if(guess == answer) {
            cout << "Congrats!! You're right!" << endl << endl << "Press anything to continue.... ";
            cin >> pressanything;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            system("cls");
            break;
        } else if(guess != answer) {

            if(guess > answer) {
                cout << "Your number is too high." << endl << "Enter a number from 1 to 100 : ";
                continue;
            } else if(guess < answer) {
                cout << "Your number is too low." << endl << "Enter a number from 1 to 100 : ";
                continue;
            }
        } 
    }

    guesshistory(guesses);
    cout << endl << "Want to play again? ";
    cin >> yn;
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if(yn == "Y" || yn == "y") {
            system("cls");
            continue;
        } else { 
            system("cls");
            break;
        }
    }
}


//And this below is for display the game and choose to play the game or not
int main() {

    bool tf = true;
    while(tf) {
    srand(time(NULL));
    short playornot;
    string yn;
    cout << "Welcome. Which game you want to play? " << endl << "1. Guessing game with 3 chances" << endl << "2. Normal guessing game" << endl << "0. exit" << endl << endl << "Your selection : ";
    cin >> playornot;
    
        switch(playornot) {

            case 1:
            system("cls");
            game1();
            system("cls");
            break;        

            case 2:
            system("cls");
            game2();
            break;

            case 0:
            tf = false;
            break;
        }
    }
}
