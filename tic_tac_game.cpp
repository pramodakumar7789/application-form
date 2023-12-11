#include <iostream>
#include <string>

// Function to draw the board
void drawBoard(char board[3][3]) {
    std::cout << "---------" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "| " << board[i][j] << " ";
        }
        std::cout << "|" << std::endl;
        std::cout << "---------" << std::endl;
    }
}

// Function to check if the player has won
bool checkWin(char board[3][3], char player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;

    return false;
}

// Function to check if the game has ended in a draw
bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

// Function to play the game
void playGame() {
    char board[3][3] = {{' ', ' ', ' '},
                        {' ', ' ', ' '},
                        {' ', ' ', ' '}};
    char player = 'X';
    bool gameEnded = false;
    int moveCount = 0;

    while (!gameEnded) {
        drawBoard(board);
        std::cout << "Player " << player << ", make your move (1-9): ";
        int move;
        std::cin >> move;

        // Ensure valid move
        while (move < 1 || move > 9 || board[(move - 1) / 3][(move - 1) % 3] != ' ') {
            std::cout << "Invalid move. Player " << player << ", please enter a valid move (1-9): ";
            std::cin >> move;
        }

        // Update board
        board[(move - 1) / 3][(move - 1) % 3] = player;

        // Check for win or draw
        if (checkWin(board, player)) {
            drawBoard(board);
            std::cout << "Player " << player << " wins!" << std::endl;
            break;
        }
        else if (checkDraw(board)) {
            drawBoard(board);
            std::cout << "It's a draw!" << std::endl;
            break;
        }

        // Switch player
        player = (player == 'X') ? 'O' : 'X';
        moveCount++;
    }
}

int main() {
    playGame();
    return 0;
}