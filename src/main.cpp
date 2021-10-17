#include <iostream>
#include "Headers/AllPassFilter.hpp"
#include "Headers/Buffer.hpp"
#include "Headers/Test.hpp"

#define OUTPUT_LENGTH 25

void generateImpulse(Buffer* buffer) {
    for(int i = 0; i < OUTPUT_LENGTH; i++) {
        buffer->write(double(i == 0));
        buffer->tick();
    }

    buffer->tick();
}

void generateZeroes(Buffer *buffer) {
    for (int i = 0; i < OUTPUT_LENGTH; i++) {
        buffer->write(0.00); 
        buffer->tick();
    }
    buffer->tick();
}

int main() {
    int cycle = 0;
    
    Buffer impulse(OUTPUT_LENGTH);
    Buffer output(OUTPUT_LENGTH);

    generateImpulse(&impulse);
    generateZeroes(&output);

    Coefficients coefficients(0.167772160000, -1.000000000000, 1.000000000000, -0.167772160000);
    AllPassFilter allpass(&coefficients, &impulse, &output);

    while(cycle < OUTPUT_LENGTH) {
        allpass.process_DF1();

        Test::assertEqual(output.get(), cycle);
        
        impulse.tick();
        output.tick();

        cycle++;
    }
}