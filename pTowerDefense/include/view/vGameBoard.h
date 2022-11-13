#ifndef VGAMEBOARD_H
#define VGAMEBOARD_H

#include <SFML/Graphics.hpp>
#include "Enemies.h"
#include "Game.h"

using namespace sf;

class vGameBoard
{
    public:

        const int WALK_SPEED = 1;

        vGameBoard();
        virtual ~vGameBoard();
        vGameBoard(const vGameBoard& other);
        vGameBoard& operator=(const vGameBoard& other);



        Texture mapTexture;
        Texture pauseTexture;
        //Texture musiqueOnTexture;
        Texture acideCloudTexture;
        Texture lightningTexture;
        Texture fireTexture;
        Texture enemyTexture;

        Sprite mapSprite;
        Sprite pauseSprite;
        //Sprite musiqueOnSprite;
        Sprite acideCloudSprite;
        Sprite lightningSprite;
        Sprite fireSprite;
        Sprite enemySprite;

        void launchView(RenderWindow& window);
        void loadSprite();
        void loadFont();
        bool verifyImage();
        void drawEntities(RenderWindow& window);
        void InputHandler(Event event, RenderWindow &window);
        bool isSpriteClicked (Sprite &spr, RenderWindow &window);

        //methods
        void launchGame();
        void animationEnemyWalk();
        void displayEnd();
        bool setTower(int y, int x, int type);
        bool setTower(int y, int x, Tower* t);
        void activeFireSpell();
        void activeLightningSpeel();
        void activeCloudSpell();

    protected:

    private:
        Game game;
        std::vector<Sprite*> listOfEnemies;
};

#endif // VGAMEBOARD_H
