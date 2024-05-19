/**
 * @file object.hpp
 * @author Alex Scofield
 * @brief Header file defining the API for the objects used in the simulation
 */

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include<array>
#include<vector>


/** CONSTANTS **/
double const WIDTH = 100;
double const HEIGHT = 100;

double const EXIT_X = 100 / 2;
double const EXIT_WIDTH = WIDTH / 4;
double const EXIT_Y = 100;


/**
 * @brief Represents a general object in the simulation
 */
class Object {
    protected:
        double pos_x;
        double pos_y;
    public:
        virtual bool checkCollision(Ball ball);
};


class Ball : Object {
    private:
        static double const DELTA = 0.01;
        std::array<double, 2> velocity(std::vector<Object> objects);
    public:
        bool checkCollision(Ball ball) override;
        void updatePosition(std::vector<Object> objects);
};


class Obstacle : Object {
    public:
        bool checkCollision(Ball ball) override;
};


#endif