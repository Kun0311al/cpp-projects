#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;

class hotel{
    private:
        int count{0},extra_charges{0};
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
        int search(char[]);
        void dine_in();
        void take_away();
        void bill_genetator();
};

void hotel::add_items(){
    cin.ignore();
    cout<<"Enter Name of new dish: "; cin.getline(new_dish,20);
    cout<<"Enter the class of dish: "; cin.getline(type_dish,20);
    cout<<"Enter the price of dish: "; cin>>*price;
}

void hotel::show_menu(){
    cout<<setw(20)<<new_dish<<setw(20)<<type_dish<<setw(10)<<*price;
}

int hotel::search(char order_dish[20]){
    if(strcmp(order_dish,new_dish)){
        return 1;
    }else{
        return 0;
    }
}

void hotel::dine_in(){
    cout<<"How much dishes you want? \n"; cin>>count;
    extra_charges = 0;
}

void hotel::bill_genetator(){
    cout<<"Your Bill Sir/Maam\n";
    cout<<"Total Price: "<<(*price)*count;
    int temp = (*price)*count;
    int p1_price = temp/100;
    int CGST = p1_price * 5;
    cout<<"CGST: \n"<<CGST;
    cout<<"SGST: \n"<<CGST;
    cout<<"Extra Charges: "<<extra_charges;
    cout<<"Total Payable amount: "<< temp + CGST + CGST + extra_charges;
    temp = p1_price = CGST = count = extra_charges = 0;
}

void hotel::take_away(){
    cout<<"How much Parcel you want? \n"; cin>>count;
    extra_charges=20;
}

int main(){
    system("CLS");
    hotel *h[100];
    int total_bill{},i,t,choice;
    char dish[50];
    char com_suggestion[100];

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
                cin.ignore();
                cout<<"What you want to order sir/maam ?\n";
                cin.getline(dish,20);
                for(t=0;t<i;t++){
                    if(h[t] -> search(dish)){
                        h[t] -> dine_in();
                        h[t] -> bill_genetator();
                        break;
                    }else{
                        cout<<"This dish is not available. Sorry\n";
                        break;
                    }
                }
                break;

            case 4:
                cin.ignore();
                cout<<"What you want to order sir/maam ?\n";
                cin.getline(dish,20);
                for(t=0;t<i;t++){
                    if(h[t] -> search(dish)){
                        h[t] -> take_away();
                        h[t] -> bill_genetator();
                        break;
                    }else{
                        cout<<"This dish is not available. Sorry\n";
                        break;
                    }
                }
                break;

            case 5:
                cout<<"Any Complaint/Suggestions? \n";
                cin.getline(com_suggestion,100);
                cout<<"Thank You Sir/Maam!\n";
                break;

            case 6:
                cout<<"Contact Details: \n";
                cout<<setw(25)<<right<<"+91 9321836220\n";
                cout<<setw(25)<<left<<"kunalparkar1233@gmail.com\n";
                
        }
    }
}