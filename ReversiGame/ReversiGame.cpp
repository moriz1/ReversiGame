//
//  ReversiGame.cpp
//  ReversiGame
//
//  Created by MorizMBP on 2015-07-11.
//  Copyright (c) 2015 MorizMBP. All rights reserved.
//

#include "ReversiGame.h"

ReversiGame::ReversiGame() {
    initGame();
}

ReversiGame::~ReversiGame() {
    destroyGame();
}

void ReversiGame::initGame() {
    board = new ReversiBoard();
    ui = new ReversiUI();
    
    blackSkipped = false;
    whiteSkipped = false;
}

void ReversiGame::destroyGame() {
    delete ui;
    delete board;
}

void ReversiGame::StartGame() {
    short player = board->GetTurn() % 2;
    
    //main game loop
    do {
        //game logic here
        board->SetValidMoves();
        ui->ShowGrid(board->GetBoardState(), board->GetValidMoves());
        
        ui->ShowScore(board->GetBlackMoves(), board->GetWhiteMoves());
        ui->ShowCurrentPlayer(board->GetTurn());
        ui->ShowValidMoves(board->GetValidMoves());
        
        checkSkipped(board->GetValidMoves());
        
        if (player == 0) {
            if (!blackSkipped) {
                InputLoop(board->SetMove(ui->SetInput()));
            }
        }
        else {
            if (!whiteSkipped) {
                InputLoop(board->SetMove(ui->SetInput()));
            }
        }
    }
    while (!blackSkipped && !whiteSkipped);
    
    //game over
    ui->ShowWinner(board->GetBlackMoves(), board->GetWhiteMoves());
}

void ReversiGame::InputLoop(short input) {
    if (input != -1) {
        //increment turns
        board->advanceTurn();
    }
    else {
        ui->ShowValidMoves(board->GetValidMoves());
        InputLoop(board->SetMove(ui->SetInput()));
    }
}

void ReversiGame::checkSkipped(std::vector<short> moves) {
    short player = board->GetTurn() % 2;
    
    if (moves.size() <= 0) {
        if (player == 0) {
            blackSkipped = true;
        }
        else {
            whiteSkipped = true;
        }
    }
}