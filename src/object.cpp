#include<object.hpp>

std::array<double, 2> Ball::velocity(std::vector<Object> objects, double exit_x, double exit_y) {
    return {0, 0};
}


void Ball::updatePosition(std::vector<Object> objects, double exit_x, double exit_y) {
    std::array<double, 2> v = velocity(objects);
    pos_x = v[0] * DELTA;
    pos_y = v[1] * DELTA;
}