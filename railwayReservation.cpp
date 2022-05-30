#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <time.h>
using namespace std;
char f[10] = "f"; //first class 
char s[10] = "s";// second class
int addr, ad, flag, f1, d, m, i, amt;
float tamt; //total amount
class login
{
	public:
	char id[100]; //to check whether login credentials are correct or not
	char pass[100];
	char password[10];
	void getid()
	{
		cout << "\nEnter your id:";
		cin >> id;
		cout << "Enter the Password: ";
		cin >> password;
		cout << "\n";
		strcpy(pass,password);
	}
	void displayid()
	{
	    cout << "\n|" << "User ID:" << "\t" << "|" << "Password\n";
		cout << "|" << id << "\t\t" << "|" << pass << "\n\n";
	}
};
class Detail
{
	public:
		int tno;
		char tname[100]; //entering the details for the new train data
		char bp[100]; 
		char dest[100];

		int c1,c1fare;
		int c2,c2fare;
		int d,m,y;
		void getDetail()
		{
			cout << "\n--Add New details--\n";
			cout << "Train no: ";
			cin >> tno;
			cout << "Train Name: ";
			cin >> tname;
			cout << "Boarding point: ";
			cin >> bp;
			cout << "Destination pt: ";
			cin >> dest;
			cout << "No of seats in first class & fare per ticket: ";
			cin >> c1 >> c1fare;
			cout << "No of seats in second class & fare per ticket: ";
			cin >> c2 >> c2fare;
			cout << "Date of travel\n";
			cout << "Day: ";
			cin >> d;
			cout << "Month: ";
			cin >> m;
			cout << "Year: ";
			cin >> y;
		}
		void displaydetail() 
		{
		    cout << "\n|Train No." << "\t" << "|Train Name" << "\t" << "|Boarding pt." << "\t" << "|Destination pt."  <<"\t";
			cout << "|F-Class" << "\t"<< "|F-Class Fare" << "\t" << "|S-Class" << "\t" << "|S-Class Fare" <<"\t";
			cout << "|Day" << "-" << "Month" << "-" << "Year" << "\n";

			cout << "|" << tno << "\t\t" << "|" << tname << "\t\t" << "|" << bp << "\t\t" << "|" << dest <<"\t\t\t";
			cout << "|" << c1 << "\t\t" << "|"<< c1fare << "\t\t" << "|" << c2<< "\t\t" << "|" << c2fare <<"\t\t";
			cout << "|" << d << "-" << m << "-" << y << "\n";
		}
};
class reser // class for reserving seats in the train
{
	public:
	int pnr;
	int tno;
	char tname[100];
	char bp[10];
	char dest[100];
	char pname[10][100];
	int age[20];
	char clas[10];
	int nosr;
	int i;
	int d,m,y;
	int con;

	float amc;  
	void getresdet()  //getting the details of the passengers
	{
		cout<<"Enter the details as follows\n";
		cout<<"Train no:";
		cin>>tno;
		cout<<"Train name:";
		cin>>tname;
		cout<<"Boarding point:";
		cin>>bp;
		cout<<"Destination pt:";
		cin>>dest;
		cout<<"No of seats required:";
		cin>>nosr;
		for(i=0;i<nosr;i++)
		{
			cout<<"Passenger name:";
			cin >> pname[i];
			cout<<"Passenger age:";
			cin>>age[i];
		}
		cout<<"Enter the class f-first class s-second class:";
		cin >> clas;
		cout<<"Date of travel:";
		cin>>d>>m>>y;
		cout<<"Enter the concession category\n";
		cout<<"1.Military\n2.Senior citizen\n";
		cout<<"3.Children below 5 yrs\n4.None\n";
		cin>>con;
		cout<<"......END OF GETTING DETAILS......\n";
	}
	void displayresdet()  //reservation data
	{
		cout<<"Pnr no: "<<pnr;
		cout<<"\nTrain no: "<<tno;
		cout<<"\nTrain name: "<<tname;
		cout<<"\nBoarding point: "<<bp;
		cout<<"\nDestination pt: "<<dest;
		cout<<"\nNo of seats reserved: "<<nosr;
		for(i=0;i<nosr;i++)
		{
			cout<<"\nPassenger name: ";puts(pname[i]);
			cout<<"Passenger age: "<<age[i];
		}

		cout<<"\nYour class: ";puts(clas);
		cout<<"\nDate of reservation: "<<d<<"-"<<m<<"-"<<y;
		cout<<"\nYour concession category: "<<con;
		cout<<"\nYou must pay: "<<amc<<endl;
		cout<<"***********************************\n";
	}
};
class canc // to cancel the ticket
{
    public:
    int pnr;
    int tno;
    char tname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    int i;
    char clas[10];
    int nosc;
    int d, m, y;
    float amr;
    void getcancdet()
    {
        cout << "Enter the details as follows\n";
        cout << "Pnr no:";
        cin >> pnr;
        cout << "Date of cancellation:";
        cin >> d >> m >> y;
        cout << "......END OF GETTING DETAILS......\n";
    }
    void displaycancdet()
    {
        cout << ".....................\n";
        cout << ".....................\n";
        cout << "Pnr no:" << pnr;
        cout << "\nTrain no:" << tno;
        cout << "\nTrain name:";
        cout << tname;
        cout << "Boarding point:";
        cout << bp;
        cout << "Destination pt:";
        cout << dest;
        cout << "\nYour class:";
        cout << clas;
        cout << "no of seats to be cancelled:" << nosc;
        for (i = 0; i < nosc; i++)
        {
            cout << "Passenger name:";
            cout << pname[i];
            cout << "passenger age:" << age[i];
        }
        cout << "\nDate of cancellation:" << d << "-" << m << "-" << y;
        cout << "\nYou can collect:" << amr << "rs" << endl;
        cout << "*****************************************\n";
        cout << "......END OF CANCELLATION.......\n";
        cout << "*****************************************\n";
    }
};
void manage();
void can();
void user();
void database();
void res();
void reserve();
void displaypassdetail();
void cancell();
void enquiry();
int main()
//main function starts here
{
	int ch;
	cout << "----- RAILWAY RESERVATION SYSTEM ----- \n";
	do
	{
		cout << "\n MAIN MENU \n";
		cout << "1.Admin mode\n2.User mode\n3.Exit \n";
		cout << "Enter your choice : ";
		cin >> ch;
		switch(ch)  //simple switch case
		{
			case 1:
				database();
				break;
			case 2:
				user();
				break;
			default:
				exit(0);
		}
	}while(ch<3);

	return 0;
}

void database() //taking the admin details to add to the database.
{
	char password[10];
	char pass[10] = "admin";
	cout << "\nEnter the Admin Password: ";
	cin >> password;
	Detail a; //object of class detail
	fstream f;
	int ch;
	char c;
	if(strcmp(pass,password)!=0)  
	{
		cout << "Enter the password correctly \n";
		cout << "You are not permitted to login this mode\n";
	}
	if(strcmp(pass,password)==0)
	{
		char c;
		do
		{
			cout << "\n --- ADMINISTRATOR MENU --- \n";
			cout << "1. Create detail Database \n";
			cout << "2. Add details \n";
			cout << "3. Display details \n";
			cout << "4. User Management \n";
			cout << "5. Diplay Passenger details \n";
			cout << "6. Return to Main Menu \n";
			cout << "Enter your choice : ";
			cin >> ch;

			switch(ch) //simple switch case
			{
				case 1:
					f.open("t.txt",ios::out|ios::binary); //opening the t.txt file to input data in binary form
					do
					{
					a.getDetail();
					f.write((char *) & a,sizeof(a));
					cout << "\nDo you want to add one more record?\n";
					cout << "y-for Yes\nn-for No\n";
					cin >> c;
					}while(c=='y');
					f.close();
					break;
				case 2:
					f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
					a.getDetail();
					f.write((char *) & a,sizeof(a));
					f.close();
					break;
				case 3:
					f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
					f.seekg(0); 
					while(f.read((char *) & a,sizeof(a)))
					{
					a.displaydetail();
					}
					f.close();
					break;
				case 4:
					manage();
					break;
				case 5:
					displaypassdetail();
					break;
			}
		}while(ch<=5);
	}
}

void reserve()  
{
    int ch;
    do
    {
        cout << "1.Reserve\n2.Return to the main menu\n";
        cout << "Enter your choice:";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            res();
            break;
        }
    } while (ch == 1);
}

void res()  //seat reserving function in the railway database
{
    Detail a;
    reser b;
    fstream f1, f2;
    time_t t;
    f1.open("t.txt", ios::in | ios::out | ios::binary);
    f2.open("p.txt", ios::in | ios::out | ios::binary | ios::app);
    int ch;
    b.getresdet();
    while (f1.read((char *)&a, sizeof(a)))
    {
        if (a.tno == b.tno)
        {
            if (strcmp(b.clas, f) == 0)
            {
                if (a.c1 >= b.nosr)
                {
                    amt = a.c1fare;
                    addr = f1.tellg();
                    ad = sizeof(a.c1);
                    f1.seekp(addr - (7 * ad));
                    a.c1 = a.c1 - b.nosr;
                    f1.write((char *)&a.c1, sizeof(a.c1));
                    if (b.con == 1)
                    {
                        cout << "Concession category:MILITARY PERSONNEL\n";
                        b.amc = b.nosr * ((amt * 50) / 100);
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        b.amc = b.nosr * ((amt * 60) / 100);
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";
                        b.amc = 0.0;
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr * amt;
                    }
                    srand((unsigned)time(&t));
                    b.pnr = rand();
                    f2.write((char *)&b, sizeof(b));
                    b.displayresdet();
                    cout << "\n-----Your ticket is reserved-----\n";
                }
                else
                {
                    cout << "**********Sorry req seats not available********\n";
                }
            }
            else if (strcmp(b.clas, s) == 0)
            {
                if (a.c2 >= b.nosr)
                {
                    amt = a.c2fare;
                    addr = f1.tellg();
                    ad = sizeof(a.c2);
                    f1.seekp(addr - (5 * ad));
                    a.c2 = a.c2 - b.nosr;
                    f1.write((char *)&a.c2, sizeof(a.c2));
                    if (b.con == 1)
                    {
                        cout << "Concession category:MILITARY PRESONNEL\n";
                        b.amc = b.nosr * ((amt * 50) / 100);
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        b.amc = b.nosr * ((amt * 60) / 100);
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";
                        b.amc = 0.0;
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr * amt;
                    }
                    f2.write((char *)&b, sizeof(b));
                    b.displayresdet();
                    cout << "\n-----Your ticket is reserved-----\n";
                }
                else
                {
                    cout << "********Sorry req no of seats not available*******\n";
                }
            }
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        cout << "!\n";
    }
    f1.close();
    f2.close();
}

void displaypassdetail() // displays the passenger details
{
	cout << "\n--------Passenger Details--------\n";
	fstream f;
	reser b;
	f.open("p.txt",ios::in|ios::out|ios::binary);
	f.seekg(0);
	while(f.read((char *) & b,sizeof(b)))
	{
		b.displayresdet();
	}
	f.close();
}
void enquiry() // display the train details
{
    fstream f;
    f.open("t.txt",ios::in|ios::out|ios::binary);
    Detail a;
    while(f.read((char *) & a,sizeof(a)))
    {
            a.displaydetail();
    }
}
void cancell()
{
    Detail a;
    reser b;
    canc c;
    fstream f1, f2, f3;
    f1.open("t.txt",ios::in|ios::out|ios::binary);
    f2.open("p.txt",ios::in|ios::out|ios::binary);
    f3.open("cn.txt",ios::in|ios::out|ios::binary);
    cout<<"**********CANCELLATION MENU*********\n";
    c.getcancdet();
    while(f2.read((char *) &b,sizeof(b)))
    {
        if (b.pnr == c.pnr)
        {
            c.tno = b.tno;
            strcpy(c.tname, b.tname);
            strcpy(c.bp, b.bp);
            strcpy(c.dest, b.dest);
            c.nosc = b.nosr;
            for (int j = 0; j < c.nosc; j++)
            {
                strcpy(c.pname[j], b.pname[j]);
                c.age[j] = b.age[j];
            }
            strcpy(c.clas, b.clas);
            if (strcmp(c.clas, f) == 0)
            {
                while (f1.read((char *)&a, sizeof(a)))
                {
                    if (a.tno == c.tno)
                    {
                        a.c1 = a.c1 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a.c1);
                        f1.seekp(addr - (7 * ad));
                        f1.write((char *)&a.c1, sizeof(a.c1));
                        tamt = b.amc;
                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        goto h;
                        c.displaycancdet();
                    }
                }
            }
            else if (strcmp(c.clas, s) == 0)
            {
                while (f1.read((char *)&a, sizeof(a)))
                {
                    if (a.tno == c.tno)
                    {
                        a.c2 = a.c2 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a.c2);
                        f1.seekp(addr - (5 * ad));
                        f1.write((char *)&a.c2, sizeof(a.c2));
                        tamt = b.amc;
                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        goto h;
                        c.displaycancdet();
                    }
                }
            }
        }
        else
        {
            flag = 0;
        }
    }
    h:
    if(flag==0)
    {
            cout << "Enter the correct pnr no\n";
    }
    f1.close();
    f2.close();
    f3.close();
}
void can() // cancel function called
{
    int ch;
    do
    {
        cout << "......CANCELLATION MENU.......\n";
        cout << "1.Cancel\n2.Return to the main menu\n";
        cout << "Enter your choice:";
        cin >> ch;
        cout << endl;
        switch (ch)
        {
        case 1:
            cancell();
            break;
        }
    } while (ch == 1);
}
void user() // checks the credentials of the user 
{
	login a;
	int ch;
	cout<<"\n-----Login User-----\n";
	char password[10];
	fstream f;
	f.open("id.txt",ios::in|ios::out|ios::binary);
	char id[100];
	cout << "Enter your ID : ";
	cin >> id;
	cout << "Enter your Password : ";
	cin >> password;
	while(f.read((char *) & a,sizeof(a)))
	{
		if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0))
		{
			do
			{
				cout<<"\n1.Reserve\n2.Cancel\n3.Enquiry\n4.Return to the main menu\n";
				cout<<"Enter your choice:";
				cin>>ch;
				switch(ch)
				{
					case 1:
						reserve();
						break;
					case 2:
						cancell();
						break;
					case 3:
						enquiry();
						break;
				}
			}while(ch<=3);
		}
		else
		{
			d=1;
		}
	}
	if(d==1)
	{
		cout<<"Enter your user id and password correctly\n";
	}
}

void manage()
{
	int ch;
	fstream f;
	char c;
	login a;
	cout<<"\n---WELCOME TO THE USER MANAGEMENT MENU---\n";
	do
	{
		cout << "1. Create id database\n";
		cout << "2. Add details\n";
		cout << "3. Display details\n";
		cout << "4. Return to the main menu\n";
		cout << "Enter your choice: ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				f.open("id.txt",ios::out|ios::binary);
				do
				{
					a.getid();
					f.write((char *) & a,sizeof(a));
					cout << "Do you want to add one more record\n";
					cout << "y-Yes\nn-No\n";
					cin>>c;
				}while(c == 'y');
				f.close();
				break;
			case 2:
				f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);
				a.getid();
				f.write((char *) & a,sizeof(a));
				f.close();
				break;
			case 3:
				f.open("id.txt",ios::in|ios::out|ios::binary);
				f.seekg(0);
				while(f.read((char *) & a,sizeof(a)))
				{
					a.displayid();
				}
				f.close();
				break;
			}
		}while(ch<=3);
}

