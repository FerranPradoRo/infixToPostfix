#include "converter.hpp"

#include <iostream>

using namespace std;

void Converter::initialize() {
  char op;
  do {
    Queue<char> expressionQueue;
    string expression;

    fflush(stdin);
    cout << "Ingrese la expresion: ";
    getline(cin, expression);

    int i(0);
    while (i < expression.length()) {
      expressionQueue.enqueue(expression[i]);
      i++;
    }

    setInfix(expressionQueue);

    postfix = getPostfix();

    cout << "Expresión convertida: ";
    while (!postfix.isEmpty()) {
      cout << postfix.dequeue();
    }

    cout << "\n\n¿Desea convertir otra expresión? S/N: ";
    cin >> op;
    op = toupper(op);
    cout << '\n';

  } while (op == 'S');
}

void Converter::setInfix(const Queue<char>& q) {
  infix = q;
}

Queue<char> Converter::getPostfix() {
  
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