#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    unsigned int m=128;
    char* str = new char[m];
    unsigned int len;
public:
    String()
    {
        cout<<"Vvedite vashu stroku, no ne bolee 128 simvolov: \n";
        cin.getline(str,m);
        len=strlen(str);
    }

    void Variant_4()
    {
        unsigned int i,k;
        k=0;
        char ch;
        for (i=0;i<len;++i)
        {
            if (str[i]=='!')
            {
                str[i]='?';
                k=k+1;
            }
        }
        if (k==0)
        {
            for (i=0;i<(len/2);i++)
            {
                ch=str[i];
                str[i]=str[len-i-1];
                str[len-i-1]=ch;
            }
        }
    }

    void Print()
    {
        cout<<"Vot vasha stroka: \n";
        int i;
        for (i=0;i<len;++i)
        {
            cout<<str[i];
        }
        cout<<"\n";
    }

    ~String()
    {
        delete [] str;
    }
};

int main()
{
    String S;
    S.Print();
    S.Variant_4();
    S.Print();
    return 0;
}
