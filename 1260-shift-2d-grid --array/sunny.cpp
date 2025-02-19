using namespace std;

#include <iostream>
#include <vector>

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        // a lot easier in O(m * n) memory
        // can pull off in O(m * n) time

        size_t rows = grid.size();
        size_t cols = grid.at(0).size();

        // rows number rows, each with cols amount of 0s
        auto result = vector<vector<int>>(rows, vector<int>(cols, 0));
        auto mn = rows * cols;
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                // 1. convert coordinate pair into 1D-index
                size_t one_d = i * cols + j; 
                // 2.calculate the shift as 1D-index
                size_t shifted = (one_d + (static_cast<size_t>(k) % mn)) % mn;

                // 3.convert into 2D-index
                size_t r = shifted / cols;
                size_t c = shifted % cols;

                // 4. store in result
                result.at(r).at(c) = grid.at(i).at(j);
            }
        }

        return result;
    }
};

