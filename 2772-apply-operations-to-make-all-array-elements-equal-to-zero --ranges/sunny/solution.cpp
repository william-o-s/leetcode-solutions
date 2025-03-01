#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::max;
using std::min;
using std::vector;

class Solution {
public:
    template <typename T>
    class range_tree {
    public:
    range_tree<T>(size_t n) : n_{n}, tree_{vector<T>(4 * n, 0)} {}

    void update(size_t uL, size_t uR, T v) {
        _update(uL, uR, v, 1, 0, n_);
    }

    T query(size_t p) {
        return _query(p, 1, 0, n_);
    }

    private:
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

    bool checkArray(vector<int>& nums, int k) {
        auto n = static_cast<size_t>(nums.size());
        auto debts = range_tree<int>(size_t(n));
        for (size_t i = 0; i < nums.size(); ++i) {
            int reduce = nums.at(i) - debts.query(i);
            if (reduce < 0) {
                return false;
            }
            if (reduce == 0) {
                nums.at(i) = 0;
            } else if (reduce > 0) {
                // must propogate to all remaining k that you are reducing
                // this only works though if there is a k-sized window after
                if (i + k <= nums.size()) {
                    debts.update(i, i + k, reduce);
                    nums.at(i) = 0;
                }
            }
        }
        for (auto ni : nums) cout << ni << ' ';
        cout << '\n';
        return all_of(nums.begin(), nums.end(), [&nums](int const &ni){ return ni == 0; });
    }
};

int main() {
    auto nums = vector<int>{60,72,87,89,63,52,64,62,31,37,57,83,98,94,92,77,94,91,87,100,91,91,50,26};
    auto k = 4;
    Solution s;
    s.checkArray(nums, k);
}
