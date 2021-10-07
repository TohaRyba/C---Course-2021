#include <iostream>
#include <cmath>

using namespace std;

class Variant_4;
class Matrix;

class Variant_4
{

public:

    void Summa_v_stolbcah_s_pologitelnym_elementom(Matrix &matrix);

};

class Matrix
{
  private:

   unsigned int rows,coloumns;
   int** mass = new int*[rows];
   friend void Variant_4::Summa_v_stolbcah_s_pologitelnym_elementom(Matrix &matrix);

  public:

    Matrix()
    {
        cout<<"\nVvedite kolichestvo strok v matrice: \n";
        cin>>rows;
        cout<<"\nVvedite kolichestvo stolbcov v matrice: \n";
        cin>>coloumns;
        //Sozdayom 2-merniy massiv
        unsigned int i,j;
        for (i=0;i<rows;i++)
        {
            mass[i] = new int[coloumns];
        }
        //Inicializiruem 2-merniy massiv
        for (i=0;i<rows;i++)
        {
            for (j=0;j<coloumns;j++)
            {
               mass[i][j] = (rand() % 200 + 1) - (rand() % 200 + 1);
            }
        }

    }

    void Print()
    {
        unsigned int i,j;
        for (i=0;i<rows;i++)
        {
            for (j=0;j<coloumns;j++)
            {
               cout<<mass[i][j]<<"\t";
            }
            cout<<"\n";
        }
    }


     ~Matrix()
     {
        //Osvobogdaem dinamicheskuyu pamyat
        unsigned int i;
        for (i=0;i<rows;i++)
        {
            delete [] mass[i];
        }
        delete [] mass;
     }

};



int main()
{
    Matrix Tablica;
    Tablica.Print();
    Variant_4 E;
    E.Summa_v_stolbcah_s_pologitelnym_elementom(Tablica);
    return 0;
}

void Variant_4::Summa_v_stolbcah_s_pologitelnym_elementom(Matrix &matrix)
{
    unsigned int i,j,k;
    int mas[matrix.coloumns];
    for (i=0;i<matrix.coloumns;i++)
    {
        mas[i]=0;
    }
    for (i=0;i<matrix.coloumns;i++)
    {
        for (j=0;j<matrix.rows;j++)
        {
           //cout<<matrix.mass[j][i]<<"\n";
           if (matrix.mass[j][i]>0)
           {
               for (k=0;k<matrix.rows;k++)
               {
                   mas[i]=mas[i]+matrix.mass[k][i];
               }
               break;
           }
        }
    }
    cout<<"\nSumma v stolbcah s pologitelnym elementom: \n";
    for (i=0;i<matrix.coloumns;i++)
    {
        if (mas[i]>0)
        {
            cout<<mas[i]<<"\t";
        }

    }
    cout<<"\n";
}
