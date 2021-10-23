#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;

int main()
{
    auto start = chrono::high_resolution_clock::now();

    vector <float> Ryukzak;
    Ryukzak.reserve(10);                         //Vmestimost Ryukzaka vibrana 1
    for (int i=0;i<=10;i++)
    {
        Ryukzak.push_back((float)i/10);
        cout<< Ryukzak[i]<<" ";
    }
    cout<<"\n"<<Ryukzak.size();
    struct Predmet
    {
        float weight;
        float price;
      //  int number;
    };
   // unsigned int chislo_predmetov = (rand()%30+1);   //Chislo_predmetov ot 1 do 1000
    unsigned int chislo_predmetov = 5;
    Predmet mass[chislo_predmetov];
    for (int i=0;i<chislo_predmetov;i++)             //Zapolnyaem massiv predmetov
    {
        mass[i].price=((float)(rand()%100+1)/100);           //Shag ceny raven 1 cent, cena ot 1 do 100 centov
        mass[i].weight=((float)(rand()%10+1)/10);          //Shag vesa vibran 1/1000 kilograma
    }

    //Formiruem matricu resheniy
    float Matr[chislo_predmetov+1][Ryukzak.size()];
    //Zapolnyaem 0 stroku, s 0 predmetov v ryukzake
    for (int i=0;i<Ryukzak.size();i++)
    {
        Matr[0][i]=0;
    }
    //Zapolyaem matricu
    for (int i=1;i<=chislo_predmetov;i++)
    {
        for (int j=0;j<Ryukzak.size();j++)
        {
            if (Ryukzak[j]-(mass[i].weight)<0)     // Proverka na vihod za granici matrici resheniy
            {
                Matr[i][j]=Matr[i-1][j];
            }
            else
            {
                if (Matr[i-1][j]<=(Matr[i-1][(int)((Ryukzak[j]-mass[i].weight)*10)]+mass[i].price))
                {
                    Matr[i][j]=(Matr[i-1][(int)((Ryukzak[j]-mass[i].weight)*10)]+mass[i].price);
                }
                else
                {
                    Matr[i][j]=Matr[i-1][j];
                }
            }
        }
    }
    for (int i=0;i<=chislo_predmetov;i++)
    {
        cout<<"\n";
        for (int j=0;j<Ryukzak.size();j++)
        {
            cout<<Matr[i][j]<<" ";
        }
    }
    cout<<"\nVot stoimost maksimalno zapolnennogo Ryukzaka: "<<Matr[chislo_predmetov][Ryukzak.size()-1];

    auto stop = chrono::high_resolution_clock::now();  //Meryaem vremya vipolneniya koda
    chrono::duration<float> duration = (stop-start);
    cout<<"\nVremya vipolneniya programmi: "<<duration.count();

    return 0;
}
