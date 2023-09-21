#ifndef MYLISP_CONS_HPP
#define MYLISP_CONS_HPP

#include <memory>
#include <string>

namespace mylisp {

class ConsCell {
public:
  ~ConsCell() = default;
};

class Atom : public ConsCell {
public:
  std::string value;

  Atom(std::string value) : value(value) {}
  ~Atom() = default;
};

class List : public ConsCell {
public:
  std::unique_ptr<ConsCell> car_;
  std::unique_ptr<ConsCell> cdr_;

  List();
  // Pointers instead of rvalue references avoids slicing problem
  List(std::unique_ptr<ConsCell> car);
  List(std::unique_ptr<ConsCell> car, std::unique_ptr<ConsCell> cdr);
  ~List() = default;

  // Copy/move ctors/assignment
  List(const List &other) = delete;
  List(List &&other) = delete;
  List &operator=(const List &other) = delete;
  List &operator=(List &&other) = delete;
};

} // namespace mylisp

#endif