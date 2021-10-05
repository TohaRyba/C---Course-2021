#include <iostream>
#include <cstring>

using namespace std;

class University
{

    public:

      unsigned int amount_of_students=0;
      string Name;

//      University()
//      {
//
//     }

      University(string universitet, unsigned int std)
      {
          Name=universitet;
          amount_of_students=std;
          cout<<"\nKonstruktor universiteta";
      }

      string GetName()
      {
          return Name;
      }

      void Print()
      {
          cout<<"\nUniversity: "<<Name;
      }

      void Obshee_chislo_studentov()
      {
          cout<<"\nObshee_chislo_studentov_v_universitete: "<<amount_of_students;
      }


      ~University()
      {

      }


};

class Faculty : public University
{

private:

    string Dekan;

public:


//    Faculty()
//    {
//
//    }

    Faculty(string fakultet, string dekan, string universitet, unsigned int std) : University(universitet,std)
    {
        Name=fakultet;
        Dekan=dekan;
        amount_of_students=std;
        cout<<"\nKonstruktor fakulteta";
    }

    void Print()
    {
        cout<<"\nFaculty: "<<Name;
        cout<<"\nDekan: "<<Dekan;
    }


    ~Faculty()
    {

    }

};

class Kurs : public Faculty
{
private:

    string Kurator;

public:

//    Kurs()
//    {
//
//    }

    Kurs(string kur, string kurat, string fakultet, string dekan, string universitet, unsigned int std) : Faculty(fakultet ,dekan, universitet,std)
    {
        Name=kur;
        Kurator=kurat;
        amount_of_students=std;
        cout<<"\nKonstruktor kursa";

    }

    void Print()
    {
        cout<<"\nKurs: "<<Name;
        cout<<"\nKurator: "<<Kurator;
        cout<<"\nChislo studentov na kurse: "<<amount_of_students<<"\n";
    }


    ~Kurs()
    {

    }

};

class Group : public Kurs
{
private:

    string Starosta;

public:


//    Group()
//    {
//
//    }

    Group(string num, string star, string kur, string kurat, string fakultet, string dekan, string universitet, unsigned int std) : Kurs(kur, kurat,fakultet,dekan,universitet,std)
    {       
        Name=num;
        Starosta=star;
        amount_of_students=std;
        cout<<"\nKonstruktor gruppi\n";
    }

    void Print()
    {
        cout<<"Group: "<<Name;
        cout<<"\nStarosta: "<<Starosta;
        cout<<"\nChislo studentov v gruppe: "<<amount_of_students<<"\n";
    }


    ~Group()
    {

    }

};

int main()
{
    University Harvard("Harvard",555);
    Faculty Math("Mathematics","Olimpiec","Harvard",150);
    Kurs One("One","Petrova","Mathematics","Olimpiec","Harvard",38);
    Group MT("513","Kukish","One","Petrova","Mathematics","Olimpiec","Harvard",20);

    cout<<MT.amount_of_students<<endl;
    cout<<One.amount_of_students<<endl;
    Group AT("515","Turkish","One","Petrova","Mathematics","Olimpiec","Harvard",17);

    cout<<AT.amount_of_students<<endl;
    cout<<One.amount_of_students<<endl;
    One.Obshee_chislo_studentov();
    MT.Print();
    AT.Print();
    One.GetName();
    cout<<One.amount_of_students
          ;
//    Math.Print();
//    Math.Obshee_chislo_studentov();
//    One.Obshee_chislo_studentov();

    return 0;
}
