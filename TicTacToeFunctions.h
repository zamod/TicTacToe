#ifndef TicTacToeFunctions_H
#define TicTacToeFunctions_H

#include <vector>

class TicTacToeBoard {
 public:
  TicTacToeBoard();
  int CheckWin() const;
  std::vector<std::vector<int>> GetBoard() const {return board_};
  void PrintBoard() const;
 private:
  std::vector<std::vector<int>> board_;
  const char kplayer_one_X_{'X'};
  const char kplayer_two_O_{'O'};
  const unsigned int kplayer_one_win_board_number_{1};
  const unsigned int kplayer_two_win_board_number_{8};
}

int CheckWin(const std::vector<std::vector<int>>& board);
void PlayTicTacToe();
void MainMenu();

#endif