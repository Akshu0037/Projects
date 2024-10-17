#include<iostream>
#include<stdlib.h.>
#include<fstream>
using namespace std;



class customer
{
	string name;
	string address;
	string phn;
	double bill;
	int Room;
	int days;
	int status;
	public:
		customer()
		{
			bill=0;
			Room=0;
			days=0;
			status=0;
		}

	void cdetails();
	void cdisplay();
	friend class hotel;
	friend class room;
};
void customer::cdetails()
{
	cout<<"Enter customer name : "<<endl;
	getline(cin,name);
	cout<<"Enter the customer's address : "<<endl;
	getline(cin,address);
	flag:
	cout<<"Enter customer's Phone number : "<<endl;
	getline(cin,phn);
	if(phn.length()!=10)
	{
		cout<<"Invalid input, Please enter 10 digit Phone number.";
		goto flag;
	}
}
void customer::cdisplay()
{
	cout<<"Custommer name : "<<name;
	cout<<"Customer address : "<<address;
	cout<<"Customer Phone number : "<<phn;
}




class room
{
	int roomNo;
	double rent;
	char ac;
	char type;
	int status=1;
	public:
		room()
		{
			rent=0;
			roomNo=0;
			ac='\0';
			type='\0';
			status=0;
		}
	friend class hotel;
	void displayroom();
	void features();	
};
void room::displayroom()
{
	cout<<"----------------------------------------Rooom Details----------------------------------------"<<endl;
		cout<<"\t\tRoom No.		Type			AC/NON-AC			Rent"<<endl;
		cout<<"\t\t1			Family			AC				3000"<<endl;
		cout<<"\t\t2			Solo			NON-AC				1000"<<endl;
		cout<<"\t\t3			Deluxe			AC				2500"<<endl;
		cout<<"\t\t4			Prime			AC				3500"<<endl;
}
void room::features()
{
	int c;
		cout<<"---------------------------------------------Features---------------------------------------------"<<endl;
		cout<<"\t\tRoom No.	 Type"<<endl;
		cout<<"\t\t1	 	Family Room"<<endl;
		cout<<"\t\t2	 	Solo Room"<<endl;
		cout<<"\t\t3	 	Deluxe Room"<<endl;
		cout<<"\t\t4	 	Prime Room"<<endl;
		cout<<"\tEnter the room number of which you wanna know the features of :";
		cin>>c;
		if(c==1)
		{
			cout<<endl<<"Features of the family room : "<<endl<<endl;
			cout<<"\t\t1.Two oversized bedrooms with queen sized beds"<<endl<<"\t\t2.Wired and wireless high-speed Internet access"<<endl<<"\t\t3.Secure key-card access"<<endl<<"\t\t4.clean washrooms"<<endl<<"\t\t5.Complimentary water bottle"<<endl;	
		}
		else if(c==2)
		{
			cout<<endl<<"Features of the solo room : "<<endl<<endl;
			cout<<"\t\t1.6-bed dome room"<<endl<<"\t\t2.High speed internet connection"<<endl<<"\t\t3.Power socket near each bed"<<endl<<"\t\t4.Separate storage space for each bed with high security fingerlocks"<<endl<<"\t\t5.Common Play area"<<endl;
		}
		else if(c==3)
		{
			cout<<endl<<"Features of the deluxe room : "<<endl<<endl;
			cout<<"\t\t1.Executive writing table and stationary set"<<endl<<"\t\t2.High speed internet connection"<<endl<<"\t\t3.Peersonal digital safe"<<endl<<"\t\t4.Fully-stocked minibar"<<endl<<"\t\t5.Coffe and tea making facilities"<<endl;
		}
		else if(c==4)
		{
			cout<<endl<<"Features of the Prime room : "<<endl<<endl;
			cout<<"\t\t1.Separate living and dining areas."<<endl<<"\t\t2.fully equipped kitchen."<<endl<<"\t\t3.Two ensuite bathrooms with separate rain shower stall and bathtub."<<endl<<"\t\t4.Jaccuzzi and steamist"<<endl<<"\t\t5.Rain and massage shower"<<endl<<"\t\t6.Walk-in wardrobe"<<endl<<"\t\t7.Bathrobe, Slippers and hairdryer"<<endl;
		}
}




class hotel
{
	room a[100];		
	customer c[100];
	int nrooms=0;
	int ncust=0;
	public:
		void booking();
		void invoice();
		void cancelbook();
		void feedback();
};
void hotel::booking()
{
	char name[20];
		char add[100];
		string Pno;
		char email[30];
		int b;
		cout<<"---------------------------------------------Bookings---------------------------------------------"<<endl;
		fstream book;
		book.open("bookdetails.txt",ios::app);
			cout<<"Enter your Name :\n";
			cin>>name;
			book<<"Name="<<name<<"\n";
			
			cout<<"Enter your Address :\n";
			cin>>add;
			book<<"Address="<<add<<"\n";
			flag:
			cout<<"Enter your Phone number :\n";
			cin>>Pno;
			book<<"Phone Number="<<Pno<<"\n";
			if(Pno.length()!=10)
		{
			cout<<"Invalid input, please enter 10 digit phone number"<<endl;
			goto flag;
		}
			
		cout<<"Enter your email : ";
		cin>>email;
		book<<"Email="<<email<<"\n";
		book.close();
		
		
		
		cout<<"\t\tRoom No.	 Type"<<endl;
		cout<<"\t\t1	 	Family Room"<<endl;
		cout<<"\t\t2	 	Solo Room"<<endl;
		cout<<"\t\t3	 	Deluxe Room"<<endl;
		cout<<"\t\t4	 	Prime Room"<<endl;
		cout<<"Enter the room number you want to book : ";
		cin>>b;
		cout<<"Enter the number of days of the stay at the hotel : ";
		cin>>c[ncust].days;
		
		cout<<"Your bill will be displayed in the invoice section"<<endl;
		cout<<"Enjoy your stay!!"<<endl;
		cout<<"Booking successful!!"<<endl;
		c[ncust].Room=b;
		a[nrooms].status=1;
		nrooms++;
		
}
void hotel::invoice()
{
	int rno;
	cout<<"Enter room number : ";
	cin>>rno;
	for(int i=0;i<=nrooms;i++)
	{
		if(rno==a[i].roomNo)
		{
			c[i].cdisplay();
		}
	}
	if(rno==1)
	{
		cout<<"Your total bill is : "<<c[ncust].days*3000<<endl;
	}
	if(rno==2)
	{
		cout<<"Your total bill is : "<<c[ncust].days*1000<<endl;
	}
	if(rno==3)
	{
		cout<<"Your total bill is : "<<c[ncust].days*2500<<endl;
	}
	if(rno==4)
	{
		cout<<"Your total bill is : "<<c[ncust].days*3500<<endl;
	}	
}
void hotel::cancelbook()
{
	int rno,i,j;
	flag:
	cout<<"Enter room number : ";
	cin>>rno;
	for(i=0;i<nrooms;i++)
	{
		if(rno==c[i].Room)
		{
			cout<<"Booking cancelled!!"<<endl;
		}
		else if(rno!=c[i].Room)
		{
			cout<<"Incorrect room number, Please enter the room number in which you stayed!";
			cin>>rno;
		}
	}
	
}

void hotel::feedback()
{
	int f,r;
	string cname;
	cout<<"Enter room number : ";
	cin>>r;
	for(int i=0;i<nrooms;i++)
	{
		if(r==c[i].Room)
		{
		cout<<"Enter your Name : ";
		cin>>cname;
		cout<<" Thanks for your time!"<<endl <<"How likely are you to recommend Hotel Prashar to a Friend or Colleague?"<<endl<<"Rate on a scale of 1-10\n";
		cin>>f;
		cout<<" Thanks for your valuable feedback!"<<endl;
		}
		else
		{
		cout<<"Please enter the valid room number in which you stayed : "<<endl;
		cin>>r;
		}
	}		
}




int main()
{
	hotel h;
	room r;
	customer c;
	cout<<"------------------------------------PRASHAR'S HOTEL-----------------------------------"<<endl;
	int a;
	do
	{
		cout<<"Enter"<<endl;
		cout<<"\t\t1. Display Rooms"<<endl;
		cout<<"\t\t2. Features of rooms"<<endl;
		cout<<"\t\t3. Book a room"<<endl;
		cout<<"\t\t4. Get invoice"<<endl;
		cout<<"\t\t5. Cancel booking"<<endl;
		cout<<"\t\t6. Feedback"<<endl;
		cout<<"\t\t7. Exit"<<endl;
		cout<<"\tEnter your choice : ";
		cin>>a;
		switch (a)
		{
			case 1:
				r.displayroom();
				break;
			case 2:
				r.features();
				break;
			case 3:
				h.booking();
				break;
			case 4:
				h.invoice();
				break;
			case 5:
				h.cancelbook();
				break;
			case 6:
				h.feedback();
				break;
			case 7:
				return 0;
			default:
				cout<<"Invalid choice"<<endl;
				break ;
		}
	}while(a!=7);
}
