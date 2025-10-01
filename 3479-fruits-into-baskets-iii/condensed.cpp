/**
    This solution is more condensed since we try to calculate the bucket offsets.
*/

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        auto N = fruits.size();
        auto B = static_cast<size_t>(
            sqrt(static_cast<double>(N))
        );

        // store max in each bucket
        auto maxs = vector<int>(baskets.begin(), baskets.end());
        auto buckets = vector<int>(static_cast<size_t>(
            ceil(
                static_cast<double>(N)
                / static_cast<double>(B)
            )
        ));

        // set all buckets
        for (size_t i = 0ULL; i < N; ++i) {
            auto bi = i / B;
            // first entry in bucket => set the bucket
            buckets[bi] = i % B == 0 ? maxs[i] : max(buckets[bi], maxs[i]);
        }

        // for each fruit try to place each of them
        auto unplaced = 0;
        for (auto fruit : fruits) {
            auto placed = false;
            for (size_t bi = 0ULL; not placed and bi < buckets.size(); ++bi) {
                // place the fruit
                if (buckets[bi] >= fruit) {
                    for (size_t i = bi * B; i < min(N, (bi + 1) * B); ++i) {
                        if (maxs[i] >= fruit) {
                            maxs[i] = -1;
                            break;
                        }
                    }
    
                    // reset this bucket
                    for (size_t i = bi * B; i < min(N, (bi + 1) * B); ++i) {
                        buckets[bi] = i % B == 0 ? maxs[i] : max(buckets[bi], maxs[i]);
                    }

                    placed = true;
                }
            }
            if (not placed) {
                ++unplaced;
            }
        }
        return unplaced;
    }
};
