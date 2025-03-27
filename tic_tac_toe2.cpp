#include <bits/stdc++.h>
using namespace std;

char brd[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};
char turn = 'X';  
int row, col;
bool draw = false;


bool checkwin() {
    
    for (int i = 0; i < 3; i++) {
        // Check rows
        if (brd[i][0] == brd[i][1] && brd[i][0] == brd[i][2]) return true;
        // Check columns
        if (brd[0][i] == brd[1][i] && brd[0][i] == brd[2][i]) return true;
    }

    // Check diagonals
    if (brd[0][0] == brd[1][1] && brd[0][0] == brd[2][2]) return true;
    if (brd[0][2] == brd[1][1] && brd[0][2] == brd[2][0]) return true;

    return false;
}


pair<int, int> aicalculate() {
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (brd[i][j] != 'X' && brd[i][j] != 'O') {
                char temp = brd[i][j];
                brd[i][j] = 'O';
                if (checkwin()) {
                    brd[i][j] = temp; 
                    return {i, j}; 
                }
                brd[i][j] = temp; 
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (brd[i][j] != 'X' && brd[i][j] != 'O') {
                char temp = brd[i][j];
                brd[i][j] = 'X';
                if (checkwin()) {
                    brd[i][j] = temp; 
                    return {i, j}; 
                }
                brd[i][j] = temp; 
            }
        }
    }

    //  choose a random available move
    vector<pair<int, int>> preferredMoves = {{1, 1}, {0, 0}, {0, 2}, {2, 0}, {2, 2}, {0, 1}, {1, 0}, {1, 2}, {2, 1}};
    for (const auto &move : preferredMoves) {
        if (brd[move.first][move.second] != 'X' && brd[move.first][move.second] != 'O') {
            return move;
        }
    }

    return {-1, -1};
}

// Display the game board
void board() {
    system("cls");
    cout << "\n\n\t Tic Tac Toe Game " << endl;
    cout << endl;

    cout << "\t      |     |     \n";
    cout << "\t  " << brd[0][0] << "   |  " << brd[0][1] << "  |  " << brd[0][2] << "  \n";
    cout << "\t _____|_____|_____\n";
    cout << "\t      |     |     \n";
    cout << "\t  " << brd[1][0] << "   |  " << brd[1][1] << "  |  " << brd[1][2] << "  \n";
    cout << "\t _____|_____|_____\n";
    cout << "\t      |     |     \n";
    cout << "\t  " << brd[2][0] << "   |  " << brd[2][1] << "  |  " << brd[2][2] << "  \n";
    cout << "\t      |     |     \n";
}


void player_turn() {
    int choice;
    if (turn == 'X') {
        cout << "\t\n Enter number 1 to 9 for X :";
        cin >> choice;
    } else {
        cout << "\t\n Enter number 1 to 9 for O :";
        pair<int, int> pos = aicalculate();
        row = pos.first;
        col = pos.second;
        choice = (row * 3) + col + 1;
    }

    switch (choice) {
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
        default: cout << "wrong choice"; break;
    }

    if (brd[row][col] != 'X' && brd[row][col] != 'O') {
        brd[row][col] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Box already filled! Try again!!\n\n";
        player_turn();
    }
    // system("sys");
    board();
}

// Gameover condition check
bool gameover() {
    if (checkwin()) return true;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (brd[i][j] != 'X' && brd[i][j] != 'O')
                return false;
        }
    }
    draw = true;
    return true;
}

int main() {
    while (true) {
        
        board();
        player_turn();
        if (gameover()) {
            break; 
        }
    }

    if (checkwin()) {
        if (turn == 'X') {
            cout << "Player O Wins Congratulations\n";
        } else {
            cout << "Player X Wins Congratulations\n";
        }
    } else {
        cout << "Game Draw!!\n";
    }

    return 0;
}
