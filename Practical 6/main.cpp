#include "bulk.h"
#include "discountedProduct.h"
#include "labor.h"
#include "shop.h"
#include "subscription.h"
#include "item.h"

void mytest1()
{
    
product myprod("Baby oil",13,11,10);

myprod.buy("7");

float newprice=myprod.price("2");

myprod.print();
std::cout<<std::endl;
bulk mydis("Rice",12,10,8,0.1,0.8);
mydis.print();



}

void mytest2()
{
    
service service1("Braiding", 21, 5, 'h');
   
    service1.buy("17 h");

  
    float totalPrice = service1.price("3 d");

    
    service1.print();
    std::cout<<std::endl;

    std::cout<<"Total pice-> "<<totalPrice<<std::endl;
    std::cout<<std::endl;

}

void mytest3()
{
     item* productItem = new product("Fanta", 2, 3,7);
    item* bulkItem = new bulk("Cereal", 11, 5, 10, 0.15,8);
    item* discountedProductItem = new product("All-Bran", 3, 5, 0.10);
    item* serviceItem = new service("Cashier", 4, 9, 'y');
    item* subscriptionItem = new subscription("DSTv", 5, 18, 'y', 0.12);
    
    shop Checkers;
    


    Checkers.addItem(productItem);
    Checkers.addItem(bulkItem);
    Checkers.addItem(discountedProductItem);
    Checkers.addItem(serviceItem);
    Checkers.addItem(subscriptionItem);
    
    
    std::cout << "Items in the shop:" << std::endl;
    Checkers.printItems();
    
    
    std::string purchaseRequests =
        "productName:5|bulkName:5|discountedProductName:5|serviceName:5y|subscriptionName:5y|laborName:5y";
    std::cout << "Buying items:" << std::endl;
    Checkers.buyItems(purchaseRequests);
    
    
    Checkers.removeItem("productName");
    
    
    std::cout << "Updated items in the shop:" << std::endl;
    Checkers.printItems();
    
}

void mytest4()
{
    product Samsung("Test Product", 7, 5, 10);

    float Price=Samsung.price("2 y");
    std::cout<<"Price 1:"<<Price<<std::endl;
    
    if (Price==5.0) 
    {
        std::cout<<"Price is equal to 5"<<std::endl;
    }
     else
    {
        std::cout<<"Price is not equal to 5"<<std::endl;
    }

    float newPrice=Samsung.price("24 m");
    std::cout << "Price 2: " << newPrice<< std::endl;
    
    if (newPrice==10.0) 
    {
        std::cout<<"New Price is equal to 10"<<std::endl;
    } 
    else 
    {
        std::cout<<"New Price is not equal to 10"<<std::endl;
    }
}

void mytest5()
{
    bulk Supplies("Combs", 2, 8, 10, 0.9, 8);

    float Price =Supplies.price("23 y");
    std::cout<<"Price->"<<Price<<std::endl;
    
    if (Price == 14.40) 
    {
        std::cout<<"Price is equal to 14.40"<<std::endl;
    } 
    else
    {
        std::cout<<"Price is not equal to 14.40"<<std::endl;
    }

    float newPrice=Supplies.price("24 m");
    std::cout<<"New Price->"<<newPrice<<std::endl;
    
    if (newPrice==16.00)
    {
        std::cout<<"New Price is equal to 16"<<std::endl;
    } 
    else 
    {
        std::cout<<"New Price is not equal to 16"<<std::endl;
    }
}

void mytest6()
{
    discountedProduct Charger("Type-C", 3, 5, 0.10,9);

    float Price=Charger.price("2 y");
    std::cout << "Price->" <<Price<< std::endl;
    
     if (Price == 14.40) 
    {
        std::cout<<"Price is equal to 14.40"<<std::endl;
    } 
    else
    {
        std::cout<<"Price is not equal to 14.40"<<std::endl;
    }

    float newPrice=Charger.price("24 m");
    std::cout<<"New Price->"<<newPrice<<std::endl;
    
    if (newPrice==16.00)
    {
        std::cout<<"New Price is equal to 16"<<std::endl;
    } 
    else 
    {
        std::cout<<"New Price is not equal to 16"<<std::endl;
    }
}

void mytest7()
{
    int workers[] = {10, 8, 12};
    labor Office("Assistants", 4, 10, 'y', workers, 3);

    float Price= Office.price("2 y");
    std::cout << "Price->" <<Price<< std::endl;
    
     if (Price == 14.40) 
    {
        std::cout<<"Price is equal to 14.40"<<std::endl;
    } 
    else
    {
        std::cout<<"Price is not equal to 14.40"<<std::endl;
    }

    float newPrice=Office.price("24 m");
    std::cout<<"New Price->"<<newPrice<<std::endl;
    
    if (newPrice==16.00)
    {
        std::cout<<"New Price is equal to 16"<<std::endl;
    } 
    else 
    {
        std::cout<<"New Price is not equal to 16"<<std::endl;
    }
}

void mytest8()
{
    subscription tv("Netflix", 5, 18, 'm', 0.12);

    float Price= tv.price("2 y");
    std::cout << "Price->" <<Price<< std::endl;
   
    if (Price == 14.40) 
    {
        std::cout<<"Price is equal to 14.40"<<std::endl;
    } 
    else
    {
        std::cout<<"Price is not equal to 14.40"<<std::endl;
    }

    float newPrice=tv.price("24 m");
    std::cout<<"New Price->"<<newPrice<<std::endl;
    
    if (newPrice==16.00)
    {
        std::cout<<"New Price is equal to 16"<<std::endl;
    } 
    else 
    {
        std::cout<<"New Price is not equal to 16"<<std::endl;
    }
}


int main() {
    item **items = new item *[6];
    items[0] = new product("productName", 0, 5, 5);
    items[1] = new bulk("bulkName", 0, 5, 5, 0.1, 8);
    items[2] = new discountedProduct("discountedProductName", 0, 5, 5, 0.1);

    items[3] = new service("serviceName", 0, 10, 'y');
    items[4] = new subscription("subscriptionName", 0, 10, 'y', 0.1);
    int *workers = new int[1];
    workers[0] = 10;
    items[5] = new labor("laborName", 0, 10, 'y', workers, 1);
    delete[] workers;

//std::cout<<items[5].buy("12 h");

    for (int i = 0; i < 6; i++) {
        items[i]->print();
    }

    for (int i = 0; i < 3; i++) {
        items[i]->buy("5");
    }

    for (int i = 3; i < 6; i++) {
        items[i]->buy("5 w");
    }

    for (int i = 0; i < 6; i++) {
        delete items[i];
    }
    delete[] items;
std::cout<<"------------------------------------------------------------------------------------------------------------"<<std::endl;
    mytest1();
std::cout<<"------------------------------------------------------------------------------------------------------------"<<std::endl;
    mytest3();    
std::cout<<"------------------------------------------------------------------------------------------------------------"<<std::endl;
    mytest2(); 

std::cout<<"------------------------------------------------------------------------------------------------------------"<<std::endl;
    mytest4(); 

std::cout<<"------------------------------------------------------------------------------------------------------------"<<std::endl;
    mytest5();

std::cout<<"------------------------------------------------------------------------------------------------------------"<<std::endl;
    mytest6();
    std::cout<<"------------------------------------------------------------------------------------------------------------"<<std::endl;
    mytest7();
    std::cout<<"------------------------------------------------------------------------------------------------------------"<<std::endl;
    mytest8();
               
//    myTest3();

    
    return 0;
}