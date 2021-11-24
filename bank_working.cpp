#include<iostream>
using namespace std;
int main(){
    int x,amount=50000;
    int acc_no,with_amount,dip_amount;
    while(true){
        cout<<"01. Cash Withdrawal"<<endl;
        cout<<"02. Cash Deposit"<<endl;
        cout<<"03. Balance Enquiry"<<endl;
        cout<<"04. EXIT"<<endl;
        cout<<"Make your choice.."<<endl;
        cin>>x;
        cout<<endl;

        if(x==1 || x==01){
            cout<<"Enter your Account Number: "<<endl;
            cin>>acc_no;
            cout<<endl;
            cout<<"Enter Amount :"<<endl;
            cin>>with_amount;
            cout<<endl;
                if(amount>=with_amount){
                    cout<<"Take your Cash.. :)"<<endl;
                    cout<<"Thank You..!!"<<endl;
                    cout<<endl;
                    amount = amount-with_amount;
                    cout<<"Available Balance: "<<amount<<endl;
                    cout<<"**************************************"<<endl;
                    cout<<endl;
                }
                else{
                    cout<<"Don't have enough amount..:("<<endl;
                    cout<<"**************************************"<<endl;
                    cout<<endl;
                }
        }
        else if(x==2 || x==02){
            cout<<"Enter Account Number: "<<endl;
            cin>>acc_no;
            cout<<endl;
            cout<<"Enter Amount: "<<endl;
            cin>>dip_amount;
            cout<<endl;
            amount = amount+dip_amount;
            cout<<"Available Amount: "<<amount<<endl;
            cout<<"**************************************"<<endl;
            cout<<endl;
        }
        else if(x==3 || x==03){
            cout<<"Enter Account Number: "<<endl;
            cin>>acc_no;
            cout<<endl;
            cout<<"Total Available Balance is "<<amount<<endl;
            cout<<"Thank You..:)"<<endl;
            cout<<"**************************************"<<endl;
            cout<<endl;
        }
        else if(x==4 || x==04){
            cout<<endl;
            cout<<"**************************************"<<endl;
            cout<<"Thank You.."<<endl;
            cout<<"**************************************"<<endl;
            cout<<endl;
        }
    }
}