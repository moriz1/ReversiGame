//
//  ReversiGame.h
//  ReversiGame
//
//  Created by MorizMBP on 2015-07-11.
//  Copyright (c) 2015 MorizMBP. All rights reserved.
//

#ifndef __ReversiGame__ReversiGame__
#define __ReversiGame__ReversiGame__

#include <stdio.h>
#include "ReversiBoard.h"
#include "ReversiUI.h"

class ReversiGame {
public:
    ReversiGame();
    ~ReversiGame();
    
    void StartGame();
    void InputLoop(short input);
private:
    void initGame();
    void destroyGame();
    void checkSkipped(std::vector<short> moves);
    
    ReversiBoard *board;
    ReversiUI *ui;
    bool blackSkipped;
    bool whiteSkipped;
};

#endif /* defined(__ReversiGame__ReversiGame__) */
