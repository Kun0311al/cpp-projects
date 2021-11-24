#include<iostream>
using namespace std;
int main(){
    int rickshaw,car,bike,bus;
    int count=0,amount=0;
    int x,y;

    while(true){
        cout<<"press 1 for bike..."<<endl;
        cout<<"press 2 for rickshaw..."<<endl;
        cout<<"press 3 for car..."<<endl;
        cout<<"press 4 for bus..."<<endl;
        cout<<"press 5 for total entries..."<<endl;
        cout<<"press 6 for Delete all entries..."<<endl;
        cin>>x;

        if (x==1)
        {
            if (count<=50)
            {
                bike++;
                amount = amount + 50;
                count = count + 1;
                cout<<"Welcome.."<<endl<<endl;
            }
            else{
                cout<<"Sorry,Parking is full..!!"<<endl;
            }
            
        }
        else if(x==2){
            if (count<=50)
            {
                rickshaw++;
                amount = amount + 100;
                count = count + 1;
                cout<<"Welcome.."<<endl<<endl;
            }
            else{
                cout<<"Sorry,Parking is full..!!"<<endl;
            }
        }
        else if(x==3){
            if (count<=50)
            {
                car++;
                amount = amount + 200;
                count = count + 1;
                cout<<"Welcome.."<<endl<<endl;
            }
            else{
                cout<<"Sorry,Parking is full..!!"<<endl;
            }
        }
        else if(x==4){
            if (count<=50)
            {
                bus++;
                amount = amount + 300;
                count = count + 1;
                cout<<"Welcome.."<<endl<<endl;
            }
            else{
                cout<<"Sorry,Parking is full..!!"<<endl;
            }
        }
        else if(x==5){
            cout<<"**************************************"<<endl;
            cout<<"total vehicals in parking : "<<count<<endl;
            cout<<"total cash collect : "<<amount<<endl;
            cout<<"total bikes in parking : "<<bike<<endl;
            cout<<"total rickshaw in parking : "<<rickshaw<<endl;
            cout<<"total cars in parking : "<<car<<endl;
            cout<<"total buses in parking : "<<bus<<endl;
            y = 50 - count;
            cout<<"Remaining empty place are : "<<y<<endl;
            cout<<"**************************************"<<endl<<endl;
        }
        else if(x==6){
            count=0;
            amount=0;
            bike=0;
            rickshaw=0;
            car=0;
            bus=0;
            cout<<"**************************************"<<endl;
            cout<<"Entry book is empty.."<<endl;
            cout<<"**************************************"<<endl<<endl;
        }
        
    }
}