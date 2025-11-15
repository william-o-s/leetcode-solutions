class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        // the answer for index i is nums[i] - min(nums[0,i))
        // then we just take the max answer for all i
        auto best = -1;
        auto lo = nums.front();
        for (auto i = nums.begin() + 1; i != nums.end(); ++i) {
            auto curr = *i;
            if (curr > lo) {
                best = max(curr - lo, best);
            }
            lo = min(lo, curr);
        }
        return best;
    }
};
