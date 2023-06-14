#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#define DEFAULT_MAX_SIZE 100

#include "List.h"
#include <stdexcept>

/*
Se creó un nuevo insert (inserto)
*/

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class ArrayList : public List<E> {
protected:
    E *elements;
    int max;
    int size;
    int pos;

    void expand() {
        E *temp = new E[max*2];
        for (int i = 0; i < size; i++)
            temp[i] = elements[i];
        delete [] elements;
        elements = temp;
        this->max = max * 2;
    }

public:
    ArrayList(int max = DEFAULT_MAX_SIZE) {
        if (max < 1) {
            throw runtime_error("Invalid max size.");
        }
        elements = new E[max];
        this->max = max; //Al tener ambos el mismo nombre, de esta manera se asigna el local al global
        size = 0;
        pos = 0;
    }
    ~ArrayList() {
        delete [] elements;
    }
    void insert(E element){
        if (size == max)
            expand();
        for (int i = size; i > pos; i--) {
            elements[i] = elements[i-1];
        }
        elements[pos] = element;
        size++;
    }
    void inserto(E element){
        if (size == max)
            expand();
        elements[pos] = element;
    }
    void append(E element) {
        if (size == max)
            expand();
        elements[size] = element;
        size++;
    }
    E remove() {
        if (size == 0) {
            throw runtime_error("List is empty.");
        }
        if (pos == size) {
            throw runtime_error("No current element.");
        }
        E result = elements[pos];
        for (int i = pos; i < size - 1; i++) {
            elements[i] = elements[i+1];
        }
        size--;
        return result;
    }
    void clear() {
        size = pos = 0;
        //delete [] elements;
        //elements = new E[max];
    }
    E getElement() {
        if (size == 0) {
            throw runtime_error("List is empty.");
        }
        if (pos == size) {
            throw runtime_error("No current element.");
        }
        return elements[pos];
    }
    void goToStart() {
        pos = 0;
    }
    void goToEnd() {
        pos = size;
    }
    void goToPos(int pos) {
        if (pos < 0 || pos > size) {
            throw runtime_error("Invalid index.");
        }
        this->pos = pos;
    }
    void next() {
        if (pos < size) {
            pos ++;
        }
    }
    void previous() {
        if (pos > 0) {
            pos--;
        }
    }
    bool isEmpty() {
        return size == 0;
    }
    bool atStart() {
        return pos == 0;
    }
    bool atEnd() {
        return pos == size;
    }
    int getPos() {
        return pos;
    }
    int getSize() {
        return size;
    }
    int indexOf(E element) {
        for (int i = 0; i < size ; i++)
            if (elements[i] == element)
                return i;
        return -1;
    }
    bool contains(E element) {
        for (int i = 0; i < size; i++)
            if (elements[i] == element)
                return true;
        return false;
    }
    void extend(List<E> *L) {
        int tempPos = L->getPos();
        for (int i = 0; i < L->getSize(); i++){
            if (size == max)
                expand();
            L->goToPos(i);
            elements[size] = L->getElement();
            size++;
        }
        L->goToPos(tempPos);
    }
    bool equals(List<E> *L) {
        int tempPos = L->getPos();
        if (size != L->getSize()) {
            L->goToPos(tempPos);
            return false;
        }
        for (int i = 0; i < size; i++) {
            L->goToPos(i);
            if (elements[i] != L->getElement()) {
                L->goToPos(tempPos);
                return false;
            }
        }
        L->goToPos(tempPos);
        return true;
    }
    void print() {
        int tempPos = pos;
        cout << "{ ";
        for (goToStart(); !atEnd(); next()){
            cout << getElement() << " ";
        }
        cout << "}" << endl;
        pos = tempPos;
    }
};

#endif // ARRAYLIST_H
