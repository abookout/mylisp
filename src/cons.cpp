#include "../lib/cons.hpp"

namespace mylisp {

// Empty list
List::List() : car_(nullptr), cdr_(nullptr) {}

// List with one element
List::List(std::unique_ptr<ConsCell> car)
    : car_(std::move(car)), cdr_(nullptr) {}

// List with two elements
List::List(std::unique_ptr<ConsCell> car, std::unique_ptr<ConsCell> cdr)
    : car_(std::move(car)), cdr_(std::move(cdr)) {}

} // namespace mylisp