#include <iostream>
#include <stdlib.h>

using namespace std;

int Partition(int data[], int len, int left, int right)
{
    if(data == NULL || len <= 0 || left < 0 || right >= len)
        return -1;
    int index = data[left];
    int i=left, j=right;
    while(i < j)
    {
       while(i < j && data[j] >= index) --j;
       if(i < j)
       {
           data[i] = data[j];
           ++i;
       }

       while(i < j && data[i] < index) ++i;
       if(i < j)
       {
           data[j] = data[i];
           --j;
       }
    }
    data[i] = index;
    return i;
}


int MoreThanHalfNum(int *num, int len)
{
    int middle = len >> 1;
    int start = 0;
    int end = len - 1;
    int index = Partition(num, len, start, end);
    while(index != middle)
    {
        if(index > middle)//划分前部分
        {
            end = index - 1;
            index = Partition(num, len, start, end);
        }
        else
        {
            start = index + 1;
            index = Partition(num, len, start, end);
        }
    }
    //返回之前可以做一次检查，因为已经知道了那个数字是什么，所以统计该数字出现的频率，然后判断是不是大于总数的一半
    return num[middle];
}


int main()
{
    int tm[6] = {1, 2, 1, 2, 1, 1};
    //int a = Partition(tm, 6, 0, 5);
    int a = MoreThanHalfNum(tm, 6);
    for(int i=0; i<6; ++i)
    {
        cout<< tm[i] << " ";
    }
    cout<<"index:"<<a<<endl;
    return 0;
}
