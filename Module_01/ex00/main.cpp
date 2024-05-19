#include "Worker.hpp"
#include "Shovel.hpp"
#include "Hammer.hpp"

int main() {
    Worker *w1 = new Worker();
    Worker *w2 = new Worker();
    Tool *s1 = new Hammer();
    Tool *s2 = new Shovel();

    std::cout << "---------------------------" << std::endl;

    w1->grab(s1);
    w1->grab(s2);
    w1->use(0);
    w1->print();
    w2->use(1);
    w2->grab(s1);
    w1->print();
    w2->print();

    std::cout << "---------------------------" << std::endl;

    delete w1;
    delete w2;
    delete s1;
    delete s2;

    std::cout << "---------------------------" << std::endl;

    Worker *w3 = new Worker();
    Worker *w4 = new Worker();
    Worker *w5 = new Worker();
    Workshop *s3 = new Workshop();
    Workshop *s4 = new Workshop();

    std::cout << "---------------------------" << std::endl;

    s3->executeWorkDay();
    s3->hire(w3);
    s4->hire(w3);
    s3->hire(w4);
    s3->hire(w5);
    s3->executeWorkDay();

    std::cout << "---------------------------" << std::endl;

    s3->fire(w4);
    s3->executeWorkDay();
    w4->work();
    s3->fire(w3);
    w3->work();

    std::cout << "---------------------------" << std::endl;

    delete w3;
    delete w4;
    delete w5;
    delete s3;
    delete s4;
}