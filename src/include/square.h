#ifndef _SQUARE_H_
#define _SQUARE_H_

// #include <array>

struct POS{
    float x;
    float y;
};

struct VEL{
    float x;
    float y;
};


class Square {
public:

    float vertices[10];

    // Constructors
    Square(); // Default constructor
    Square(int init_length, POS init_position); // Parameterized constructor

    // Destructor
    ~Square();

    // Functions
    void setLength(int newLength);

    void setPosition(POS newPosition);

    void updatePosition();

    void setVelocity(VEL newVeloctity);

    void setVertices();

    int getLength();

    POS getPosition();

    void printVertices();

    void printPosition();

    void unloadVertices(float array[]);

    bool edgeDetect(float width, float height);

    // std::array<float, 8> getVertices();

private:
    int length;
    POS position;
    VEL velocity;

};

#endif