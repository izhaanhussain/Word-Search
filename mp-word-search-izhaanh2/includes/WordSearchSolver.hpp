#ifndef WORDSEARCHSOLVER_HPP
#define WORDSEARCHSOLVER_HPP

#include <cstddef>
#include <string>
#include <vector>
#include <limits>

#include "WordLocation.hpp"

enum class CheckDirection { kHorizontal, kVertical, kLeftDiag, kRightDiag };

class WordSearchSolver {
public:
  WordSearchSolver(const std::vector<std::vector<char>>& puzzle);
  WordLocation FindWord(const std::string& word);
  WordLocation FindWord(const std::string& word, CheckDirection direction);
  WordLocation HorCheck(const std::string& word);
  WordLocation VertCheck(const std::string& word);
  WordLocation LeftCheck(const std::string& word);
  WordLocation RightCheck(const std::string& word);

private:
  bool LocationInBounds(size_t row, size_t col) const;
  std::vector<std::vector<char>> puzzle_;
  size_t puzzle_height_;
  size_t puzzle_width_;
};
#endif