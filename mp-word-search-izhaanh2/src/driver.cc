#include <iostream>
#include <string>
#include <vector>

#include "WordSearchSolver.hpp"

int main() {
  std::vector<std::vector<char>> puzzle{{'p', 'h', 'u', 'e', 'a', 'o', 'u', 'm'},
                                        {'a', 'e', 'v', 'h', 'x', 'l', 'l', 'o'},
                                        {'c', 'l', 'l', 'h', 'l', 'h', 'm', 'o'},
                                        {'a', 'l', 'u', 'l', 'e', 't', 'l', 'm'},
                                        {'t', 'o', 'u', 'l', 't', 't', 'u', 'm'},
                                        {'t', 'l', 'l', 't', 'x', 'o', 'l', 'm'},
                                        {'t', 'o', 'u', 'h', 't', 'o', 'u', 'h'}};
  WordSearchSolver wss(puzzle);
  // std::cout << wss.FindWord("hello", CheckDirection::kHorizontal);
  // std::cout << wss.FindWord("hello");
  std::cout << wss.FindWord("hello", CheckDirection::kLeftDiag);
}