// taken from cs4128

#include <algorithm>
#include <sys/wait.h>
#include <vector>

using std::max;
using std::min;
using std::vector;

/**
  supports in log(n) time:
  1. range updates
  2. point queries
 */
 template <typename T>
 class range_tree {
 public:
 range_tree<T>(size_t n) : range_tree<T>(n, 4 * n) {}

 void update(size_t uL, size_t uR, T v) {
     _update(uL, uR, v, 1, 0, n_);
 }

 T query(size_t p) {
     return _query(p, 1, 0, n_);
 }

 private:
 range_tree<T>(size_t n, size_t tree_size) : n_{n}, tree_{vector<T>(tree_size, 0)} {}

 void _update(size_t uL, size_t uR, T v, size_t i, size_t cL, size_t cR) {
     if (uL == cL && uR == cR) {
     tree_.at(i) += v;
     return;
     }
     size_t mid = (cL + cR) / 2;
     if (uL < mid) _update(uL, min(uR, mid), v, i * 2, cL, mid);
     if (uR > mid) _update(max(uL, mid), uR, v, i * 2 + 1, mid, cR);
 }

 T _query(size_t p, size_t i, size_t cL, size_t cR) {
     if (cR - cL == 1) {
     return tree_.at(i);
     }
     int mid = (cL + cR) / 2;
     long long ans = tree_.at(i);
     if (p < mid) ans += _query(p, i * 2, cL, mid);
     else ans += _query(p, i * 2 + 1, mid, cR);
     return ans;
 }

 vector<T> tree_;
 size_t n_;
 };
