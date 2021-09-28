#include <iostream>
#include <cmath>

using namespace std;

class Vector
{
    private:
    
        unsigned int amount;
        int *array = new int[amount];
    
    public:
        
        Vector(unsigned int razmer)
        {
            int i;
            amount=razmer;
            for (i=0;i<razmer;i++)
            {
                array[i]=rand()%100;
            }
        }
        
        Vector(int *mass, unsigned int razmer)
        {
            int i;
            amount=razmer;
            for(i=0;i<razmer;i++)
            {
                array[i]=mass[i];
            }
        }

        void Print()
        {
            int i;
            cout<<"Vot vash Vector: \n";
            for(i=0;i<amount;i++)
            {
                cout<<array[i]<<" ";
            }
            cout<<"\n";
        }

        void Sort()
        {
            int i,x,j;
            float average;
            for(i=0;i<(amount-1);i++)
            {
                x=array[i];
                for(j=0;j<(amount-1-i);j++)
                {
                   if (x<array[i+j+1])
                   {
                       x=array[i+1+j];
                       array[i+1+j]=array[i];
                       array[i]=x;
                   }

                }
            }
            j=0;
            for (i=0;i<amount;i++)
            {
                j=array[i]+j;
            }
            average=(float)j/amount;
            cout<<"Maximalnoe znachenie elementa vectora: "<<array[0]<<"\n";
            cout<<"Minimalnoe znachenie elementa vectora: "<<array[amount-1]<<"\n";
            cout<<"Srednee znachenie elementa po vectoru: "<<average<<"\n";
        }

        void Variant_4()
        {
            int i,j,k;
            int x[(amount/2+1)], y[(amount/2)];
            for(i=0;i<(amount/2+1);i++)
            {
                x[i]=0;
            }
            j=0;
            k=0;
            for(i=0;i<amount;i++)
            {
                if ((i%2)==0)
                {
                   x[j]=array[i];
                   j++;
                }
                else
                {
                    y[k]=array[i];
                    k++;
                }
            }
            for (i=0;i<j;i++)
            {
                array[i]=x[i];
            }
            for (i=j;i<amount;i++)
            {
                array[i]=y[i-j];
            }

        }

        ~Vector()
        {
            delete [] array;
        }
        
};

int main()
{
    cout<<"Vedite kolichestvo elementov v 1 massive: \n";
    int l,m;
    unsigned int k;
    int *arr_1 = new int[l];
    cin>>k;
    cout<<"Vvedite elementi massiva: \n";
    for (m=0;m<k;m++)
    {
        cout<<"Element "<<(m+1)<<" :";
        cin>>arr_1[m];
        cout<<"\n";
    }
    // Sozdayom obekt klassa pervim konstructorom
    Vector A(10);
    // Sozdayom obekt klassa vtorim konstructorom
    Vector B(arr_1,k);
    A.Print();
    B.Print();
    //Vizivaem metod sortirovki i metod varianta №4
    B.Sort();
    B.Print();
    A.Variant_4();
    A.Print();
    delete [] arr_1;
    return 0;
}
