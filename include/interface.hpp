#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include <string>

#include "queue.hpp"
#include "stack.hpp"

class Interface {
 private:
  Queue postfix;
  Queue infix;
  Stack stack;
  std::string result;
 public:
  void initialize();
  void receiveInfix(const Queue&);
  Queue convertInfix();
};

#endif  // __INTERFACE_H__