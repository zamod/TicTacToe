#include <algorithm>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <utility>

#include "TicTacToeFunctions.h"

TicTacToeBoard::TicTacToeBoard() : board_{{0,0,0}, {0,0,0}, {0,0,0}} {}

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
    for (const auto& row : board_) {
        for (const auto& column : row) {
            std::cout << "[";
            if (column == kplayer_one_1_and_X_.first) { //if this row is equal to 1 (i.e. player one is here)
                std::cout << kplayer_one_1_and_X_.second; //print X
            } else if (column == kplayer_two_2_and_O_.first) { //if equal to 2 (i.e. is claimed by player two)
                std::cout << kplayer_two_2_and_O_.second; //print O
            } else { //if nobody has claimed the square
                std::cout << " "; //print a blank
            }
            std::cout << "]";
        }
        std::cout << "\n"; //new line after completing a row
    }
}

void TicTacToeBoard::PlayerMakeAMove(int player_number) {
    int move_square_number{1};
    int player_move_choice{0};
    std::vector<int> possible_moves; //stores possible moves for later lookup, using a vector since it's only a max of 9 items to search through
    while (player_move_choice != 1 && player_move_choice != 2 && player_move_choice != 3 && player_move_choice != 4 && player_move_choice != 5 && player_move_choice != 6 && player_move_choice != 7 && player_move_choice != 8 && player_move_choice != 9) {
        for (const auto& row : board_) {
            for (const auto& column : row) {
                std::cout << "[";
                if (column == kplayer_one_1_and_X_.first) {
                    std::cout << " ";
                } else if (column == kplayer_two_2_and_O_.first) { //if equal to 2 (i.e. is claimed by player two)
                    std::cout << " ";
                } else { //if nobody has claimed the square
                    std::cout << move_square_number;
                    possible_moves.push_back(move_square_number);
                }
                ++move_square_number;
                std::cout << "]";
            }
            std::cout << "\n";
        }
        std::cout << "Which spot would you like to choose? ";
        while((!(std::cin >> player_move_choice)) || (std::find(possible_moves.begin(), possible_moves.end(), player_move_choice) == possible_moves.end())) { //if user enters a non-integer or enters an invalid move square number
            std::cout << "Invalid move choice. Please enter a valid move: ";
            std::cin.clear(); //clear error flag that cin threw
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard all the extra input, if any
        }
    }
    switch (player_move_choice) { //translates the 1-9 choice into the proper vector cooridinates
        case 1:
            board_.at(0).at(0) = player_number;
            break;
        case 2:
            board_.at(0).at(1) = player_number;
            break;
        case 3:
            board_.at(0).at(2) = player_number;
            break;
        case 4:
            board_.at(1).at(0) = player_number;
            break;
        case 5:
            board_.at(1).at(1) = player_number;
            break;
        case 6:
            board_.at(1).at(2) = player_number;
            break;
        case 7:
            board_.at(2).at(0) = player_number;
            break;
        case 8:
            board_.at(2).at(1) = player_number;
            break;
        case 9:
            board_.at(2).at(2) = player_number;
            break;
    }
}
