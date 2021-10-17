#include "Headers/AllPassFilter.hpp"

AllPassFilter::AllPassFilter(Coefficients* input_coefficients, Buffer *input_buffer, Buffer* output_buffer) : Filter(input_coefficients, input_buffer, output_buffer) {
    delay_line = new Buffer(8);
    delay_line->wipe();
}

AllPassFilter::~AllPassFilter() {
    delete delay_line;
}

void AllPassFilter::process_DF1() {
    fir();
    iir();
}

void AllPassFilter::process_DF2() {
    double past = delay_line->getFromPast(8);

    delay_line->write(input->get() + c->a0 * past);
    output->write(c->a0 * delay_line->get() + c->a1 * past);

    delay_line->tick();
}