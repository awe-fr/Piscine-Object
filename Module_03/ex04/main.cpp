#include "ILogger.hpp"
#include "vector"

int main () {
    ILogger *one = new Logger1("test.txt");
    ILogger *two = new Logger2(std::cout);
    std::vector<ILogger *> vec;
    vec.push_back(one);
    vec.push_back(two);
    for (int i = vec.size(); i > 0; i--) {
        vec[i - 1]->write("test");
    }
    vec[0]->write("string 1\n");
    vec[1]->write("string 2\n");
}