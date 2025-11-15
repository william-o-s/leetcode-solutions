class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // abcabcbb
        // l
        // r
        // {a} // 1
        
        // {ab} // 2
        // l
        //  r
        // {abc} // 3
        // l
        //    r
        // l   a // <- not update the answer
        //  l  a // {abc}

        // CONCERN: is it possible for the loop to terminate in the middle without the right reaching the end?
        // no it's not, you have to move the left along until you can move the right

        // aaabc

        // l  {a}
        //  r

        //  l
        //  r {a}
        
        //  l
        //   r {a}

        //    abc
        //    l r

        if (s.empty()) {
            return 0;
        }

        size_t N = s.size();
        size_t l = 0ULL, r = 1ULL;
        // start the window at l=0, r=1 so that there is a window
        auto chars = unordered_set<char>{s.front()};
        size_t ans = 1ULL;
        while (l <= r and l < N and r < N) {
            // if we have not seen the right character, then add it to the window
            // move the right along
            auto right = s[r];
            if (not chars.count(right)) {
                chars.insert(right);
                ans = max(ans, chars.size());
                ++r;
            } 
            // if we have seen the right character, then we have to remove the left first
            else {
                auto left = s[l];
                chars.erase(left);
                ++l;
            }
        }

        return static_cast<int>(ans);
    }
};
