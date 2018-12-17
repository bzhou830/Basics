#include <iostream>
using namespace std;

bool IsUgly(int num)
{
    while(num % 2 == 0)
        num /= 2;
    while(num % 3 == 0)
        num /= 3;
    while(num % 5 == 0)
        num /= 5;

    return (num == 1) ? true : false;
}

int GetUglyNum(int index)
{
    if(index <= 0)
        return 0;
    int number = 0;
    int uglyFound = 0;
    while(uglyFound < index)
    {
        ++number;
        if(IsUgly(number))
        {
            //cout << number <<endl;
            ++uglyFound;
        }
    }
    return number;
}

int main()
{
    cout << GetUglyNum(15) << endl;
    return 0;
}
