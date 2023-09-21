#include "../lib/parser.hpp"
namespace mylisp {

// void quote()

using mylisp::Atom;
using mylisp::ConsCell;

Parser::Parser(std::string src) : src_(src), index_(0) {}

char Parser::peek() { return src_[index_]; }

char Parser::next() { return src_[index_++]; }

void Parser::skip_whitespace() {
  while (index_ < src_.length() && isspace(src_[index_])) {
    ++index_;
  }
}

std::unique_ptr<ConsCell> Parser::parse_quote() {
  return std::make_unique<List>(std::make_unique<Atom>("quote"), parse());
}

std::unique_ptr<Atom> Parser::parse_atom() {
  // TODO: uninterned
  std::string atom = "";
  char c;
  do {
    c = next();
    atom += c;
  } while (isalnum(c) || c == '-' || c == '_');

  return std::make_unique<Atom>(atom);
}

std::unique_ptr<List> Parser::parse_list() {
  // TODO:
  return nullptr;
}

std::unique_ptr<ConsCell> Parser::parse() {
  skip_whitespace();

  char c = next();

  // Possible things to find are an atom, a "'", or a "(".
  if (c == '\'') {
    // Quote. Convert the ' with the atom 'quote'
    return parse_quote();
  } else if (c == '(') {
    // List
    return parse_list();
  } else {
    // Atom
    // TODO: could also be an error or smth like ')'?
    return parse_atom();
  }
}

} // namespace mylisp