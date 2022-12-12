#include<iostream>
#include<string>
using namespace std;

class hotel{
    private:
        int *price;
        char *dine_in, *take_away;
    public:
        hotel(){
            price = new int[10];
            dine_in = new char[20];
            take_away = new char[20];
        }
        void show_menu();
        void dine_in();
        void take_away();
};

void hotel::show_menu(){

}

int main(){
    system("CLS");
    int total_bill{},i,t,choice;
    char Dish[50];

    //actual program
    while(1){
        cout<<"Welcome to Modern Pride\n";
        cout<<"\nHow Can I Help You Sir/ Maam?\n";
        cout<<"1. Show Menu\n";
        cout<<"2. Dine-In Order\n";
        cout<<"3. Take Away Order\n";
        cout<<"4. Complaint /Suggestions\n";
        cout<<"5. Contact Us\n";
        cin>>choice;

        switch(choice){
            case 1: 
                show_menu();
                break;
        }
    }
}