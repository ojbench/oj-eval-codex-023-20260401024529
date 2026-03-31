#ifndef SJTU_EXCEPTIONS_HPP
#define SJTU_EXCEPTIONS_HPP

#include <exception>

namespace sjtu {

class exception : public std::exception {
 public:
  const char *what() const noexcept override { return "sjtu::exception"; }
};

class index_out_of_bound : public exception {};
class invalid_iterator : public exception {};
class container_is_empty : public exception {};

}  // namespace sjtu

#endif

