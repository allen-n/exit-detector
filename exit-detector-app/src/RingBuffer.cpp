#include "../inc/RingBuffer.h"

RingBuffer::RingBuffer(int bufferSize)
{
    this->bufferSize = bufferSize;
    this->mean = 0;
    this->idx = 0;
    this->buffer = new double[bufferSize];
    for (int i = 0; i < bufferSize; i++)
    {
        this->buffer[i] = 0;
    }
}

RingBuffer::~RingBuffer()
{
    delete[] this->buffer;
    // Better to crash than read garbage at this address
    this->buffer = nullptr;
}

void RingBuffer::addValue(double value)
{
    this->total -= this->buffer[this->idx];
    this->buffer[this->idx] = value;
    this->total += value;
    this->mean = this->total / (double)this->bufferSize;
    this->idx = (this->idx + 1) % this->bufferSize;
}

double RingBuffer::getMean()
{
    return this->mean;
}