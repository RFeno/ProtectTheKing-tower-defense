#include "Player.h"
#include <string>
#include <TowerEarth.h>
#include <TowerIce.h>
#include <TowerIron.h>
#include <TowerSand.h>

using namespace std;

Player::Player()
{
    //ctor
    this->name="name";
    this->coins = 0;
    this->score = 0;
}

Player::Player(string name, int coins, int score): name(name),coins(coins),score(score)
{
    //ctor
}


Player::~Player()
{
    //dtor
}

/*Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}*/

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
