#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    // [100, 4, 200, 1, 3, 2]
    // the end of a streak won't have e + 1

    // cout << nums.size() << '\n';

    auto seen = unordered_set<int>(nums.begin(), nums.end());
    int answer = 0;
    for (int n : nums) {
        // n is not the end of a streak
        if (seen.contains(n + 1)) {
            // cout << "SKIPPED: " << n << '\n';
            continue;
        }
        // cout << "START: " << n << '\n';
        int length = 1;
        while (seen.contains(--n)) {
            // cout << "  " << n << '\n';
            ++length;
        }
        answer = max(answer, length);
    }

    return answer;
}

int main() {
    // too slow for ints 1 ... 50,000
    auto big = vector<int>(50 * 1000);
    for (int i = 1; i <= 50 * 1000; ++i) {
        big[i - 1] = i;
    }

    longestConsecutive(big);
}
