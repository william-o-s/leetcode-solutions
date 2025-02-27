#include <vector>

using std::vector;

class Solution {
public:
    /**
          A ^ B ^ C ^ B ^ A
        = A ^ A ^ B ^ B ^ C
        = 0 ^ 0 ^ C
        = 0 ^ C
        = C
    */
    int singleNumber(vector<int>& nums) {
        // int is at least [-2^32, 2^31 - 1]
        // 2^31 - 1 ~= about 2 * 10^9
        // so should fit in an int
        int total_xor = nums.front();
        for (size_t i = 1; i < nums.size(); ++i) {
            total_xor ^= nums.at(i);
        }
        return total_xor;
    }
};
