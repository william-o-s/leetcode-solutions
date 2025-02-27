#include <iostream>
#include <vector>

using std::cout;
using std::vector;

class Solution {
public:
    // this is apparently Kernighan's algorithm
    // it is O(1) * O(n) with a high constant factor
    // the constant factor is the number of bits in an integer
    // the bound is picked annoyingly (10^5) so that it is bigger than
    // 2^16, but smaller than 2^32
    // so no size of integer will work fast enough
    vector<int> countBits(int n) {
        // can cheat maybe?
        // only iterate up to the highest base ie: ceil(log2(10^5))=17
        int const LARGEST_BASE_2 = 17;

        auto answer = vector(n + 1, 0);

        for (int i = 0; i <= n; ++i) {
            int num_ones = 0;
            for (size_t digit = 0; digit <= LARGEST_BASE_2; ++digit) {
                int shifted = i >> digit;
                num_ones += (1 & shifted);
            }

            answer.at(i) = num_ones;
        }

        return answer;
    }
};
