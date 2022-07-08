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
            number = new long;
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
        long  *number;
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
}

//data show case
void n_acc::showdata(){
    cout<<"User name: "<<user<<endl;
    cout<<"Amount: "<<*amount;
    cout<<"Phone no: "<<*number;
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
        cout<<"cash withdrawal sucessfull"<<endl;
        cout<<"collet your cash1..:))"<<endl;
        cout<<"New account balance: "<<*amount<<endl;
    }else{
        cout<<"Not enough amount in account...:(("<<endl;
    }
    
}

//cash deposit
void n_acc::c_deposit(){
    int cash{};
    cout<<"Enter Amount : "<<endl;
    cin>>cash;
    *amount += cash;
    cout<<"user name: "<<user<<endl;
    cout<<"cash deposited successfully..:))"<<endl;
    cout<<"New account balance : "<<*amount<<endl;
}

//change name
void n_acc::change_name(){
    int p_number{};
    cout<<"Enter new number: "<<endl;
    cin>>p_number;
    *number = p_number;
    cout<<"Change number successfull..:))"<<endl;
    cout<<"user name: "<<user<<endl;
    cout<<"New phone number : "<<*number<<endl;
}

//main function
int main(){
    n_acc* U[20];
    int choice{};
    int i{0},t;
    char user_n[20];
    while (true)
    {
        cout<<"1. New Account"<<endl;
        cout<<"2. Balance enquiry"<<endl;
        cout<<"3. Cash withdrawal"<<endl;
        cout<<"4. Cash deposit"<<endl;
        cout<<"5. Edit phone number"<<endl;
        cin>>choice;
        
        switch (choice)
        {
            //New account
        case 1:
            U[i]=new n_acc;
            U[i]->New_account();
            i++;
            break;

            //balance enquiry
        case 2:
            cin.ignore();
            cout<<"Enter user name: "<<endl;
            cin.getline(user_n,20);
            for(t=0;t<i;t++){
                if (U[t]->search(user_n))
                {
                    cout<<"User found succesfully";
                    U[t]->showdata();
                    break;
                }
                
            }
            if (t==1)
            {
                cout<<"user not found";
            }
            break;

            //cash withdrawal
        case 3:
            cin.ignore();
            cout<<"Enter user name: "<<endl;
            cin.getline(user_n,20);
            for (t = 0;t < i; t++){
                if (U[t]->search(user_n)){
                    cout<<"User found succesfully";
                    U[t]->c_withdrawal();
                    break;
                }
            }
            break;

            //cash deposit
        case 4:
            cin.ignore();
            cout<<"Enter user name: "<<endl;
            cin.getline(user_n,20);
            for(t=0;t<i;t++){
                if (U[t]->search(user_n)){
                    cout<<"User found succesfully";
                    U[t]->c_deposit();
                    break;
                }
            } 
            break;   

            //edit phone number
        case 5:
            cin.ignore();
            cout<<"Enter user name: "<<endl;
            cin.getline(user_n,20);
            for(t=0;t<i;t++){
                if (U[t]->search(user_n)){
                    cout<<"User found succesfully";
                    U[t]->change_name();
                    break;
                }
            } 
            break;     
            
        
        default:
            cout<<"Enter valid choice::((("<<endl;
            break;
        }
        
    }
    
}