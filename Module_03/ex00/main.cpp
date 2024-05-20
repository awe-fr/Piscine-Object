#include "Car.hpp"

int main() {
    Car *car = new Car();

    std::cout << "---------------------------------" << std::endl;

    car->accelerate(200);
    car->stop();
    car->start();

    std::cout << "---------------------------------" << std::endl;

    car->accelerate(200);
    car->apply_force_on_brakes(50);
    car->accelerate(1);
    car->apply_emergency_brakes();

    std::cout << "---------------------------------" << std::endl;

    car->turn_wheel(200);
    car->turn_wheel(-2);
    car->straighten_wheels();
    car->turn_wheel(-15);

    std::cout << "---------------------------------" << std::endl;

    car->shift_gear_down();
    car->shift_gear_up();
    car->shift_gear_up();
    car->shift_gear_up();
    car->shift_gear_down();
    car->shift_gear_down();
    car->shift_gear_up();
    car->shift_gear_up();
    car->shift_gear_up();
    car->shift_gear_up();
    car->shift_gear_up();
    car->reverse();
    car->shift_gear_down();
    car->shift_gear_up();

    std::cout << "---------------------------------" << std::endl;

    car->start();
    car->stop();

    std::cout << "---------------------------------" << std::endl;

    delete car;
}