#include <stdio.h>

// Funktion zur Anzeige des aktuellen Spielbretts
void displayBoard(char board[3][3]) {
    printf("Tic-Tac-Toe\n");
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int row, col;
    char currentPlayer = 'X';
    int moves = 0;

    while (1) {
        displayBoard(board);
        printf("Spieler %c, geben Sie Zeile und Spalte ein (z.B. 1 2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Überprüfen, ob die Eingabe gültig ist
        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ') {
            printf("Ungültige Eingabe. Bitte erneut versuchen.\n");
            continue;
        }

        // Zeichen des aktuellen Spielers auf dem Spielfeld setzen
        board[row - 1][col - 1] = currentPlayer;
        moves++;

        // Überprüfen, ob ein Spieler gewonnen hat
        int rowWin = 0, colWin = 0, diagWin1 = 0, diagWin2 = 0;
        for (int i = 0; i < 3; i++) {
            if (board[i][i] == currentPlayer) diagWin1++;
            if (board[i][2 - i] == currentPlayer) diagWin2++;
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == currentPlayer) rowWin++;
                if (board[j][i] == currentPlayer) colWin++;
            }
            if (rowWin == 3 || colWin == 3 || diagWin1 == 3 || diagWin2 == 3) {
                displayBoard(board);
                printf("Spieler %c hat gewonnen!\n", currentPlayer);
                return 0;
            }
            rowWin = 0;
            colWin = 0;
        }

        // Wenn keine Gewinner festgestellt wurden und das Spielfeld voll ist, ist es ein Unentschieden.
        if (moves == 9) {
            displayBoard(board);
            printf("Unentschieden!\n");
            return 0;
        }

        // Wechseln Sie zum nächsten Spieler
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}