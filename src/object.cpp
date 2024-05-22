#include "object.hpp"
#include <math.h>

std::array<double, 2> Ball::velocity(std::vector<Object> objects, double exit_x, double exit_y) {
    double x = exit_x - pos_x;
    double y = exit_y - pos_y;
    double norm = sqrt(x * x + y * y);
    return {x / norm, y / norm};
}


void Ball::updatePosition(std::vector<Object> objects, double exit_x, double exit_y) {
    std::array<double, 2> v = velocity(objects, exit_x, exit_y);
    pos_x += 20* DELTA * v[0];
    pos_y += 20* DELTA * v[1];
}
