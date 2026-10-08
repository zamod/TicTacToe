#include <iostream>
#include <limits> //for cin error handling

#include "TicTacToeFunctions.h"
#include "TicTacToeAI.h"

int main() {
    TicTacToeBoard game_board;
    TicTacToeAI perfect_player_one;
    int win_condition{0};
    int player_number{2};
    char user_answer{'z'};
    std::cout << "Do you want to play a game? (y/n): ";
    while ((!(std::cin >> user_answer)) && (user_answer != 'y' && user_answer != 'n')) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "That isn't a valid answer. Once again, do you want to play a game? (y/n): ";
    }
    switch (user_answer) {
        case 'y':
            std::cout << "Then let the game begin!\n";
            break;
        case 'n':
            std::cout << "Aww, I really wanted to play a game. Too bad, you lose.\n";
            std::cin.get();
            return 0;
    }
    while (!win_condition) {
        game_board.AIMakeAMove(perfect_player_one.MakeMove(game_board.GetBoard()), perfect_player_one.GetPlayerNumber());
        game_board.PrintBoard();
        game_board.PlayerMakeAMove(player_number);
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
    if (win_condition == 3) {
        std::cout << "It's a draw.\n";
    }
    return 1;
    //TODO: Logic to start the game against the perfect AI
    /* working code sans AI
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
    */
}