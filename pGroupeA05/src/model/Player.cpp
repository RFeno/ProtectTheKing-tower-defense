#include "Player.h"
#include "FireSpell.h"
#include "AcidCloudSpell.h"
#include "LightningSpell.h"
#include <string>

using namespace std;

Player::Player(int coins, int score): coins(coins),score(score)
{
    //ctor
}

Player::Player(const Player& other): coins(other.coins),score(other.score), acidNumber(other.acidNumer), firNumber(other.fireNumber), lightningNumber(other.lightningNumber), numberOfEnemyKilled(other.numberOfEnemyKilled)
{
    //copy ctor
    //clone because AIP
    for(Spell *spell:other.listOfSpells)
    {
        listOfSpells.push_back(spell->clone());
    }
}

Player::~Player()
{
    //dtor
    for(Spell *spell:listOfSpells)
    {
        delete spell;
    }
}

Player& Player::operator=(const Player& rhs)
{
    if (this == &rhs) return *this; // handle self assignment

    this->coins=rhs.coins;
    this->score=rhs.score;
    this->acidNumber=rhs.acidNumber;
    this->fireNumber=rhs.fireNumber;
    this->lightningNumber=rhs.lightningNumber;
    this->numberOfEnemyKilled=rhs.numberOfEnemyKilled;

    for(Spell* spell: listOfSpells)
    {
        delete spell;
    }

    this->listOfSpells.clear();

    //clone because AIP
    for(Spell *spell:rhs.listOfSpells)
    {
        listOfSpells.push_back(spell->clone());
    }

    //assignment operator
    return *this;
}

/** this method add score to player score */
void Player::addScore(int ScoreToAdd)
{
    setScore(score+ScoreToAdd);
}

/** if the type of spell is in the list of player, use the spell and after remove */
bool Player::activeSpell(TypeOfSpell type,vector<Enemies*> listOfEnemies)
{
    if(useAndRemoveSpell(type,listOfEnemies))
    {
        return true;
    }
    return false;
}

/** use the spell to cause damage and then remove the spell in the list of spell of player*/
bool Player::useAndRemoveSpell(TypeOfSpell type,vector<Enemies*> listOfEnemies)
{
    int index = searchSpellByType(type);

    if(index!=-1)
    {
        ///USE
        listOfSpells[index]->attackEnemies(listOfEnemies);

        ///REMOVE
        Spell *tmp = *(listOfSpells.begin() + index);
        listOfSpells.erase(listOfSpells.begin()+index);
        delete tmp;

        return true;
    }
    else
    {
        cout << "this spell is not in the list" << endl;
    }
    return false;
}

/** return the index of the first type of spell asked */
int Player::searchSpellByType(TypeOfSpell type)
{
    int index = -1;

    for(int i=0;i<(int)listOfSpells.size();i++)
    {
        switch(type)
        {
            case fire:
                if(dynamic_cast<FireSpell*>(listOfSpells[i]))
                {
                    return i;
                }
                break;
            case acidCloud:
                if(dynamic_cast<AcidCloudSpell*>(listOfSpells[i]))
                {
                    return i;
                }
                break;
            case lightning:
                if(dynamic_cast<LightningSpell*>(listOfSpells[i]))
                {
                    return i;
                }
            break;
        }
    }

    return index;
}

/** add a new spell to list */
void Player::buySpell(TypeOfSpell type)
{
    switch(type)
    {
        case acidCloud:
            listOfSpells.push_back(new AcidCloudSpell());
            break;
        case fire:
            listOfSpells.push_back(new FireSpell());
            break;
        case lightning:
            listOfSpells.push_back(new LightningSpell());
            break;
    }
}

/** update the number of each spells in stock */
void Player::updateSpellsNumber()
{
    acidNumber = 0;
    fireNumber = 0;
    lightningNumber = 0;
    if(getSpells().size() != 0)
    {
        for(Spell* spell : getSpells())
        {
            if(dynamic_cast<AcidCloudSpell*>(spell))
            {
               acidNumber++;
            }
            if(dynamic_cast<FireSpell*>(spell))
            {
               fireNumber++;
            }
            if(dynamic_cast<LightningSpell*>(spell))
            {
               lightningNumber++;
            }
        }
    }
}

/** clear the list of spells */
void Player::clearListOfSpells()
{
    for(Spell* spell: listOfSpells)
    {
        delete spell;
    }
    listOfSpells.clear();
}

/** return a clone of player */
Player* Player::clone()const
{
    return new Player(*this);
}
