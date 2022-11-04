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
//    switch(type)
//    {
//        case earth:
//
//            if(coins-type >=0)
//            {
//                listOfTower.push_back(new TowerEarth);
//                setCoins(coins-=type);
//            }
//            break;
//
//        case ice:
//
//            if(coins-type >=0)
//            {
//                listOfTower.push_back(new TowerIce);
//                setCoins(coins-=type);
//            }
//
//            break;
//
//        case iron:
//
//            if(coins-type >=0)
//            {
//                listOfTower.push_back(new TowerIron);
//                setCoins(coins-=type);
//            }
//
//            break;
//
//        case sand:
//            if(coins-type >=0)
//            {
//                listOfTower.push_back(new TowerSand);
//                setCoins(coins-=type);
//            }
//            break;
//    }
}
