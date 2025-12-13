#pragma once

#include <stdint.h>

typedef uint64_t U64;

#define NAME "cheese 1.0"
#define BOARD_SQ_NUM 120

#define MAXGAMEMOVES 2048

enum {FALSE, TRUE};

enum 
{
    // Empty place on board 
    EMPTY,
    // White Pieces
    wP, wN, wB, wR, wQ, wK,
    // Black Pieces 
    bP, bN, bB, bR, bQ, bK 
};

// Files and Ranks
enum { FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE };
enum { RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE };

// Represents colors
enum { WHITE, BLACK, BOTH };

// Castling rules (using bits) 0 0 0 0
enum { WCK = 1, WQC = 2, BKC = 4, BQC = 8};

// Board Representation Enum
enum 
{
    A1 = 21, B1, C1, D1, E1, F1, G1, H1,
    A2 = 31, B2, C2, D2, E2, F2, G2, H2,
    A3 = 41, B3, C3, D3, E3, F3, G3, H3,
    A4 = 51, B4, C4, D4, E4, F4, G4, H4,
    A5 = 61, B5, C5, D5, E5, F5, G5, H5,
    A6 = 71, B6, C6, D6, E6, F6, G6, H6,
    A7 = 81, B7, C7, D7, E7, F7, G7, H7,
    A8 = 91, B8, C8, D8, E8, F8, G8, H8,

    //Invalid Square
    NO_SQ
};

typedef struct {
    
    int move;
    int castlePerm;
    int enPas;
    int fiftyMove;
    U64 posKey;

} S_UNDO;

// Structure for the full board
typedef struct
{
    int pieces[BOARD_SQ_NUM];
    
    // bitboard for pawns
    // 00000000
    // 11111111 // for white 
    // 00000000 
    // 00000000 
    // 00000000 
    // 00000000 
    // 11111111 // for black
    // 00000000
    U64 pawns[3];
    
    // Square with white and black king
    int KingSq[2];

    // current side to move
    int side;

    // enPassant if active or not
    int enPas;

    // fifty moves tie rule
    int fiftyMove;

    // half moves
    int ply;
    int hisPly;

    // castling permission
    int castlePerm;

    // hashkey for our position
    U64 posKey;

    // number of pieces on board
    int pceNum[13];

    // non-pawn pieces (3 for white, black, both)
    int bigPce[3];
    int majPce[3];
    int minPce[3];

    // allows undo: storing the history of the board
    S_UNDO history[MAXGAMEMOVES];

} S_BOARD;
