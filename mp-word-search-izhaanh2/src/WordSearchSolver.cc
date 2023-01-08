#include "WordSearchSolver.hpp"

WordSearchSolver::WordSearchSolver(const std::vector<std::vector<char>>& puzzle) {
  size_t row = puzzle.size();
  size_t col = puzzle.at(0).size();
  puzzle_height_ = row;
  puzzle_width_ = col;
  puzzle_ = puzzle;
}

WordLocation WordSearchSolver::FindWord(const std::string& word) {
  WordLocation hor = FindWord(word, CheckDirection::kHorizontal);
  WordLocation vert = FindWord(word, CheckDirection::kVertical);
  WordLocation left = FindWord(word, CheckDirection::kLeftDiag);
  WordLocation right = FindWord(word, CheckDirection::kRightDiag);
  if (!hor.char_positions.empty()) {
    return hor;
  } else if (!vert.char_positions.empty()) {
    return vert;
  } else if (!right.char_positions.empty()) {
    return right;
  } else if (!left.char_positions.empty()) {
    return left;
  }
  return WordLocation{};
}

WordLocation WordSearchSolver::FindWord(const std::string& word, CheckDirection direction) {
  if (direction == CheckDirection::kHorizontal) {
    return HorCheck(word);
  } else if (direction == CheckDirection::kVertical) {
    return VertCheck(word);
  } else if (direction == CheckDirection::kLeftDiag) {
    return LeftCheck(word);
  } else if (direction == CheckDirection::kRightDiag) {
    return RightCheck(word);
  }
  return WordLocation{};
}

WordLocation WordSearchSolver::HorCheck(const std::string& word) {
  size_t temp_num = 0;
  std::vector<CharPositions> chars;
  for (size_t i = 0; i < puzzle_height_; ++i) {
    for (size_t j = 0; j < puzzle_width_; ++j) {
      if (puzzle_.at(i).at(j) == word.at(temp_num)) {
        CharPositions temp = {};
        temp.character = word.at(temp_num);
        temp.row = i;
        temp.col = j;
        chars.push_back(temp);
        temp_num++;
      } else {
        temp_num = 0;
        chars.clear();
      }
      if (temp_num == word.size()) {
        WordLocation ret;
        ret.word = word;
        ret.char_positions = chars;
        return ret;
      }
    }
  }
  return WordLocation{};
}

WordLocation WordSearchSolver::VertCheck(const std::string& word) {
  std::vector<CharPositions> chars;
  size_t temp_num = 0;
  for (size_t i = 0; i < puzzle_width_; ++i) {
    for (size_t j = 0; j < puzzle_height_; ++j) {
      if (puzzle_.at(j).at(i) == word.at(temp_num)) {
        CharPositions temp = {};
        temp.character = word.at(temp_num);
        temp.row = j;
        temp.col = i;
        chars.push_back(temp);
        temp_num++;
      } else {
        temp_num = 0;
        chars.clear();
      }
      if (temp_num == word.size()) {
        WordLocation ret;
        ret.word = word;
        ret.char_positions = chars;
        return ret;
      }
    }
  }
  return WordLocation{};
}

WordLocation WordSearchSolver::LeftCheck(const std::string& word) {
  unsigned int temp_num = 0;
  std::vector<CharPositions> chars;
  for (size_t i = 0; i < puzzle_height_; ++i) {
    for (size_t j = 0; j < puzzle_width_; ++j) {
      if (puzzle_.at(i).at(j) == word.at(temp_num)) {
        for (size_t row = i, col = j; col != std::numeric_limits<size_t>::max() && row < puzzle_height_; ++row, --col) {
          if (puzzle_.at(row).at(col) == word.at(temp_num)) {
            CharPositions temp = {};
            temp.character = word.at(temp_num);
            temp.row = row;
            temp.col = col;
            chars.push_back(temp);
            temp_num++;
          } else {
            temp_num = 0;
            chars.clear();
          }
          if (temp_num == word.size()) {
            WordLocation ret;
            ret.word = word;
            ret.char_positions = chars;
            return ret;
          }
        }
      }
      temp_num = 0;
      chars.clear();
    }
  }
  return WordLocation{};
}

WordLocation WordSearchSolver::RightCheck(const std::string& word) {
  unsigned int temp_num = 0;
  std::vector<CharPositions> chars;
  for (size_t i = 0; i < puzzle_height_; ++i) {
    for (size_t j = 0; j < puzzle_width_; ++j) {
      if (puzzle_.at(i).at(j) == word.at(temp_num)) {
        for (size_t row = i, col = j; row < puzzle_height_ && col < puzzle_width_; ++row, ++col) {
          if (puzzle_.at(row).at(col) == word.at(temp_num)) {
            CharPositions temp = {};
            temp.character = word.at(temp_num);
            temp.row = row;
            temp.col = col;
            chars.push_back(temp);
            temp_num++;
          } else {
            temp_num = 0;
            chars.clear();
          }
          if (temp_num == word.size()) {
            WordLocation ret;
            ret.word = word;
            ret.char_positions = chars;
            return ret;
          }
        }
      }
      else {
        temp_num = 0;
        chars.clear();
      }
    }
  }
  return WordLocation{};
}

bool WordSearchSolver::LocationInBounds(size_t row, size_t col) const {
  return ((row < puzzle_height_) && (col < puzzle_width_));
}