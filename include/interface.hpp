#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <string>

#include "queue.hpp"
#include "stack.hpp"

class Interface {
 private:
  Queue<char> postfix;
  Queue<char> infix;
  Stack<char> stack;
  std::string result;
 public:
  void initialize();
  void setInfix(const Queue<char>&);
  Queue<char> convertInfix();
};

#endif  // __INTERFACE_H__