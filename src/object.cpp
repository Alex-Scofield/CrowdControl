#include "object.hpp"
#include <math.h>

std::array<double, 2> Ball::velocity(std::vector<std::shared_ptr<Object>> objects, double exit_x, double exit_y) {
    double x = exit_x - pos_x;
    double y = exit_y - pos_y;
    double norm = sqrt(x * x + y * y);
    return {x / norm, y / norm};
}


bool Object::checkCollision(Ball &ball) {
    double x = pos_x - ball.getPosX();
    double y = pos_y - ball.getPosY();
    return sqrt(x * x + y * y) <= radius + ball.getRadius();
}


void Object::updateVelocityCollidee(Ball &ball, std::array<double, 2> &velocity) {
    if(!checkCollision(ball)) {
        return;
    }

    double x = pos_x - ball.getPosX();
    double y = pos_y - ball.getPosY();
    double mag = sqrt(velocity[0] * velocity[0] + velocity[1] * velocity[1]);

    velocity[0] += (-x) * mag / sqrt(x * x + y * y);
    velocity[1] += (-y) * mag / sqrt(x * x + y * y);
}


void Ball::updatePosition(std::vector<std::shared_ptr<Object>> objects, double exit_x, double exit_y) {
    std::array<double, 2> v = velocity(objects, exit_x, exit_y);

    for(int i = 0; i < objects.size(); i++) {
        std::shared_ptr<Object> obj = objects[i];
        if(obj->getPosX() != getPosX() || obj->getPosY() != getPosY()) {
            obj->updateVelocityCollidee(*this, v);
        }
    }
    pos_x += DELTA * v[0];
    pos_y += DELTA * v[1];
}
