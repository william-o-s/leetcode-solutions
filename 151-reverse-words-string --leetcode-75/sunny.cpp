// a skeleton of a constant-memory solution

#include <algorithm>
#include <optional>
#include <string>

using std::nullopt;
using std::optional;
using std::string;
using std::swap;

class Solution {
public:
    string reverseWords(string s) {
        // O(n)   reverse the entire string
        reverseSubString(s, 0ULL, s.size() - 1);
    
        // O(n^2) remove all leading, trailing and consecutive spaces 
        removeLeadingSpaces(s);
        removeTrailingSpaces(s);
    
        size_t totalRemoved = 0;
        for (auto rem = removeFirstGroupConsecutiveSpaces(s); rem > 0; rem = removeFirstGroupConsecutiveSpaces(s)) {
            totalRemoved += rem;
        }
        // reduce the size of the string by all remaining letters
        for (size_t _ = 0; _ < totalRemoved; ++_) {
            s.pop_back();
        }
    
        // O(n^2) reverse each word
        reverseEachWord(s);
    
        return s;
    }
    
    // reverse the string in-place between indices l and r inclusive
    void reverseSubString(string &s, size_t l, size_t r) {
        auto i = l;
        auto j = r;
        while (i < j) {
            swap(s.at(i++), s.at(j--));
        }
    }
    
    void removeLeadingSpaces(string &s) {
        // find first non-whitespace index
        size_t first = 0ULL;
        while (s.at(first) == ' ') {
            ++first;
        }
    
        // now shift everything in the array back by first
        for (auto i = first; i < s.size(); ++i) {
            s.at(i - first) = s.at(i);
        }
    
        // remove last two letters
        for (size_t _ = 0ULL; _ < first; ++_) {
            s.pop_back();
        }
    }
    
    // keep removing the last letter while it is a spacebar
    void removeTrailingSpaces(string &s) {
        while (!s.empty()) {
            auto back = s.back();
            if (back != ' ') {
                break;
            }
            s.pop_back();
        }
    }
    
    /**
        mimic strtok:
        remove the first consecutive group and return whether a group was removed
    
        return the number of letters shifted down
    */
    size_t removeFirstGroupConsecutiveSpaces(string &s) {
        bool lastLetterIsSpace = false;
        optional<size_t> new_start;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s.at(i) == ' ') {
                // if we've seen a space before then this is the new start
                if (lastLetterIsSpace) {
                    new_start = i;
                } 
                // this is the first spacebar we've seen;
                // need to look at the next character to decide on what to do
                else {
                    lastLetterIsSpace = true;
                }
            } else {
                lastLetterIsSpace = false;
                // check if we are just in a word normally -> can check if 
                if (new_start) {
                    auto answer = i - *new_start;
                    // shift all characters down to old start
                    for (auto j = i; j < s.size(); ++j) {
                        s.at(*new_start) = s.at(j);
                        new_start = (*new_start) + 1;
                    }
                    return answer;
                }
            }
        }
    
        // no new start was found
        return 0;
    }
    
    void reverseEachWord(string &s) {
        // just record where the start of the current word is
        optional<size_t> currStart;
        size_t i = 0;
        for (; i < s.size(); ++i) {
            auto c = s.at(i);
            if (c == ' ') {
                if (currStart) {
                    reverseSubString(s, *currStart, i - 1);
                    currStart = nullopt;
                }
            } else {
                // we just found a spacebar and are now on the start of a new word
                if (!currStart) {
                    currStart = i;
                }
            }
        }
        // reverse the last word
        if (currStart) {
            reverseSubString(s, *currStart, i - 1);
            currStart = nullopt;
        }
    }
};

int main() {}
