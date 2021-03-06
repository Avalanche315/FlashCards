#pragma once

#include "Card.h"
#include <vector>

class CardManager
{
public:
    CardManager();
    Card returnCurrentItem() const;
    int getIndex() const;
    void increaseIndex();
    void setIndex(int index);
    int getPoints() const;
    void increasePoints();
    void setPoints(int points);
    int size() const;
    std::vector<Card>& getList();
    bool empty() const;
    void push_back(Card& card);
    bool deleteCard();
    bool isLastElement();
private:
    std::vector<Card> cardList{};
    int index{};
    int points{};
};


