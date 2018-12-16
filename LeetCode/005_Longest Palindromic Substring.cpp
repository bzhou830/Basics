/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
*/

class Solution {
public:
    /*
    bool isPalindromic(string str)
    {
        int start = 0, end = str.length() - 1;
        while (start < end)
        {
            if (str[start] != str[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    
    string longestPalindrome(string s) {
        int maxlen = 0;
        string res;
        int i=0,j=0;
        for (i = 0; i<s.length(); ++i)
        {
            for (j = i; j<s.length(); ++j)
            {
                string str = s.substr(i, j - i + 1);
                if (isPalindromic(str))
                {
                    if(maxlen<str.length())
                    {
                        res = str;
                        maxlen = str.length();
                    }
                }
            }
        }
        return res;
    }
    
    */
    /*
    string LongestCommonSubstring(string s, string r)
    {
        vector<char> tb(s.length() * r.length(), 0);
        int z = 0;
        string ret;
        for (int i = 0; i < s.length(); ++i)
        {
            for (int j = 0; j < r.length(); ++j)
            {
                if (s[i] == r[j])
                {
                    if (i == 0 || j == 0)
                        tb[i*s.length() + j] = 1;
                    else
                        tb[i*s.length() + j] = tb[(i - 1)*s.length() + j - 1] + 1;

                    if (tb[i*s.length() + j] > z)
                    {
                        z = tb[i*s.length() + j];
                        ret = s.substr(i - z + 1, z);
                    }
                }
            }
        }
        return ret;
    }

    
    
    string longestPalindrome(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        string res = LongestCommonSubstring(s, r);
        return res;
    }
    */
    string longestPalindrome(string s) 
    {
        const int strLen = s.size();    
        int begin = 0;  int maxLen = 1;    
        bool table[1000][1000] = {false};   
        //前期的初始化1: 独立的一个字符也是回文啊  
        for (int i = 0; i < strLen; i++)       
            table[i][i] = true;     
        //前期的初始化2：两个相等的相邻字符当然也是（吐槽，不能通过递推获取，所以只能单独拿出来初始化）  
        for (int i = 0; i < strLen-1; i++)   
        {     
            if (s[i] == s[i+1])   
            {        
                table[i][i+1] = true;   
                begin = i;        
                maxLen = 2;      
            }    
        }  
        //递推3：寻找长度为3及其以上的回文子串  
        for (int len = 3; len <= strLen; len++) //当前子串的长度len  
        {      
            for (int i = 0; i < strLen-len+1; i++) //当前子串起始位置i  
            {        
                int j = i+len-1; //子串末尾位置j     --》j-i=len-1  
                if (s[i] == s[j] && table[i+1][j-1])   
                {          
                    table[i][j] = true;          
                    begin = i;          
                    maxLen = len;        
                }      
            }    
        }    
        return s.substr(begin, maxLen);  
    }
};