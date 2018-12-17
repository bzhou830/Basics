#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class BigInt
{
public:
    BigInt();
    BigInt(long int s);
    BigInt(string str);
    BigInt(const BigInt& a);

    friend BigInt operator+(BigInt a,BigInt b);             //重载加法
    friend BigInt operator-(BigInt a,BigInt b);             //重载减法
    friend BigInt operator*(BigInt a,BigInt b);             //重载乘法
    friend BigInt operator/(BigInt a,BigInt b);             //重载除法
    friend ostream& operator<<(ostream& out,BigInt& a);     //重载输入
    friend istream& operator>>(istream& in,BigInt& a);      //重载输出
    friend int SizeJudge(BigInt a,BigInt b);                //

    BigInt operator=(BigInt a);                             //
private:
    vector<int> vec;
    int negative;                                           //0为正，1为负
};


BigInt::BigInt()
{
    vec.push_back(0);
    negative = 0;
}

BigInt::BigInt(long int s)
{
    if(s < 0)
    {
        negative = 1;
        s = -s;
    }
    else
        negative = 0;
    int i;
    while(s>9)
    {
        i = s%10;
        vec.push_back(i);
        s /=10;
    }
    vec.push_back(s);
}

BigInt::BigInt(string str)
{
    if(str[0] == '-')
    {
        negative = 1;
        str = str.substr(1, str.size() - 1);
    }
    else
        negative = 0;

    for(int i = str.size() - 1; i >= 0; i-- )
    {
        vec.push_back(str[i]-'0');
    }
}


BigInt::BigInt(const BigInt& a)
{
    vec = a.vec;
    negative = a.negative;
}


BigInt BigInt::operator=(BigInt a)
{
    vec = a.vec;
    negative = a.negative;
    return *this;
}


ostream& operator<<(ostream& out,BigInt& a)
{
    string str = "";
    int judge = 0;
    if((a.vec[a.vec.size()-1]+'0') == '-')
        judge = 1;
    if((a.negative == 1)&&judge == 0)
    {
        str += '-';
    }
    for(int i=a.vec.size()-1;i>=0;i--)
    {
        str += (a.vec[i]+'0');
    }
    out<<str;
    return out;
}

istream& operator >> (istream& in,BigInt& a)
{
    string str="";
    in >> str;
    a.vec.clear();
    for(int i=str.size()-1;i>=0;i--)
    {
        a.vec.push_back(str[i]-'0');
    }
    return in;
}

BigInt operator+(BigInt a,BigInt b)
{
    int negative_judge = 0;
    if(a.negative == 1&&b.negative == 1)//全负
    {
        negative_judge = 1;
    }
    if(a.negative == 0&&b.negative == 0)//全正
    {
        negative_judge = 0;
    }
    if(a.negative == 0&&b.negative == 1)//a正b负
    {
        b.negative = 0;
        return (a-b);
    }
    if(a.negative == 1&&b.negative == 0)//a负b正
    {
        a.negative = 0;
        return (b-a);
    }
    BigInt c,tmp;
    int alen,blen,min,max,i;
    alen = a.vec.size();
    blen = b.vec.size();
    if(alen>blen)
    {
        c.vec = a.vec;
        tmp.vec = b.vec;
        min = blen;
        max = alen;
    }
    else
    {
        c.vec = b.vec;
        tmp.vec = a.vec;
        min = alen;
        max = blen;
    }
    for(i=0;i<min-1;i++)//min=max？
    {
        c.vec[i] += tmp.vec[i];
        if(c.vec[i]>9)
        {
            c.vec[i] -= 10;
            c.vec[i+1] += 1;
        }
    }
    c.vec[i] +=tmp.vec[i];
    if(c.vec[i]>9)
    {
        c.vec[i] -=10;
        if(min == max)
            c.vec.push_back(1);
        else
            c.vec[i+1] +=1;
    }
    for(i=min;i<max-1;i++)
    {
        if(c.vec[i]>9)
        {
            c.vec[i] -=10;
            c.vec[i+1] +=1;
        }
    }
    if(c.vec[max-1]>9)
    {
        c.vec[max-1] -=10;
        c.vec.push_back(1);
    }
    i=c.vec.size()-1;//去掉前面的0
    while(c.vec[i] == 0)
    {
        c.vec.pop_back();
        i--;
    }
    if(negative_judge == 1)
    {
        string str = "-";
        c.vec.push_back(str[0]-'0');
    }
    return c;
}

BigInt operator-(BigInt a,BigInt b)
{
    int negative_judge = 0;
    if(a.negative == 1&&b.negative == 1)//全负
    {
        a.negative = 0;
        b.negative = 0;
        return (b-a);
    }
    if(a.negative == 0&&b.negative == 0)//全正
    {
        negative_judge = 0;
    }
    if(a.negative == 0&&b.negative == 1)//a正b负
    {
        b.negative = 0;
        return (a+b);
    }
    if(a.negative == 1&&b.negative == 0)//a负b正
    {
        b.negative =1;
        return (a+b);
    }
    BigInt c,tmp;
    int alen,blen,min,max,i,judge=0;
    alen = a.vec.size();
    blen = b.vec.size();
    //大值赋给c，小值赋给tmp
    if(alen>blen)
    {
        c.vec = a.vec;
        tmp.vec = b.vec;
        min = blen;
        max = alen;
        judge = 1;
    }
    else if(alen == blen)
    {
        for(i=alen-1;i>=0;i--)
        {
            if(a.vec[i]>b.vec[i])
            {
                c.vec = a.vec;
                tmp.vec = b.vec;
                min = blen;
                max = alen;
                judge = 1;
                break;
            }
            else if(a.vec[i]<b.vec[i])
            {
                c.vec = b.vec;
                tmp.vec = a.vec;
                min = alen;
                max = blen;
                judge = 2;
                break;
            }
        }
        if(i==-1)
            return (BigInt)0;
    }
    else
    {
        c.vec = b.vec;
        tmp.vec = a.vec;
        min = alen;
        max = blen;
        judge = 2;
    }
    for(i=0;i<min;i++)//min=max？c>tmp
    {
        c.vec[i] -= tmp.vec[i];
        if(c.vec[i]<0)
        {
            c.vec[i] += 10;
            c.vec[i+1] -= 1;
        }
    }
    if(min<max)
        for(i=min;i<max;i++)
        {
            if(c.vec[i]<0)
            {
                c.vec[i] +=10;
                c.vec[i+1] -=1;
            }
        }
        if(judge == 2)
        {
            string str="-";
            c.vec.push_back(str[0]-'0');
        }
        i=c.vec.size()-1;//去掉前面的0
        while(c.vec[i] == 0)
        {
            c.vec.pop_back();
            i--;
        }
        return c;
}

BigInt operator*(BigInt a,BigInt b)
{
    BigInt c;
    int alen,blen,i,j,max,tmp;
    alen = a.vec.size();
    blen = b.vec.size();
    max = alen+blen;
    c.vec.clear();
    for(i=0;i<max;i++)
    {
        c.vec.push_back(0);
    }
    for(i=0;i<alen;i++)
    {
        for(j=0;j<blen;j++)
        {
            tmp = c.vec[i+j]+a.vec[i]*b.vec[j];
            if(tmp>9)
            {
                if(i+j+1<max)
                {
                    c.vec[i+j+1] += tmp/10;
                    tmp %= 10;
                }
                else
                {
                    c.vec.push_back(tmp/10);
                    tmp %= 10;
                }
            }
            c.vec[i+j] = tmp;
        }
    }
    i=c.vec.size()-1;//去掉前面的0
    while(c.vec[i] == 0)
    {
        c.vec.pop_back();
        i--;
    }
    if((a.negative == 0&&b.negative == 1)||(a.negative ==
1&&b.negative == 0))//a正b负//a负b正
    {
        string str="-";
        c.vec.push_back(str[0]-'0');
        c.negative = 1;
    }
    else
    {
        c.negative = 0;
    }
    return c;
}

BigInt operator/(BigInt a,BigInt b)
{
    if(SizeJudge(a,b) == -1)
    {
        return (BigInt)0;
    }
    else if(SizeJudge(a,b) == 0)
    {
        return (BigInt)1;
    }
    BigInt tmp;
    int alen,blen,i;
    alen = a.vec.size();
    blen = b.vec.size();
    if(blen == 1&&b.vec[0] == 0)
    {
        BigInt err("error");
        return err;
    }
    i = alen-blen;
    int j = 1;
    while(i>0)
    {
        j *=10;
        i--;
    }
    BigInt count(j);
    tmp = count*b;
    if(SizeJudge(a,tmp) == 1)
    {
        while(SizeJudge(a,tmp) == 1)
        {
            count = count+1;
            tmp = b*count;
        }
    }
    else if(SizeJudge(a,tmp) == -1)
    {
        while(SizeJudge(a,tmp) == -1)
        {
            count = count-1;
            tmp = b*count;
        }
    }
    if((a.negative == 0&&b.negative == 1)||(a.negative ==
1&&b.negative == 0))//a正b负//a负b正
    {
        string str="-";
        count.vec.push_back(str[0]-'0');
        count.negative = 1;
    }
    else
    {
        count.negative = 0;
    }
    return count;
}

int SizeJudge(BigInt a,BigInt b)
{//1代表大于，0代表等于，-1代表小于
    int alen,blen,i;
    alen = a.vec.size();
    blen = b.vec.size();
    if(alen>blen)
    {
        return 1;
    }
    else if(alen == blen)
    {
        for(i=alen-1;i>=0;i--)
        {
            if(a.vec[i]>b.vec[i])
            {
                return 1;
            }
            else if(a.vec[i]<b.vec[i])
            {
                return -1;
            }
        }
        if(i==0)
            return 0;
    }
    else
    {
        return -1;
    }
}

int main()
{
    ////测试数据输入
    BigInt a("999999999999999999999"),b("8888"),c;
    //cin>>b;
    //cout<<"the input:"<<b<<endl;
    c = a+b;
    cout<<a<<"+"<<b<<"="<<c<<endl;
    //cin.get();
    ////测试加法
    //BigInt a("999999999999999999999"),b("8888"),c;
    //c = a+b;
    //cout<<a<<"+"<<b<<"="<<c<<endl;
    //BigInt d("-1111");
    //c = a+d;
    //cout<<a<<"+"<<d<<"="<<c<<endl;
    //c = 7777777+a;
    //cout<<"7777777"<<"+"<<a<<"="<<c<<endl;
    //BigInt s(a);//调用拷贝构造函数
    //c = s+a;
    //cout<<s<<"+"<<a<<"="<<c<<endl;
    ////测试减法
    //BigInt a("999999999999999999999"),b("8888"),c;
    //c = a-b;
    //cout<<a<<"-"<<b<<"="<<c<<endl;
    //BigInt d("-1111");
    //c = a-d;
    //cout<<a<<"-"<<d<<"="<<c<<endl;
    //c = 7777777-a;
    //cout<<"7777777"<<"-"<<a<<"="<<c<<endl;
    ////测试乘法
    //BigInt a("999999999999999999999"),b("8888"),c;
    //c = a*b;
    //cout<<a<<"*"<<b<<"="<<c<<endl;
    //BigInt d("-1111");
    //c = a*d;
    //cout<<a<<"*"<<d<<"="<<c<<endl;
    //c = 7777777*a;
    //cout<<"7777777"<<"*"<<a<<"="<<c<<endl;
    ///测试除法
    //BigInt a("999999999999999999999"),b("888888888888888"),c;
    //c = a/b;
    //cout<<a<<"/"<<b<<"="<<c<<endl;
    //c = b/a;
    //cout<<b<<"/"<<a<<"="<<c<<endl;
    //BigInt d("-111111111111111");
    //c = a/d;
    //cout<<a<<"/"<<d<<"="<<c<<endl;
    //c = 0/a;
    //cout<<"0"<<"/"<<a<<"="<<c<<endl;
    //计算并显示30！
    //BigInt a("30"),c("1");
    //int i = 30;
    //while(i>0)
    //{
    //    c = c*a;
    //    a = a-1;
    //    i--;
    //}
    //cout<<"30! = "<<c<<endl;
    return 0;
}
