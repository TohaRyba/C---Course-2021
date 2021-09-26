#include <iostream>

using namespace std;

struct Student
{
   char Name[15];
   char Surname[25];
   int Mark[3];
};

int amount;

// Obyavlaem funktiyu Vivod
void Vivod(Student *r,int k);

// Sozdaem dinamicheskiy massiv structur
Student *array = new Student[amount];

int main()
{
    // Vvodim kolichestvo studentov
    int i,j;
    char x;
    do
    {
        cout<<"Vvedite kolichestvo studentov >=5 : \n";
        cin>>amount;
    } while (amount<5);


    // Zapolnyaem massiv struktur
    for (i=0;i<amount;i++)
    {
        cout<<"Vvedite imya "<<(i+1)<<" studenta: \n";
        cin>>array[i].Name;
        cout<<"Vvedite familiyu "<<(i+1)<<" studenta: \n";
        cin>>array[i].Surname;
        for (j=0;j<3;j++)
        {
            cout<<"Vvedite "<<(j+1)<<" otsenki "<<(i+1)<<" studenta: \n";
            cin>>array[i].Mark[j];
        }
    }
    // Formatno vivodim massiv structur
    void Vivod(Student *array,int amount);
    cout<<"\nVvedite luboy simvol: ";
    cin>>x;
    return 0;
}

// Sozdayom functiyu Vivod
void Vivod(Student *r,int k)
{
    int l,n;
    for (l=0;l<k;l++)
    {
        cout<<array[l].Name<<" "<<array[l].Surname<<"\n";
        cout<<"Marks are: ";
        for (n=0;n<3;n++)
        {
            cout<<array[l].Mark[n]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}

