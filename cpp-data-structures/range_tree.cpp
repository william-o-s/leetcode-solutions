// taken from cs4128

#include <algorithm>

using std::max;
using std::min;

long long lazyadd[1<<18];

int n;

// supports in log(n) time:
// 1. range updates
// 2. point queries

void update(int uL, int uR, int v, int i = 1, int cL = 0, int cR = n) {
  if (uL == cL && uR == cR) {
    lazyadd[i] += v;
    return;
  }
  int mid = (cL + cR) / 2;
  if (uL < mid) update(uL, min(uR, mid), v, i * 2, cL, mid);
  if (uR > mid) update(max(uL, mid), uR, v, i * 2 + 1, mid, cR);
}

long long query(int p, int i = 1, int cL = 0, int cR = n) {
  if (cR - cL == 1) {
    return lazyadd[i];
  }
  int mid = (cL + cR) / 2;
  long long ans = lazyadd[i];
  if (p < mid) ans += query(p, i * 2, cL, mid);
  else ans += query(p, i * 2 + 1, mid, cR);
  return ans;
}
