#ifndef VGAMEMANAGER_H
#define VGAMEMANAGER_H

#include <SFML/Graphics.hpp>

class vGameManager
{
    public:
        vGameManager();
        virtual ~vGameManager();
        void launchGame();
        void launchMainMenu();
        void launchGameBoard();
        void resetView();

    protected:

    private:
        sf::RenderWindow *window;
        const int WIN_WIDTH = 1400;
        const int WIN_HEIGHT = 800;
};

#endif // VGAMEMANAGER_H
