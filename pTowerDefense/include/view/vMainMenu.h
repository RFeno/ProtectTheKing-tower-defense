#ifndef VMAINMENU_H
#define VMAINMENU_H
#include <SFML/Graphics.hpp>

using namespace sf;

class vMainMenu
{
    public:
        //constructors
        vMainMenu();
        //methods
        void launchMenu(RenderWindow& window);
        void loadSprite();
        void loadFont();
        bool verifyImage();
        void drawEntities(RenderWindow& window);
        void InputHandler(Event event, RenderWindow &window);
        bool isSpriteClicked (Sprite &spr, RenderWindow &window);


        virtual ~vMainMenu();


    protected:

    private:



};

#endif // VMAINMENU_H
