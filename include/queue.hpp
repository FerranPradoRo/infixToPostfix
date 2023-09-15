#ifndef __QUEUE_H__
#define __QUEUE_H__

#include "exception.hpp"

#define ARRAYSIZE 1024

// Definicion

class Queue {
 private:
  char data[ARRAYSIZE];
  int frontPos;
  int endPos;

  void copyAll(const Queue&);

 public:
  Queue();
  Queue(const Queue&);

  Queue& operator= (const Queue&);

  bool isEmpty() const;
  bool isFull() const;

  void enqueue(const char&);

  char dequeue();

  char getFront() const;
};

// Implementacion


void Queue::copyAll(const Queue& s) {
  int i(0);
  while (i <= s.endPos) {
    data[i] = s.data[i];
    i++;
  }
  endPos = s.endPos;
}


Queue::Queue() : frontPos(0), endPos(ARRAYSIZE - 1) {}


Queue::Queue(const Queue& q) {
  copyAll(q);
}


Queue& Queue::operator=(const Queue& q) {
  copyAll(q);
  return *this;
}


bool Queue::isEmpty() const {
  return (frontPos == endPos + 1) || (frontPos == 0 && endPos == ARRAYSIZE - 1);
}


bool Queue::isFull() const {
  return (frontPos == endPos + 2) ||
         (frontPos == ARRAYSIZE - 1 && endPos == 1) ||
         (frontPos == ARRAYSIZE - 2 && endPos == 0);
}


void Queue::enqueue(const char& e) {
  if (isFull()) {
    throw Exception("Desbordamiento de datos, enqueue");
  }

  data[endPos = (++endPos == ARRAYSIZE ? 0 : endPos)] = e;
}


char Queue::dequeue() {
  if (isEmpty()) {
    throw Exception("Insuficiencia de datos, dequeue");
  }

  char result(data[frontPos]);

  if (++frontPos == ARRAYSIZE) {
    frontPos = 0;
  }

  return result;
}


char Queue::getFront() const {
 if(isEmpty()){
  throw Exception("Insuficiencia de datos, getFront");
 }

 return data[frontPos];
}

#endif  // __QUEUE_H__