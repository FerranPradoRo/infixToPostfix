#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "exception.hpp"

// Definicion

template <class T, int ARRAYSIZE = 1024>
class Queue {
 private:
  T data[ARRAYSIZE];
  int frontPos;
  int endPos;

  void copyAll(const Queue&);

 public:
  Queue();
  Queue(const Queue&);

  Queue& operator=(const Queue&);

  bool isEmpty() const;
  bool isFull() const;

  void enqueue(const T&);

  T dequeue();

  T getFront() const;
};

// Implementacion

template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::copyAll(const Queue& s) {
  int i(0);
  while (i <= s.endPos) {
    data[i] = s.data[i];
    i++;
  }
  endPos = s.endPos;
}

template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue() : frontPos(0), endPos(ARRAYSIZE - 1) {}

template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>::Queue(const Queue& q) {
  copyAll(q);
}

template <class T, int ARRAYSIZE>
Queue<T, ARRAYSIZE>& Queue<T, ARRAYSIZE>::operator=(const Queue& q) {
  copyAll(q);
  return *this;
}

template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isEmpty() const {
  return (frontPos == endPos + 1) || (frontPos == 0 && endPos == ARRAYSIZE - 1);
}

template <class T, int ARRAYSIZE>
bool Queue<T, ARRAYSIZE>::isFull() const {
  return (frontPos == endPos + 2) ||
         (frontPos == ARRAYSIZE - 1 && endPos == 1) ||
         (frontPos == ARRAYSIZE - 2 && endPos == 0);
}

template <class T, int ARRAYSIZE>
void Queue<T, ARRAYSIZE>::enqueue(const T& e) {
  if (isFull()) {
    throw Exception("Desbordamiento de datos, enqueue");
  }

  data[endPos = (++endPos == ARRAYSIZE ? 0 : endPos)] = e;
}

template <class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::dequeue() {
  if (isEmpty()) {
    throw Exception("Insuficiencia de datos, dequeue");
  }

  T result(data[frontPos]);

  if (++frontPos == ARRAYSIZE) {
    frontPos = 0;
  }

  return result;
}

template <class T, int ARRAYSIZE>
T Queue<T, ARRAYSIZE>::getFront() const {
 if(isEmpty()){
  throw Exception("Insuficiencia de datos, getFront");
 }

 return data[frontPos];
}

#endif  // __QUEUE_H__