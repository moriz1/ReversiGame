//
//  main.cpp
//  ReversiGame
//
//  Created by MorizMBP on 2015-07-08.
//  Copyright (c) 2015 MorizMBP. All rights reserved.
//

#include <iostream>
#include "ReversiGame.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    ReversiGame *game = new ReversiGame();
    
    game->StartGame();
    
    delete game;
    
    return 0;
}
