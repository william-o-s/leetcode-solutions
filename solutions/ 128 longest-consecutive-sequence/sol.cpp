#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int>& nums) {
    auto seen = unordered_set<int>(nums.begin(), nums.end()), ends = unordered_set<int>{};
    int answer = 0;
    for (int n : nums) {
        // n is not the end of a streak
        if (!seen.contains(n + 1) && !ends.contains(n)) {
            ends.insert(n);
            int length = 1;
            while (seen.contains(--n)) {
                ++length;
            }
            answer = max(answer, length);
        }
    }
    
    return answer; 
}
