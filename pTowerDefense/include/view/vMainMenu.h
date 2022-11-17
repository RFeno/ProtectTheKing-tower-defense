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



};

#endif // VMAINMENU_H
