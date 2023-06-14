#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


template <typename E>
class PriorityQueue {
private:
    void operator =(const PriorityQueue &other) {}
    PriorityQueue(const PriorityQueue &other) {}

public:
    PriorityQueue() {}
    virtual ~PriorityQueue() {}
    virtual void insert(E element, int priority) =0;
    virtual E min() =0;
    virtual E removeMin() =0;
    virtual int getSize() =0;
    virtual bool isEmpty() =0;
    virtual void print() =0;
};

#endif // PRIORITYQUEUE_H
