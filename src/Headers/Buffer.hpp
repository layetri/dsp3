#pragma once

struct Buffer {
    Buffer(int size);
    ~Buffer();

    void wipe();
    void tick();

    double get();
    double getFromPast(int places);
    int wrap(int position);

    void write(double sample);

    private:
        double* data;

        int size;
        int position = 0;
};