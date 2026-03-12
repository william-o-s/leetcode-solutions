#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    void heapifyDown(vector<int>& nums, int size, int rootInd, bool isMin=false) {
        if (size <= 1 or rootInd < 0 or rootInd >= size - 1) return;
        int keyInd = rootInd;
        int leftChildInd = 2 * rootInd + 1, rightChildInd = 2 * rootInd + 2;
        if (leftChildInd < size and (isMin ? nums[leftChildInd] < nums[keyInd] : nums[leftChildInd] > nums[keyInd]))
            keyInd = leftChildInd;
        if (rightChildInd < size and (isMin ? nums[rightChildInd] < nums[keyInd] : nums[rightChildInd] > nums[keyInd]))
            keyInd = rightChildInd;
        if (nums[keyInd] != nums[rootInd]) {
            swap(nums[rootInd], nums[keyInd]);
            heapifyDown(nums, size, keyInd, isMin);
        }
    }

    void heapifyArray(vector<int>& nums, bool isMin=false) {
        int size = nums.size();
        if (size <= 1) return;
        int tailRootInd = (size >> 1) - 1;
        for (int rootInd = tailRootInd; rootInd >= 0; rootInd--)
            heapifyDown(nums, size, rootInd, isMin);
    }

    vector<int> sortArray(vector<int>& nums) {
        if (nums.size() <= 1) return nums;
        heapifyArray(nums);
        for (int size = nums.size() - 1; size; size--) {
            swap(nums[size], nums[0]);
            heapifyDown(nums, size, 0);
        }
        return nums;
    }
};

void printArray(vector<int>& nums) {
    cout << "Sorted: ";
    for (auto num : nums)
        cout << num << ' ';
    cout << '\n';
}

int main(void) {
    vector<int> arr1 = {5,2,3,1};
    arr1 = Solution().sortArray(arr1);
    printArray(arr1);

    vector<int> arr2 = {5,1,1,2,0,0};
    arr2 = Solution().sortArray(arr2);
    printArray(arr2);
}