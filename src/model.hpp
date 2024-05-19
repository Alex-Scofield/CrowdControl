#ifndef MODEL_HPP
#define MODEL_HPP

#include<vector>
#include "object.hpp"


/**
 * @brief Implements a simulation of a crowd exiting a room
 * 
 */
class Model {
    private:
        static double const WIDTH = 100;
        static double const HEIGHT = 100;
        static double const EXIT_X = 100 / 2;
        static double const EXIT_WIDTH = WIDTH / 4;
        static double const EXIT_Y = 100;

        std::vector<Ball> balls;
        std::vector<Obstacle> obstacles;
        int niter = 0; // Current step
        static const int ITER_MAX = 1000; // Maximum number of iterations in the simulation

    public:
        /**
         * @brief Returns all of the objects (balls and obstacles) present in the simulation
         * 
         * @return std::vector<Object> 
         */
        std::vector<Object> getObjects();

        /**
         * @brief Performs a step in the simulation
         * 
         * @return true if the step completed the simulation 
         * (niter exceeded iter_max or if all balls have escaped)
         * @return false otherwise
         */
        bool step();

        /**
         * @brief Runs the simulation
         * 
         * @return int Numbeer of iterations needed to complete the simulation
         */
        int runSimulation();
};

#endif