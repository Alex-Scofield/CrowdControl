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
        std::vector<Ball> balls;
        std::vector<CircleObstacle> circle_obstacles;
        int niter; // Current step
        static const int ITER_MAX = 1000; // Maximum number of iterations in the simulation

    public:
        constexpr static double WIDTH = 100;
        constexpr static double HEIGHT = 100;
        constexpr static double EXIT_X = 100 / 2;
        constexpr static double EXIT_WIDTH = WIDTH / 4;
        constexpr static double EXIT_Y = 100;
        
        /**
         * @brief Construct a new Model object
         * 
         * @param nballs Number of balls to be placed
         * @param nobstacles Number of obstacles to be placed
         */
        Model(int nballs, int nobstacles);

        /**
         * @brief Get the balls concerned by the simulation
         * 
         * @return std::vector<Ball> 
         */
        std::vector<Ball> getBalls() { return balls; }

        /**
         * @brief Get the circle obstacles
         * 
         * @return std::vector<CircleObstacle> 
         */
        std::vector<CircleObstacle> getCircleObstacles() { return circle_obstacles; }

        /**
         * @brief Returns all of the model's objects
         * 
         * @return std::vector<Object*> 
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