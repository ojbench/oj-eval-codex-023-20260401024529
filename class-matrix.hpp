#ifndef DIAMOND_MATRIX_HPP
#define DIAMOND_MATRIX_HPP

#include <vector>

namespace Diamond {

template <typename _Td> class Matrix {
  size_t n_rows = 0, n_cols = 0;
  std::vector<std::vector<_Td>> data;
  struct RowProxy {
    std::vector<_Td> &row;
    _Td &operator[](const size_t &pos) { return row[pos]; }
  };
  struct ConstRowProxy {
    const std::vector<_Td> &row;
    const _Td &operator[](const size_t &pos) const { return row[pos]; }
  };

public:
  Matrix() = default;
  Matrix(const size_t &r, const size_t &c) : n_rows(r), n_cols(c), data(r, std::vector<_Td>(c)) {}
  Matrix(const size_t &r, const size_t &c, const _Td &fill) : n_rows(r), n_cols(c), data(r, std::vector<_Td>(c, fill)) {}
  Matrix(const Matrix &) = default;
  Matrix &operator=(const Matrix &) = default;
  ~Matrix() = default;

  inline const size_t &RowSize() const { return n_rows; }
  inline const size_t &ColSize() const { return n_cols; }

  RowProxy operator[](const size_t &k) { return RowProxy{data[k]}; }
  ConstRowProxy operator[](const size_t &k) const { return ConstRowProxy{data[k]}; }

  friend bool operator==(const Matrix &_a, const Matrix &_b) {
    if (_a.n_rows != _b.n_rows || _a.n_cols != _b.n_cols) return false;
    for (size_t i = 0; i < _a.n_rows; ++i)
      for (size_t j = 0; j < _a.n_cols; ++j)
        if (_a.data[i][j] != _b.data[i][j]) return false;
    return true;
  }
};

} // namespace Diamond

#endif

