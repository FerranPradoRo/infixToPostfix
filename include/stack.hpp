#ifndef __Stack_HPP__
#define __Stack_HPP__

#include "exception.hpp"

#define ARRAYSIZE 1024

// DEFINICION


class Stack {
 private:
  char data[ARRAYSIZE];
  int top;

  void copyAll(const Stack&);

 public:
  Stack();
  Stack(const Stack&);  // Constructor copia

  Stack& operator=(const Stack&);  // Operador de asignación

  bool isEmpty() const;
  bool isFull() const;

  void push(const char&);  // Elemento por referencia

  char pop();

  char getTop() const;
};

// IMPLEMENTACION

void Stack::copyAll(const Stack& s) {
  int i(0);
  while (i <= s.top) {
    data[i] = s.data[i];
    i++;
  }
  top = s.top;
}


Stack::Stack() : top(-1) { }


Stack::Stack(const Stack& s) {
  copyAll(s);
}

/* 
Stack::Stack(const Stack& s) {
  *this = s
} */


Stack& Stack::operator=(const Stack& s) {
  copyAll(s);

  return *this;
}


bool Stack::isEmpty() const {
  return top == -1;
}


bool Stack::isFull() const {
  return top == ARRAYSIZE - 1;
}


void Stack::push(const char& e) {
  if (isFull()) {
    throw Exception("Desbordamiento de datos, push");
  }

  data[++top] = e;
}


char Stack::pop() {
  if (isEmpty()) {
    throw Exception("Insuficiencia de datos, pop");
  }

  return data[top--];
}


char Stack::getTop() const {
  if (isEmpty()) {
    throw Exception("Insuficiencia de datos, getTop");
  }

  return data[top];
}

#endif // __Stack_HPP__