#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();
        auto freq = vector<int>(26, 0);
        for (auto t : tasks) ++freq.at(t - 'A');
        sort(freq.begin(), freq.end(), greater<int>());
        auto i = freq.begin();
        auto most = *i;
        auto n_blocks = most - 1;
        auto time = n_blocks * (n + 1) + 1;
        // use a normal queue, pq might reuse blocks
        auto blocks = queue<int>{};
        for (auto _ = 0; _ < n_blocks; ++_) blocks.push(n);
        ++i;
        for (; i != freq.end() and *i; ++i) {
            if (blocks.empty()) {
                time += *i;
                continue;
            }
            auto j = *i;
            auto rem = blocks.size();
            // use up max(initial_queue_size, *i) blocks
            for (auto _ = 0; _ < rem and j; ++_) {
                auto t = blocks.front();
                blocks.pop();
                --j;
                if (t > 1) blocks.push(t - 1);
            }
            // however many are left over, need to be squeezed in
            time += j;
        }
        return time;
    }
};

auto main() -> int {
    auto s = Solution{};
    auto v = vector<char>{'A','A','A','A','A','A','B','C','D','E','F','G'};
    auto i = s.leastInterval(v, 2);
    cout << i << '\n';
}
