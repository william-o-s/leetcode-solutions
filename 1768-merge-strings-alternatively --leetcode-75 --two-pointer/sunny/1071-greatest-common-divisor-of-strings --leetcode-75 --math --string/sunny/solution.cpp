#include <algorithm>
#include <string>
#include <vector>

using std::binary_search;
using std::string;
using std::vector;

class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        auto div1 = all_divisors(str1);
        auto div2 = all_divisors(str2);

        auto &smallest = (div1.size() < div2.size()) ? (div1) : (div2);
        auto &biggest = (&smallest == &div1) ? (div2) : (div1);

        // iterate through the factors in reverse order so we find the largest
        for (auto i = smallest.rbegin(); i != smallest.rend(); ++i) {
            if (binary_search(biggest.begin(), biggest.end(), *i)) {
                return *i;
            }
        }

        return string{""};
    }

    vector<size_t> factors(size_t n) {
        vector<size_t> answer;
        for (size_t i = 1; i <= n; ++i) {
            if (n % i == 0) {
                answer.push_back(i);
            }
        }
        return answer;
    }

    bool prefix_is_divisor(size_t len, string &s) {
        for (size_t i = 0; i < len; ++i) {
            auto curr = s.at(i);
            // check that the character len away matches the prefix
            // len=3
            // a b c a b c
            // 0 1 2 3
            // here check i=0, i=3, i=6 etc. are all the same
            for (size_t j = i + len; j < s.size(); j += len) {
                if (s.at(j) != curr) {
                    return false;
                }
            }
        }
        return true;
    }

    vector<string> all_divisors(string &s) {
        vector<string> answer;
        auto facs = factors(s.size());
        for (auto f : facs) {
            if (prefix_is_divisor(f, s)) {
                answer.push_back(s.substr(0, f));
            }
        }
        return answer;
    }
};
