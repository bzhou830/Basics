/*************************************************************************
	> File Name: 25_Permutation.cpp
	> Author: 
	> Mail: 
	> Created Time: 2016年07月26日 星期二 14时28分10秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
using namespace std;

void PermutationChild(char *pStr, char *pBegin)
{
    if(*pBegin == '\0')
        printf("%s\n", pStr);
    else
    {
        for(char *pCh=pBegin; *pCh != '\0'; ++pCh)
        {
            char tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;
            PermutationChild(pStr, pBegin + 1);

            tmp = *pCh;
            *pCh = *pBegin;
            *pBegin = tmp;
        }
    }
}

void Permutation(char* pStr)
{
    if(pStr == NULL)
        return;
    PermutationChild(pStr, pStr);
}

int main()
{
    char str[4] = "abc";
    Permutation(str);
    return 0;
}





