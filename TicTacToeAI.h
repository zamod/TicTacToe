#ifndef TicTacToeAi_H
#define TicTacToeAi_H

#include <vector>
#include <utility>

class TicTacToeAI {
 public:
  TicTacToeAI();
  TicTacToeAI(int difficulty, int player_number);
  std::pair<int, int> MakeMove(std::vector<std::vector<int>> board);
  int CheckWin(const std::vector<std::vector<int>>& board_) const;
  void SetDifficulty(int difficulty) {difficulty_ = difficulty;};
  void SetPlayerNumber(int player_number) {player_number_ = player_number;};
  int GetPlayerNumber() const {return player_number_;};
 private:
  int difficulty_; // 1 for crappy easy, 2 for medium, 3 for hard, 4 for perfect
  int player_number_;
  int number_of_moves_;
  std::pair<int, int> last_move_;
  const unsigned int kplayer_one_win_board_number_{1};
  const unsigned int kplayer_two_win_board_number_{8};
};

#endif