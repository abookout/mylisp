#ifndef MYLISP_PARSER_HPP
#define MYLISP_PARSER_HPP

#include "../lib/cons.hpp"

namespace mylisp {
class Parser {
public:
  Parser(std::string src);
  ~Parser() = default;

  Parser(const Parser &) = delete;
  Parser(Parser &&) = delete;
  Parser &operator=(const Parser &) = delete;
  Parser &operator=(Parser &&) = delete;

  // Parse a lisp expression as a string, returning a Cons containing the parsed
  // expression (i.e. the AST) on success
  std::unique_ptr<ConsCell> parse();

private:
  std::string src_;
  int index_;

  char peek();
  char next();
  void skip_whitespace();

  // Assumes '(' has already been consumed
  std::unique_ptr<List> parse_list();
  std::unique_ptr<Atom> parse_atom();

  // Returns (quote <expr>)
  std::unique_ptr<ConsCell> parse_quote();
};
} // namespace mylisp

#endif