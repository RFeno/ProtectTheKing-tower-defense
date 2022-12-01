#ifndef VGAMEOVER_H
#define VGAMEOVER_H

#include <SFML/Graphics.hpp>

class vGameOver
{
    public:
        vGameOver(sf::RenderWindow &window);
        virtual ~vGameOver();

        ///DISPLAY
        void launchView();

        /**DRAW*/
        void drawEntities();

        /**LOAD AND CONFIGURE IMAGES*/
        void loadSprites();

        ///CHARGE IMAGES
        void chargeImages();

        ///TEXTURES
        sf::Texture tableEmptyTexture;
        sf::Texture headerFailedTexture;
        sf::Texture resetButtonTexture;


    protected:

    private:
};

#endif // VGAMEOVER_H
