//
//  ReversiBoard.h
//  ReversiGame
//
//  Created by MorizMBP on 2015-07-08.
//  Copyright (c) 2015 MorizMBP. All rights reserved.
//

#ifndef __ReversiGame__ReversiBoard__
#define __ReversiGame__ReversiBoard__

#include <stdio.h>
#include <vector>

struct node {
    short val = -1;  //-1 = empty and valid move
                     //-2 = black
                     //-3 = white
                     //2 = empty and invalid move
    
    short index;
    
    short nn = -1; //indices for neighbors. -1 if null
    short ss = -1;
    short ee = -1;
    short ww = -1;
    short ne = -1;
    short nw = -1;
    short se = -1;
    short sw = -1;
};

class ReversiBoard {
public:
    ReversiBoard();
    ~ReversiBoard();
    
    short GetTurn();
    node* GetBoardState();
    void SetValidMoves();
    std::vector<short> GetValidMoves();
    short SetMove(short index);
    void advanceTurn();
    bool hasValidMoves();
    std::vector<short> GetBlackMoves();
    std::vector<short> GetWhiteMoves();
private:
    void createBoard();
    void killBoard();
    void flip(short index);
    void setValidMovesBlackHelper(short index);
    void setValidMovesWhiteHelper(short index);
    void flipBlackHelper(short index);
    void flipWhiteHelper(short index);
    
    short turn;
    node* board;
    std::vector<short> blackMoves;
    std::vector<short> whiteMoves;
    std::vector<short> validMoves;
};

#endif /* defined(__ReversiGame__ReversiBoard__) */
