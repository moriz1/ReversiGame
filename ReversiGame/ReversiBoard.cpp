//
//  ReversiBoard.cpp
//  ReversiGame
//
//  Created by MorizMBP on 2015-07-08.
//  Copyright (c) 2015 MorizMBP. All rights reserved.
//

#include "ReversiBoard.h"
#include <algorithm>

ReversiBoard::ReversiBoard() {
    board = new node[64];
    createBoard();
    turn = 0;
}

ReversiBoard::~ReversiBoard() {
    killBoard();
}

void ReversiBoard::killBoard() {
    delete board;
}

short ReversiBoard::GetTurn() {
    return turn;
}

node* ReversiBoard::GetBoardState() {
    return board;
}

//returns -1 if move is invalid, input otherwise
short ReversiBoard::SetMove(short index) {
    short player = turn % 2;
    
    if (std::find(validMoves.begin(), validMoves.end(), index) != validMoves.end()) {
        if (player == 0) {
            blackMoves.push_back(index);
        }
        else {
            whiteMoves.push_back(index);
        }
        
        board[index].val = player;
        flip(index);
        
        return index;
    }

    return -1;
}

void ReversiBoard::advanceTurn() {
    turn++;
}

//this makes no distinction as to WHO has valid moves or not; just whether the current active player has valid
//moves or not.
bool ReversiBoard::hasValidMoves() {
    if (validMoves.size() > 0) {
        return true;
    }
    return false;
}

std::vector<short> ReversiBoard::GetBlackMoves() {
    return blackMoves;
}

std::vector<short> ReversiBoard::GetWhiteMoves() {
    return whiteMoves;
}

void ReversiBoard::flip(short index) {
    short player = turn % 2;
    
    //look through surrounding squares. if they exist in the other player's moves, flip them
    if (player == 0) {
        flipBlackHelper(index);
    }
    else {
        flipWhiteHelper(index);
    }
}

void ReversiBoard::flipBlackHelper(short index) {
    short player = turn % 2;
    short direction = 0;
    short nextDirection = 0;
    short currentSearchIndex = -1;
    bool shouldStopSearching = false;
    
    for (short i = 0; i < 8; i++) {
        switch (i) {
            case 0:
                direction = board[index].nw;
                nextDirection = board[direction].nw;
                break;
            case 1:
                direction = board[index].nn;
                nextDirection = board[direction].nn;
                break;
            case 2:
                direction = board[index].ne;
                nextDirection = board[direction].ne;
                break;
            case 3:
                direction = board[index].ww;
                nextDirection = board[direction].ww;
                break;
            case 4:
                direction = board[index].ee;
                nextDirection = board[direction].ee;
                break;
            case 5:
                direction = board[index].sw;
                nextDirection = board[direction].sw;
                break;
            case 6:
                direction = board[index].ss;
                nextDirection = board[direction].ss;
                break;
            case 7:
            default:
                direction = board[index].se;
                nextDirection = board[direction].se;
                break;
        }
        
        currentSearchIndex = direction;
        while (!shouldStopSearching && currentSearchIndex != -1) {
            if (std::find(whiteMoves.begin(), whiteMoves.end(), currentSearchIndex) != whiteMoves.end()) {
                
                //also have to check if the next square isn't empty, or edge of board
                if (nextDirection != -1 && board[nextDirection].val != -1)
                {
                    whiteMoves.erase(std::remove(whiteMoves.begin(), whiteMoves.end(), currentSearchIndex), whiteMoves.end());
                    blackMoves.push_back(currentSearchIndex);
                    board[currentSearchIndex].val = player;
                    
                    switch (i) {
                        case 0:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].nw;
                            break;
                        case 1:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].nn;
                            break;
                        case 2:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].ne;
                            break;
                        case 3:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].ww;
                            break;
                        case 4:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].ee;
                            break;
                        case 5:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].sw;
                            break;
                        case 6:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].ss;
                            break;
                        case 7:
                        default:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].se;
                            break;
                    }
                    
                    //currentSearchIndex = board[currentSearchIndex].nw;
                    shouldStopSearching = false;
                }
                else {
                    shouldStopSearching = true;
                }
            }
            else {
                shouldStopSearching = true;
            }
        }
        
        shouldStopSearching = false;
    }
}

void ReversiBoard::flipWhiteHelper(short index) {
    short player = turn % 2;
    short direction = 0;
    short nextDirection = 0;
    short currentSearchIndex = -1;
    bool shouldStopSearching = false;
    
    for (short i = 0; i < 8; i++) {
        switch (i) {
            case 0:
                direction = board[index].nw;
                nextDirection = board[direction].nw;
                break;
            case 1:
                direction = board[index].nn;
                nextDirection = board[direction].nn;
                break;
            case 2:
                direction = board[index].ne;
                nextDirection = board[direction].ne;
                break;
            case 3:
                direction = board[index].ww;
                nextDirection = board[direction].ww;
                break;
            case 4:
                direction = board[index].ee;
                nextDirection = board[direction].ee;
                break;
            case 5:
                direction = board[index].sw;
                nextDirection = board[direction].sw;
                break;
            case 6:
                direction = board[index].ss;
                nextDirection = board[direction].ss;
                break;
            case 7:
            default:
                direction = board[index].se;
                nextDirection = board[direction].se;
                break;
        }
        
        currentSearchIndex = direction;
        while (!shouldStopSearching && currentSearchIndex != -1) {
            if (std::find(blackMoves.begin(), blackMoves.end(), currentSearchIndex) != blackMoves.end()) {
                
                //also have to check if the next square isn't empty, or edge of board
                if (nextDirection != -1 && board[nextDirection].val != -1)
                {
                    blackMoves.erase(std::remove(blackMoves.begin(), blackMoves.end(), currentSearchIndex), blackMoves.end());
                    whiteMoves.push_back(currentSearchIndex);
                    board[currentSearchIndex].val = player;
                    
                    switch (i) {
                        case 0:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].nw;
                            break;
                        case 1:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].nn;
                            break;
                        case 2:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].ne;
                            break;
                        case 3:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].ww;
                            break;
                        case 4:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].ee;
                            break;
                        case 5:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].sw;
                            break;
                        case 6:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].ss;
                            break;
                        case 7:
                        default:
                            currentSearchIndex = nextDirection;
                            nextDirection = board[nextDirection].se;
                            break;
                    }
                    
                    //currentSearchIndex = board[currentSearchIndex].nw;
                    shouldStopSearching = false;
                }
                else {
                    shouldStopSearching = true;
                }
            }
            else {
                shouldStopSearching = true;
            }
        }
        
        shouldStopSearching = false;
    }
}

void ReversiBoard::SetValidMoves() {
    short player = turn % 2;
    validMoves.clear();
    
    if (player == 0) { //black's turn
        
        //now we look at squares around white's moves for valid black moves
        for (short i = 0; i < whiteMoves.size(); i++) {
            setValidMovesBlackHelper(i);
        }
    }
    else {
        for (short i = 0; i < blackMoves.size(); i++) {
            setValidMovesWhiteHelper(i);
        }
    }
}

void ReversiBoard::setValidMovesBlackHelper(short index) {
    short player = turn % 2;
    short direction = 0;
    short opposite = 0;
    bool foundOrEdge = false;
    short currentSearchIndex = -1;
    
    for (short i = 0; i < 8; i++) {
        switch (i) {
            case 0:
                direction = board[whiteMoves[index]].nw;
                opposite = board[whiteMoves[index]].se;
                break;
            case 1:
                direction = board[whiteMoves[index]].nn;
                opposite = board[whiteMoves[index]].ss;
                break;
            case 2:
                direction = board[whiteMoves[index]].ne;
                opposite = board[whiteMoves[index]].sw;
                break;
            case 3:
                direction = board[whiteMoves[index]].ww;
                opposite = board[whiteMoves[index]].ee;
                break;
            case 4:
                direction = board[whiteMoves[index]].ee;
                opposite = board[whiteMoves[index]].ww;
                break;
            case 5:
                direction = board[whiteMoves[index]].sw;
                opposite = board[whiteMoves[index]].ne;
                break;
            case 6:
                direction = board[whiteMoves[index]].ss;
                opposite = board[whiteMoves[index]].nn;
                break;
            case 7:
            default:
                direction = board[whiteMoves[index]].se;
                opposite = board[whiteMoves[index]].nw;
                break;
        }
        
        //check in all directions for edge of board
        //and that the square is unoccupied
        if (direction != -1 && board[direction].val == -1) {
            //if we find an unoccupied square in this direction, check the OTHER direction
            //in a line, to see if we ever find a black move. if so, then this move is valid
            
            currentSearchIndex = opposite;
            
            while (!foundOrEdge) {
                //if opposite square is edge of board, stop searching
                if (currentSearchIndex == -1) {
                    foundOrEdge = true;
                }
                //if opposite square is a black piece, we've found a valid move
                else if (board[currentSearchIndex].val == player) {
                    foundOrEdge = true;
                    
                    //check if this square is already in the validMoves vector
                    if (!(std::find(validMoves.begin(), validMoves.end(), currentSearchIndex) != validMoves.end())) {
                        validMoves.push_back(direction);
                    }
                }
                //if opposite square is a white piece, set index to that square's index,
                //and keep going
                else if (board[currentSearchIndex].val != player) {
                    foundOrEdge = false;
                    
                    switch (i) {
                        case 0:
                            opposite = board[currentSearchIndex].se;
                            break;
                        case 1:
                            opposite = board[currentSearchIndex].ss;
                            break;
                        case 2:
                            opposite = board[currentSearchIndex].sw;
                            break;
                        case 3:
                            opposite = board[currentSearchIndex].ee;
                            break;
                        case 4:
                            opposite = board[currentSearchIndex].ww;
                            break;
                        case 5:
                            opposite = board[currentSearchIndex].ne;
                            break;
                        case 6:
                            opposite = board[currentSearchIndex].nn;
                            break;
                        case 7:
                        default:
                            opposite = board[currentSearchIndex].nw;
                            break;
                    }
                    
                    currentSearchIndex = opposite;
                }
            }
        }
        foundOrEdge = false;
    }
}

void ReversiBoard::setValidMovesWhiteHelper(short index) {
    short player = turn % 2;
    short direction = 0;
    short opposite = 0;
    bool foundOrEdge = false;
    short currentSearchIndex = -1;
    
    for (short i = 0; i < 8; i++) {
        switch (i) {
            case 0:
                direction = board[blackMoves[index]].nw;
                opposite = board[blackMoves[index]].se;
                break;
            case 1:
                direction = board[blackMoves[index]].nn;
                opposite = board[blackMoves[index]].ss;
                break;
            case 2:
                direction = board[blackMoves[index]].ne;
                opposite = board[blackMoves[index]].sw;
                break;
            case 3:
                direction = board[blackMoves[index]].ww;
                opposite = board[blackMoves[index]].ee;
                break;
            case 4:
                direction = board[blackMoves[index]].ee;
                opposite = board[blackMoves[index]].ww;
                break;
            case 5:
                direction = board[blackMoves[index]].sw;
                opposite = board[blackMoves[index]].ne;
                break;
            case 6:
                direction = board[blackMoves[index]].ss;
                opposite = board[blackMoves[index]].nn;
                break;
            case 7:
            default:
                direction = board[blackMoves[index]].se;
                opposite = board[blackMoves[index]].nw;
                break;
        }
        
        //check in all directions for edge of board
        //and that the square is unoccupied
        if (direction != -1 && board[direction].val == -1) {
            //if we find an unoccupied square in this direction, check the OTHER direction
            //in a line, to see if we ever find a black move. if so, then this move is valid
            
            currentSearchIndex = opposite;
            
            while (!foundOrEdge) {
                //if opposite square is edge of board, stop searching
                if (currentSearchIndex == -1) {
                    foundOrEdge = true;
                }
                //if opposite square is a black piece, we've found a valid move
                else if (board[currentSearchIndex].val == player) {
                    foundOrEdge = true;
                    
                    //check if this square is already in the validMoves vector
                    if (!(std::find(validMoves.begin(), validMoves.end(), currentSearchIndex) != validMoves.end())) {
                        validMoves.push_back(direction);
                    }
                }
                //if opposite square is a white piece, set index to that square's index,
                //and keep going
                else if (board[currentSearchIndex].val != player) {
                    foundOrEdge = false;
                    switch (i) {
                        case 0:
                            opposite = board[currentSearchIndex].se;
                            break;
                        case 1:
                            opposite = board[currentSearchIndex].ss;
                            break;
                        case 2:
                            opposite = board[currentSearchIndex].sw;
                            break;
                        case 3:
                            opposite = board[currentSearchIndex].ee;
                            break;
                        case 4:
                            opposite = board[currentSearchIndex].ww;
                            break;
                        case 5:
                            opposite = board[currentSearchIndex].ne;
                            break;
                        case 6:
                            opposite = board[currentSearchIndex].nn;
                            break;
                        case 7:
                        default:
                            opposite = board[currentSearchIndex].nw;
                            break;
                    }
                    
                    currentSearchIndex = opposite;
                }
            }
        }
        foundOrEdge = false;
    }
}

std::vector<short> ReversiBoard::GetValidMoves() {
    return validMoves;
}

void ReversiBoard::createBoard() {
    for (short i = 0; i < 64; i++) {
        board[i] = *new node;
        board[i].index = i;
        
        //prefilled
        if (i == 27 || i == 36) {
            board[i].val = 0;
            blackMoves.push_back(i);
        }
        if (i == 28 || i == 35) {
            board[i].val = 1;
            whiteMoves.push_back(i);
        }
        
        switch (i) {
                //corners
            case 0:
                board[i].ee = 1;
                board[i].ss = 8;
                board[i].se = 9;
                break;
            case 7:
                board[i].ww = 6;
                board[i].sw = 14;
                board[i].ss = 15;
                break;
            case 56:
                board[i].nn = 48;
                board[i].ne = 49;
                board[i].ee = 57;
                break;
            case 63:
                board[i].nw = 54;
                board[i].nn = 55;
                board[i].ww = 62;
                break;
                
                //top edge
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                board[i].ww = i - 1;
                board[i].ee = i + 1;
                board[i].sw = i + 7;
                board[i].ss = i + 8;
                board[i].se = i + 9;
                break;
                
                //bottom edge
            case 57:
            case 58:
            case 59:
            case 60:
            case 61:
            case 62:
                board[i].nw = i - 9;
                board[i].nn = i - 8;
                board[i].ne = i - 7;
                board[i].ww = i - 1;
                board[i].ee = i + 1;
                break;
                
                //left edge
            case 8:
            case 16:
            case 24:
            case 32:
            case 40:
            case 48:
                board[i].nn = i - 8;
                board[i].ne = i - 7;
                board[i].ee = i + 1;
                board[i].ss = i + 8;
                board[i].se = i + 9;
                break;
                
                //right edge
            case 15:
            case 23:
            case 31:
            case 39:
            case 47:
            case 55:
                board[i].nw = i - 9;
                board[i].nn = i - 8;
                board[i].ww = i - 1;
                board[i].sw = i + 7;
                board[i].ss = i + 8;
                break;
                
            default:
                board[i].nw = i - 9;
                board[i].nn = i - 8;
                board[i].ne = i - 7;
                board[i].ww = i - 1;
                board[i].ee = i + 1;
                board[i].sw = i + 7;
                board[i].ss = i + 8;
                board[i].se = i + 9;
                break;
        }
    }
}