#ifndef GREMLIN_H
#define GREMLIN_H


class Gremlin
{
    public:
        Gremlin();
        virtual ~Gremlin();
        Gremlin(const Gremlin& other);
        Gremlin& operator=(const Gremlin& other);

    protected:

    private:
};

#endif // GREMLIN_H
