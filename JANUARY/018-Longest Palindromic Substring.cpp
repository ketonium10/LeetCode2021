/**
 * Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/

class Solution
{
public:
    string longestPalindrome(string s)
    {
        {
            int n = s.size();
            if (n == 0)
                return "";

            // dp[i][j] will be 'true' if the string from index i to j is a palindrome.
            bool dp[n][n];

            //Initialize with false

            memset(dp, 0, sizeof(dp));

            //Every Single character is palindrome
            for (int i = 0; i < n; i++)
                dp[i][i] = true;

            string ans = "";
            ans += s[0];

            for (int i = n - 1; i >= 0; i--)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (s[i] == s[j])
                    {
                        //If it is of two character OR if its susbtring is palindrome.
                        if (j - i == 1 || dp[i + 1][j - 1])
                        {
                            //Then it will also a palindrome substring
                            dp[i][j] = true;

                            //Check for Longest Palindrome substring
                            if (ans.size() < j - i + 1)
                                ans = s.substr(i, j - i + 1);
                        }
                    }
                }
            }
            return ans;
        }
    }
};