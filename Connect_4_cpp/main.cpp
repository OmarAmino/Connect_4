// Title: Connect 4 game
// Author: Omar Elgammal
// Supervised by: Dr. Mohamed El-Ramly Structured programming class - FCAI
// Last modification: 22 - Mar - 2022

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// This game version is resizable
// You can change (col, row) values to set the board size
const int col = 7;
const int row = 6;

int turn = 1;
char player_symbol;
char board[row][col];
int p;
string player;

// Function to assign an empty board

void generate_board() {
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function that displays board

void print_board() {
    cout << endl;
    for (int y = 1; y < col+1; y++) {

        cout << " " << y;
    }
    cout << endl;
    for (int x = 0; x < row; x++) {
        for (int y = 0; y < col; y++) {
            cout << "|";
            cout << board[x][y];
            if (y == col - 1) {
                cout << "|";
            }
        }
        cout << endl;
    }
    for (int i = 0; i < col * 2; i++) {
        cout << "-";
    }
}

// Function that determines the turn of which player and takes input from player

void play() {


    if (turn % 2 == 1) {
        player = "Player X your turn:  ";
        player_symbol = 'X';
    }
    else {
        player = "Player O your turn:  ";
        player_symbol = 'O';
    }
    turn++;
    string s;
    cout << endl << player;
    cin >> s;
    int x = 1;
    for (int i = 1;i < col + 1; i++){
        if (s == to_string(i)){
            x = 0;
            break;
        }
    }
    if (x){
        cout<<"Invalid input. Please choose a column from 1 to "<< col;
        turn--;
        play();
    }
    else{
        stringstream geek(s);
        geek >> p;
    }

}

// Function that stores the input in the board

void board_update() {
    int player_input = p - 1;

    for (int i = row-1; i >= 0; i--) {
        if (board[i][player_input] == ' ') {
            board[i][player_input] = player_symbol;
            break;
        }
        else if (board[0][player_input] != ' ') {
            cout << "Column is full" << endl;
            turn--;
            break;
        }
    }
}

// Function that checks if the player wins

bool check_winner() {

    // checking horizontal
    for (int x = 0; x < row; x++)
        for (int y = 0; y < col - 3; y++)
            if (board[x][y] == player_symbol && board[x][y + 1] == player_symbol && board[x][y + 2] == player_symbol &&
                board[x][y + 3] == player_symbol)
                return true;

    // checking vertically
    for (int y = 0; y < row; y++) {
        for (int x = 0; x < row - 3; x++) {
            if (board[x][y] == player_symbol && board[x + 1][y] == player_symbol && board[x + 2][y] == player_symbol &&
                board[x + 3][y] == player_symbol)
                return true;
        }
    }
    // checking \ diagonal
    for (int x = 0; x < row - 3; x++) {
        for (int y = 3; y < col; y++) {
            if (board[x][y] == player_symbol && board[x + 1][y - 1] == player_symbol && \
                        board[x + 2][y - 2] == player_symbol && board[x + 3][y - 3] == player_symbol)
                return true;
        }
    }

    // checking / diagonal
    for (int x = 0; x < row - 3; x++) {
        for (int y = 0; y < col - 3; ++y) {
            if (board[x][y] == player_symbol && board[x + 1][y + 1] == player_symbol && \
                        board[x + 2][y + 2] == player_symbol && board[x + 3][y + 3] == player_symbol)
                return true;

        }
    }


    return false;
}

int main() {
    generate_board();
    while (true) {
        print_board();
        play();
        board_update();
        if (check_winner()) {
            print_board();
            cout << endl << "Player " << player_symbol << " is the winner" << endl;
            break;
        }
        if (turn == (col * row + 1)) {
            print_board();
            cout << endl << "The game is draw" << endl;
            break;
        }
    }


    return 0;
}
