#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include <stdexcept>
#include <iostream>
#include "Node.h"
#include "Queue.h"

/*
Se modificó ligeramente el método 'print'
*/

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class LinkedQueue : public Queue<E> {
private:
    Node<E> *front;
    Node<E> *back;
    int size;

public:
    LinkedQueue() {
        front = back = new Node<E>();
        size = 0;
    }
    ~LinkedQueue() {
        clear();
        delete front;
    }
    void enqueue(E element) {
        back = back->next = new Node<E>(element);
        size++;
    }
    E dequeue() {
        if (size == 0)
            throw runtime_error("Queue is empty.");
        E result = front->next->element;
        Node<E> *temp = front->next;
        front->next = temp->next;
        delete temp;
        size--;
        if (size == 0)
            back = front;
        return result;
    }
    E frontValue() {
        if (size == 0)
            throw runtime_error("Queue is empty.");
        return front->next->element;
    }
    void clear() {
        while(front->next != nullptr){
            Node<E> *temp = front->next;
            front->next = temp->next;
            delete temp;
        }
        back = front;
        size = 0;
    }
    bool isEmpty() {
        return size == 0;
    }
    int getSize() {
        return size;
    }
    void print() {
        cout << "{ ";
        for (Node<E> *temp = front->next; temp != nullptr; temp = temp->next)
            cout << temp->element->getNombre() << " ";
        cout << "}" << endl;
    }
};

#endif // LINKEDQUEUE_H
