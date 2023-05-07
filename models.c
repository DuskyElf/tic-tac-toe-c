#include "models.h"
#include <assert.h>

// -------- Elem functions ----------
char elem_char_version(Elem element) {
    switch (element) {
        case elem_None:
            return ' ';
        case elem_X:
            return 'X';
        case elem_O:
            return 'O';
    }
}

// -------- Board functions ----------
Board init_board() {
    Board board = {
        .board = {
            {elem_None, elem_None, elem_None},
            {elem_None, elem_None, elem_None},
            {elem_None, elem_None, elem_None}
        }
    };
    return board;
}

int pos_is_empty(Board* board, Position pos) {
    pos.row -= 1;
    pos.col -= 1;
    assert(pos.row < 3);
    assert(pos.col < 3);
    return board->board[pos.row][pos.col] == elem_None;
}

void set_position(Board* board, Position pos, Elem player) {
    pos.row -= 1;
    pos.col -= 1;
    assert(pos.row < 3);
    assert(pos.col < 3);
    board->board[pos.row][pos.col] = player;
}

