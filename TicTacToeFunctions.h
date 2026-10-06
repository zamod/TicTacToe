#ifndef TicTacToeFunctions_H
#define TicTacToeFunctions_H

#include <vector>
#include <utility>

class TicTacToeBoard {
 public:
  TicTacToeBoard();
  int CheckWin() const;
  std::vector<std::vector<int>> GetBoard() const {return board_};
  void PrintBoard() const;
  void PlayerMakeAMove(int player_number);
 private:
  std::vector<std::vector<int>> board_;
  const std::pair<int, char> kplayer_one_1_and_X_{1, 'X'};
  const std::pair<int, char> kplayer_two_2_and_O_{2, 'O'};
  const unsigned int kplayer_one_win_board_number_{1};
  const unsigned int kplayer_two_win_board_number_{8};
}

int CheckWin(const std::vector<std::vector<int>>& board);
void PlayTicTacToe();
void MainMenu();

#endif