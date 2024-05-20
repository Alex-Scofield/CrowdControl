/**
 * @file object.hpp
 * @author Alex Scofield
 * @brief Header file defining the API for the objects used in the simulation
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include<array>
#include<vector>


// Forward declaration
class Ball;

/**
 * @brief Represents a general object in the simulation
 */
class Object {
    protected:
        double pos_x;
        double pos_y;
        Object() : pos_x(0), pos_y(0) {}
    public:
        /**
         * @brief Checks wether the current object is touching a given ball
         * 
         * @param ball 
         * @return true if the object is colliding with the given ball
         * @return false otherwise
         */
        //virtual bool checkCollision(Ball &ball);
};


/**
 * @brief Represents a ball trying to escape a room
 * 
 */
class Ball : Object {
    private:
        double radius; // Size of the ball
        constexpr static double DELTA = 10; // Time step to be used to calculate ball's movement
        std::array<double, 2> velocity(std::vector<Object> objects, double exit_x, double exit_y);
    public:
        Ball(double radius, double pos_x, double pos_y) : radius(radius) {this->pos_x = pos_x; this->pos_y = pos_y;}
        //bool checkCollision(Ball &ball) override { return 0; }
        void updatePosition(std::vector<Object> objects, double exit_x, double exit_y);

        double getRadius() { return radius; }
        double getPosX() { return pos_x; }
        double getPosY() { return pos_y; }
        void cr() { pos_x += 0.001; }
};


/**
 * @brief Represents an obstacle in the room
 * 
 */
class Obstacle : Object {
    public:
        //bool checkCollision(Ball &ball) override { return 0; }
};

#endif