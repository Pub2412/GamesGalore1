#include <iostream>
using namespace std;

int main() {
    char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // Game board
    char player = 'X'; // Starting player
    int choice;
    bool game_over = false;

    cout << "Welcome to Tic-Tac-Toe!\n";

    while (!game_over) {
        // Display the board
        cout << "Current board:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        // Player choice
        cout << "Player " << player << ", choose your position (1-9): ";
        cin >> choice;

        // Update the board
        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        board[row][col] = player;

        // Check for a win
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
                (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
                cout << "Player " << player << " wins!\n";
                game_over = true;
                break;
            }
        }
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
            cout << "Player " << player << " wins!\n";
            game_over = true;
        }

        // Check for a draw
        bool draw = true;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    draw = false;
                    break;
                }
            }
        }
        if (draw) {
            cout << "It's a draw!\n";
            game_over = true;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
