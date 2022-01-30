#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

char mat[256];
char str[15];

struct otvet
{
    int arr[15][2];
    int dlina_zapisi=0;
};

int amount;
otvet * otv = new otvet[amount];

//int otvet[15][2];
int t=0;
int dlina_stroki;
int vb;
int schet=0;


void poisk_right(int x,int y, char sym[],int am,char st[],int dl,otvet ot);
void poisk_left(int x,int y, char sym[],int am,char st[],int dl,otvet ot);
void poisk_up(int x,int y, char sym[],int am,char st[],int dl,otvet ot);
void poisk_down(int x,int y, char sym[],int am,char st[],int dl,otvet ot);




int main()
{
    // Ввод строк

    cout<<"Insert the string consists of n^n letters:\n";
    cin>>mat;
    cout<<"\nInsert the string youare going to find:\n";
    cin>>str;
    cout<<"\n";

    // Счетчики

    int i=strlen(mat);
    int j=strlen(str);
    cout<<i<<"\n";
    cout<<j<<"\n";

     // Проверка на то, что матрица квадратна

    int y=0;
    for (int k=0;k<17;k++)
    {
        if (k*k==i) y++;
    }
    if (y==0)
    {
        cout<<"Matrica ne n^n!!!";
        exit(1);
    }

    // Вывод матрицы

    cout<<"There is the matrix:\n\n";
    dlina_stroki=sqrt(i);



    y=0; // Счетчик
    char matr[dlina_stroki][dlina_stroki];
    for (int k=0; k<dlina_stroki; k++)
    {
        for (int l=0; l<dlina_stroki; l++)
        {
            matr[k][l]=mat[y];
            y++;
            cout<<matr[k][l]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";


    // Расчт решения


    vb=0; // Счетчик

    for (int k=0; k<dlina_stroki; k++)
    {
        for (int l=0; l<dlina_stroki; l++)
        {
            if (matr[k][l]==str[vb])
            {
                int ko,lo;
                ko=k;
                lo=l;

                //cout<<ko<<" "<<lo<<"\n";

                for (int sd=0; sd<otv->dlina_zapisi; sd++) // Заполнили первый элемент массива otv
                {
                    otv->arr[sd][0]=0;
                    otv->arr[sd][1]=0;
                }
                otv->arr[0][0]=ko;
                otv->arr[0][1]=lo;
                otv->dlina_zapisi++;


                t++;
                vb++;
                schet++;

                otvet mt;
                for (int we=0; we<15; we++)
                {
                    mt.arr[we][0]=0;
                    mt.arr[we][1]=0;
                }
                mt.dlina_zapisi=1;

                mt.arr[0][0]=ko;
                mt.arr[0][1]=lo;


                poisk_down(ko,lo,str,vb,mat,dlina_stroki,mt);
                poisk_up(ko,lo,str,vb,mat,dlina_stroki,mt);
                poisk_right(ko,lo,str,vb,mat,dlina_stroki,mt);
                poisk_left(ko,lo,str,vb,mat,dlina_stroki,mt);

                cout<<"\n";

                cout<<"schet "<<schet<<" j="<<j<<"\n\n";

                for (int xd=0; xd<schet; xd++)   // Вывод результатов
                {
                    if (otv->dlina_zapisi==j)
                    {
                        cout<<"Answer is:\n";
                        for (int er=0; er<otv->dlina_zapisi; er++)
                        {
                            cout<<otv->arr[er][0]<<" "<<otv->arr[er][1]<<"\n";
                        }
                    }
                    otv--;
                }

                for (int xd=0; xd<schet; xd++)   // Обнуление массива указателей для дальнейшей работы
                {
                    otv->dlina_zapisi=0;
                    for (int er=0; er<15; er++)
                    {
                        otv->arr[er][0]=0;
                        otv->arr[er][1]=0;
                    }
                    otv++;
                }

                for (int xd=0; xd<schet; xd++)
                {
                    otv--;
                }
                schet=0;
                vb=0;
            }
        }

    }
    cout<<"If the answer is not displayed, then the search word is not in the matrix!\n";
    delete [] otv;
    return 0;
}


void poisk_left(int x,int y, char sym[],int am,char st[],int dl,otvet ot)
{
    cout<<"poisk_left "<<x<<" "<<y<<"\n";

    int g=0;
    char matric[dl][dl];
    for (int k=0; k<dl; k++)
    {
        for (int l=0; l<dl; l++)
        {
            matric[k][l]=st[g];
            g++;
        }
    }


    struct otvet ob;   // Копируем содержимое otvet от работы предыдущих функций
    for (int k=0; k<15; k++)
    {
        ob.arr[k][0]=0;
        ob.arr[k][1]=0;
    }
    for (int k=0; k<ot.dlina_zapisi; k++)
    {
        ob.arr[k][0]=ot.arr[k][0];
        ob.arr[k][1]=ot.arr[k][1];
    }
    ob.dlina_zapisi=ot.dlina_zapisi;


    if (y-1<0)
    {
        cout<<"poisk_left_out"<<"\n";
        return;
    }
    if (matric[x][y-1]==sym[am])
    {
        otv++;    // Переходим на следующий указатель otv и записываем в него предыдущий результат + результат этой функции
        for (int i=0; i<15; i++)
        {
            otv->arr[i][0]=0;
            otv->arr[i][1]=0;
        }

        for (int i=0; i<(ob.dlina_zapisi); i++)
        {
            otv->arr[i][0]=ob.arr[i][0];
            otv->arr[i][1]=ob.arr[i][1];
        }
        otv->dlina_zapisi=ob.dlina_zapisi+1;

        otv->arr[otv->dlina_zapisi-1][0]=x;  // Запись в массив otv
        otv->arr[otv->dlina_zapisi-1][1]=y-1;

        ot.dlina_zapisi=ob.dlina_zapisi+1;
        ot.arr[otv->dlina_zapisi-1][0]=x;   // Запись в массив для передачи следующей функции
        ot.arr[otv->dlina_zapisi-1][1]=y-1;

        t++;
        am++;
        schet++;

        if (strlen(sym)==otv->dlina_zapisi)
        {
            cout<<"poisk_left_out"<<"\n";
            return;
        }

        poisk_up(x,y-1,str,am,mat,dlina_stroki,ot);
        poisk_down(x,y-1,str,am,mat,dlina_stroki,ot);
        poisk_left(x,y-1,str,am,mat,dlina_stroki,ot);
    }
    cout<<"poisk_left_out"<<"\n";
}

void poisk_right(int x,int y, char sym[],int am,char st[],int dl,otvet ot)
{

    cout<<"poisk_right "<<x<<" "<<y<<"\n";

    int g=0;
    char matric[dl][dl];
    for (int k=0; k<dl; k++)
    {
        for (int l=0; l<dl; l++)
        {
            matric[k][l]=st[g];
            g++;
        }
    }


    struct otvet ob;   // Копируем содержимое otvet от работы предыдущих функций
    for (int k=0; k<15; k++)
    {
        ob.arr[k][0]=0;
        ob.arr[k][1]=0;
    }
    for (int k=0; k<ot.dlina_zapisi; k++)
    {
        ob.arr[k][0]=ot.arr[k][0];
        ob.arr[k][1]=ot.arr[k][1];
    }
    ob.dlina_zapisi=ot.dlina_zapisi;

    if (y+1>dlina_stroki-1)
    {
        cout<<"poisk_right_out"<<"\n";
        return;
    }
    if (matric[x][y+1]==sym[am])
    {

        otv++;    // Переходим на следующий указатель otv и записываем в него предыдущий результат + результат этой функции
        for (int k=0; k<15; k++)
        {
            otv->arr[k][0]=0;
            otv->arr[k][1]=0;
        }

        for (int k=0; k<(ob.dlina_zapisi); k++)
        {
            otv->arr[k][0]=ob.arr[k][0];
            otv->arr[k][1]=ob.arr[k][1];
        }
        otv->dlina_zapisi=(ob.dlina_zapisi+1);

        otv->arr[otv->dlina_zapisi-1][0]=x;
        otv->arr[otv->dlina_zapisi-1][1]=y+1;

        ot.dlina_zapisi=ob.dlina_zapisi+1;
        ot.arr[otv->dlina_zapisi-1][0]=x;   // Запись в массив для передачи следующей функции
        ot.arr[otv->dlina_zapisi-1][1]=y+1;


        /*
        cout<<x<<" "<<(y+1)<<" "<<otv->dlina_zapisi<<"\n";

        for (int ty=0; ty< otv->dlina_zapisi; ty++)
        {
            cout<<otv->arr[ty][0]<<" "<<otv->arr[ty][1]<<"\n";  // !!!!!!!!!!!!!!! Проверка
        }
        */

        t++;
        am++;
        schet++;

        if (strlen(sym)==otv->dlina_zapisi)
        {
            cout<<"poisk_right_out"<<"\n";
            return;
        }

        poisk_up(x,y+1,str,am,mat,dlina_stroki,ot);
        poisk_down(x,y+1,str,am,mat,dlina_stroki,ot);
        poisk_right(x,y+1,str,am,mat,dlina_stroki,ot);
    }
    cout<<"poisk_right_out"<<"\n";
}

void poisk_up(int x,int y, char sym[],int am, char st[],int dl,otvet ot)
{

    cout<<"poisk_up "<<x<<" "<<y<<"\n";

    int g=0;
    char matric[dl][dl];
    for (int k=0; k<dl; k++)
    {
        for (int l=0; l<dl; l++)
        {
            matric[k][l]=st[g];
            g++;
        }
    }


    struct otvet ob;   // Копируем содержимое объекта ot от работы предыдущих функций
    for (int k=0; k<15; k++)
    {
        ob.arr[k][0]=0;
        ob.arr[k][1]=0;
    }
    for (int k=0; k<ot.dlina_zapisi; k++)
    {
        ob.arr[k][0]=ot.arr[k][0];
        ob.arr[k][1]=ot.arr[k][1];
    }
    ob.dlina_zapisi=ot.dlina_zapisi;

    if (x-1<0)
    {
        cout<<"poisk_up_out"<<"\n";
        return;
    }

    if (matric[x-1][y]==sym[am])
    {

        otv++;    // Переходим на следующий указатель otv и записываем в него предыдущий результат + результат этой функции
        for (int i=0; i<15; i++)
        {
            otv->arr[i][0]=0;
            otv->arr[i][1]=0;
        }

        for (int i=0; i<(ob.dlina_zapisi); i++)
        {
            otv->arr[i][0]=ob.arr[i][0];
            otv->arr[i][1]=ob.arr[i][1];
        }
        otv->dlina_zapisi=ob.dlina_zapisi+1;

        otv->arr[otv->dlina_zapisi-1][0]=x-1;
        otv->arr[otv->dlina_zapisi-1][1]=y;


        ot.dlina_zapisi=ob.dlina_zapisi+1;
        ot.arr[otv->dlina_zapisi-1][0]=x-1;   // Запись в массив для передачи следующей функции
        ot.arr[otv->dlina_zapisi-1][1]=y;


        /*
        cout<<(x-1)<<" "<<y<<" "<<otv->dlina_zapisi<<"\n";


        for (int ty=0; ty< otv->dlina_zapisi; ty++)
        {
            cout<<otv->arr[ty][0]<<" "<<otv->arr[ty][1]<<"\n";  // !!!!!!!!!!!!!!! Проверка
        }
        */

        t++;
        am++;
        schet++;

        if (strlen(sym)==otv->dlina_zapisi)
        {
            cout<<"poisk_up_out"<<"\n";
            return;
        }

        poisk_up(x-1,y,str,am,mat,dlina_stroki,ot);
        poisk_left(x-1,y,str,am,mat,dlina_stroki,ot);
        poisk_right(x-1,y,str,am,mat,dlina_stroki,ot);
    }
    cout<<"poisk_up_out"<<"\n";
}

void poisk_down(int x,int y, char sym[],int am, char st[],int dl,otvet ot)
{

    cout<<"poisk_down "<<x<<" "<<y<<"\n";

    int g=0;
    char matric[dl][dl];
    for (int k=0; k<dl; k++)
    {
        for (int l=0; l<dl; l++)
        {
            matric[k][l]=st[g];
            g++;
        }
    }


    struct otvet ob;   // Копируем содержимое otvet от работы предыдущих функций
    for (int k=0; k<15; k++)
    {
        ob.arr[k][0]=0;
        ob.arr[k][1]=0;
    }
    for (int k=0; k<ot.dlina_zapisi; k++)
    {
        ob.arr[k][0]=ot.arr[k][0];
        ob.arr[k][1]=ot.arr[k][1];
    }
    ob.dlina_zapisi=ot.dlina_zapisi;

    if (x+1>dlina_stroki-1)
    {
        cout<<"poisk_down_out"<<"\n";
        return;
    }

    if (matric[x+1][y]==sym[am])
    {

        otv++;    // Переходим на следующий указатель otv и записываем в него предыдущий результат + результат этой функции
        for (int i=0; i<15; i++)
        {
            otv->arr[i][0]=0;
            otv->arr[i][1]=0;
        }

        for (int i=0; i<(ob.dlina_zapisi); i++)
        {
            otv->arr[i][0]=ob.arr[i][0];
            otv->arr[i][1]=ob.arr[i][1];
        }
        otv->dlina_zapisi=ob.dlina_zapisi+1;

        otv->arr[otv->dlina_zapisi-1][0]=x+1;
        otv->arr[otv->dlina_zapisi-1][1]=y;


        ot.dlina_zapisi=ob.dlina_zapisi+1;
        ot.arr[otv->dlina_zapisi-1][0]=x+1;   // Запись в массив для передачи следующей функции
        ot.arr[otv->dlina_zapisi-1][1]=y;


        t++;
        am++;
        schet++;

        if (strlen(sym)==otv->dlina_zapisi)
        {
            cout<<"poisk_down_out"<<"\n";
            return;
        }

        poisk_right(x+1,y,str,am,mat,dlina_stroki,ot);
        poisk_down(x+1,y,str,am,mat,dlina_stroki,ot);
        poisk_right(x+1,y,str,am,mat,dlina_stroki,ot);
    }
    cout<<"poisk_down_out"<<"\n";
}
