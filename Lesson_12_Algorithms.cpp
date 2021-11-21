#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Customer
{
    string fio;
    unsigned int amount_of_deals;
    unsigned int summa_of_cash;
    string email;
public:
    Customer()
    {

    }
    // Konstruktor kopirovaniya
    Customer(const Customer &other)
    {
        this->fio=other.fio;
        this->email=other.email;
        this->summa_of_cash=other.summa_of_cash;
        this->amount_of_deals=other.amount_of_deals;
    }
};

void print(Customer &other);   //Prototip funkcii

int main()
{
    unsigned int amount_of_customers;
    cout<<"Vvedite kolichestvo klientov: "<<endl;
    cin>>amount_of_customers;
    Customer A[amount_of_customers];
    unsigned int baza;
    for (unsigned int i=0;i<amount_of_customers;i++)
    {
        unsigned int l_f;      //Dlina familii
        l_f=rand()%15+1;
        A[i].fio.push_back(rand()%26+1+64);
        for (unsigned int j=0;j<(l_f-1);j++)
        {
            A[i].fio.push_back(rand()%26+1+96);
        }
        A[i].email=A[i].fio+"@gmail.com";
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

        A[i].summa_of_cash=rand()%2000+1;
        A[i].amount_of_deals=rand()%1000+1;
    }

    if (amount_of_customers<500)
    {
        baza=amount_of_customers;
    }
    else
    {
        baza=500;
    }
    Customer B[baza];

    //Sortirovka sgenerirovannogo massiva Customer

    Customer C;
    for (unsigned int i=0;i<=(amount_of_customers-2);i++)
    {
        for (unsigned int j=i+1;j<=(amount_of_customers-1);j++)
        {
            if (A[i].amount_of_deals<A[j].amount_of_deals)
            {
                C=A[j];

                A[j].fio.clear();
                A[j].email.clear();

                A[j]=A[i];

                A[i].fio.clear();
                A[i].email.clear();

                A[i]=C;

                C.fio.clear();
                C.email.clear();
            }
        }
    }

    for (unsigned int i=0;i<baza;i++)
    {
        B[i]=A[i];
    }

    for (unsigned int i=0;i<baza;i++)
    {
        cout<<(i+1)<<"."<<endl;
        print(B[i]);
        cout<<endl;
    }

    return 0;
}

void print(Customer &other)
{
    cout<<"FIO : "<<other.fio<<endl;
    cout<<"Email : "<<other.email<<endl;
    cout<<"Amount of money : "<<other.summa_of_cash<<endl;
    cout<<"Amount of deals : "<<other.amount_of_deals<<endl;
}
