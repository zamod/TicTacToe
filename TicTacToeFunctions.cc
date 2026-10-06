#include <iostream>
#include <string>
#include <vector>

#include "TicTacToeFunctions.h"

TicTacToeBoard::TicTacToeBoard() : board_{{0,0,0} {0,0,0} {0,0,0}} {}

int TicTacToeBoard::CheckWin() const {
    //player 1 winning would equal 1, player two winning would equal 8, no winning would equal 0
    //the horizantal win conditions
    int win_state_one{board_.at(0).at(0) * board_.at(0).at(1) * board_.at(0).at(2)}; //the top horizantal line win condition
    int win_state_two{board_.at(1).at(0) * board_.at(1).at(1) * board_.at(1).at(2)}; //the middle horizantal line
    int win_state_three{board_.at(2).at(0) * board_.at(2).at(1) * board_.at(2).at(2)}; //the bottom horizantal line
    //the vertical win conditions
    int win_state_four{board_.at(0).at(0) * board_.at(1).at(0) * board_.at(2).at(0)}; //the first vertical line
    int win_state_five{board_.at(0).at(1) * board_.at(1).at(1) * board_.at(2).at(1)}; //the second vertical line
    int win_state_six{board_.at(0).at(2) * board_.at(1).at(2) * board_.at(2).at(2)}; //the third vertical line win condition
    //the diagnal win conditions
    int win_state_seven{board_.at(0).at(0) * board_.at(1).at(1) * board_.at(2).at(2)}; //the top left to bottom right win condition
    int win_state_eight{board_.at(0).at(2) * board_.at(1).at(1) * board_.at(2).at(0)}; //the top right to bottom left win condition
    if (win_state_one == kplayer_one_win_board_number_ || win_state_two == kplayer_one_win_board_number_ || win_state_three == kplayer_one_win_board_number_ || win_state_four == kplayer_one_win_board_number_ || win_state_five == kplayer_one_win_board_number_ || win_state_six == kplayer_one_win_board_number_ || win_state_seven == kplayer_one_win_board_number_ || win_state_eight == kplayer_one_win_board_number_) { //player 1 wins
        return 1;
    } else if (win_state_one == kplayer_two_win_board_number_ || win_state_two == kplayer_two_win_board_number_ || win_state_three == kplayer_two_win_board_number_ || win_state_four == kplayer_two_win_board_number_ || win_state_five == kplayer_two_win_board_number_ || win_state_six == kplayer_two_win_board_number_ || win_state_seven == kplayer_two_win_board_number_ || win_state_eight == kplayer_two_win_board_number_) { //player 2 wins
        return 2;
    }
    return 0;
}

void TicTacToeBoard::PrintBoard() const {

}

/*int CheckWin(const std::vector<std::vector<int>>& board_) { //player 1 winning would equal 1, player two winning would equal 8, no winning would equal 0
    //the horizantal win conditions
    int win_state_one{board_.at(0).at(0) * board_.at(0).at(1) * board_.at(0).at(2)}; //the top horizantal line win condition
    int win_state_two{board_.at(1).at(0) * board_.at(1).at(1) * board_.at(1).at(2)}; //the middle horizantal line
    int win_state_three{board_.at(2).at(0) * board_.at(2).at(1) * board_.at(2).at(2)}; //the bottom horizantal line
    //the vertical win conditions
    //the diagnal win conditions
    int win_state_seven{board_.at(0).at(0) * board_.at(1).at(1) * board_.at(2).at(2)}; //the top left to bottom right win condition
    int win_state_eight{board_.at(0).at(2) * board_.at(1).at(1) * board_.at(2).at(0)}; //the top right to bottom left win condition
    if (win_state_one == 1 || win_state_two == 1 || win_state_three == 1 || win_state_four == 1 || win_state_five == 1 || win_state_six == 1 || win_state_seven == 1 || win_state_eight == 1) { //player 1 wins
        return 1;
    } else if (win_state_one == 8 || win_state_two == 8 || win_state_three == 8 || win_state_four == 8 || win_state_five == 8 || win_state_six == 8 || win_state_seven == 8 || win_state_eight == 8) { //player 2 wins
        return 2;
    }
    return 0;
}*/
