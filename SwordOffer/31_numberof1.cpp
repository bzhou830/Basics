#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
using namespace std;

int PowerBase10(unsigned int n)
{
    int rt = 1;
    for(unsigned int i=0; i<n; ++i)
        rt *= 10;
    return rt;
}

int NumberOf1(const char* strN)
{
    if(!strN || *strN < '0' || *strN > '9' || *strN == '\0') //检查输入是否合法
        return 0;

    int first = *strN - '0';
    unsigned int len = static_cast<unsigned int>(strlen(strN));
    if(len == 1 && first == 0)              //只有一位数字，最后一位是 0
        return 0;
    if(len == 1 && first > 0)               //只有一位数字，最后一位数字 > 0
        return 1;
    //最高位数字产生的个数
    int numFirstDigit = 0;
    if(first > 1)
        numFirstDigit = PowerBase10(len - 1);
    else if(first == 1)
        numFirstDigit = atoi(strN + 1) + 1;
    //除最高位的数字产生的个数
    int numOtherDigits = first * (len - 1) * PowerBase10(len - 2);
    int numRecursive = NumberOf1(strN + 1);
    return numFirstDigit + numOtherDigits + numRecursive;
}

int NumOf1Between1AndN(int n)
{
    if(n <= 0)
        return 0;
    char strN[50];
    sprintf(strN, "%d", n);

    return NumberOf1(strN);
}

int main()
{
    cout << NumOf1Between1AndN(21345) << endl;
    return 0;
}
