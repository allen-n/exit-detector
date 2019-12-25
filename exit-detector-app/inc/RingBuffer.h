/*
Ring buffer utility class, created by Allen Nikka, December 25, 2019
*/

#ifndef RING_BUFFER_H
#define RING_BUFFER_H

class RingBuffer
{
public:
    /**
     * @param bufferSize Size of the buffer
     */
    RingBuffer(int bufferSize);
    ~RingBuffer();

    /**
     * Add a value to the ring buffer
     * @param value The value to add to the ring buffer
     */
    void addValue(double value);

    /**
     * Gets the current average value of the ring buffer
     * @returns The current mean of all values in the ring buffer
     */
    double getMean();

private:
    double *buffer; // Value storage
    int idx;        // Current index of ring buffer
    double total;   // Current sum of all values in buffer
    int bufferSize; // Size of the buffer
    double mean;    //Current mean value of buffer
};

#endif // !RING_BUFFER_H
