/*************************************************************************
	> File Name: 逆序对个数问题
	> Author: 
	> Mail: 
	> Created Time: 2016年08月02日 星期二 09时03分54秒
 ************************************************************************/

#include<iostream>
using namespace std;


int InversePairsCore(int *num, int *copy, int start, int end)
{
    if(start == end)
    {
        copy[start] = num[start];
        return 0;
    }

    int len = (end-start)/2;
    int left = InversePairsCore(copy, num, start, start + len);
    int right = InversePairsCore(copy, num, start+len+1, end);

    int i = start + len;

    int j = end;
    int indexCopy = end;
    int count = 0;
    while(i >= start && j >= start+len+1)
    {
        if(num[i] > num[j])
        {
            copy[indexCopy--] = num[i--];
            count += j - start - len;
        }
        else
        {
            copy[indexCopy--] = num[j--];
        }
    }

    for(;i>=start;--i)
        copy[indexCopy--] = num[j--];

    for(;j>=start+len+1;--j)
        copy[indexCopy--] = num[j];
    return left + right + count;
}

int InversePairs(int *num, int len)
{
    if(num == NULL || len <= 0)
        return 0;
    int *copy = new int[len];
    
    for(int i=0; i<len; ++i)
        copy[i] = num[i];

    int count  = InversePairsCore(num,copy,0,len-1);

    delete[] copy;
    return count;
}


int main()
{
    int num[4] = {7, 5, 6, 4};
    int rt = InversePairs(num, 4);
    
    cout<<"rt: " << rt << endl;
    return 0;
}

