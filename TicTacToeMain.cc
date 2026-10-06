#include <iostream>

#include "TicTacToeFunctions.h"

int main() {
    TicTacToeBoard game_board;
    int win_condition{0};
    int player_number{1};
    bool is_turn_odd{true};
    bool is_turn_even{false};
    while (!win_condition) {
        game_board.PrintBoard();
        std::cout << "\n";
        game_board.PlayerMakeAMove(player_number);
        if (is_turn_odd) {
            player_number = 2;
            is_turn_odd = false;
            is_turn_even = true;
            win_condition = game_board.CheckWin();
            continue;
        }
        if (is_turn_even) {
            player_number = 1;
            is_turn_even = false;
            is_turn_odd = true;
            win_condition = game_board.CheckWin();
            continue;
        }
    }
    if (win_condition == 1) {
        game_board.PrintBoard();
        std::cout << "Player 1 wins!\n";
        return 0;
    }
    if (win_condition == 2) {
        game_board.PrintBoard();
        std::cout << "Player 2 wins!\n";
        return 0;
    }
    return 1;
}