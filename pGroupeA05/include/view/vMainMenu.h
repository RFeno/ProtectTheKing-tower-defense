#ifndef VMAINMENU_H
#define VMAINMENU_H
#include <SFML/Graphics.hpp>

using namespace sf;

class vMainMenu
{
    public:
        //constructors
        vMainMenu(RenderWindow& window);

        //methods
        void launchMenu();
        void loadSprite();
        bool verifyImage();
        void drawEntities();
        void InputHandler(Event event);
        bool isSpriteClicked (Sprite &sprf);

        virtual ~vMainMenu();

        Texture bgTexture;
        Texture logoTexture;
        Texture playTexture;

        Sprite bgSprite;
        Sprite playSprite;
        Sprite logoSprite;


    protected:

    private:
        sf::RenderWindow* windowFromMain;



};

#endif // VMAINMENU_H
