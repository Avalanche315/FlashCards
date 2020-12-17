#include "cardmanager.h"

CardManager::CardManager()
{

}

Card CardManager::returnCurrentItem() const
{
  return cardList[index];
}

int CardManager::getIndex() const
{
    return index;
}

void CardManager::increaseIndex() {
    ++index;
}

void CardManager::setIndex(int index) {
    this->index = index;
}

int CardManager::getPoints() const {
    return points;
}

void CardManager::increasePoints() {
    ++points;
}

void CardManager::setPoints(int points) {
    this->points = points;
}

int CardManager::size() const {
    return cardList.size();
}

bool CardManager::empty() const {
    return cardList.empty();
}

std::vector<Card>& CardManager::getList() {
    return cardList;
}

void CardManager::push_back(Card& card) {
    cardList.push_back(card);
}

bool CardManager::deleteCard() {
    bool editStatus = false;
    if(!cardList.empty()) {
        if(!cardList.empty()) {
            auto index = cardList.begin() + getIndex();
            cardList.erase(index);
            editStatus = true;
        }
        editStatus = true;
    }
    return editStatus;
}
