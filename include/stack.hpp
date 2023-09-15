#ifndef __Stack_HPP__
#define __Stack_HPP__

#include "exception.hpp"

// DEFINICION

template <class T, int ARRAYSIZE = 1024>
class Stack {
 private:
  T data[ARRAYSIZE];
  int top;

  void copyAll(const Stack&);

 public:
  Stack();
  Stack(const Stack&);  // Constructor copia

  Stack& operator=(const Stack&);  // Operador de asignación

  bool isEmpty() const;
  bool isFull() const;

  void push(const T&);  // Elemento por referencia

  T pop();

  T getTop() const;
};

// IMPLEMENTACION
template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::copyAll(const Stack& s) {
  int i(0);
  while (i <= s.top) {
    data[i] = s.data[i];
    i++;
  }
  top = s.top;
}

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack() : top(-1) { }

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack(const Stack& s) {
  copyAll(s);
}

/* template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>::Stack(const Stack& s) {
  *this = s
} */

template <class T, int ARRAYSIZE>
Stack<T, ARRAYSIZE>& Stack<T, ARRAYSIZE>::operator=(const Stack& s) {
  copyAll(s);

  return *this;
}

template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isEmpty() const {
  return top == -1;
}

template <class T, int ARRAYSIZE>
bool Stack<T, ARRAYSIZE>::isFull() const {
  return top == ARRAYSIZE - 1;
}

template <class T, int ARRAYSIZE>
void Stack<T, ARRAYSIZE>::push(const T& e) {
  if (isFull()) {
    throw Exception("Desbordamiento de datos, push");
  }

  data[++top] = e;
}

template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::pop() {
  if (isEmpty()) {
    throw Exception("Insuficiencia de datos, pop");
  }

  return data[top--];
}

template <class T, int ARRAYSIZE>
T Stack<T, ARRAYSIZE>::getTop() const {
  if (isEmpty()) {
    throw Exception("Insuficiencia de datos, getTop");
  }

  return data[top];
}

#endif // __Stack_HPP__