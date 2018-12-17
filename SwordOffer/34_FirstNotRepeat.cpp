#include <iostream>
using namespace std;

//"桶" 
char FirstNotRepeat(char *str)
{
    if(str == NULL) return '\0';
    char tb[256] = {0};

    char *p = str;
    while(*p != '\0')
        tb[*(p++)]++;

    p = str;
    while(*p != '\0')
    {
        if(tb[*p] == 1)
            return *p;
        p++;
    }
    return '\0';
}

int main()
{
    char p[20] = "abaccdef";
    cout << FirstNotRepeat(p) << endl;
    return 0;
}


