#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn = 'X';
int row, column;

void display_board() {
    system("cls"); // use system("clear"); on Unix-based systems
    cout << "\t\tT I C - T A C - T O E\n";
    cout << "\tPlayer1 [X]  -  Player2 [O]\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t   " << board[0][0] << " | " << board[0][1] << "   |  " << board[0][2] << "  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t   " << board[1][0] << " | " << board[1][1] << "   |  " << board[1][2] << "  \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t   " << board[2][0] << " | " << board[2][1] << "   |  " << board[2][2] << "  \n";
    cout << "\t\t     |     |     \n";
}

bool check_win() {
    for (int i = 0; i < 3; i++) {
        // Check rows and columns
        if ((board[i][0] == turn && board[i][1] == turn && board[i][2] == turn) ||
            (board[0][i] == turn && board[1][i] == turn && board[2][i] == turn))
            return true;
    }
    // Check diagonals
    if ((board[0][0] == turn && board[1][1] == turn && board[2][2] == turn) ||
        (board[0][2] == turn && board[1][1] == turn && board[2][0] == turn))
        return true;

    return false;
}

bool check_draw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void player_turn() {
    int choice;
    cout << "\n\tPlayer [" << turn << "] turn: ";
    cin >> choice;

    switch(choice) {
        case 1: row = 0; column = 0; break;
        case 2: row = 0; column = 1; break;
        case 3: row = 0; column = 2; break;
        case 4: row = 1; column = 0; break;
        case 5: row = 1; column = 1; break;
        case 6: row = 1; column = 2; break;
        case 7: row = 2; column = 0; break;
        case 8: row = 2; column = 1; break;
        case 9: row = 2; column = 2; break;
        default:
            cout << "Invalid choice! Try again.\n";
            player_turn();
            return;
    }

    if (board[row][column] != 'X' && board[row][column] != 'O') {
        board[row][column] = turn;
        if (check_win()) {
            display_board();
            cout << "\nPlayer [" << turn << "] wins!\n";
            exit(0);
        } else if (check_draw()) {
            display_board();
            cout << "\nThe game is a draw!\n";
            exit(0);
        } else {
            turn = (turn == 'X') ? 'O' : 'X';
        }
    } else {
        cout << "Box already filled! Try again.\n";
        player_turn();
    }
}

int main() {
    while (true) {
        display_board();
        player_turn();
    }
    return 0;
}

