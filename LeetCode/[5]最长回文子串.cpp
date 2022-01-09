//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。 
//
// 示例 1： 
//
// 输入: "babad"
//输出: "bab"
//注意: "aba" 也是一个有效答案。
// 
//
// 示例 2： 
//
// 输入: "cbbd"
//输出: "bb"
// 
// Related Topics 字符串 动态规划 
// 👍 2499 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
        int res = 0;
        bool mid = false;
        unordered_map<char, int> m;
        for (char c : s) ++m[c];
        for (auto it = m.begin(); it != m.end(); ++it) {
            res += it->second;
            if (it->second % 2 == 1) {
                res -= 1;
                mid = true;
            } 
        }
        return mid ? res + 1 : res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
