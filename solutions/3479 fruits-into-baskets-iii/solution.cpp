int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    auto root = static_cast<size_t>(sqrt(static_cast<double>(fruits.size())));

    // solve using square root decompression
    // break up into m blocks each of sqrt(n) in size
    // store the max in each block
    // if fruit < max(bucket), then yes we can place!
    // then just look in the bucket for the first such value

    // store the min in each of these
    auto buckets = vector<int>(baskets.begin(), baskets.end());
    auto roots = vector<int>(fruits.size() / root + (fruits.size() % root != 0));

    for (size_t i = 0; i < roots.size(); ++i) {
        auto hi = buckets[i * root];
        for (size_t j = 1; (i * root + j) < buckets.size() and j < + root; ++j) {
            hi = max(hi, buckets[i * root + j]);
        }
        roots[i] = hi;
    }

    auto remain = static_cast<int>(fruits.size());
    for (auto f : fruits) {
        for (size_t i = 0; i < roots.size(); ++i) {
            if (roots[i] >= f) {
                for (size_t j = 0; (i * root + j) < buckets.size() and j < root; ++j) {
                    if (buckets[i * root + j] >= f) {
                        // place the fruit here in basket i * root + j
                        --remain;
                        buckets[i * root + j] = -1;
                        // now stop considering f
                        break;
                    }
                }
                // update the bucket
                auto hi = buckets[i * root];
                for (size_t j = 1; (i * root + j) < buckets.size() and j < + root; ++j) {
                    hi = max(hi, buckets[i * root + j]);
                }
                roots[i] = hi;
                break;
            }
        }
    }

    return remain;
}
