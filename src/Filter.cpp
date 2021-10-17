#include "Headers/Filter.hpp"

Filter::Filter(Coefficients* coefficients, Buffer* input_buffer, Buffer* output_buffer) {
    input = input_buffer;
    output = output_buffer;
    
    this->c = coefficients;
}

Filter::~Filter() {}

void Filter::fir() {
    float s = input->get() * c->a0 + input->getFromPast(n) * c->a1;

    output->write(s);
}

void Filter::iir() {
    float s = output->get() * c->b0 - output->getFromPast(n) * c->b1;
        
    output->write(s);
}

void Filter::tick() {
    output->tick();
}

double Filter::getSample() {
    return output->get();
}