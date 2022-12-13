#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class hotel{
    private:
        int *price;
        char *dine_in, *take_away, *new_dish,*type_dish;
    public:
        hotel(){
            new_dish = new char[20];
            price = new int[10];
            dine_in = new char[20];
            take_away = new char[20];
            type_dish = new char[20];
        }
        void add_items();
        void show_menu();
        void dine_in();
        void take_away();
};

void hotel::add_items(){
    cout<<"Enter Name of new dish: "; cin.getline(new_dish,20);
    cout<<"Enter the class of dish: "; cin.getline(type_dish,20);
    cout<<"Enter the price of dish: "; cin>>*price;
}

void hotel::show_menu(){
    cout<<setw(20)<<new_dish<<setw(20)<<type_dish<<setw(10)<<*price;
}

int main(){
    system("CLS");
    hotel *h[100];
    int total_bill{},i,t,choice;
    char Dish[50];

    //actual program
    while(1){
        cout<<"Welcome to Modern Pride\n";
        cout<<"\nHow Can I Help You Sir/ Maam?\n";
        cout<<"1. Add new item\n";
        cout<<"2. Show Menu\n";
        cout<<"3. Dine-In Order\n";
        cout<<"4. Take Away Order\n";
        cout<<"5. Complaint /Suggestions\n";
        cout<<"6. Contact Us\n";
        cin>>choice;

        switch(choice){
            case 1: 
                h[i]= new hotel;
                h[i] -> add_items();
                break;
            
            case 2:
                cout<<"Menu\n";
                for(t=0;t<i;t++){
                    h[t] -> show_menu();
                }
                cout<<"What you want to order sir/maam ?\n";
                break;
            
            case 3:
                
        }
    }
}