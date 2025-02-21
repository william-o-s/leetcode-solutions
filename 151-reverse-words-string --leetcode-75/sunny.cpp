// a skeleton of a constant-memory solution

class Solution {
public:
    /**
        RUNTIME:
        O(n)   reverse the entire string
        O(n^2) remove all leading, trailing and consecutive spaces 
        O(n^2) reverse each word
        
        MEMORY:
        O(1) no dynamic memory needed
    */
    string reverseWords(string s) {
        // O(n)   reverse the entire string
        reverseSubString(s, 0ULL, s.size() - 1);

        // O(n^2) remove all leading, trailing and consecutive spaces 
        removeLeadingSpaces(s);
        removeTrailingSpaces(s);
        // removeConsecutiveSpaces(s);

        for (auto rem = removeFirstGroupConsecutiveSpaces(s); rem; rem = removeFirstGroupConsecutiveSpaces(s)) {}
        // now the string is the perfect size after whitespace has been compressed

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

    /**
        _ _ b o b _
        shift left by 2
        b _ b o b _
        b o b o b _
        b o b _ b _
                ^ need to remove the last two here
    */
    void removeLeadingSpaces(string &s) {
        // remove leading spaces
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
        could be smarter and do something like return the index after the removed whitespace group
        - need to deal with shifting zzz

        close your eyes and pretend like string.erase(iter, iter) doesn't do memory allocation
        the alternative is you manually shift everything over zzz
    */
    bool removeFirstGroupConsecutiveSpaces(string &s) {
        auto firstSpaceBar = find(s.begin(), s.end(), ' ');
        if (firstSpaceBar == s.end()) {
            return false;
        }

        auto endOfGroup = firstSpaceBar;
        while (*endOfGroup != ' ' && endOfGroup != s.end()) {
            ++endOfGroup;
        }

        // need to leave one spacebar so don't erase the first spacebar itself
        ++firstSpaceBar;
        s.erase(firstSpaceBar, endOfGroup);
        return true;
    }

    /**
        PRECONDITIONS
        1. there is no leading or trailing space
        2. there are no consecutive spaces
    */
    void reverseEachWord(string &s) {
        // a b c _ d e f
        //       ^ i=0 | l=3
        size_t l = 0ULL;
        size_t r = 0ULL;
        while (r < s.size()) {
            if (s.at(r) != ' ') {
                ++r;
            } else {
                // now [l, r) should be a word
                reverseSubString(s, l, r - 1);
                ++r; 
                l = r;
            }
        }
    }
};
