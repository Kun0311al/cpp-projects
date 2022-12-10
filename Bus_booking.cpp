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
    cin.ignore();
    cout<<"\n\nEnter New Details:\n";
    cout<<"\nEnter Bus Name: ";
    cin.getline(bus_name,50);
    cout<<"Starting Point of Bus: ";
    cin.getline(arrival,50);
    cout<<"Last Destination of Bus: ";
    cin.getline(destination,50);
    cout<<"Ticket Fare: ";
    cin>>*price;
    cout<<"Total Seats in Bus: ";
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
    cout<<"Available Seats: "<<*seat<<"\n";
    cout<<"Price: "<<*price<<"\n";
}

void bus::buy_ticket(){
    int seat_count{0};
    cout<<"\n\nEnter the Number of seat: ";
    cin>>seat_count;
    if(seat_count<=*seat){
        cout<<"\n\nTicket Booked Successfully.\n";
        *seat=*seat-seat_count;
        cout<<"Payable amount: "<<(seat_count*(*price));
    }else{
        cout<<"\n\nRequire seats are not available. Only "<<*seat<<" seats are available.";
    }
}

void bus::cancel_ticket(){
    int cancel_count{0};
    cout<<"\n\nEnter the numbers of seat: ";
    cin>>cancel_count;
    *seat=*seat+cancel_count;
    cout<<"\n\nyour "<<cancel_count<<" tickets are canceled. Thank You.\n";
    cout<<"your ticket amount will sent to your bank in 2-3 week days.\n";
}

int main(){
    bus *b[100];
    int i{0},t,choice;
    char end_point[100], start_point[100], bus_Name[100];

    while (1)
    {
        cout<<"\n\nWelcome to Samarth Travels\n";
        cout<<"\nEnter your choice from below\n";
        cout<<"1. New Bus Entry\n";
        cout<<"2. Check Availability \n";
        cout<<"3. Book Ticket \n";
        cout<<"4. Cancel Ticket \n\n";
        cin>>choice;

        switch (choice)
        {
        case 1:
            b[i]= new bus;
            b[i] -> feed_entry();
            i++;
            break;
        
        case 2:
        cin.ignore();
            cout<<"\nEnter Bus Name: ";
            cin.getline(bus_Name,50);
            for(t=0;t<i;t++){
                if(b[t] -> search(bus_Name)){
                    cout<<"\nBus Found Successfully\n";
                    b[t] -> show_data();
                    break;
                }
                else{
                    cout<<"\nBus not found check bus name.\n";
                    break;
                }
            }
            break;

        case 3:
        cin.ignore();
            cout<<"\nEnter Bus Name: \n";
            cin.getline(bus_Name,50);
            for (t = 0; t < i; t++)
            {
                if (b[t] -> search(bus_Name)){
                    b[t]->buy_ticket();
                    break;
                }
                else{
                    cout<<"\nEnter valid Bus Name.\n";
                    break;
                } 
            }
            break;

        case 4:
        cin.ignore();
            cout<<"\nEnter Your Bus Ticket: \n";
            cin.getline(bus_Name,50);
            for (t = 0; t < i; t++)
            {
                if (b[t] -> search(bus_Name)){
                    b[t]->cancel_ticket();
                    break;
                }else{
                    cout<<"\nEnter valid Bus Name.\n";
                    break;
                }
            }
            break;
            
            
        default:
            cout<<"Enter valid choice.\n";
            break;
        }
    }
    
}