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
};

#endif // VGAMEMANAGER_H
