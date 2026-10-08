#include "TicTacToeAI.h"

#include <random>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <utility>

TicTacToeAI::TicTacToeAI() : difficulty_{4}, player_number_{1}, number_of_moves_{0}, last_move_{-1, -1} {}

TicTacToeAI::TicTacToeAI(int difficulty, int player_number) : difficulty_{difficulty}, player_number_{player_number}, number_of_moves_{0}, last_move_{-1, -1} {}

std::pair<int, int> TicTacToeAI::MakeMove(std::vector<std::vector<int>> board) {
    std::pair<int, int> move_choice{-1,0};
    int row_count{0};
    int column_count{0};
    int random_number{-1};
    srand(time(nullptr));
    if (player_number_ == 1) {
        if (number_of_moves_ == 0) {
            move_choice = {1, 1}; //only one ideal choice, dead center
            ++number_of_moves_; //update move counter and return
            last_move_ = move_choice;
            return move_choice;
        }
        if (number_of_moves_ == 1) {
            if (board.at(0).at(0) == 2) { //top left
                random_number = rand() % 2;
                switch (random_number) { //randomly pick either top right or bottom left
                    case 0:
                        move_choice = {0, 2};
                        break;
                    case 1:
                        move_choice = {2, 0};
                        break;
                }
                ++number_of_moves_; //update move counter and return
                last_move_ = move_choice;
                return move_choice;
            }
            if (board.at(0).at(2) == 2) { //top right
                random_number = rand() % 2;
                switch (random_number) { //randomly pick either top left or bottom right
                    case 0:
                        move_choice = {0, 0};
                        break;
                    case 1:
                        move_choice = {2, 2};
                        break;
                }
                ++number_of_moves_; //update move counter and return
                last_move_ = move_choice;
                return move_choice;
            }
            if (board.at(2).at(0) == 2) { //bottom left
                random_number = rand() % 2;
                switch (random_number) { //randomly pick either top left or bottom right
                    case 0:
                        move_choice = {0, 0};
                        break;
                    case 1:
                        move_choice = {2, 2};
                        break;
                }
                ++number_of_moves_; //update move counter and return
                last_move_ = move_choice;
                return move_choice;
            }
            if (board.at(2).at(2) == 2) {  //bottom right
                random_number = rand() % 2;
                switch (random_number) { //randomly pick either top right or bottom left
                    case 0:
                        move_choice = {0, 2};
                        break;
                    case 1:
                        move_choice = {2, 0};
                        break;
                }
                ++number_of_moves_; //update move counter and return
                last_move_ = move_choice;
                return move_choice;
            }
            random_number = rand() % 4; //if no corners are taken, randomly pick a corner to take
            switch (random_number) {
                case 0:
                    move_choice = {0, 0};
                    break;
                case 1:
                    move_choice = {0, 2};
                    break;
                case 2:
                    move_choice = {2, 0};
                    break;
                case 3:
                    move_choice = {2, 2};
                    break;
            }
            ++number_of_moves_; //update move counter and return
            last_move_ = move_choice;
            return move_choice;
        }
        for (auto& row : board) { //cycle through the board, test if switching a 0 to a 1 wins the game, if so, that's the move choice
            for (auto& column : row) {
                if (column == 0) {
                    column = 1;
                    if (CheckWin(board) == 1) {
                        move_choice.first = row_count;
                        move_choice.second = column_count;
                        ++number_of_moves_;
                        last_move_ = move_choice; //update move counter and return
                        return move_choice;
                    }
                    column = 0;
                }
                ++column_count;
            }
            column_count = 0;
            ++row_count;
        }
        row_count = 0;
        column_count = 0;
        for (auto& row : board) { //cycle through the board, test if switching a 0 to a 2 wins the game, if so, that's the move choice
            for (auto& column : row) { //defensive/prevent opponent from winning
                if (column == 0) {
                    column = 2;
                    if (CheckWin(board) == 2) {
                        move_choice.first = row_count;
                        move_choice.second = column_count;
                        ++number_of_moves_; //update move counter and return
                        last_move_ = move_choice;
                        return move_choice;
                    }
                    column = 0;
                }
                column_count = 0;
                ++column_count;
            }
            ++row_count;
        }
        if (last_move_.first == 0 && last_move_.second == 0) { //if last move was top left
            if (board.at(0).at(1) == 2 && board.at(2).at(0) == 0) { //if opponent is in the middle top
                move_choice = {2, 0}; //take bottom left
                last_move_ = move_choice;
                ++number_of_moves_;  //update move counter and return
                return move_choice;
            }
            if (board.at(1).at(0) == 2 && board.at(0).at(2) == 0) { //if opponent is in middle left
                move_choice = {0, 2}; //take top right
                last_move_ = move_choice;
                ++number_of_moves_;
                return move_choice; //update move counter and return
            }
        }
        if (last_move_.first == 0 && last_move_.second == 2) { //if last move was top right
            if (board.at(0).at(1) == 2 && board.at(2).at(2) == 0) { //if opponent is in the middle top
                move_choice = {2, 2}; //take bottom right
                last_move_ = move_choice;
                ++number_of_moves_;  //update move counter and return
                return move_choice;
            }
            if (board.at(1).at(2) == 2 && board.at(0).at(0) == 0) { //if opponent is in the middle right
                move_choice = {0, 0}; //take top left
                last_move_ = move_choice;
                ++number_of_moves_;  //update move counter and return
                return move_choice;
            }
        }
         if (last_move_.first == 2 && last_move_.second == 0) { //if last move was bottom left
            if (board.at(1).at(0) == 2 && board.at(2).at(2) == 0) { //if opponent is in the middle left
                move_choice = {2, 2}; //take bottom right
                last_move_ = move_choice;
                ++number_of_moves_;  //update move counter and return
                return move_choice;
            }
            if (board.at(2).at(1) == 2 && board.at(0).at(0) == 0) { //if opponent is in the middle bottom
                move_choice = {0, 0}; //take top left
                last_move_ = move_choice;
                ++number_of_moves_;  //update move counter and return
                return move_choice;
            }
        }
        if (last_move_.first == 2 && last_move_.second == 2) { //if last move was bottom right
            if (board.at(1).at(2) == 2 && board.at(2).at(0) == 0) { //if opponent is in the middle right
                move_choice = {2, 0}; //take bottom left
                last_move_ = move_choice;
                ++number_of_moves_;  //update move counter and return
                return move_choice;
            }
            if (board.at(2).at(1) == 2 && board.at(0).at(2) == 0) { //if opponent is in the middle bottom
                move_choice = {0, 2}; //take top right
                last_move_ = move_choice;
                ++number_of_moves_;  //update move counter and return
                return move_choice;
            }
        }
        std::vector<std::pair<int, int>> possible_moves; //if no other moves available, create a vector to store all possible moves
        possible_moves.reserve(9);
        row_count = 0;
        column_count = 0;
        for (auto& row : board) {
            for (auto& column : row) {
                if (column == 0) {
                    possible_moves.push_back({row_count, column_count}); //iterate through the board to find and store the possible moves
                }
                ++column_count;
            }
            column_count = 0;
            ++row_count;
        }
        random_number = rand() % possible_moves.size();
        move_choice = possible_moves.at(random_number); //randomly select a move
        last_move_ = move_choice;
        ++number_of_moves_; //update move counter and return
        return move_choice;
    }
    std::vector<std::pair<int, int>> possible_moves; //same code as above, prevents the compiler from throwing an error about no return type in all control paths
    possible_moves.reserve(9);
    row_count = 0;
    column_count = 0;
    for (auto& row : board) {
        for (auto& column : row) {
            if (column == 0) {
                possible_moves.push_back({row_count, column_count}); //iterate through the board to find and store the possible moves
            }
            ++column_count;
        }
        column_count = 0;
        ++row_count;
    }
    random_number = rand() % possible_moves.size();
    move_choice = possible_moves.at(random_number); //randomly select a move
    last_move_ = move_choice;
    ++number_of_moves_; //update move counter and return
    return move_choice;
}

int TicTacToeAI::CheckWin(const std::vector<std::vector<int>>& board_) const {
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