#include <iostream>
#include <string>
#include <vector>

#include "TicTacToeFunctions.h"

bool CheckWin(const std::vector<std::vector<int>>& board) { //player 1 winning would equal 1, player two winning would equal 6, no winning would equal 0
    //the horizantal win conditions
    int win_state_one{board.at(0).at(0) * board.at(0).at(1) * board.at(0).at(2)}; //the top horizantal line win condition
    int win_state_two{board.at(1).at(0) * board.at(1).at(1) * board.at(1).at(2)}; //the middle horizantal line
    int win_state_three{board.at(2).at(0) * board.at(2).at(1) * board.at(2).at(2)}; //the bottom horizantal line
    //the vertical win conditions
    int win_state_four{board.at(0).at(0) * board.at(1).at(0) * board.at(2).at(0)}; //the first vertical line
    int win_state_five{board.at(0).at(1) * board.at(1).at(1) * board.at(2).at(1)}; //the second vertical line
    int win_state_six{board.at(0).at(2) * board.at(1).at(2) * board.at(2).at(2)}; //the third vertical line win condition
    //the diagnal win conditions
    int win_state_seven{board.at(0).at(0) * board.at(1).at(1) * board.at(2).at(2)}; //the top left to bottom right win condition
    int win_state_eight{board.at(0).at(2) * board.at(1).at(1) * board.at(2).at(0)}; //the top right to bottom left win condition
    if (win_state_one == 1 || win_state_two == 1 || win_state_three == 1 || win_state_four == 1 || win_state_five == 1 || win_state_six == 1 || win_state_seven == 1 || win_state_eight == 1) {
        return true;
    } else if (win_state_one == 6 || win_state_two == 6 || win_state_three == 6 || win_state_four == 6 || win_state_five == 6 || win_state_six == 6 || win_state_seven == 6 || win_state_eight == 6) {
        return true;
    }
    return false;
}