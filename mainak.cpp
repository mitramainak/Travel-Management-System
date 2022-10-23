#include<iostream>
#include<fstream>
#include<iomanip>
#include<windows.h>
using namespace std;
void menu();

class ManageMenu
{
    protected:
    string UserName;
    public:
    ManageMenu(){
        system("color 0A");
        cout<<"\n\n\n\n\n\n\n\n\n\n\t enter your name to continue as an admin:";
        cin>>UserName ;
        system("CLS");
        menu();
    }
    ~ManageMenu(){} 
};

class Customer{
public:
string name,gender,address;
int age,mobileNo;
static int CustID; 
char all[999];
void details()
{
    ofstream out("old-customers.txt",ios::app);
    {
    cout<<"enter customer ID:-";
    cin>>CustID;
    cout<<"please enter your name:-";
    cin>>name;
    cout<<"please enter your age :-";
    cin>>age;
    cout<<"please enter your Mobile No :-";
    cin>>mobileNo;
    cout<<"please enter your address:-";
    cin>>address;
    cout<<"please enter your Gender :-";
    cin>>gender;
    }
   out<<"\nCustomerID:"<<CustID<<"\nName:"<<name<<"\nGender:"<<gender<<"\nage:"<<age<<"\nmobile Number:"<<mobileNo<<"\nAdress:"<<address<<endl;
   out.close();
   cout<<"We saved your details record for future purposes\n"<<endl;
}

    void ShowDetails()
    {int n;
     ifstream in("old-customers.txt");
     {
        if(!n)
        {
            cout<<"FIle Error!"<<endl;
        }
        while(!(in.eof()))
        {
            in.getline(all,999);
             cout<<all<<endl;
        }
        in.close();
     }
    }
};

int Customer::CustID;
 
class Cabs
{
public:
int cabChoice;
int Kilometers;
float cabcost;
static float LastCabCost;

void cabDetails()
{
cout<<"We collaborated with fastest,safest amd smartest cab services around the country"<<endl;
cout<<"---ABC Cabs---\n"<<endl;
cout<<"1.Rest a standard cab-Rs.15 for 1KM"<<endl;
cout<<"2.Rent a Luxary Cab-Rs.25 for 1KM"<<endl;

cout<<"\nTo calculate to cost for your journey:"<<endl;
cout<<"Enter Which Kind of cab you want to:"<<endl;
cin>>cabChoice;
cout<<"Enter the kilometer you want to travel:";
cin>>Kilometers;

int hirecab;
if(cabChoice==1){
    cabcost=Kilometers*15;
    cout<<"\nYour Tour cost is:"<<cabcost<<"rupees for it a standard cab"<<endl;
    cout<<"press 1 to hire this cab: or";
    cout<<"press enter 2 to select another cab:";
    cin>>hirecab;

    system("CLS");
    if(hirecab==1){
        LastCabCost=cabcost;
        cout<<"you havesuccessively hirea a standard cab"<<endl;
        cout<<"Goto Menu and Take the reciept"<<endl;
}
else if(hirecab ==  2){
    cabDetails();
}
else{
    cout<<"Invalid Input!redirecting to previous menu\nPlease wait"<<endl;
     Sleep(999);
    system("CLS");
    cabDetails();
    }
}
if(cabChoice==2){
       cabcost=Kilometers*15;
    cout<<"\nYour Tour cost is:"<<cabcost<<"rupees for it a standard cab"<<endl;
    cout<<"press 1 to hire this cab: or";
    cout<<"press enter 2 to select another cab:";
    cin>>hirecab;

    system("CLS");
    if(hirecab==1){
        LastCabCost=cabcost;
        cout<<"you havesuccessively hirea a standard cab"<<endl;
        cout<<"Goto Menu and Take the reciept"<<endl;
}
else if(hirecab ==  2){
    cabDetails();
}
else{
    cout<<"Invalid Input!redirecting to previous menu\nPlease wait"<<endl;
    Sleep(1100);
    system("CLS");
    cabDetails();
    }
}
    else{
    cout<<"Invalid Input!redirecting to MAIN menu\nPlease wait"<<endl;
    Sleep(1100);
    system("CLS");
    menu();
    }
    cout<<"\n Press redirecting to MAIN MEMU"<<endl;
    cin>>hirecab;
    system("CLS");
    if(hirecab  == 1){
    menu();
    }
    else{
        menu();
    }
}
};

float Cabs::LastCabCost;

class Booking
{
public:
int choiceHotels;
int PackChoice;
static float hotelcost;
void hotels()
{
string HotelNo[]={"Avendra,ChoiceYou","Parallal"};
for(int i=0;i<3;i++)
cout<<(i+1)<<" . Hotel"<<HotelNo[i]<<endl;
cout<<"\n currently we colloboraated the hotels!"<<endl;
cout<<"press any key to back or \nEnter number of the hotel you want to book:";
cin>>choiceHotels;
system("CLS");

if(choiceHotels==1)
{
    cout<<"----------Welcome to the HOTEL AVENDRA----------\n"<<endl;
    cout<<"The Garden,food and beverage.Enjoy all you can drink,stay coll and chillrd in the summer sum."<<endl;
    cout<<"Package offered by Avendra:\n"<<endl;
    cout<<"1. Standard Pack"<<endl;
    cout<<"\tAll basic facilities you need just for:Rs.5000.00"<<endl;
    cout<<"2. Premium Pack"<<endl;
    cout<<"\tEnjoy premium is:Rs.10000.00"<<endl;
    cout<<"3. Luxary Pack"<<endl;
    cout<<"\tLive a luxary life at Avendra:Rs.15000.00"<<endl;
    cout<<"\nPress another key for back or\nEnter package Number you want to book"<<endl;
    cin>>PackChoice; 
    if(PackChoice==1)
    {
        hotelcost=5000.00;
        cout<<"\nYou have succesivily booked Standard Pack"<<endl;
        cout<<"Go to menu to take the reciept"<<endl;
    }  
    else if(PackChoice==2)
    {
        hotelcost=10000.00;
        cout<<"\nYou have succesivily booked Premium Pack"<<endl;
        cout<<"Go to menu to take the reciept"<<endl;
    }
    else if(PackChoice==3)
    {
        hotelcost=15000.00;
        cout<<"\nYou have succesivily booked Luxary Pack"<<endl;
        cout<<"Go to menu to take the reciept"<<endl;
    }
    else{
        cout<<"Invalid Input!Redirecting to previous menu\nPlease wait"<<endl;
        Sleep(1100);
        system("CLS");
        hotels();
    }
    int gotomenu;
    cout<<"\nPlease 1 to redirect main menu:";
    cin>>gotomenu;
    if(gotomenu==1)
    {
         menu();
    }
    else
    {
        menu();
    }
}
}
};
float Booking::hotelcost;
class charges : public Booking,Cabs,Customer
{
public:
void PrintBill()
{
 ofstream outf("reciept.txt");
 {
     outf<<"----------ABC Travel Agency-----------"<<endl;
     outf<<"-------------Receipt------------------"<<endl;
     outf<<"_______________________________________"<<endl;

     outf<<"Customer ID: "<<Customer::CustID<<endl<<endl;
     outf<<"Description\t\t Total: "<<endl;
     outf<<"Hotel Cost:\t\t"<<fixed<<setprecision(2)<<Booking::hotelcost<<endl;
     outf<<"Travel (cab) cost:\t"<<fixed<<setprecision(2)<<Cabs::LastCabCost<<endl;

     outf<<"_______________________________________"<<endl;
     outf<<"Total charge:\t\t"<<fixed<<setprecision(2)<<Booking::hotelcost+Cabs::LastCabCost<<endl;
     outf<<"_______________________________________"<<endl;
     outf<<"---------------THANK YOU---------------"<<endl;
 }
 outf.close();
}

void showBill()
{
ifstream inf("receipt.txt");
{
    if(!inf)
    {
        cout<<"File Opening Error!"<<endl;
    }
    while(!(inf.eof()))
    {
        inf.getline(all,999);
        cout<<all<<endl;
    }
}
inf.close();
}
};
void menu()
{

    int mainChoice;
    int inChoice;
    int gotomenu;
   cout<<"\t\t   *ABC Travels*\n "<<endl;
   cout<<"----------------------Main Menu-------------------------"<<endl;

   cout<<"\t ____________________________________________"<<endl;
   cout<<"\t|\t\t\t\t\t|"<<endl;
   cout<<"\t|\tCustomer Management- ->1\t|"<<endl;
   cout<<"\t|\tCabs Management     -->2\t|"<<endl;
   cout<<"\t|\tBoooking Management -->3\t|"<<endl;
   cout<<"\t|\tCharges & Bill      -->4\t|"<<endl;
   cout<<"\t|\tExit                -->5\t|"<<endl;
   cout<<"\t|\t\t\t\t\t"<<endl;
   cout<<"\t____________________________________________"<<endl;

   cout<<"\nEnter your Choice:"<<endl;
   cin >>mainChoice;
   system("CLS");
   Customer a2;
   Cabs a3;
   Booking a4;
   charges a5;
   if(mainChoice==1)
   {
    cout<<"-----Customers-----\n"<<endl;
    cout<<"1. Enter New Customer"<<endl;
    cout<<"2.See Old Customer"<<endl;
    cout<<"\nEnter Choice";
    cin>>inChoice;
    system("CLS");
    if(inChoice==1)
    {
        a2.details();
    }
    else if(inChoice==2)
    {
        a2.ShowDetails();
    }
    else
    {
        cout<<"Invalid Input! Redirecting to previous menu \nPlease wait!"<<endl;
        Sleep(1100);
        system("CLS");
        menu();
    }
    cout<<"\nPress 1 to Redirect main menu:"<<endl;
    cin>>gotomenu;
    system("CLS");
    if(gotomenu==1)
    {
        menu();
    }
    else{
        menu();
    }
       }
       else if(mainChoice==2)
       {
        a3.cabDetails();
       }
       else if(mainChoice==3)
       {
        cout<<"----> Book a Luxary Hotel using the system <--"<<endl;
        a4.hotels();
       }
       else if(mainChoice==4)
       {
        cout<<"---> Get Your Receipt <---"<<endl;
        a5.PrintBill();
        cout<<"your receipt is altready printed you can get it from File path\n"<<endl;
        cout<<"to display the your receipt in the screen,Enter 1: or Enter another Key to Back Main menu:"<<endl;
        cin>>gotomenu;
        if(gotomenu==1)
        {
            system("CLS");
            a5.showBill();
            cout<<"\nPress 1 to redirect main menu:";
            cin>>gotomenu;
            system("CLS");
            if(gotomenu==1)
            {
                menu();
            }
            else
            {
                menu();
            }
            
        }
        else{
            system("CLS");
            menu();
        }
       }
       else if(mainChoice==5)
       {
        cout<<"---- GOOD-BYE----"<<endl;
        Sleep(999);
        system("CLS");
        menu();
       }
       else
       {
        cout<<"Invalid Input! Redirecting to previous menu\nPlease wait"<<endl;
        Sleep(999);
        system("CLS");
        menu();
       }
}
int main()
{
 ManageMenu StarObj;
}
