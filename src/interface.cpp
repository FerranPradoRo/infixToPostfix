#include "interface.hpp"

#include <iostream>

using namespace std;

void Interface::initialize() {
  char op;
  do {
    fflush(stdin);
    Queue<char> expressionQueue;
    string expression;
    cout << "Ingrese la expresion: ";
    getline(cin, expression);

    int i(0);
    while (i < expression.length()) {
      expressionQueue.enqueue(expression[i]);
      i++;
    }

    receiveInfix(expressionQueue);

    /* while (!infix.isEmpty()) {
      cout << " a-";
      cout << " infix: " << infix.dequeue();
    } */

    // cout << '\n';

    /* while (!expressionQueue.isEmpty()) {
      cout << " expressionQueue: " << expressionQueue.dequeue();
    } */

    postfix = convertInfix();

    while (!postfix.isEmpty()) {
      cout << postfix.dequeue();
    }

    cout << "\n¿Desea convertir otra expresión? S/N: ";
    cin >> op;
    op = toupper(op);
  } while (op == 'S');
}

void Interface::receiveInfix(const Queue<char>& q) { infix = q; }

Queue<char> Interface::convertInfix() {
  Queue<char> postfix;
  while (!infix.isEmpty()) {
    if (infix.getFront() == '(') {
      stack.push(infix.getFront());
    } else if (infix.getFront() == ')') {
      while (stack.getTop() != '(') {
        postfix.enqueue(stack.pop());
      }
      stack.pop();
    } else if (infix.getFront() == '*' || infix.getFront() == '/') {
      while (!stack.isEmpty() &&
             (stack.getTop() == '*' || stack.getTop() == '/' ||
              stack.getTop() == '^')) {
        postfix.enqueue(stack.pop());
      }
      stack.push(infix.getFront());
    } else if (infix.getFront() == '+' || infix.getFront() == '-') {
      while (!stack.isEmpty() &&
             (stack.getTop() == '+' || stack.getTop() == '-' ||
              stack.getTop() == '*' || stack.getTop() == '/' ||
              stack.getTop() == '^')) {
        postfix.enqueue(stack.pop());
      }
      stack.push(infix.getFront());
    } else if (infix.getFront() == '^') {
      stack.push(infix.getFront());
    } else {
      postfix.enqueue(infix.getFront());
    }
    infix.dequeue();
  }
  while (!stack.isEmpty()) {
    postfix.enqueue(stack.pop());
  }
  return postfix;
}
