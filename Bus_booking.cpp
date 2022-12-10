#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

class bus {
    private:
        char *bus_name, *destination, *arrival;
        int *seat;
        float *price;
    public:
        bus() {
            bus_name = new char[100];
            destination = new char[100];
            arrival = new char[100];
            seat = new int[60];
            price = new float[100];
        }
        void feed_entry();
        void show_data();
        void buy_ticket();
        void cancel_ticket();
        int search(char[]);
};

void bus::feed_entry(){
    
    cout<<"Starting Point of Bus: \n";
    cin.getline(arrival,50);
    cout<<"Last Destination of Bus: \n";
    cin.getline(destination,50);
    cout<<"Enter Bus Name: \n";
    cin.getline(bus_name,50);
    cout<<"Ticket Fare: \n";
    cin>>*price;
    cout<<"Total Seats in Bus: \n";
    cin>>*seat;
}

int bus::search(char name[50]){
    if(strcmp(name,bus_name)==0){
        return 1;
    }
    else{
        return 0;
    }
}

void bus::show_data(){
    cout<<"Bus name: "<<bus_name<<"\n";
    cout<<"Arrival: "<<arrival<<"\n";
    cout<<"Destination: "<<destination<<"\n";
    cout<<"Available Seats: "<<seat<<"\n";
    cout<<"Price: "<<price<<"\n";
}

void bus::buy_ticket(){
    int seat_count{0};
    cout<<"Enter the Number of seat: ";
    cin>>seat_count;
    if(seat_count<=*seat){
        cout<<"Ticket Booked Successfully.\n";
        *seat=*seat-seat_count;
        cout<<"Payable amount: "<<(seat_count*(*price));
    }else{
        cout<<"Require seats are not available. Only "<<*seat<<" seats are available.";
    }
}

void bus::cancel_ticket(){
    int cancel_count{0};
    cout<<"Enter the numbers of seat: ";
    cin>>cancel_count;
    *seat=*seat+cancel_count;
    cout<<"your "<<cancel_count<<" tickets are canceled. Thank You.\n";
    cout<<"your ticket amount will sent to your bank in 2-3 week days.\n";
}

int main(){
    bus *b[100];
    int i{0},t,choice;
    char end_point[100], start_point[100], bus_Name[100];

    while (1)
    {
        cout<<"Welcome to Samarth Travels\n";
        cout<<"Enter your choice from below\n";
        cout<<"1. New Bus Entry\n";
        cout<<"2. Check Availability \n";
        cout<<"3. Book Ticket \n";
        cout<<"4. Cancel Ticket \n";
        cin>>choice;

        switch (choice)
        {
        case 1:
            b[i]= new bus;
            b[i] -> feed_entry();
            i++;
            break;
        
        case 2:
            cout<<"Enter Bus Name: \n";
            cin.getline(bus_Name,50);
            for(t=0;t<i;t++){
                if(b[t] -> search(bus_Name)){
                    cout<<"\nBus Found Successfully\n";
                    b[t] -> show_data();
                    break;
                }
                if(t==i){
                    cout<<"Bus not found check bus name.\n";
                    break;
                }
            }
            break;

        case 3:
            cout<<"Enter Bus Name: \n";
            cin.getline(bus_Name,50);
            for (t = 0; t < i; t++)
            {
                if (b[t] -> search(bus_Name)){
                    b[t]->buy_ticket();
                    break;
                }
                if (t==i)
                {
                    cout<<"Enter valid Bus Name.\n";
                    break;
                } 
            }
            break;

        case 4:
            cout<<"Enter Your Bus Ticket: \n";
            cin.getline(bus_Name,50);
            for (t = 0; t < i; t++)
            {
                if (b[t] -> search(bus_Name)){
                    b[t]->cancel_ticket();
                    break;
                }if(t==i)
                {
                    cout<<"Enter valid Bus Name.\n";
                    break;
                }
            }
            break;
            
            
        default:
            break;
        }
    }
    
}