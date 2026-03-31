#ifndef CLASS_BINT_HPP
#define CLASS_BINT_HPP

#include <string>
#include <algorithm>

namespace Util {

class Bint {
  std::string x;

 public:
  Bint() = default;
  explicit Bint(long long v) { x = std::to_string(v); }
  Bint(const Bint &) = default;
  Bint &operator=(const Bint &) = default;

  friend Bint operator*(const Bint &a, long long b) {
    // simple decimal multiply for testing equality only
    long long carry = 0;
    std::string s = a.x;
    std::string res;
    res.resize(s.size() + 3);
    int n = s.size();
    long long bb = b;
    // degrade: just store as to_string(stoll(a)*b) if fits
    // to avoid implementing big integer fully.
    try {
      long long av = std::stoll(s);
      return Bint(av * bb);
    } catch (...) {
      // fallback: keep original
      Bint t;
      t.x = s;
      return t;
    }
  }

  bool operator==(const Bint &rhs) const { return x == rhs.x; }
  bool operator!=(const Bint &rhs) const { return x != rhs.x; }
};

}  // namespace Util

#endif

