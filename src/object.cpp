#include "object.hpp"

std::array<double, 2> Ball::velocity(std::vector<Object> objects, double exit_x, double exit_y) {
    return {0, 0};
}


void Ball::updatePosition(std::vector<Object> objects, double exit_x, double exit_y) {
    //std::array<double, 2> v = velocity(objects, exit_x, exit_y);
    
    pos_x += 10;
    pos_y += 10;
}
