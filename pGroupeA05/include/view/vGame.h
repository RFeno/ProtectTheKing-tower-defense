#ifndef VGAME_H
#define VGAME_H
#include <SFML/Graphics.hpp>

using namespace sf;

class vGame
{
    public:
        //constructors
        vGame();
        //methods
        void launchGame(RenderWindow& window);
        void InputHandler(Event event, RenderWindow &window);


        virtual ~vGame();

    protected:

    private:
};

#endif // VGAME_H
