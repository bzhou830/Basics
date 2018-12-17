#include <iostream>
using namespace std;

bool g_InvalidInput = false;

int FindMaxSubArray(int *pData, int len)
{
    if(pData == NULL || len <= 0)
    {
        g_InvalidInput = true;
        return 0;
    }

    g_InvalidInput = false;
    int nCurSum = 0;
    int nMaxSum = 0x80000000; //负数
    //cout << "max: " << nMaxSum << endl;
    for(int i=0; i<len; ++i)
    {
        if(nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];

        if(nCurSum > nMaxSum)
            nMaxSum = nCurSum;
    }
    return nMaxSum;
}

int main()
{
    int tm[8] = {1, -2, 3, 10, -4, 7, 2, -5};
    int rt = FindMaxSubArray(tm, 8);
    cout<< "rt: " << rt << endl;
    return 0;
}

