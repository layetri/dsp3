#include "Buffer.hpp"
#pragma once
#define DELAY 8

struct Coefficients {
    Coefficients(float i_a0, float i_a1, float i_b0, float i_b1) {
        a0 = i_a0;
        a1 = i_a1;
        b0 = i_b0;
        b1 = i_b1;
    };

    float a0, a1, b0, b1;
};

struct Filter {
    Filter(Coefficients*, Buffer*, Buffer*);
    ~Filter();

    void fir();
    void iir();

    void tick();

    double getSample();

    Buffer* input;
    Buffer* output;

    Coefficients* c;

    int n = DELAY;
};
