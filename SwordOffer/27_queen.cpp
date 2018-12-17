 /*************************************************************************
	> File Name: 27_queen.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年07月26日 星期二 16时24分34秒
 ************************************************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

int queens(int n);
void permutation(int *str, int start, int n, int &rtNumber);
bool isRight(int *, int);

int queens(int n)           //n皇后问题
{
    int solutionN = 0;
    int *ColumnIndex = new int[n];
    for(int i = 0; i < n; i++)
        ColumnIndex[i] = i;
    
    permutation(ColumnIndex, 0, n, solutionN);
    
    return solutionN;
}

//全排列
void permutation(int *str, int start, int n, int &rtNumber)
{        
    if(str == NULL) return;

    if(start == n-1)
    {
        //检查输出
        if(isRight(str, n))
        {
            rtNumber++;
            for(int k = 0; k < n; k++)
                cout<< str[k] << ' ';
            cout << endl;
        }
        return;
    }

    for(int i = start; i<n; i++)
    {
        int temp = str[start];
        str[start] = str[i];
        str[i] = temp;

        permutation(str, start+1, n, rtNumber);

        temp = str[start];
        str[start] = str[i];
        str[i] = temp;
    }
}

bool isRight(int *str, int n)
{
    bool result = true;
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n;j++)
        {
            if( i!=j && abs(i-j) == abs(str[i]-str[j]))
            {
                result = false;
                return result;
            }
        }
    }
    return result;
}

int main()
{
    cout<< queens(8) <<endl;
    return 0;
}
