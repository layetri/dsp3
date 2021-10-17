#include "Headers/AllPassFilter.hpp"
#include "Headers/Buffer.hpp"
#include "Headers/Test.hpp"

#define OUTPUT_LENGTH 25

void generateImpulse(Buffer* buffer) {
    buffer->wipe();
    buffer->write(1.00);
}

int main() {
    int cycle = 0;
    
    Buffer impulse(OUTPUT_LENGTH);
    Buffer output(OUTPUT_LENGTH);

    generateImpulse(&impulse);
    output.wipe();

    Coefficients coefficients(0.167772160000, -1.000000000000, 1.000000000000, -0.167772160000);
    AllPassFilter allpass(&coefficients, &impulse, &output);

    while(cycle < OUTPUT_LENGTH) {
        allpass.process_DF2();

        Test::assertEqualResponse(output.get(), cycle);
        
        impulse.tick();
        output.tick();

        cycle++;
    }
}