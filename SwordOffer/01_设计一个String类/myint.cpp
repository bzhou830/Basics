#include <iostream>
#include <string.h>

using namespace std;

class myInt
{
public:
    myInt();
    myInt(const char* str);
    myInt(const int num);
    myInt(const long num);
    
    ~myInt();
    
private:
    char* m_pMyint;
    bool m_isPositive;
};


myInt::myInt()
{
    m_pMyint = NULL;
    m_isPositive = true;
}

myInt::myInt(const char *str)
{
    int len = strlen(str);
    m_pMyint = new char[len + 1];
    memset(m_pMyint, 0, sizeof(char) * (len + 1) );
    m_isPositive = true;

    int i = 0;

    if(str[0] == '-')
    {
        m_isPositive = false;
        i++;
    }

    for(int j=0 ;str[i]!= '\0'; ++i,++j)
    {
        m_pMyint[j] = str[i];
    }
}



