#ifndef TicTacToeFunctions_H
#define TicTacToeFunctions_H

#include <vector>

class TicTacToeBoard {
 public:
  TicTacToeBoard();
  int CheckWin() const;
  std::vector<std::vector<int>> GetBoard() const {return board_};
 private:
  std::vector<std::vector<int>> board_;
}

int CheckWin(const std::vector<std::vector<int>>& board);
void PlayTicTacToe();
void MainMenu();

#endif