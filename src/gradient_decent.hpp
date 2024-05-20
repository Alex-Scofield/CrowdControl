#ifndef GRADIENT_DESCENT_HPP
#define GRADIENT_DESCENT_HPP

#include <vector>
#include <array>

/**
 * @brief Procedure that finds the optimal placements of a given amount of obstacles to facilitate exit of a crowd
 * 
 * @param ball_count Amount of balls constituting the crowd
 * @param obstacle_placements Reference to the placements of the obstacles
 */
void gradientDescent(int ball_count, std::vector<std::array<double, 2>> &obstacle_placements);

#endif