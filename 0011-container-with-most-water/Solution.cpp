#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int max = 0;
        while (l < r) {
            max = std::max(max, std::min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else if (height[l] == height[r]) {
                // Neither l or r can be contenders since the next maximum must
                // have smaller width and thus compensate with a larger height
                // The keyword 'larger height' is why neither l or r is needed
                l++;
                r--;
            } else {
                r--;
            }
        }

        return max;
    }
};

int main(void) {
    std::vector<int> arr1 = {1,8,6,2,5,4,8,3,7};
    printf("arr1 output: %d\n", Solution().maxArea(arr1));

    return 0;
}