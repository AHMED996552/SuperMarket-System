#include <iostream>
#include <vector>
#include <conio.h>
#include <cmath>
#include <string>
using namespace std;

//--------variables--------------
int menu_size=9;
string name_manger ="Ahmed";
string password_manger="Ahmed120230263!";

//--------Arrays--------------
string products[20]={"Tomattos","Salad","Rice","Meat","carrots","Onions","Tissues","Botteles","Glue"};
int prices [20]={10,20,30,40,50,60,70,80,90};
vector<int> bag;
//--------Function--------------
void user_page();
void manger_page();
void show_menu();
void buy_product();
void create();
void login();
void manger_process();
void add();
void Edit();












int main ()
{
    int choice ;
    do
    {
        cout <<"------SuperMarket System-------"<<endl;
        cout <<"-------Enter to open-------"<<endl;
        getch();
        cout <<"Choose the mood"<<endl;
        cout <<"1-User"<<endl<<"2-Maneger"<<endl<<"3-Exit"<<endl;
        
        cin >> choice;
        switch (choice)
        {
        case 1:
        user_page();
        break;
        case 2:
        manger_page();
        break;
        }
    }
    while (choice!=3);
    
    
}








void user_page()
{
    int choice ;
    cout <<"========================="<<endl;
    cout <<"Enter your name"<<endl;
    string user_name;
    cin >> user_name;
    cout <<"========================="<<endl;
    cout <<"========================="<<endl;
    cout << "Welcome "<< user_name<< endl;
    do
    {
        cout <<"What you can do :"<<endl;
        cout <<"1-Show the menu"<<endl;
        cout <<"2-Buy a product"<<endl;
        cout <<"3-Exit "<<endl;
        cin >> choice;
        cout <<"========================="<<endl;
        switch (choice)
        {
            case 1:
            show_menu();
            break;
            case 2:
            buy_product();
            break;
        }
        cout <<"========================="<<endl;
    }
    while(choice!=3);
    
}

void show_menu()
{
    
    for (int i=0;i<menu_size;i++)
    {
        cout <<i+1<<"-"<<products[i] <<" "<<prices[i]<<endl;
    }
}

void buy_product()
{
    vector<int> bag;
    int choice;
    int number_of_products;
    do
    {
        int len=0;
        cout <<"choose the process :- "<< endl;
        cout <<"1-Add products to cart "<< endl;
        cout <<"2-Show the reciept"<< endl;
        cout <<"3-Return to main"<< endl;
        cin >> choice ;
        switch (choice)
        {
        case 1:
                cout << "Enter the number of products you want to buy :"<< endl;
                cin >> number_of_products;
                bag.clear();
                for (int i=0;i<number_of_products;i++)
                {
                cout << "choose the number of product number "<<i+1<< " to buy "<< endl;
                show_menu();
                int product_to_bag;
                cin >> product_to_bag;
                bag.push_back(product_to_bag);
                }
            break;
        case 2:
            int total=0;
            if (bag.empty()) 
            {
                cout << "The bag is empty please choose the products,Then show the reciept" << endl;
                buy_product();
            }
            else
            {
            for (int i=0;i<bag.size();i++)
            {
                total+=prices[bag[i]-1];
                cout <<i+1<<"-"<< products[bag[i]-1]<< " = " << prices[bag[i]-1]<<endl;
            }
            cout << "Total ="<<total <<endl;
            }
            break;
    }
    }
    while (choice!=3);

}

void manger_page()
{
    int choice;
    do
    {
        cout <<"Choose the mood"<<endl;
        cout <<"1-Create new Email"<<endl;
        cout <<"2-Login"<<endl;
        cout <<"3-Return to main"<<endl;
        cin >> choice;
    switch (choice)
    {
    case 1:
        create();
        break;
    case 2:
        login();
        break;
    
    }
    }
    while (choice!=3);
    
    

}

void create()
{
    string new_manger;
    string password;
    string re_new_manger;
    string re_password;
    int experience;
    cout << "Enter your name"<<endl;
    cin >> new_manger;
    cout << "Enter your password"<<endl;
    cin >> password;
    cout << "Enter your experience"<<endl;
    cin >> experience;
    if (experience>=3)
    {
        cout << "Congratulations on your acceptance!"<< endl;
        do
        {
            cout << "ReEnter your name"<<endl;
            cin >> re_new_manger;
            cout << "ReEnter your password"<<endl;
            cin >> re_password;
        } while (new_manger!=re_new_manger && password!=re_password);
        cout << "Welcome "<<new_manger<< endl;
        cout <<"========================="<<endl;
        manger_process();
    }
    else 
    {
        cout << "Sorry, your experience is not enough. "<< endl;
        cout << "Please apply again after reaching 3 years of experience or more"<< endl;
        cout << "Good Luck! "<< endl;
    }
}

void login()
{
    string user;
    string password;
    cout <<"Enter your user name :- "<<endl;
    cin >>user;
    cout <<"Enter your user password :- "<<endl;
    cin >>password;
    if (user==name_manger && password==password_manger)
    {
        cout <<"Welcome "<<user<<endl ;
        manger_process();
    }
}

void manger_process()
{
    int choice;
    do 
    {
        cout <<"Choose the process :"<<endl;
        cout <<"1-Add Element to menu"<<endl;
        cout <<"2-Edit"<<endl;
        cout <<"3-Return to manger page"<<endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            add();
            break;
        case 2:
            Edit();
            break;
        }
    }
    while(choice!=3);

}

void add()
{
    cout <<"The menu now has 9 products"<<endl;
    cout << "Enter the new size you want :-"<<endl;
    cin>> menu_size;
    if (menu_size<=9)
    {
        cout <<"New size must be bigger than 9"<<endl;
    }
    else 
    {
        for (int i=0;i<menu_size-9;i++)
        {
            cout <<"Enter the name of your product :-"<<endl;
            cin >> products[i+9];
            cout <<"Enter the price of your product :-"<<endl;
            cin >> prices[i+9];
        }
        show_menu();
    }
}

void Edit()
{
    int choose;
    cout << "choose the thing you want edit it in the menu :-"<<endl;
    cout <<"1-edit product "<<endl;
    cout <<"2-edit price "<<endl;
    cin >>choose;
    if (choose==1)
    {
        string edit;
        cout <<"Enter the number of product you want to edit it :"<<endl;
        show_menu();
        cin >>choose ;
        cout <<"Enter the new name of product you want to edit it :"<<endl;
        cin>> edit;
        products[choose-1]=edit;
        cout <<"The operation is done!"<<endl;
        show_menu();
    }
    else if (choose==2)
    {
        int edit;
        cout <<"Enter the number of product you want to edit his price :"<<endl;
        show_menu();
        cin >>choose ;
        cout <<"Enter the new price of product you want to edit his price :"<<endl;
        cin>> edit;
        prices[choose-1]=edit;
        cout <<"The operation is done!"<<endl;
        show_menu();
    }
}



















