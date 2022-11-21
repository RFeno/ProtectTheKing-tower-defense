#ifndef VSTATE_H
#define VSTATE_H

//class vEnnemy;

class vState
{
    public:
        virtual ~vState();
        /*vState(const vState& other);
        vState& operator=(const vState& other);*/

        //mehtods
        /*virtual void anime()=0;

        virtual void attack()=0;
        virtual void dead()=0;

        //getters and setters
        void setVEnemy(vEnnemy *vEnemy)
        {
            this->vEnemy=vEnemy;
        }

        vEnnemy *getEnemy()
        {
            return vEnemy;
        }*/

    protected:
        //vEnnemy *vEnemy;

    private:
};

#endif // VSTATE_H
