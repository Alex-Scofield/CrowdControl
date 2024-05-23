/**
 * @file main.cpp
 * @author Alex Scofield
 * @brief Entry point for the simulation
 */


#include "model.hpp"
#include "graphics.hpp"

int main(int argc, char** argv) {
    Model model = Model(80, 5);
    graphics(argc, argv, model);
    return 0;
}