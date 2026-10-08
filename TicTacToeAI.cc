#include <"TicTacToeAi.h">

#include <random>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <utility>

std::pair<int, int> TicTacToeAi::MakeMove(std::vector<std::vector<int>> board) const {
    std::pair<int, int> move_choice{-1,0};
    int random_number{-1};
    srand(time(nullptr));
    if (player_number_ == 1) {
        if (number_of_moves_ == 0) {
            move_choice = {0, 1};
            /*random_number = rand() % 5;
            switch (random_number) {
                case 0:
                    move_choice = {0, 0};
                    break;
                case 1:
                    move_choice = {0, 2};
                    break;
                case 2:
                    move_choice = {1, 1};
                    break;
                case 3:
                    move_choice = {2, 0};
                    break;
                case 4:
                    move_choice = {2, 2};
                    break;
            } */
            ++number_of_moves_;
            return move_choice;
        }
        if (number_of_moves_ == 1) {
            if (board.at(0).at(0) == 2) {
                random_number = rand() % 2;
                switch (random_number) {
                    case 0:
                        move_choice = {0, 2};
                        break;
                    case 1:
                        move_choice = {2, 0};
                        break;
                }
                return move_choice;
            }
        }
        for (auto& row : board) { //cycle through the board, test if switching a 0 to a 1 wins the game, if so, that's the move choice
            for (auto& column : row) {
                if (column == 0) {
                    column = 1;
                    if (CheckWin(board) == 1) {
                        move_choice.first = row;
                        move_choice.second = column;
                        ++number_of_moves_;
                        return move_choice;
                    }
                    column = 0;
                }
            }
        }
        for (auto& row : board) { //cycle through the board, test if switching a 0 to a 2 wins the game, if so, that's the move choice
            for (auto& column : row) { //defensive/prevent opponent from winning
                if (column == 0) {
                    column = 2;
                    if (CheckWin(board) == 2) {
                        move_choice.first = row;
                        move_choice.second = column;
                        number_of_moves_ += 1;
                        return move_choice;
                    }
                    column = 0;
                }
            }
        }
    }
}

int TicTacToeAi::CheckWin(const std::vector<std::vector<int>>& board_) const {
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

/* if (board.at(0).at(0) == 1 && board.at(0).at(1) == 1) {
            return 3;
        }
        if (board.at(0).at(0) == 1 && board.at(0).at(2) == 1) {
            return 2;
        }
        if (board.at(0).at(1) == 1 && board.at(0).at(2) == 1) {
            return 1;
        } */