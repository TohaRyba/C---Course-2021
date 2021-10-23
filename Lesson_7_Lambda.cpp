#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int main()
{
    //Zadanie №1. Vivod vektora lambda-funkciey
    vector <int> V = {1,2,3,4,5,6,7,8,9};
    auto f = [&V]()
    {
        for (unsigned int i=0;i<V.size();i++)
        {
            cout<<V[i]<<" ";
        }
    };
    cout<<"Vot vash vector: \n";
    f();
    cout<<endl;

    //Zadanie №2. Lambda-funkciya dlya podschota kolichestva perestanovok v vektore
    vector <int> W;
    unsigned int k=rand()%100+1;
    W.reserve(k);
    auto f1 = [&k](vector <int> &t)
    {
        cout<<"Vot vash vector: \n";
        for (unsigned int i=0;i<k;i++)
        {
            t[i]=rand()%100+1;
            cout<<t[i]<<" ";
        }
        unsigned int chislo_perestanovok=0;
        unsigned int l;
        for (unsigned int i=0;i<k;i++)
        {
            for (unsigned int j=i+1;j<k;j++)
            {
                if (t[i]>t[j])
                {
                    l=t[i];
                    t[i]=t[j];
                    t[j]=l;
                    chislo_perestanovok++;
                }
            }
        }
        cout<<"\nVot vash otsortirovanniy vector: \n";
        for (unsigned int i=0;i<k;i++)
        {
            cout<<t[i]<<" ";
        }
        cout<<"\nVot chislo perestanovok pri sortirovke: "<<chislo_perestanovok<<endl;
    };
    f1(W);
    f1(W);

    //Zadanie №3. Lambda dlya poiska vhogdeniya podstroki v stroku

    char str[]="Эта программа написана в Windows 10";
    char pod_str[]="Windows";
    auto f2 = [str,pod_str]()
    {
        int i=0;
        int j=0;
        while(pod_str[i]!=0)
        {
            i++;
        }
        char *ch = strstr(str,pod_str);
        cout<<"\nVot vasha podstroka: ";
        for (j=0;j<i;j++)
        {
            cout<<ch[j];
        }
    };
    f2();

    //Zadanie №4. Generaciya vectora iz N posledovateelnih elementov
    vector <int> Y;
    auto f3 = [&Y](int n)
    {
        for (int i=0;i<=n;i++)
        {
            Y.push_back(i);
        }
        cout<<"\nVot sgenerirovanniy vector: ";
        for (int i=0;i<=n;i++)
        {
            cout<<Y[i]<<" ";
        }
    };
    f3(27);

    //Zadanie №5. Sformirovat noviy vector.
    vector <int> Q;
    int k_1=(rand()%50 +1);
    cout<<"\nVot vash vektor: ";
    for (int i=0;i<k_1;i++)
    {
        Q.push_back(i);
        cout<<Q[i]<<" ";
    }
    cout<<"\nChislo elementov v vektore: "<<k_1;
    auto f4 = [k_1](vector <int> &Q, int k)
    {
        vector <int> Q_1;
        if (Q.size()<=k)
        {
            cout<<"\n K dolgno bit < chisla elementov v vektore";
            return 0;
        }
        cout<<"\nVot sformirovanniy vector: ";
        for (int i=0;i<k_1;i++)
        {
             Q_1.push_back(i+k);
             cout<<Q_1[i]<<" ";
        }
    };
    f4(Q,5);
    return 0;
}
