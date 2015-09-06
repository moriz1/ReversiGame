//
//  ReversiUI.h
//  ReversiGame
//
//  Created by MorizMBP on 2015-07-11.
//  Copyright (c) 2015 MorizMBP. All rights reserved.
//

#ifndef __ReversiGame__ReversiUI__
#define __ReversiGame__ReversiUI__

#include <stdio.h>
#include <vector>
#include "ReversiBoard.h"

class ReversiUI {
public:
    ReversiUI();
    ~ReversiUI();
    
    void ShowGrid(node board[], std::vector<short> moves);
    void ShowCurrentPlayer(short turn);
    void ShowValidMoves(std::vector<short> moves);
    void ShowScore(std::vector<short> blackMoves, std::vector<short> whiteMoves);
    void ShowWinner(std::vector<short> blackMoves, std::vector<short> whiteMoves);
    short SetInput();
private:
};

#endif /* defined(__ReversiGame__ReversiUI__) */
