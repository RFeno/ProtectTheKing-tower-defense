#include "Player.h"
#include <string>

using namespace std;

Player::Player(string name, int coins, int score): name(name),coins(coins),score(score)
{
    //ctor
}


Player::~Player()
{
    //dtor
}

Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->name=rhs.name;
    this->coins=rhs.coins;
    this->score=rhs.score;

    //assignment operator
    return *this;
}

void Player::addScore(int ScoreToAdd)
{
    setScore(score+ScoreToAdd);
}
/*
*this method add a new tower to list of tower of player if he have enough money
*if the purchase is completed, he debits the player
*/
void Player::buyTower(TypeOfTower type)
{

}
