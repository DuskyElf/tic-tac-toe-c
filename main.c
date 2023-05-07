#include <stdio.h>
#include <assert.h>
#include "./models.h"

void render_board(Board* board) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("|%c|", elem_char_version(board->board[i][j]));
        }
        printf("\n");
    }
}

Position prompt_pos() {
    unsigned int row;
    do {
        printf("> row: ");
        scanf("%d", &row);
    } while (row < 1 || row > BOARD_SIZE);

    unsigned int col;
    do {
        printf("> col: ");
        scanf("%d", &col);
    } while (col < 1 || col > BOARD_SIZE);

    Position res = {
        .row = row,
        .col = col,
    };
    return res;
}

void shift_player(Elem* player) {
    assert(*player != elem_None);
    *player = *player == elem_X ? elem_O : elem_X;
}

Elem check_for_win(Board* board) {
    // check for rows
    for (int i = 0; i < 3; i++) {
        if (board->board[i][0] == board->board[i][1] && board->board[i][1] == board->board[i][2]) {
            return board->board[i][0];
        }
    }
    
    // check for cols
    for (int i = 0; i < 3; i++) {
        if (board->board[0][i] == board->board[1][i] && board->board[1][i] == board->board[2][i]) {
            return board->board[0][i];
        }
    }

    // check for diagonals
    if (board->board[0][0] == board->board[1][1] && board->board[1][1] == board->board[2][2]) {
        return board->board[0][0];
    }
    if (board->board[0][2] == board->board[1][1] && board->board[1][1] == board->board[2][0]) {
        return board->board[0][0];
    }

    return elem_None;
}

int main(void) {
    printf("A Simple Board Game\n");
    printf("Game starts now!\n");
    Board board = init_board();
    render_board(&board);

    Elem current_player = elem_X;
    while (1) {
        Position pos = prompt_pos();
        if (!pos_is_empty(&board, pos)) {
            printf("Invalid Position, Try again\n");
            continue;
        }
        set_position(&board, pos, current_player);
        render_board(&board);

        Elem winner = check_for_win(&board);
        if (!(winner == elem_None)) {
            printf("Game Over: Player %c won the game!\n", elem_char_version(winner));
            break;
        }
        shift_player(&current_player);
    }
}
