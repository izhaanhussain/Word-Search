// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Student Name                    Environment : ubuntu:bionic               //
//  Date ......: 2021/02/10                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "CharPositions.hpp"
#include "WordLocation.hpp"
#include "WordSearchSolver.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////
std::vector<std::vector<char>> none_puzzle{{'p', 'h', 'u', 'e', 'a', 'o', 'u', 'm'},
                                        {'a', 'e', 'v', 'h', 'x', 'l', 'l', 'o'},
                                        {'c', 'l', 'l', 'h', 'l', 'h', 'm', 'o'},
                                        {'a', 'l', 'u', 'l', 'e', 't', 'l', 'm'},
                                        {'t', 'o', 'u', 'l', 't', 't', 'u', 'm'},
                                        {'t', 'l', 'l', 't', 'x', 'o', 'l', 'm'},
                                        {'t', 'o', 'u', 'h', 't', 'o', 'u', 'h'}};
WordSearchSolver wss(none_puzzle);
/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("True == True", "") {   
    REQUIRE(true == true); 
}

TEST_CASE("horNone", "") { 
    REQUIRE(wss.FindWord("izhaan", CheckDirection::kHorizontal).char_positions.empty()); 
}

TEST_CASE("vertNone", "") { 
    REQUIRE(wss.FindWord("izhaan", CheckDirection::kVertical).char_positions.empty()); 
}

TEST_CASE("leftNone", "") { 
    REQUIRE(wss.FindWord("izhaan", CheckDirection::kLeftDiag).char_positions.empty()); 
}

TEST_CASE("rightNone", "") { 
    REQUIRE(wss.FindWord("izhaan", CheckDirection::kRightDiag).char_positions.empty()); 
}

TEST_CASE("horYes", "") { 
    REQUIRE(!wss.FindWord("xllo", CheckDirection::kHorizontal).char_positions.empty()); 
}

TEST_CASE("vertYes", "") { 
    REQUIRE(!wss.FindWord("lulu", CheckDirection::kVertical).char_positions.empty()); 
}

TEST_CASE("leftYes", "") { 
    REQUIRE(!wss.FindWord("hello", CheckDirection::kLeftDiag).char_positions.empty()); 
}

TEST_CASE("rightYes", "") { 
    REQUIRE(!wss.FindWord("etlh", CheckDirection::kRightDiag).char_positions.empty()); 
}

TEST_CASE("allNone", "") { 
    REQUIRE(wss.FindWord("izhaan").char_positions.empty()); 
}

TEST_CASE("allYes", "") { 
    REQUIRE(!wss.FindWord("hello").char_positions.empty()); 
}
/////////////////////////////////////////////////////////////////////////////////////////////