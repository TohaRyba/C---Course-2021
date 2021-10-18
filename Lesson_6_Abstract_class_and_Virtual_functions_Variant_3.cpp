#include <iostream>
#include <cstring>

using namespace std;

class Shop
{
public:
    string name;
    unsigned int average_product_cost;
    virtual void ShowName(Shop & shop)=0;
    virtual void ShowAverageProductCost(Shop & shop)=0;
};

class Grocery: public Shop
{
public:
    unsigned int amount_of_products;
    Grocery(string name)
    {
        this->name=name;
    }
    Grocery(string name,unsigned int average_product_cost,unsigned int amount_of_products)
    {
        this->name=name;
        this->average_product_cost=average_product_cost;
        this->amount_of_products=amount_of_products;
    }
    void ShowAverageBill()
    {
        cout<<"\nAverage bill in grocery is: "<<(average_product_cost*amount_of_products)<<" $";
    }
    void ShowName(Shop & shop) override
    {
        cout<<"\nName is: "<<shop.name;
    }
    void ShowAverageProductCost(Shop & shop) override
    {
        cout<<"\nShow average product cost is: "<<shop.average_product_cost;
    }
    virtual void AverageRentPrice()=0;
    virtual void ShowExpirationDate()=0;
    virtual ~Grocery()
    {

    }
};

class Industrial: public Shop
{
public:
    unsigned int amount_of_products;
    Industrial(string name)
    {
        this->name=name;
    }
    Industrial(string name,unsigned int average_product_cost,unsigned int amount_of_products)
    {
        this->name=name;
        this->average_product_cost=average_product_cost;
        this->amount_of_products=amount_of_products;
    }
    void ShowAverageBill()
    {
        cout<<"\nAverage bill in grocery is: "<<(average_product_cost*amount_of_products)<<" $";
    }
    void ShowName(Shop & shop) override
    {
        cout<<"\nName is: "<<shop.name;
    }
    void ShowAverageProductCost(Shop & shop) override
    {
        cout<<"\nAverage product cost is: "<<shop.average_product_cost;
    }
    virtual void AmountOfProviders()=0;
    virtual void ShowGuarantee()=0;
    virtual ~Industrial()
    {

    }
};

class Mall: public Grocery
{
private:
    unsigned int expiration_date=20;
    float average_rent_price=22.6;
public:   
    Mall(string name,unsigned int average_product_cost,unsigned int amount_of_products): Grocery(name,average_product_cost,amount_of_products)
    {

    }
    void ShowExpirationDate() override
    {
        cout<<"\nExpiration date is: "<<expiration_date<<" days";
    }
    void ShowName(Shop & mall) override
    {
        cout<<"\nName is: "<<mall.name;
    }
    void AverageRentPrice() override
    {
        cout<<"\nAverage rent price for 1 square meter is: "<<average_rent_price<<" $";
    }
    ~Mall() override
    {

    }
};

class Supermarket: public Grocery
{
private:
    unsigned int expiration_date=30;
    float average_rent_price=32.4;
public:
    Supermarket(string name,unsigned int average_product_cost,unsigned int amount_of_products): Grocery(name,average_product_cost,amount_of_products)
    {

    }
    void ShowExpirationDate() override
    {
        cout<<"\nExpiration date is: "<<expiration_date<<" days";
    }
    void ShowName(Shop & mall) override
    {
        cout<<"\nName is: "<<mall.name;
    }
    void AverageRentPrice() override
    {
        cout<<"\nAverage rent price is: "<<average_rent_price<<" $";
    }
    ~Supermarket() override
    {

    }
};

class HouseholdChemicals: public Industrial
{
private:
    unsigned int guarantee=60;
    unsigned int amount_of_providers=14;
public:
    HouseholdChemicals(string name,unsigned int average_product_cost,unsigned int amount_of_products): Industrial(name,average_product_cost,amount_of_products)
    {

    }
    void ShowName(Shop & supermarket) override
    {
        cout<<"\nName is: "<<supermarket.name;
    }
    void ShowGuarantee() override
    {
        cout<<"\nThe guarantee in this shop is: "<<guarantee<<" days";
    }
    void AmountOfProviders() override
    {
        cout<<"\nAmount of providers of this shop are: "<<amount_of_providers;
    }
    ~HouseholdChemicals() override
    {

    }
};

class HardwareStore: public Industrial
{
private:
    unsigned int guarantee=90;
    unsigned int amount_of_providers=22;
public:
    HardwareStore(string name,unsigned int average_product_cost,unsigned int amount_of_products): Industrial(name,average_product_cost,amount_of_products)
    {

    }
    void ShowGuarantee() override
    {
        cout<<"\nThe guarantee in this shop is: "<<guarantee<<" days";
    }
    void AmountOfProviders() override
    {
        cout<<"\nAmount of providers of this shop are: "<<amount_of_providers;
    }
    ~HardwareStore() override
    {

    }
};

int main()
{
    cout<<"Shops: \n";
    Mall DanaMall("DanaMall",25,456);
    DanaMall.ShowName(DanaMall);
    DanaMall.AverageRentPrice();
    DanaMall.ShowAverageBill();
    Mall MamaMall("MamaMall",52,654);
    MamaMall.ShowName(MamaMall);
    MamaMall.AverageRentPrice();
    HouseholdChemicals WashigShop(" WashigShop",14,127);
    WashigShop.ShowName(WashigShop);
    WashigShop.ShowGuarantee();
    WashigShop.AmountOfProviders();
    HardwareStore AutoRepaire("BMW Service",53,543);
    AutoRepaire.ShowName(AutoRepaire);
    AutoRepaire.ShowAverageProductCost(AutoRepaire);
    AutoRepaire.ShowGuarantee();
    return 0;
}
