#include <bits/stdc++.h>
#include "deque.hpp"
#include "class-integer.hpp"
#include "class-matrix.hpp"
#include "class-bint.hpp"

static std::mt19937 rng(123456);
static const int MAX_N = 5000;

template <typename Ans, typename Test>
bool isEqual(Ans &ans, Test &test) {
  if (ans.size() != test.size()) return false;
  if (ans.empty()) return true;
  for (size_t i = 0; i < ans.size(); ++i) {
    if (rng() % 2) {
      if (ans[i] != test[i]) return false;
    } else {
      if (ans.at(i) != test.at(i)) return false;
    }
  }
  if (ans.empty() != test.empty() || ans.front() != test.front() || ans.back() != test.back()) return false;
  return true;
}

template <typename Ans, typename Test>
void randnumFill(Ans &ans, Test &test, int n = 20000) {
  for (int i = 0; i < n; ++i) {
    int x = (int)rng();
    if (rng() % 2) {
      ans.push_back(x);
      test.push_back(x);
    } else {
      ans.push_front(x);
      test.push_front(x);
    }
  }
}

bool pushTest() {
  std::deque<int> ans; sjtu::deque<int> deq;
  for (int i = 0; i < MAX_N; ++i) {
    int x = (int)rng();
    if (rng() % 2) { deq.push_front(x); ans.push_front(x); }
    else { deq.push_back(x); ans.push_back(x); }
  }
  return isEqual(ans, deq);
}
bool popTest() {
  std::deque<long long> ans; sjtu::deque<long long> deq; randnumFill(ans, deq, MAX_N * 3);
  for (int i = 0; i < MAX_N; ++i) {
    if (rng() % 2) { deq.pop_front(); ans.pop_front(); }
    else { deq.pop_back(); ans.pop_back(); }
  }
  return isEqual(ans, deq);
}
bool insertTest() {
  std::deque<int> ans, ans2, ans3; sjtu::deque<int> deq, deq2, deq3;
  for (int i = 0; i < 100; ++i) {
    int x = (int)rng(); int pos = ans.empty() ? 0 : (int)(rng() % ans.size());
    if (rng() % 2) { deq.insert(deq.begin() + pos, x); ans.insert(ans.begin() + pos, x); }
    else { deq.insert(deq.end() - pos, x); ans.insert(ans.end() - pos, x); }
  }
  ans2.insert(ans2.begin(), 0x5d); ans3.insert(ans3.end(), 93);
  deq2.insert(deq2.begin(), 0x5d); deq3.insert(deq3.end(), 93);
  if (!isEqual(ans2, deq2) || !isEqual(ans3, deq3)) return false;
  return isEqual(ans, deq);
}
bool iteratorTest() {
  std::deque<int> ans; sjtu::deque<int> deq; randnumFill(ans, deq, MAX_N * 2);
  auto ai = ans.begin() + ans.size() / 2; auto di = deq.begin() + deq.size() / 2;
  for (int i = 0; i < MAX_N; ++i) { if (rng() % 2) { ai++; di++; } else { ai--; di--; } if (*ai != *di) return false; }
  for (int i = 0; i < MAX_N; ++i) {
    std::deque<int>::iterator A[] = {ans.begin(), ans.end()}; sjtu::deque<int>::iterator D[] = {deq.begin(), deq.end()};
    int off = (int)(rng() % (ans.size() / 3 + 1));
    A[0] += off; A[1] -= off; D[0] += off; D[1] -= off;
    for (int j = 0; j < 2; ++j) if (*A[j] != *D[j]) return false;
    if ((A[1] - A[0]) != (D[1] - D[0])) return false;
  }
  return true;
}
bool eraseTest() {
  std::deque<int> ans; sjtu::deque<int> deq; randnumFill(ans, deq, MAX_N * 2);
  for (int i = 0; i < 100; ++i) {
    int pos = (int)(rng() % ans.size());
    if (rng() % 2) { deq.erase(deq.begin() + pos); ans.erase(ans.begin() + pos); }
    else { deq.erase(deq.end() - 1 - pos); ans.erase(ans.end() - 1 - pos); }
  }
  return isEqual(ans, deq);
}

int main() {
  std::vector<std::pair<const char*, bool(*)()>> tests = {
      {"Testing push...", &pushTest},
      {"Testing pop...", &popTest},
      {"Testing insert...", &insertTest},
      {"Testing iterator...", &iteratorTest},
      {"Testing erase...", &eraseTest}
  };
  bool error = false;
  for (auto &t : tests) {
    printf("%-40s", t.first);
    bool ok = t.second();
    if (ok) printf("Passed\n"); else { printf("Failed !!!\n"); error = true; }
  }
  if (error) printf("\nUnfortunately, you failed in this test\n");
  else printf("\nCongratulations, your deque passed all the tests!\n");
  return 0;
}
