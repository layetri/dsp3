#include "Headers/Buffer.hpp"

Buffer::Buffer(int size) {
    data = new double[size];
    this->size = size;
    position = 0;
}

Buffer::~Buffer() {
    delete[] data;
}

void Buffer::wipe() {
    for(int i = 0; i < size; i++) {
        data[i] = 0.00;
    }
}

void Buffer::tick() {
    position = (position + 1) * (position < size - 1);
}

void Buffer::write(double sample) {
    data[position] = sample;
}

double Buffer::get() {
    return data[wrap(position)];
}

double Buffer::getFromPast(int places) {
    return data[wrap(position - places)];
}

int Buffer::wrap(int pos) {
    return ((0 <= pos && pos < size) * pos) +
           ((pos < 0) * (size + pos)) +
           ((pos > size) * (pos % size));
}