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
    public:
        /**
         * @brief Checks wether the current object is touching a given ball
         * 
         * @param ball 
         * @return true if the object is colliding with the given ball
         * @return false otherwise
         */
        virtual bool checkCollision(Ball &ball);
};


/**
 * @brief Represents a ball trying to escape a room
 * 
 */
class Ball : Object {
    private:
        double radius; // Size of the ball
        constexpr static double DELTA = 0.01; // Time step to be used to calculate ball's movement
        std::array<double, 2> velocity(std::vector<Object> objects, double exit_x, double exit_y);
    public:
        bool checkCollision(Ball &ball) override { return 0; }
        void updatePosition(std::vector<Object> objects, double exit_x, double exit_y);
};


/**
 * @brief Represents an obstacle in the room
 * 
 */
class Obstacle : Object {
    public:
        bool checkCollision(Ball &ball) override { return 0; }
};

#endif