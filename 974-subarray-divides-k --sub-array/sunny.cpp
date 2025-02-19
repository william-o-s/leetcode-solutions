#include <iostream>
#include <vector>

using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    auto n = nums.size();
    auto prefix = vector<int>(n, 0);
    prefix[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        prefix[i] = prefix[i - 1] + nums[i];
    }
    for (auto &p : prefix) {
        p = ((p % k) + k) % k;
    }
    int answer = 0;
    auto all_freq = vector<int>(k, 0);
    auto left_freq = vector<int>(k, 0);
    for (auto p : prefix) {
        ++all_freq[p];
    }
    for (auto p : prefix) {
        answer += (p == 0);
    }
    ++left_freq[prefix[0]];
    for (int i = 1; i < n; ++i) {
        int val = prefix[i - 1];
        int curr = all_freq[val] - left_freq[val];
        // cannot pair up if there is only one
        if (all_freq[val] <= 1) {
            curr = 0;
        }

        cout << "i: " << i << " val: " << val << " curr: " << curr << '\n';
        cout << "left: ";
        for (auto l : left_freq) cout << l << ' ';
        cout << '\n';

        cout << "all : ";
        for (auto a : all_freq) cout << a << ' ';
        cout << "\n\n";

        answer += curr;
        if (left_freq[val] != all_freq[val]) {
            ++left_freq[val];
        }
    } 
    return answer;
}

void test(vector<int> v, int k) {
    cout << subarraysDivByK(v, k) << '\n';
}

int main() {
    // test(vector<int>{4, 5, 0, -2, -3, 1}, 5);
    // test(vector<int>{7, 4, -10}, 5);
    test(vector<int>{2, 3, -10}, 5);
}
