#include <algorithm>
#include <vector>
#include <deque>

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        auto all = vector<string>{};
        auto answer = vector<string>{};
        auto seen = unordered_set<string>{};
        backtrack(s, all);
        if (all.empty()) {
            answer.push_back(string{""});
        } else {
            auto longest = all.front().size();
            for (auto a : all) {
                longest = max(a.size(), longest);
            }
            for (auto& a : all) {
                if (a.size() == longest and not seen.contains(a)) {
                    answer.push_back(a);
                    seen.insert(a);
                }
            }
        }
        return answer;
    }

    // balanced string if empty stack
    bool balanced(string& s) {
        auto stack = deque<int>{};
        for (auto c : s) {
            if (c == '(') {
                stack.push_back(c);
            } else if (c == ')') {
                if (stack.empty()) {
                    return false;
                }
                stack.pop_back();
            }
        }
        return stack.empty();
    }

    void backtrack(string substr, vector<string>& answer) {
        if (substr.empty()) {
            return;
        }

        if (balanced(substr)) {
            answer.push_back(substr);
        }

        for (auto c = substr.begin(); c != substr.end(); ++c) {
            if (*c != '(' and *c != ')') {
                continue;
            }

            auto removed = string{substr.begin(), c} + string{c + 1, substr.end()};
            backtrack(removed, answer);
        }
    }
};
