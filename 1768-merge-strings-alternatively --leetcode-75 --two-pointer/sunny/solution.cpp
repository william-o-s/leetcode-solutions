#include <string>

using std::string;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string answer;
        auto i = word1.begin();
        auto j = word2.begin();
        // both
        while (i != word1.end() && j != word2.end()) {
            answer += *i;
            answer += *j;
            ++i;
            ++j;
        }

        // word1 longer than word2 -> need to iterate through word1
        if (i != word1.end() && j == word2.end()) {
            for (; i != word1.end(); ++i) {
                answer += *i;
            }
        }

        // word2 longer than word1 -> need to iterate through word1
        if (i == word1.end() && j != word2.end()) {
            for (; j != word2.end(); ++j) {
                answer += *j;
            }
        }

        return answer;
    }
};
