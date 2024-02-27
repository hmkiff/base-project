#include "include/square.h"
#include <iostream>
// #include <array>

Square::Square()
{
    length = 6;
    position = {.x=0.0f, .y = 0.0f};
    setVertices();

}

Square::Square(int init_length, POS init_position)
{
    length = init_length;
    position = init_position;
    setVertices();
}

Square::~Square()
{
}

void Square::setLength(int newLength)
{
    length = newLength;
}

void Square::setPosition(POS newPosition)
{
    position = newPosition;
    setVertices();
}

void Square::updatePosition()
{
    position.x = position.x + velocity.x;
    position.y = position.y + velocity.y;
    setVertices();
}

void Square::setVelocity(VEL newVelocity)
{
    velocity.x = newVelocity.x;
    velocity.y = newVelocity.y;
}

int Square::getLength()
{
    return length;
}

POS Square::getPosition()
{
    return position;
}

void Square::printVertices()
{
    for(int i = 0; i < 10; i=i+2){
        std::cout << "x: " << vertices[i] << ", y: " << vertices[i+1] << std::endl;
    }
}

void Square::printPosition()
{
    std::cout << "x: " << position.x << ", y: " << position.y << std::endl;
}

void Square::unloadVertices(float array[]){
    for(int i = 0; i<10; i++){
        array[i] = vertices[i];
    }
}

bool Square::edgeDetect(float width, float height)
{
    bool hit = 0;
    for(int i=0; i<8; i=i+2){
        if((vertices[i] <= 0) || (vertices[i] >= width)){
            hit = 1;
            position.x = position.x - velocity.x;
            setVertices();
            velocity.x = -velocity.x;
        }
        else if((vertices[i+1] <= 0) || (vertices[i+1] >= height)){
            hit = 1;
            position.y = position.y - velocity.y;
            setVertices();
            velocity.y = -velocity.y;
        }
    }
    return hit;
}

// std::array<float, 8> Square::getVertices(float[] vertices,)
// {
//     return vertices;
// }

void Square::setVertices()
{
    vertices[0] = position.x - (length);
    vertices[1] = position.y - (length);
    vertices[2] = position.x + (length)+(length/2);
    vertices[3] = position.y - (length);
    vertices[4] = position.x + (length)+(length/2);
    vertices[5] = position.y + (length);
    vertices[6] = position.x - (length);
    vertices[7] = position.y + (length);
    vertices[8] = position.x - (length);
    vertices[9] = position.y - (length);
}