#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <fstream>

using namespace std;

struct Clerk
{
    string fio;
    unsigned int date_of_birth;
    unsigned int month_of_birth;
    unsigned int year_of_birth;
    string sex;
};

unsigned int amount;

ofstream fout;
ifstream fin;

void Zagruz_dannih(Clerk * B);

int main()
{
    //setlocale(LC_ALL,"ru");
    //vector <Clerk> A;

    //cout<<"Введите количество служащих: ";
    cout<<"Vvedite kolichestvo slugaschih: ";
    cin>>amount;
    //A.reserve(amount);
    Clerk A[amount];
    Clerk B[amount];
    Clerk C;

    //Zapolnyaem massiv struktur

    for (int i=0;i<amount;i++)
    {
        unsigned int l_f;      //Dlina familii
        l_f=rand()%15+1;
        A[i].fio.push_back(rand()%26+1+64);
        for (unsigned int j=0;j<(l_f-1);j++)
        {
            A[i].fio.push_back(rand()%26+1+96);
        }
        A[i].fio.push_back(' ');

        unsigned int l_i;
        l_i=rand()%8+1;       //Dlina imeni
        A[i].fio.push_back(rand()%26+1+64);
        for (unsigned int j=0;j<(l_i-1);j++)
        {
            A[i].fio.push_back(rand()%26+1+96);
        }
        A[i].fio.push_back(' ');

        unsigned int l_o;
        l_o=rand()%11+1;       //Dlina otchestva
        A[i].fio.push_back(rand()%26+1+64);
        for (unsigned int j=0;j<(l_o-1);j++)
        {
            A[i].fio.push_back(rand()%26+1+96);
        }


        A[i].year_of_birth=(rand()%47+1)+18+1956;


        A[i].month_of_birth=rand()%12+1;


        switch (A[i].month_of_birth)
        {
            case 1: A[i].date_of_birth=rand()%31+1; break;
            case 2: A[i].date_of_birth=rand()%28+1; break;
            case 3: A[i].date_of_birth=rand()%31+1; break;
            case 4: A[i].date_of_birth=rand()%30+1; break;
            case 5: A[i].date_of_birth=rand()%31+1; break;
            case 6: A[i].date_of_birth=rand()%30+1; break;
            case 7: A[i].date_of_birth=rand()%31+1; break;
            case 8: A[i].date_of_birth=rand()%31+1; break;
            case 9: A[i].date_of_birth=rand()%30+1; break;
            case 10: A[i].date_of_birth=rand()%31+1; break;
            case 11: A[i].date_of_birth=rand()%30+1; break;
            case 12: A[i].date_of_birth=rand()%31+1; break;
        }


        unsigned int sex=rand()%2;
        if (sex%2==1)
        {
            A[i].sex="male";
        }
        else
        {
             A[i].sex="female";
        }
    }


    //Zagrugaem massiv sruktur v fayl

    fout.open("MyFile.txt");
    for (unsigned int i=0;i<amount;i++)
    {
        fout<<A[i].fio<<endl;
        fout<<A[i].date_of_birth<<"."<<A[i].month_of_birth<<"."<<A[i].year_of_birth<<endl;
        fout<<A[i].sex<<endl;
    }
    fout.close();


    //Perehodim k vipolneniyu zadachi

    unsigned int number;
    do
    {
        cout<<"Viberite deystvie: \n\n";
        cout<<"1. Zagruzit dannie iz fayla\n";
        cout<<"2. Vivod dannih na ekran\n";
        cout<<"3. Sortirovka bazi dannih po alfovitu (po familii)\n";
        cout<<"4. Vivod: spisok ludey, rodivshihsya v zadannom mesyce\n";
        cout<<"5. Vivod: familiyu samogo starshego mugchini\n";
        cout<<"6. Vivod: vse familii, nachinayuschiesya s zadannoy bukvi\n";
        cout<<"0. Vihod iz programmy\n\n";
        cout<<"Vash vibor: ";
        cin>>number;
        switch(number)
        {
        case 1:
            Zagruz_dannih(B);
            break;
        case 2:
            for (int l=0;l<amount;l++)
            {
                cout<<B[l].fio<<endl;
                cout<<B[l].date_of_birth<<"."<<B[l].month_of_birth<<"."<<B[l].year_of_birth<<endl;
                cout<<B[l].sex<<endl;
                cout<<endl;
            }
            break;
        case 3:
            for (unsigned int i=0;i<=(amount-2);i++)
            {
                for (unsigned int j=(i+1);j<=(amount-1);j++)
                {
                    if (B[i].fio[0]>B[j].fio[0])
                    {
                        C.fio=B[j].fio;
                        C.sex=B[j].sex;
                        C.date_of_birth=B[j].date_of_birth;
                        C.month_of_birth=B[j].month_of_birth;
                        C.year_of_birth=B[j].year_of_birth;

                        B[j].fio.clear();
                        B[j].sex.clear();

                        B[j].fio=B[i].fio;
                        B[j].sex=B[i].sex;
                        B[j].date_of_birth=B[i].date_of_birth;
                        B[j].month_of_birth=B[i].month_of_birth;
                        B[j].year_of_birth=B[i].year_of_birth;

                        B[i].fio.clear();
                        B[i].sex.clear();

                        B[i].fio=C.fio;
                        B[i].sex=C.sex;
                        B[i].date_of_birth=C.date_of_birth;
                        B[i].month_of_birth=C.month_of_birth;
                        B[i].year_of_birth=C.year_of_birth;

                        C.fio.clear();
                        C.sex.clear();
                    }
                }
            }

            for (int l=0;l<amount;l++)
            {
                cout<<B[l].fio<<endl;
                cout<<B[l].date_of_birth<<"."<<B[l].month_of_birth<<"."<<B[l].year_of_birth<<endl;
                cout<<B[l].sex<<endl;
                cout<<endl;
            }
            break;
        case 4:
            unsigned int month_number;
            cout<<"Vvedite nomer mesyaca: ";
            cin>>month_number;
            cout<<endl;
            for (unsigned int i=0;i<amount;i++)
            {
                if (B[i].month_of_birth==month_number)
                {
                    cout<<B[i].fio<<endl;
                    cout<<B[i].date_of_birth<<"."<<B[i].month_of_birth<<"."<<B[i].year_of_birth<<endl;
                    cout<<B[i].sex<<endl;
                    cout<<endl;
                }
            }
            break;
        case 5:
            for (unsigned int i=0;i<amount;i++)
            {
                if (B[i].sex=="male")
                {
                    C.fio=B[i].fio;
                    C.sex=B[i].sex;
                    C.date_of_birth=B[i].date_of_birth;
                    C.year_of_birth=B[i].year_of_birth;
                    C.month_of_birth=B[i].month_of_birth;
                    break;
                }
            }
            for (unsigned int i=0;i<amount;i++)
            {
                if (B[i].sex=="male" && ((B[i].year_of_birth+(B[i].month_of_birth/12)+(B[i].date_of_birth/365))<(C.year_of_birth+(C.month_of_birth/12)+(C.date_of_birth/365))));
                {
                    C.fio=B[i].fio;
                    C.sex=B[i].sex;
                    C.date_of_birth=B[i].date_of_birth;
                    C.year_of_birth=B[i].year_of_birth;
                    C.month_of_birth=B[i].month_of_birth;
                }
            }
            cout<<C.fio<<endl;
            cout<<C.date_of_birth<<"."<<C.month_of_birth<<"."<<C.year_of_birth<<endl;
            cout<<C.sex<<endl;
            cout<<endl;
            break;
        case 6:
            char letter;
            cout<<"Vvedite bukvu: ";
            cin>>letter;
            cout<<endl;
            for (unsigned int i=0;i<amount;i++)
            {
                if ((B[i].fio[0]+32)==letter)
                {
                    cout<<B[i].fio<<endl;
                    cout<<B[i].date_of_birth<<"."<<B[i].month_of_birth<<"."<<B[i].year_of_birth<<endl;
                    cout<<B[i].sex<<endl;
                    cout<<endl;
                }
            }
            break;
        }

    } while (number!=0);



    return 0;
}

void Zagruz_dannih(Clerk * B)
{
    fin.open("MyFile.txt",ofstream::app);
    string st,st_date,st_month,st_year;
    for(int y=0;y<amount;y++)
    {
       getline(fin,st);
       for (int p=0;p<st.size();p++)
       {
         B[y].fio.push_back(st[p]);
       }
       //st=B[i].fio;
       st.clear();
       getline(fin,st);
       int m=0;
       int f,g;
       for (unsigned int j=0;j<st.size();j++)
       {
           if (st[j]=='.' && m==0)
           {
               f=j;
               for (int k=0;k<j;k++)
               {
                   st_date.push_back(st[k]);
               }
               m++;
               continue;
           }
           if (st[j]=='.' && m==1)
           {
               g=j;
               for (int k=(f+1);k<j;k++)
               {
                   st_month.push_back(st[k]);
               }
               m++;
               continue;
           }
           if (m==2)
           {
               for (int k=(g+1);k<(g+5);k++)
               {
                   st_year.push_back(st[k]);
               }
               m++;
           }
       }
       if (st_date.size()==2)
       {
           B[y].date_of_birth=(st_date[0]-'0')*10+(st_date[1]-'0');
       }
               else
       {
           B[y].date_of_birth=(st_date[0]-'0');
       }
       st_date.clear();
       if (st_month.size()==2)
       {
           B[y].month_of_birth=(st_month[0]-'0')*10+(st_month[1]-'0');
       }
               else
       {
           B[y].month_of_birth=(st_month[0]-'0');
       }
       st_month.clear();
       B[y].year_of_birth=(st_year[0]-'0')*1000+(st_year[1]-'0')*100+(st_year[2]-'0')*10+(st_year[3]-'0');
       st_year.clear();
       getline(fin,B[y].sex);

    }
    fin.close();
}


