#pragma once

#include <string>

class Card {
  public:
    Card() {}
    Card(std::string term, std::string def, int points)
        : term{term}, def{def}, points{points} {}
    std::string getTerm();
    std::string getDef();
    int getPoints();
  private:
    std::string term;
    std::string def;
    int points;
};
