import java.util.Arrays;

class Solution {
    /**
     * Reference: https://cp-algorithms.com/string/manacher.html
     * @param s - Input string
     * @return the longest palindromic substring.
     */
    public String longestPalindrome(String s) {
        if (s.length() <= 1)
            return s;

        String maxString = s.substring(0, 1);
        s = "#" + s.replaceAll("", "#") + "#";
        int[] dp = new int[s.length()];
        int maxLength = 1, center = 0, right = 0;

        for (int i = 0; i < s.length(); i++) {
            if (i < right)
                dp[i] = Math.min(right - i, dp[2 * center - i]);

            while (
                (i - dp[i] - 1) >= 0
                && (i + dp[i] + 1) < s.length()
                && s.charAt(i - dp[i] - 1) == s.charAt(i + dp[i] + 1)
            )
                dp[i] += 1;

            if (i + dp[i] > right) {
                center = i;
                right= i + dp[i];
            }

            if (dp[i] > maxLength) {
                maxLength = dp[i];
                maxString = s.substring(i - dp[i], i + dp[i] + 1).replace("#", "");
            }
        }

        return maxString;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        System.out.println(solution.longestPalindrome("ac"));
    }
}