#ifndef LINKEDPRIORITYQUEUE_H
#define LINKEDPRIORITYQUEUE_H

#include <iostream>
#include <stdexcept>
#include "PriorityQueue.h"
#include "LinkedQueue.h"

/*
Se modificó ligeramente el método 'print'
*/

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class LinkedPriorityQueue : public PriorityQueue<E> {
private:
    LinkedQueue<E> *queues;
    int priorities;
    int size;

public:
    LinkedPriorityQueue(int priorities) {
        if (priorities < 1)
            throw runtime_error("Invalid number of priorities.");
        queues = new LinkedQueue<E>[priorities];
        this->priorities = priorities;
        size = 0;
    }
    ~LinkedPriorityQueue() {
        delete [] queues;
    }
    void insert(E element, int priority) {
        if (priority < 0 || priority >= priorities)
            throw runtime_error("Invalid priority.");
        queues[priority].enqueue(element);
        size++;
    }
    E min() {
        if (size == 0)
            throw runtime_error("Queue is empty.");
        for (int pos = 0; pos < priorities; pos++)
            if (!queues[pos].isEmpty())
                return queues[pos].frontValue();
        throw runtime_error("Queue not found.");
    }
    E removeMin() {
        if (size == 0)
            throw runtime_error("Queue is empty.");
        for (int pos = 0; pos < priorities; pos++)
            if (!queues[pos].isEmpty()) {
                size--;
                return queues[pos].dequeue();
            }
        throw runtime_error("Queue not found.");
    }
    int getSize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
    void print() {
        for (int i = 0; i < priorities; i++) {
            if (i == 0) {
                cout << "Cola especial: ";
                queues[i].print();
            }
            else {
                cout << "Cola regular: ";
                queues[i].print();
            }
        }
    }
};

#endif // LINKEDPRIORITYQUEUE_H
