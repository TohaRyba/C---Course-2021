#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Person
{
    string name;
    string surname;
};

template <typename T>
class Queue
{
private:
    vector <T> Q;
    unsigned int amount;  //dlina ocheredi
    unsigned int u=0;    //schetchik
public:
    Queue(unsigned int amount)
    {
        Q.reserve(amount);
        this->amount=amount;
    }
    //vector <T> :: iterator  first;
    void add_last(T person)
    {
        u++;
        if(amount<u)
        {
            throw "Ochered perepolnena!";
        }
        Q.push_back(person);
    }
    void put_away_first()
    {
        if(u<=0)
        {
            throw "Ochered pusta!";
        }
        u--;
        Q.erase(Q.begin());
    }
    void print()
    {
        cout<<"Vot vasha ochered: \n";
        for(int i=0;i<Q.size();i++)
        {
            cout<<Q[i]<<" ";
        }
        cout<<endl;
    }
    void print(Person )
    {
        cout<<"Vot vasha ochered: \n";
        for(int i=0;i<Q.size();i++)
        {
            cout<<Q[i].name<<" "<<Q[i].surname<<endl;
        }
        cout<<endl;
    }
    ~Queue()
    {

    }
};

void Add_person()
{

}

int main()
{
    Queue <int> Queue_int(5);
    Queue_int.add_last(1);
    Queue_int.add_last(2);
    Queue_int.add_last(3);
    Queue_int.add_last(4);
    Queue_int.add_last(5);
    Queue_int.print();
    Queue_int.put_away_first();
    Queue_int.print();

    Queue <string> Queue_string(5);
    Queue_string.add_last("Petya");
    Queue_string.add_last("Vasya");
    Queue_string.add_last("Katya");
    Queue_string.add_last("Tanya");
    Queue_string.add_last("Gosha");
    Queue_string.print();
    Queue_string.put_away_first();
    Queue_string.print();

    string st="";

    Queue <Person> Queue_Person(5);
    Person A,B,X;
    A.name="Anton";
    A.surname="Ryba";
    B.name="Vlad";
    B.surname="Usha";
    Queue_Person.add_last(A);
    Queue_Person.print(A);
    Queue_Person.add_last(B);
    Queue_Person.print(B);

    unsigned int number;
    do
    {
        cout<<"1. Dobavit element v ochered <int>"<<endl;
        cout<<"2. Ubrat element iz ocheredi <int>"<<endl;
        cout<<"3. Ubrat element iz ocheredi <Person>"<<endl;
        cout<<"4. Dobavit element v ochered <Person"<<endl;
        cout<<"5. Ubrat element iz ocheredi <string>"<<endl;
        cout<<"6. Dobavit element v ochered <string>"<<endl;
        cout<<"0. Zavershenie programmy"<<endl;
        cin>>number;
        switch (number)
        {
        case 1:
            int x;
            cout<<"Vvedite celoe chislo: "<<endl;
            cin>>x;
            cout<<endl;
            try
        {
            Queue_int.add_last(x);
        }
            catch (const char *str)
        {
            cout<<str<<endl;
        }
            Queue_int.print();
            break;
        case 2:
            try
        {
             Queue_int.put_away_first();
        }
            catch (const char *str)
        {
            cout<<str<<endl;
        }
            Queue_int.print();
            break;
        case 3:
            try
        {
            Queue_Person.put_away_first();
        }
            catch (const char *str)
        {
            cout<<str<<endl;
        }
            Queue_Person.print(X);
            break;
        case 4:
            cout<<"Vvedite imya Person: "<<endl;
            cin>>X.name;
            cout<<endl;
            cout<<"Vvedite familiyu Person: "<<endl;
            cin>>X.surname;
            try
        {
            Queue_Person.add_last(X);
        }
            catch (const char *str)
        {
            cout<<str<<endl;
        }
            Queue_Person.print(X);
            X.name.clear();
            X.surname.clear();
            break;
        case 5:
            try
        {
            Queue_string.put_away_first();
        }
            catch (const char *str)
        {
            cout<<str<<endl;
        }
            Queue_string.print();
            break;
        case 6:
            cout<<"Vvedite imya: "<<endl;
            cin>>st;
            cout<<endl;
            try
        {
            Queue_string.add_last(st);
        }
            catch (const char *str)
        {
            cout<<str<<endl;
        }
            Queue_string.print();
            st.clear();
            break;

        }
    }  while (number!=0);

    return 0;
}
