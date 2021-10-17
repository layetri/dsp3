#include "Headers/Buffer.hpp"
#include <iostream>

Buffer::Buffer(int size) {
    data = new double[size];
    this->size = size;
    position = 0;
}

Buffer::~Buffer() {
    delete[] data;
}

void Buffer::tick() {
    position = (position + 1) * (position < size);
}

void Buffer::write(double sample) {
    data[position] = sample;
}

double Buffer::get() {
    return data[wrap(position)];
}

double Buffer::getFromPast(int places) {
    // std::cout << wrap(position - places) << ": " << data[wrap(position - places)] << std::endl;
    return data[wrap(position - places)];
}

int Buffer::wrap(int pos) {
    return ((0 < pos < size) * pos) +
           ((pos < 0) * (size + pos)) +
           ((pos > size) * (pos % size));
}