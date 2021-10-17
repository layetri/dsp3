#include "Headers/AllPassFilter.hpp"
#include <iostream>

AllPassFilter::AllPassFilter(Coefficients* input_coefficients, Buffer *input_buffer, Buffer* output_buffer) : Filter(input_coefficients, input_buffer, output_buffer) {
    
}

AllPassFilter::~AllPassFilter() {}

void AllPassFilter::process_DF1() {
    fir();
    iir();

    // output->write(0.167772 * (input->get() + output->getFromPast(8)) - input->getFromPast(8));
    // std::cout << output->get() << std::endl;
}

void AllPassFilter::process_DF2() {

}