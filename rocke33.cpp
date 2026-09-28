/**
 * ============================================================================
 * Project: Rock, Paper, Scissors — Interactive Console Game (rocke33.cpp)
 * Author:  Sohrab Soomro (FAST NUCES Peshawar)
 * Course:  Programming Fundamentals (PF)
 *
 * Description:
 *   A console-based Rock-Paper-Scissors game written in C++. The player
 *   competes across multiple rounds against a randomized computer opponent
 *   while their cumulative session score is tracked.
 *
 * Key Concepts Used:
 *   - Modular function decomposition (inputuser, winner, displayrules)
 *   - Switch-case control structures & input validation retry loops
 *   - Pseudo-random number generation via rand() % 3 + 1
 * ============================================================================
 */

#include <iostream>
#include <cstring>   // String handling utilities (getline / string comparisons)
#include <cstdlib>   // Standard library for rand() computer move generation
#include <conio.h>   // Console I/O utilities (system cls support on Windows)

using namespace std;

// Function prototypes for modular game flow
int inputuser();
int winner(string userinput, string cinput);
void displayrules();

int main()
{
    cout << "** Rock, Scissor, Paper Game **" << endl << endl;

    string name;
    cout << "Enter your name: ";
    // Note: getline(cin, name) can also be used if spaces in names are needed
    cin >> name;
    cout << endl;

    char input;
    int score = 0;

    // Main game loop: continues until the player enters 'n' or 'N'
    do
    {
        // system("cls"); // Optional: clears the console screen between rounds
        displayrules();
        score = score + inputuser();

        cout << endl << endl << "Would you like to play again? Press any key (or 'n'/'N' to exit): ";
        cin >> input;
        cout << endl;
    } while (input != 'n' && input != 'N');

    cout << name << ": your final score is " << score << endl;
    cout << "*********" << endl;
    return 0;
}

/**
 * Prompts the player for their move (1=Rock, 2=Paper, 3=Scissor),
 * generates the computer's random move, and returns 1 if the player wins
 * the round (or 0 for a loss/draw).
 */
int inputuser()
{
    int input;
    string userinput;

    cout << "1. Rock" << endl;
    cout << "2. Paper" << endl;
    cout << "3. Scissor" << endl;

label1:
    cout << "Enter your input (1-3): ";
    cin >> input;
    cout << endl;

    switch (input)
    {
    case 1:
        userinput = "Rock";
        break;
    case 2:
        userinput = "Paper";
        break;
    case 3:
        userinput = "Scissor";
        break;
    default:
        cout << "Invalid option! Please choose between 1 and 3." << endl;
        goto label1;
    }

    // Generate random computer move in the range [1, 3]
    int computerinput = rand() % 3 + 1;
    string cinput;

    switch (computerinput)
    {
    case 1:
        cinput = "Rock";
        break;
    case 2:
        cinput = "Paper";
        break;
    case 3:
        cinput = "Scissor";
        break;
    }

    cout << "Computer chose: " << cinput << endl;

    // Evaluate round outcome: 1 = Player Wins, 0 = Computer Wins, -1 = Draw
    int output = winner(userinput, cinput);
    switch (output)
    {
    case 1:
        cout << "You win this round!";
        return 1;
    case 0:
        cout << "Computer wins this round!";
        return 0;
    case -1:
        cout << "Match draw!";
        return 0;
    }
    return 0;
}

/**
 * Compares the player's move and computer's move according to classic rules:
 *   - Rock crushes Scissor
 *   - Scissor cuts Paper
 *   - Paper covers Rock
 * Returns: 1 (user win), 0 (computer win), -1 (draw)
 */
int winner(string userinput, string cinput)
{
    if (cinput == "Rock")
    {
        if (userinput == "Rock") return -1;
        else if (userinput == "Scissor") return 0;
        else if (userinput == "Paper") return 1;
    }
    if (cinput == "Scissor")
    {
        if (userinput == "Rock") return 1;
        else if (userinput == "Scissor") return -1;
        else if (userinput == "Paper") return 0;
    }
    if (cinput == "Paper")
    {
        if (userinput == "Rock") return 0;
        else if (userinput == "Scissor") return 1;
        else if (userinput == "Paper") return -1;
    }
    return -1;
}

/**
 * Displays a quick summary of the game rules before each round.
 */
void displayrules()
{
    cout << endl << endl;
    cout << "	Game Rules:" << endl;
    cout << "	 = Rock crushes the Scissor" << endl;
    cout << "	 = Scissor cuts the Paper" << endl;
    cout << "	 = Paper covers the Rock" << endl;
}
