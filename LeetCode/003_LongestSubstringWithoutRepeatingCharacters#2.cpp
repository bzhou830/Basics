/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        char mem[256] = {0};
        int maxlen = 0;
        int i=0,j=0;
        for(i = 0; i < s.size(); ++i)
        {
            mem[s[i]] = 1;
            for(j = i+1; j < s.size(); ++j)
            {
                if(mem[s[j]] != 1)
                {
                    mem[s[j]] = 1;
                }
                else
                {
                    memset(mem, 0, 256);
                    break;
                }
            }
            maxlen = max(maxlen, j-i);
        }
        return maxlen;
    }
};