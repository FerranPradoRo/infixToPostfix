#ifndef __CONVERTER_H__
#define __CONVERTER_H__

#include <string>

#include "queue.hpp"
#include "stack.hpp"

class Converter {
 private:
  Queue<char> postfix;
  Queue<char> infix;
  Stack<char> stack;

 public:
  void initialize();
  void setInfix(const Queue<char>&);
  Queue<char> getPostfix();
};

#endif  // __CONVERTER_H__