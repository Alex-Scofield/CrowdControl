/**
 * @file object.hpp
 * @author Alex Scofield
 * @brief Header file defining the API for the objects used in the simulation
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include<array>
#include<vector>
#include<memory>


// Forward declaration
class Ball;

/**
 * @brief Represents a general object in the simulation
 */
class Object {
    protected:
        double pos_x;
        double pos_y;
        double radius; // Size of the ball

    public:
        Object(double radius, double pos_x, double pos_y) : radius(radius) {this->pos_x = pos_x; this->pos_y = pos_y;}
        double getRadius() { return radius; }
        double getPosX() { return pos_x; }
        double getPosY() { return pos_y; }

        bool checkCollision(Ball &ball);
        void updateVelocityCollidee(Ball &ball, std::array<double, 2> &velocity);
};


/**
 * @brief Represents a ball trying to escape a room
 * 
 */
class Ball : public Object {
    private:
        constexpr static double DELTA = 0.03; // Time step to be used to calculate ball's movement
        std::array<double, 2> velocity(std::vector<std::shared_ptr<Object>> objects, double exit_x, double exit_y);

    public:
        Ball(double radius, double pos_x, double pos_y) : Object(radius, pos_x, pos_y) {}
        void updatePosition(std::vector<std::shared_ptr<Object>> objects, double exit_x, double exit_y);
        double getRadius() { return radius; }
        double getPosX() { return pos_x; }
        double getPosY() { return pos_y; }
};

#endif