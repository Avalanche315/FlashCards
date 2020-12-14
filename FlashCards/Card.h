#pragma once

#include <string>

class Card {
  public:
    Card() {}
    Card(std::string term, std::string def)
        : term{term}, def{def} {}
    std::string getTerm();
    std::string getDef();
  private:
    std::string term;
    std::string def;
};
