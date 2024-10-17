#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<iomanip>
using namespace std;
class data
{
	int no,stno,r;
	string fname,lname,line,hno,vno,area,city,state;
	string contact;
	float fine;
	public:
		void showdata();
		void adddata();
		void deletedata();
		void searchdata();
		void moredata();
		void detaildata();
};

void data::showdata()
{
	int x=0;
	fstream file;
	file.open("traffic data.txt",ios::out|ios::app|ios::in);
	cout<<setw(5)<<"Reg No."<<ends<<setw(10)<<"Name"<<endl;
	while(file.good())
	{
		file>>no;
		getline(file,line);
		if(x!=no)
		cout<<setw(5)<<no<<ends<<setw(20)<<line<<endl;
		x=no;
	}
	file.close();
	
}

void data::adddata()
{
	int n;
	fstream file;
	file.open("traffic data.txt",ios::out|ios::app|ios::in);
	int t;
	cout<<"Enter number of data: ";
	cin>>t;
	cout<<"Enter the data: "<<endl<<"Reg No. First Name Last Name "<<endl;
	for(int i=0;i<t;i++)
	{
		cin>>no>>fname>>lname;
		file<<setw(5)<<no<<ends<<setw(10)<<fname<<setw(10)<<lname<<endl;
   	}
	file.close();
}

void data::deletedata()
{
	string temp;
	fstream file;
	fstream fin;
	cout<<endl<<"Enter the id number of defaulter: ";
	int d,f,p,i=0;
	file.open("traffic data.txt",ios::in|ios::out);
	fin.open("temperary files.txt",ios::out|ios::in|ios::trunc);
	cin>>d;
	while(file.good())//for writing Temperary Files 
	{
		file>>no;
		getline(file,fname);
		if(d!=no)
		{
			if(i!=no)
			{
				cout<<setw(5)<<no<<ends<<setw(10)<<fname<<endl;
				fin<<setw(5)<<no<<ends<<setw(10)<<fname<<endl;
			}			
			i=no;
		}
		
	}
	file.close();
	fin.close();
	fin.open("temperary files.txt",ios::out|ios::in);
	file.open("traffic data.txt",ios::out|ios::in);//adding data again
	while(fin.good())//for writing Temperary Files 
	{
		fin>>no;
		getline(fin,fname);
		if(fname!=temp)	file<<setw(5)<<no<<ends<<setw(10)<<fname<<endl;
		temp=fname;		
	}
	
	file.close();
	fin.close();
}

void data::moredata()
{
	int d,t=0,e=0;
	fstream file,f;
	file.open("traffic data.txt",ios::out|ios::app|ios::in);
	f.open("Additional Files.txt",ios::out|ios::app|ios::in);
	cout<<endl<<"Enter the Reg no of Defaulter: ";
	cin>>d;
	while(file.good())
	{
		file>>no;
		getline(file,line);
		if(no==d)
		{
			
			cout<<endl<<"Enter Required Data: "<<endl;
			cout<<"\t Vehicle No: (SS00CC0000) "; cin>>vno;
			cout<<"\t House No. : "; cin>>hno;
			cout<<"\t Area Name: (one Word) "; cin>>area;
			cout<<"\t City: "; cin>>city;
			cout<<"\t State: "; cin>>state;
			cout<<"\t Contact Number: "; cin>>contact;
			cout<<"\t Fine: Rs "; cin>>fine;
			f<<setw(5)<<no<<ends<<setw(11)<<vno<<ends<<setw(11)<<hno<<ends<<setw(11)<<area<<ends<<setw(11)<<city<<ends<<setw(11)<<state<<ends<<setw(11)<<contact<<ends<<setw(11)<<fine<<endl;
			t=d;
			e=1;
			goto stop;
		}
	}
	if(e!=1) cout<<"Invalid Registration no."<<endl;
		f>>no>>vno>>hno>>area>>city>>state>>contact>>fine;
		cout<<setw(5)<<no<<ends<<setw(11)<<vno<<ends<<setw(11)<<hno<<area<<city<<state<<contact<<fine;
	stop:
	file.close();
	f.close();
}

void data::searchdata()
{
	fstream file;
	cout<<endl<<"Enter the id number of defaulter: ";
	int d,f,p;
	file.open("traffic data.txt",ios::out|ios::in);
	cin>>d;
	while(file.good())
	{
		file>>no;
		getline(file,line);
		if(d==no)
		{
			cout<<setw(5)<<no<<ends<<setw(20)<<line<<endl;
			f=1;
			
		}
	}
	
	if(f!=1) cout<<"Wrong Id number OR Data not present"<<endl;
	file.close();
}

void data::detaildata()
{
	int q,e=0,u=0;
	fstream file,f;
	file.open("traffic data.txt",ios::out|ios::in);
	f.open("Additional Files.txt",ios::out|ios::app|ios::in);
	cout<<endl<<"Enter The Registration no. of Required defaulter: ";
	cin>>q;
	while(file.good())
	{
		file>>no;
		getline(file,line);
		if(q==no) 
		{
			e=1;
			cout<<endl<<"Registration no: "<<no;
			cout<<endl<<"Name: "<<line;
			while(f.good())
			{
				f>>no;
				getline(f,fname);
				if(q==no)
				{
					
					u=1;
				}
			}
			if(u!=1) 
			{
				cout<<endl<<"ERROR!!!!! DATA NOT FOUND ;-( ";
				goto p;
			}	
			cout<<endl<<"details: "<<endl;
			cout<<ends<<setw(11)<<"Vehicle No"<<ends<<setw(11)<<"House No"<<ends<<setw(11)<<"Area Name"<<ends<<setw(11)<<"City"<<ends<<setw(11)<<"State"<<ends<<setw(11)<<"Contact"<<ends<<setw(11)<<"Fine";
		 	cout<<endl<<fname;
		 } 
	}
	if(e!=1) 
	{
		cout<<endl<<"WRONG INPUT!!!";
		goto p;
	}
	
	p:
	file.close();
	f.close();
}

int main()
{
	data o;
	cout<<" \t\t ------- ------ ---------- ------"<<endl<<" \t\t Traffic Chalan Management System"<<endl<<" \t\t ------- ------ ---------- ------"<<endl;
	cout<<endl<<"Choose Your Option:";
	cout<<endl<<"\t 1. Register Defaulter"<<endl<<"\t 2. Search for data"<<endl<<"\t 3. Show whole Data"<<endl<<"\t 4. Delete data";
	cout<<endl<<"\t 5. Add Data of The Defaulter"<<endl<<"\t 6. Detail Data of Defaulter";
	cout<<endl<<"Your Choise: ";
	int c;
	cin>>c;
	switch(c)
	{
		case 1://add data
			cout<<endl;
			o.adddata();			
			break;
		case 2://search for data
			cout<<endl;
			o.searchdata();
			break;
		case 3://show data
			cout<<endl;
			o.showdata();
			break;
		case 4://delete data
			cout<<endl;
			o.deletedata();
			break;
		case 5: //additional data 
			cout<<endl;
			o.moredata();
			break;
		case 6: //Defaulter's Details
			cout<<endl;
			o.detaildata();
			break;
		default://wrong input
			cout<<"You Entered Wrong input"<<endl;
			break;	
	}
	cout<<endl<<"Choose:"<<endl<<"\t 1. Repeat"<<endl<<"\t 2. End"<<endl;
	cin>>c;
	if(c==2)
	goto end;
	else
	goto again;
	again:
		cout<<endl<<"Choose Your Option:";
	cout<<endl<<"\t 1. Register Defaulter"<<endl<<"\t 2. Search for data"<<endl<<"\t 3. Show whole Data"<<endl<<"\t 4. Delete data";
	cout<<endl<<"\t 5. Add Data of The Defaulter"<<endl<<"\t 6. Detail Data of Defaulter";
	cout<<endl<<"Your Choise: ";
	cin>>c;
	switch(c)
	{
		case 1://add data
			cout<<endl;
			o.adddata();			
			break;
		case 2://search for data
			cout<<endl;
			o.searchdata();
			break;
		case 3://show data
			cout<<endl;
			o.showdata();
			break;
		case 4://delete data
			cout<<endl;
			o.deletedata();
			break;
		case 5: //additional data 
			cout<<endl;
			o.moredata();
			break;
		case 6: //Defaulter's Details
			cout<<endl;
			o.detaildata();
			break;
		default://wrong input
			cout<<"You Entered Wrong input"<<endl;
			break;	
	}
	cout<<endl<<"Choose:"<<endl<<"\t 1. Repeat"<<endl<<"\t 2. End"<<endl;
	cin>>c;
	if(c==2)
	goto end;
	else
	goto again;
	end:
		return 0;
}

