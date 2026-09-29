#ifndef TicTacToeAi_H
#define TicTacToeAi_H

#include <vector>

class TicTacToeAI {
 public:
  std::vector<int> MakeMove(const std::vector<std::vector<int>>& board) const;
 private:
  int difficulty_; // 1 for crappy easy, 2 for medium, 3 for hard, 4 for perfect
}

#endif