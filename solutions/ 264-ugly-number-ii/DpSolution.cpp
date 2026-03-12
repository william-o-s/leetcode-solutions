#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * DP list contains n ugly numbers in order - the ordered nature is key
     * as each advanced pointer for 2,3,5 finds the next minimum ugly number
     * given the previous pointer - since the pointers advance one at a time,
     * you only consider the next largest number given the multiplication.
     *
     * Sample:
     * n=1, p2=0, p3=0, p5=0: [1]
     * n=2, p2=1 (next minimum is 2*2=4), p3=0, p5=0: [1, 2*1]
     * n=3, p2=1, p3=1 (next minimum is 2*3=6), p5=0: [1, 2, 3*1]
     * n=4, p2=2 (next minimum is 3*2=6), p3=1, p5=0: [1, 2, 3, 4]
     * n=5, p2=2, p3=1, p5=1 (next minimum is 2*5=10): [1, 2, 3, 4, 5]
     */
    int nthUglyNumber(int n) {
        int p2 = 0, p3 = 0, p5 = 0;
        int nums[n];
        nums[0] = 1;

        for (int i = 1; i < n; i++) {
            int next_p2 = nums[p2]*2, next_p3 = nums[p3]*3, next_p5 = nums[p5]*5;
            int next = min(next_p2, min(next_p3, next_p5));
            if (next == next_p2) p2++;
            if (next == next_p3) p3++;
            if (next == next_p5) p5++;
            nums[i] = next;
        }

        return nums[n-1];
    }
};

int main(void) {
    for (int i = 1; i <= 10; i++) {
        printf("%dth Ugly Number: %d\n", i, Solution().nthUglyNumber(i));
    }

    return 0;
}