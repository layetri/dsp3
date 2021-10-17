#include "Buffer.hpp"
#include "Filter.hpp"
#pragma once

struct AllPassFilter : public Filter {
    AllPassFilter(Coefficients*, Buffer* input_buffer, Buffer* output_buffer);
    ~AllPassFilter();

    void process_DF1();
    void process_DF2();

    Buffer* delay_line;
};