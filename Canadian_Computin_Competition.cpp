#include <iostream>
#include <cstring>

using namespace std;


char st[2000];

int fact(int a);
char * exchange(char * str, int needle_len, char * ch_1);

int main()
{

    int needle_len, haystack_len;
    char str_needl[2000];
    char str_haystack[2000];

    int schet_matr=0;


    cout<<"Insert needle string:"<<endl;
    cin.getline(str_needl,2000);
    cout<<endl;
    cout<<"Insert haystack string:"<<endl;
    cin.getline(str_haystack,2000);
    cout<<endl;

    needle_len=strlen(str_needl);
    haystack_len=strlen(str_haystack);


    char matr[fact(needle_len)][needle_len];


    for (int i=0; i<needle_len; i++)
    {
        matr[0][i]=str_needl[i];

    }

    schet_matr++;
    int schet_1=0;
    int schet_2=0;


    for (int k=(needle_len-2); k>=0; k--)  // цикл пробегает указателем от к-2 до 0
    {
        schet_1=0;
        for (int j=0; j<schet_matr; j++)
        {
            for (int q=k; q<(needle_len-1); q++)
            {
                char exam[2000];
                if (schet_2==0)
                {
                    for (int i=0; i<needle_len; i++) // записываем в новую строку текущий указатель на matr
                    {
                        exam[i]=matr[j][i];
                    }
                }
                else
                {
                    for (int i=0; i<needle_len; i++) // записываем в новую строку текущий указатель на matr
                    {
                        exam[i]=matr[schet_matr+schet_1-1][i];
                    }
                }

                exchange(exam,needle_len,&exam[q]);
                for (int i=0; i<needle_len; i++) // записываем в новую строку текущий указатель на matr
                {
                    matr[schet_matr+schet_1][i]=st[i];
                }

                schet_1++;
                schet_2++;
            }

            schet_2=0;
        }
        schet_matr=schet_matr+schet_1;
    }


    //////////

    for (int i=0; i<schet_matr;i++)
    {
        for (int j=0;j<needle_len;j++)  // вывод всех строк matr
        {
            cout<<matr[i][j];
        }
        cout<<endl;
    }

    //////////
    int u=0;

    for (int i=0; i<(fact(needle_len)-1); i++)
    {
        for (int j=i+1; j<fact(needle_len); j++)
        {
            char ty_1[needle_len],ty_2[needle_len];
            for (int k=0; k<needle_len; k++)
            {
                ty_1[k]=matr[i][k];
                ty_2[k]=matr[j][k];
            }
            if (strcmp( ty_1, ty_2)==0)
            {
                u++;
            }
        }
    }
    cout<<endl;
    cout<<"Amount of equal strings from the matrix of all combinations of needle_string: "<<u<<endl<<endl<<endl;

    for (int i=0; i<(fact(needle_len)-1); i++)
    {
        for (int j=i+1; j<fact(needle_len); j++)
        {
            char ty_1[needle_len],ty_2[needle_len];
            for (int k=0; k<needle_len; k++)
            {
                ty_1[k]=matr[i][k];
                ty_2[k]=matr[j][k];
            }
            if (strcmp( ty_1, ty_2)==0)
            {
                for (int l=0; l<needle_len; l++)
                {
                    matr[j][l]='0';
                }
            }
        }
    }

    cout<<"All posible combinations of needle_string without repetition: "<<endl<<endl;
    for (int i=0; i<fact(needle_len); i++)
    {
        if (matr[i][0]!='0')
        {
            for (int j=0;j<needle_len;j++)
            {
                cout<<matr[i][j];
            }
            cout<<endl;
        }
    }
    cout<<endl;

    int answer=0;

    for (int i=0; i<fact(needle_len); i++)
    {
        if (matr[i][0]!='0')
        {
            char fg[needle_len];
            for (int j=0; j<needle_len;j ++)
            {
                fg[j]=matr[i][j];
            }

            for (int d=0; d<(haystack_len-needle_len+1); d++)
            {
                char gf[needle_len];
                for (int o=0; o<needle_len; o++)
                {
                    gf[o]=str_haystack[o+d];
                }
                if (strcmp(fg,gf)==0)
                {
                    answer++;
                    break;
                }
            }
        }
    }

    cout<<"Answer is: "<<answer<<endl;

    return 0;
}

char * exchange(char * str, int needle_len, char * ch_1)
{
    int i=0;
    while (str != ch_1)
    {
        st[i] = * str;
        str++;
        i++;
    }

    char dirka = * str;
    str++;
    st[i] = * str;
    i++;
    st[i]=dirka;
    i++;
    str++;
    while (*str!='0')
    {
        st[i] = * str;
        str++;
        i++;
    }

    return st;
}


int fact(int a)
{
    if (a==0) return 1;
    else
    {
        return a*fact(a-1);
    }
}
