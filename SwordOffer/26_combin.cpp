/*************************************************************************
	> File Name: 26_combin.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年07月26日 星期二 16时05分43秒
 ************************************************************************/
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

void AllmCombin(char *pBegin, vector<char> &vt, int m)
{
    if(vt.size()==m)
    {
        for(vector<char>::iterator it = vt.begin(); it!=vt.end(); it++)
            cout << *it << " ";
        cout<<endl;
        return;
    }
    if(*pBegin!=0)
    {
        vt.push_back(*pBegin);
        AllmCombin(pBegin+1, vt, m);

        vt.pop_back();
        AllmCombin(pBegin+1, vt, m);
    }
}

void AllmCombination(char *str,int m)
{
    if(str == NULL || m <= 0 || strlen(str) < m)
        return;
    vector<char> vt;
    AllmCombin(str, vt, m);
}

int main()
{
    char str[6] = "after";
    AllmCombination(str,3);
    return 0;
}

