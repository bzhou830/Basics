#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

const int g_MaxNumberLen = 10;
char * g_StrCombine1 = new char[g_MaxNumberLen*2 + 1];
char * g_StrCombine2 = new char[g_MaxNumberLen*2 + 1];

int compare(const void* strNumber1, const void* strNumber2)
{
    strcpy(g_StrCombine1, *(const char**)strNumber1);
    strcat(g_StrCombine1, *(const char**)strNumber2);

    strcpy(g_StrCombine2, *(const char**)strNumber2);
    strcat(g_StrCombine2, *(const char**)strNumber1);
    int rt = strcmp(g_StrCombine1, g_StrCombine2);
    return rt;
}

void PrintMinNumber(int *numbers, int len)
{
    if(numbers == NULL || len <= 0)
        return;
    char** strNumbers = (char**)(new int [len]);
    for(int i=0; i<len; ++i)
    {
        strNumbers[i] = new char[g_MaxNumberLen + 1];
        sprintf(strNumbers[i], "%d", numbers[i]);
    }
    qsort(strNumbers, len, sizeof(char*), compare);

    for(int i=0; i<len; ++i)
        printf("%s", strNumbers[i]);
    printf("\n");

    for(int i=0; i<len; ++i)
        delete[] strNumbers[i];
    delete[] strNumbers;
}

int main()
{
    int tm[6] = {3,32,321,9,4,1};
    PrintMinNumber(tm, 6);
    return 0;
}
