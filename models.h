#define BOARD_SIZE 3

typedef enum {
    elem_None = 0,
    elem_X,
    elem_O,
} Elem;

typedef struct {
    Elem board[BOARD_SIZE][BOARD_SIZE];
} Board;

typedef struct {
    unsigned char row;
    unsigned char col;
} Position;

char elem_char_version(Elem element);

Board init_board();
int pos_is_empty(Board* board, Position pos);
void set_position(Board* board, Position pos, Elem player);
