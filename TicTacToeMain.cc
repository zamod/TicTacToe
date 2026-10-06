#include <iostream>

#include "TicTacToeFunctions.h"

int main() {
    TicTacToeBoard game_board;
    game_board.PrintBoard();
    game_board.PlayerMakeAMove(1);
    game_board.PrintBoard();
    std::cin.get();
    return 0;
}