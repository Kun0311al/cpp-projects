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

        void New_account();
        void showdata();
        int search(char[]);
         
    private:
        char *user;
        float *amount;
        long  *number;
};

void n_acc::New_account(){
    cin.ignore();
    cout<<"Enter Your name: "<<endl;
    cin.getline(user,20);
    cout<<"Enter amount:"<<endl;
    cin>>*amount;
    cout<<"Enter phone no.: "<<endl;
    cin>>*number;
}

void n_acc::showdata(){
    cout<<"User name: "<<user<<endl;
    cout<<"Amount: "<<*amount;
    cout<<"Phone no: "<<*number;
}

int n_acc::search(char user_ID[20]){
    if(strcmp(user_ID,user)==0){
        return 1;
    }else{
        return 0;
    }
}

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
        cout<<"5. Edit name"<<endl;
        cin>>choice;
        
        switch (choice)
        {
        case 1:
            U[i]=new n_acc;
            U[i]->New_account();
            i++;
            break;
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
            
        
        default:
            break;
        }
        
    }
    
}