#include <iostream>
#include <cstring>

using namespace std;



class String
{
    private:

    unsigned int amount;
    char* stroka = new char[amount];

    public:

      String(char* r, unsigned int k)
        {
            int j;
            for(j=0;j<k;j++)
            {
                stroka[j]=r[j];
            }
        }

      ~String()
        {
            delete [] stroka;
        }

      void Print(unsigned int m)
      {
          int i;
          for (i=0;i<m;i++)
          {
              cout<<stroka[i];
          }
          cout<<"\n";
      }

      void Variant_4(char* r,unsigned int m)
      {
          int i;
          int j=0;
          cout<<"Rabota varianta 4: \n";
          for (i=0;i<m;i++)
          {
              if (r[i]=='!')
              {
                  j=j+1;
                  stroka[i]='?';
              }
          }
          if (j==0)
          {
              for (i=0;i<=m;i++)
              {
                  stroka[i-1]=r[m-i];
              }
          }

      }

};

int main()
{
    unsigned int t=128;
    char *str = new char[t];
    unsigned int dlina;
    cout<<"Vvedite vashu stroku, no ne bolee 128 simvolov: \n";
    cin.getline(str,t);
    cout<<"Vot vasha stroka: \n";
    cout<<str;
    cout<<"\nDlina vashey stroki = "<<strlen(str)<<"\n";
    dlina = strlen(str);
    String Vasha_stroka(str,dlina);
    Vasha_stroka.Print(dlina);
    Vasha_stroka.Variant_4(str,dlina);
    Vasha_stroka.Print(dlina);
    delete [] str;
    return 0;
}
