#ifndef TicTacToeAi_H
#define TicTacToeAi_H

#include <vector>
#include <utility>

class TicTacToeAI {
 public:
  TicTacToeAI();
  TicTacToeAI(int difficulty, int player_number);
  std::pair<int, int> MakeMove(const std::vector<std::vector<int>>& board) const;
  void SetDifficulty(difficulty) {difficulty_ = difficulty;};
  void SetPlayerNumber(player_number) {player_number_ = player_number;};
  int GetPlayerNumber() const {return player_number_;};
 private:
  int difficulty_; // 1 for crappy easy, 2 for medium, 3 for hard, 4 for perfect
  int player_number_;
  int number_of_moves_;
}

#endif