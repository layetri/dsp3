#include <iostream>

struct Test {
    Test() {};
    ~Test() {};

    static void assertEqual(float value, int place) {
        double assertion[] = {0.167772, 0, 0, 0, 0, 0, 0, 0, -0.971853, 0, 0, 0, 0, 0, 0, 0, -0.16305, 0, 0, 0, 0, 0, 0, 0, -0.0273552};

        if(place < sizeof(assertion)) {
            std::cout << "Output as desired: " << (int(value * 100000) == int(assertion[place] * 100000)) << std::endl << " [" << value << ", " << assertion[place] << "]" << std::endl;
        } else {
            std::cout << "Assertion failed: invalid data." << std::endl;
        }
    }
};