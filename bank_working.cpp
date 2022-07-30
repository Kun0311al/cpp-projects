#include<iostream>
#include<string>
#include<stdlib.h>
#include<cstring>
using namespace std;

class n_acc{
    public:
        n_acc(){
            user = new char[20];
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
    cin.getline(user,20);
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
    cout<<"User name: "<<user<<endl;
    cout<<"Amount: "<<*amount<<endl;
    cout<<"Phone no: "<<*number<<endl;
    cout<<"***************************************"<<endl<<endl;
}

//search user
int n_acc::search(char user_ID[20]){
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
        cout<<"New account balance: "<<*amount<<endl;
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
    cout<<"user name: "<<user<<endl;
    cout<<"cash deposited successfully..:))"<<endl;
    cout<<"New account balance : "<<*amount<<endl;
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
    cout<<"user name: "<<user<<endl;
    cout<<"New phone number : "<<*number<<endl;
    cout<<"***************************************"<<endl<<endl;
}

//main function
int main(){
    n_acc* U[20];
    int i{0},t{0};
    int choice{0};
    char user_n[20];
    while (true)
    {
        
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
                cin.getline(user_n,20);
                for(t=0;t<i;t++){
                    if (U[t]->search(user_n))
                    {
                        cout<<"User found succesfully"<<endl<<endl;
                        U[t]->showdata();
                        break;
                    }else if (t==1){
                        cout<<"user not found"<<endl<<endl;
                    }
                choice = 0;   
                }
                break;

                //cash withdrawal
            case 3:
                cin.ignore();
                cout<<"Enter user name: "<<endl;
                cin.getline(user_n,20);
                for (t = 0;t < i; t++){
                    if (U[t]->search(user_n)){
                        cout<<"User found succesfully"<<endl;
                        U[t]->c_withdrawal();
                        break;
                    }else{
                        cout<<"user not found"<<endl;
                    }
                }
                choice = 0;
                break;

                //cash deposit
            case 4:
                cin.ignore();
                cout<<"Enter user name: "<<endl;
                cin.getline(user_n,20);
                for(t=0;t<i;t++){
                    if (U[t]->search(user_n)){
                        cout<<"User found succesfully"<<endl;
                        U[t]->c_deposit();
                        break;
                    }else{
                        cout<<"user not found"<<endl;
                    }
                } 
                choice = 0;
                break;   

                //edit phone number
            case 5:
                cin.ignore();
                cout<<"Enter user name: "<<endl;
                cin.getline(user_n,20);
                for(t=0;t<i;t++){
                    if (U[t]->search(user_n)){
                        cout<<"User found succesfully"<<endl;
                        U[t]->change_name();
                        break;
                    }else{
                        cout<<"user not found"<<endl;
                    }
                } 
                choice = 0;
                break;     
                
            
            default:
                cout<<"Enter valid choice::((("<<endl;
                break;
        }
        
    }
    return 0;
    
}