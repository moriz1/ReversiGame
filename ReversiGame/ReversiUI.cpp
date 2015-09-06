//
//  ReversiUI.cpp
//  ReversiGame
//
//  Created by MorizMBP on 2015-07-11.
//  Copyright (c) 2015 MorizMBP. All rights reserved.
//

#include <iostream>
#include "ReversiUI.h"

ReversiUI::ReversiUI() {
}

ReversiUI::~ReversiUI() {
}

//this will display a graphical representation of the board itself
//i'm going to go with a simpler text representation here
//(@@): black, (++): white, (  ): empty, (##): valid move
void ReversiUI::ShowGrid(node board[], std::vector<short> moves) {
    short value = -1;
    for (short i = 0; i < 64; i++) {
        value = board[i].val;
        
        if (moves.size() > 0 && (std::find(moves.begin(), moves.end(), board[i].index) != moves.end())) {
            value = i;
        }
        
        switch (value) {
            case -1:
                std::cout << "(  ) ";
                break;
            case 0:
                std::cout << "-@@- ";
                break;
            case 1:
                std::cout << "-++- ";
                break;
            default:
                if (value - 10 < 0) {
                    std::cout << "  " << value << "  ";
                }
                else {
                    std::cout << " " << value << "  ";
                }
                break;
        }
        
        switch (i) {
            case 7:
            case 15:
            case 23:
            case 31:
            case 39:
            case 47:
            case 55:
            case 63:
                std::cout << std::endl << std::endl;
                break;
            default:
                break;
        }
    }
}

//displays the current player and turn number
void ReversiUI::ShowCurrentPlayer(short turn) {
    short player = turn % 2;
    
    std::cout << "turn " << turn+1 << std::endl;
    
    if (player == 0) {
        std::cout << "Black-@@-'s turn:" << std::endl;
    }
    else
    {
        std::cout << "White-++-'s turn:" << std::endl;
    }
}

//displays all the valid moves
void ReversiUI::ShowValidMoves(std::vector<short> moves) {
    if (moves.size() > 0) {
        std::cout << "valid moves: ";
        
        for (short i = 0; i < moves.size(); i++) {
            std::cout << moves[i] << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "!!no valid moves. skipping to next player!!" << std::endl;
    }
    
    std::cout << "> ";
}

void ReversiUI::ShowScore(std::vector<short> blackMoves, std::vector<short> whiteMoves) {
    std::cout << "Black's score: " << blackMoves.size() << std::endl;
    std::cout << "White's score: " << whiteMoves.size() << std::endl;
}

void ReversiUI::ShowWinner(std::vector<short> blackMoves, std::vector<short> whiteMoves) {
    std::cout << "GAME OVER: ";
    
    if (blackMoves.size() > whiteMoves.size()) {
        std::cout << "Black wins!" << std::endl;
    }
    else if (blackMoves.size() < whiteMoves.size()) {
        std::cout << "White wins!" << std::endl;
    }
    else {
        std::cout << "Tied!" << std::endl;
    }
}

short ReversiUI::SetInput() {
    short input;
    std::cin >> input;
    
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return -1;
    }
    
    return input;
}