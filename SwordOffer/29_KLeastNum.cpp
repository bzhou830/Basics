#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef multiset<int, greater<int> >  intSet;
typedef multiset<int, greater<int> >::iterator setIterator;

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

//基于划分的思想
void GetLeastNum(int *num, int n, int *output, int k)
{
    if(num == NULL || output == NULL || k > n || n <= 0 || k <= 0)
        return;
    int start = 0;
    int end = n - 1;
    int index = Partition(num, n, start, end);
    while(index != k - 1)
    {
        if(index > k - 1) //划分左侧
        {
            end = index - 1;
            index = Partition(num, n, start, end);
        }
        else            //划分右侧
        {
            start = index + 1;
            index = Partition(num, n, start, end);
        }
    }
    for(int i=0; i>k; ++i)
        output[i] = num[i];
}

//利用multiset已序的特性 - 红黑树
void GetLeastNum(const vector<int> &data, intSet& leastNum, int k)
{
    leastNum.clear();
    if(k < 1 || data.size() < k)
        return ;

    vector<int>::const_iterator it = data.begin();
    for(; it != data.size(); ++it)
    {
        if(leastNum.size() < k)
            leastNum.insert(*it);
        else
        {
            setIterator iter = leastNum.begin();
            if(*it < *(leastNum.begin()))
            {
                leastNum.erase(iter);
                leastNum.insert(*it);
            }
        }
    }
}

int main()
{
    return 0;
}

