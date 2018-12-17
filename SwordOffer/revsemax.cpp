/*
 * 最长递减子序列问题
 * 典型动态规划问题
*/
#include<iostream>

using namespace std;

int revsemax(int *num, int len)
{
    if(num == NULL || len <= 0)
        return 0;
    int *tmparr = new int[len];
    for(int i=0; i<len; ++i)
        tmparr[i] = 1;

    int j = 0;
    int maxnum = 1;
    for(int i=1;i<len;++i)
    {
        j = i-1;
        maxnum = 1;
        while(j>=0)
        {
            if(num[i] < num[j] && maxnum <= tmparr[j])
                maxnum = tmparr[j] + 1;
            j--;
        }
        tmparr[i] = maxnum;
    }
    //找到最大的数字
    maxnum = 1;
    for(int i=1; i<len; ++i)
    {
        if(tmparr[i] > maxnum)
            maxnum = tmparr[i];
    }
    delete[] tmparr;
    return maxnum;
}

int main()
{
    int arr[8] = {1,-2,3,10,-4,7,2,-5};
    cout << "revse: " << revsemax(arr, 8) << endl;
    return 0;
}

