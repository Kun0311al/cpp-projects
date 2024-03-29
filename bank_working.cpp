#include<iostream>
#include<string>
#include<stdlib.h>
#include<cstring>
#include<iomanip>
using namespace std;

class n_acc{
    public:
        n_acc(){
            user = new char[50];
            amount =new float;
            number = new long long;
        }

        //funtion declaration
        void New_account();
        void showdata();
        int search(char[]);
        void c_withdrawal();
        void c_deposit();
        void change_name();
         
    private:
        char *user;
        float *amount;
        long long *number;
};

//functions definations
//new account
void n_acc::New_account(){
    cin.ignore();
    cout<<"Enter Your name: "<<endl;
    cin.getline(user,50);
    cout<<"Enter amount:"<<endl;
    cin>>*amount;
    cout<<"Enter phone no.: "<<endl;
    cin>>*number;
    cout<<"***************************************"<<endl;
    cout<<"Account created successfully!!"<<endl;
    cout<<"***************************************"<<endl<<endl;
}

//data show case
void n_acc::showdata(){
    cout<<"***************************************"<<endl;
    cout<<setw(20)<<"User name: "<<setw(50)<<user<<endl;
    cout<<setw(20)<<"Amount: "<<setw(20)<<*amount<<endl;
    cout<<setw(20)<<"Phone no: "<<setw(20)<<*number<<endl;
    cout<<"***************************************"<<endl<<endl;
}

//search user
int n_acc::search(char user_ID[50]){
    if(strcmp(user_ID,user)==0){
        return 1;
    }else{
        return 0;
    }
}


//cash withdrawal
void n_acc::c_withdrawal(){
    int cash{};
    cout<<"Enter amount: "<<endl;
    cin>>cash;
    if (cash<=*amount){
        *amount -= cash;
        cout<<endl<<"***************************************"<<endl;
        cout<<"cash withdrawal sucessfull"<<endl;
        cout<<"collet your cash1..:))"<<endl;
        cout<<setw(20)<<"New account balance:"<<setw(20)<<*amount<<endl;
        cout<<"***************************************"<<endl<<endl;
    }else{
        cout<<endl<<"***************************************"<<endl;
        cout<<"Not enough amount in account...:(("<<endl;
        cout<<"***************************************"<<endl<<endl;
    }
    
}

//cash deposit
void n_acc::c_deposit(){
    int cash{};
    cout<<"Enter Amount : "<<endl;
    cin>>cash;
    *amount += cash;
    cout<<"***************************************"<<endl;
    cout<<"cash deposited successfully..:))"<<endl;
    cout<<setw(20)<<"user name: "<<setw(50)<<user<<endl;
    cout<<setw(20)<<"New account balance: "<<setw(20)<<*amount<<endl;
    cout<<"***************************************"<<endl<<endl;
}

//change name
void n_acc::change_name(){
    long long p_number{};
    cout<<endl<<"Enter new number: "<<endl<<endl;
    cin>>p_number;
    *number = p_number;
    cout<<"***************************************"<<endl;
    cout<<endl<<"Change number successfull..:))"<<endl<<endl;
    cout<<setw(20)<<"user name: "<<setw(50)<<user<<endl;
    cout<<setw(20)<<"New phone number : "<<setw(20)<<*number<<endl;
    cout<<"***************************************"<<endl<<endl;
}

//main function
int main(){
    system("cls");
    n_acc* U[20];
    int i{0},t{0},choice{0};
    char user_n[20];
    while (true)
    {
        cout<<"\t\tWelcome to Apna Bank\t\t"<<endl<<endl;
        cout<<"1. New Account"<<endl;
        cout<<"2. Balance enquiry"<<endl;
        cout<<"3. Cash withdrawal"<<endl;
        cout<<"4. Cash deposit"<<endl;
        cout<<"5. Edit phone number"<<endl<<endl;
        cout<<"enter your choice: "<<endl;
        cin>>choice;
        
        switch (choice)
        {
            //New account
            case 1:
                U[i]=new n_acc;
                U[i]->New_account();
                i++;
                choice = 0;
                break;

                //balance enquiry
            case 2:
                cin.ignore();
                cout<<"Enter user name: "<<endl;
                cin.getline(user_n,50);
                for(t=0;t<i;t++){
                    if (U[t]->search(user_n))
                    {
                        cout<<endl<<"User found succesfully"<<endl<<endl;
                        U[t]->showdata();
                        break;
                    }else if (t==0){
                        cout<<endl<<"user not found"<<endl<<endl;
                    }
                choice = 0;   
                }
                break;

                //cash withdrawal
            case 3:
                cin.ignore();
                cout<<"Enter user name: "<<endl;
                cin.getline(user_n,50);
                for (t = 0;t < i; t++){
                    if (U[t]->search(user_n)){
                        cout<<endl<<"User found succesfully"<<endl;
                        U[t]->c_withdrawal();
                        break;
                    }else if (t==0){
                        cout<<endl<<"user not found"<<endl;
                    }
                }
                choice = 0;
                break;

                //cash deposit
            case 4:
                cin.ignore();
                cout<<"Enter user name: "<<endl;
                cin.getline(user_n,50);
                for(t=0;t<i;t++){
                    if (U[t]->search(user_n)){
                        cout<<endl<<"User found succesfully"<<endl;
                        U[t]->c_deposit();
                        break;
                    }else if (t==0){
                        cout<<endl<<"user not found"<<endl;
                    }
                } 
                choice = 0;
                break;   

                //edit phone number
            case 5:
                cin.ignore();
                cout<<"Enter user name: "<<endl;
                cin.getline(user_n,50);
                for(t=0;t<i;t++){
                    if (U[t]->search(user_n)){
                        cout<<endl<<"User found succesfully"<<endl;
                        U[t]->change_name();
                        break;
                    }else if (t==0){
                        cout<<endl<<"user not found"<<endl;
                    }
                } 
                choice = 0;
                break;     
                
            
            default:
                cout<<endl<<"Enter valid choice::((("<<endl<<endl;
                break;
        }
        
    }
    return 0;
    
}