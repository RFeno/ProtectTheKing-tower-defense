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
        Texture musiqueOnTexture;
        Texture musiqueOffTexture;
        Texture settingsTexture;
        Texture playTexture;

        Sprite bgSprite;
        Sprite ogreSprite;
        Sprite musiqueOnSprite;
        Sprite musiqueOffSprite;
        Sprite settingsSprite;
        Sprite playSprite;
        Sprite logoSprite;

        const int WIN_WIDTH = 1400;
        const int WIN_HEIGHT = 800;


    protected:

    private:
        sf::RenderWindow* windowFromMain;



};

#endif // VMAINMENU_H
