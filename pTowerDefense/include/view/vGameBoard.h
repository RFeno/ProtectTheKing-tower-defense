#ifndef VGAMEBOARD_H
#define VGAMEBOARD_H

#include <SFML/Graphics.hpp>

using namespace sf;

class vGameBoard
{
    public:
        vGameBoard();
        virtual ~vGameBoard();
        vGameBoard(const vGameBoard& other);
        vGameBoard& operator=(const vGameBoard& other);

        void launchView(RenderWindow& window);
        void loadSprite();
        void loadFont();
        bool verifyImage();
        void drawEntities(RenderWindow& window);
        void InputHandler(Event event, RenderWindow &window);
        bool isSpriteClicked (Sprite &spr, RenderWindow &window);

    protected:

    private:
};

#endif // VGAMEBOARD_H
