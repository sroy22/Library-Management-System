#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fstream.h>

class Member

{ char name[20];

float fee;

longtelno;

int regno;
public:
int ret()
{ returnregno;
 }

void showmembers();

void getmembers();

 };

void Member::showmembers()

{
cout<<"Member Details";

cout<<endl;

cout<<"Registration Number:"<<regno;

cout<<endl;

cout<<"Name:"<<name;

cout<<endl;

cout<<"Telephone Number:"<<telno;
cout<<endl;
 }

void Member:: getmembers()

{ clrscr();
gotoxy(25,5);
cout<<"Enter Registration Number";

cin>>regno;

gotoxy(25,7);

cout<<"Name";

gets(name);

gotoxy(25,11);

cout<<"Telephone number";

cin>>telno;

 }
void displaymember()
{   clrscr();

ifstream fin;
fin.open("members.dat", ios::binary|ios::in);
Member M;

while(fin.read((char*)&M,sizeof(M)))
M.showmembers();

fin.close();
}

void addmember()          // function to add members

{
clrscr();
charch;
inti,n;

Member m;

ofstream fout;
fout.open("members.dat",ios::binary|ios::app);
gotoxy(25,11);
cout<<"Enter how many members you want to add";
cin>>n;
for(i=0;i<n;i++)
{   clrscr();
gotoxy(25,11);
cout<<"ADDING A NEW MEMBER";

gotoxy(25,12);

cout<<"Enter the details of the new member";

gotoxy(25,14);

cout<<"Press any key to continue";

getch();

m.getmembers();

fout.write((char*)&m,sizeof(m));

gotoxy(25,16);

cout<<"Member Added";

gotoxy(25,18);

clrscr();
  }
fout.close();

}

class Book
  {char bname[20];

char author[15];
public:
int bcode;
int noofcopy;
int retbookno()
{ return bcode;
}
int retnoofcopy()
{ return noofcopy;
}
char* retbname()
{ return bname;
 }
char*retauthor()
{ return author;
 }
void showbook()
{
cout<<"Book Details";

cout<<endl;

cout<<"Book Number:"<<bcode;

cout<<endl;

cout<<"Name:"<<bname;
cout<<endl;

cout<<"Author"<<author;
cout<<endl;
cout<<"Number of copies"<<noofcopy;
 }

void getbook()
{ clrscr();
gotoxy(25,5);

cout<<"Enter Book Number";

cin>>bcode;

gotoxy(25,7);

cout<<"Name";

gets(bname);

gotoxy(25,11);

cout<<"Author";

gets(author);
gotoxy(25,15);
cout<<"Number of copies";
cin>>noofcopy;
 }
 };
void display()                    // function to display book details
{
 Book B;
clrscr();

ifstream fin;
fin.open("book.dat", ios::binary|ios::in);


while(fin.read((char*)&B,sizeof(B)))
B.showbook();
fin.close();
}
void issuebook()              // function to issue a book
{  int studentno;
int bookno;
Book B;
Member M;
int found=0;
clrscr();
cout<<"\n BOOK ISSUE ...";
cout<<"\n Enter The student's admission no.";
cin>>studentno;
fstream f1,f2;
f1.open("members.dat",ios::in|ios::out|ios::binary);
f2.open("book.dat",ios::in|ios::out|ios::binary);
         while(f1.read((char*)&M,sizeof(M)) && found==0)
         {
         if(studentno==M.ret())
                 {
                   found=1;
                    cout<<"\n\n\tEnter the book no. ";
                   cin>>bookno;
                   while(f2.read((char*)&B,sizeof(B)))
                              {			
                               if(B.retbookno()==bookno)
                               { 
                               getch();
                               if(B.noofcopy==0)
                                    {
                                      cout<<endl;
                                     cout<<"There are no copies left in the library";
                                    cout<<endl;
                                      cout<<"Please borrow another book";
                                     }
                                 else
					      {B.noofcopy=B.noofcopy-1;
                                     Int bos=-1*sizeof(B);
                                     f2.seekp(bos,ios::cur);
                                     f2.write((char*)&B,sizeof(B)); 
                                    cout<<endl;
                                      cout<<"Thanks for borrowing";
                             }
                      }
             else
cout<<"This book does not exist";
  }
 }
else
cout<<"This student record does not exist";
getch();
f1.close();
f2.close();
}
}
void bookdeposit()             // function to deposit a book
{    Member M;
Book B;
int studentno;
int bookno;
int found=0;
int day; int fine;
clrscr();
cout<<"\nBOOK DEPOSIT";
cout<<"\n Enter The student's admission no.";
cin>>studentno;
fstream f1,f2;

f1.open("members.dat",ios::in|ios::out|ios::binary);
f2.open("book.dat",ios::in|ios::out|ios::binary);
while(f1.read((char*)&M,sizeof(M)) && found==0)
          {
           if(studentno==M.ret())
              {
                     found=1;
                     while(f2.read((char*)&B,sizeof(B)))	
                { cout<<"Enter the book code of the book to be returned";            	                cin>>bookno;

				if(B.retbookno()==bookno)
	{gotoxy(25,15);
					B.noofcopy=B.noofcopy+1;
	intbos=-1*sizeof(B);
					f2.seekp(bos,ios::cur);
					f2.write((char*)&B,sizeof(B));
	cout<<endl;

	cout<<"\n Book deposited in no. of days";
	cin>>day;
	if(day>15)
	{
	fine=(day-15)*10;
                         cout<<"\n\nFine has to deposited Rs. "<<fine;
	}
                                          }

	else
	cout<<"This book has not been issued";

	}
	}
                                 else
                           cout<<"Student record does not exist";
cout<<"Go back to main menu";
mainmenu();
}
f1.close();
f2.close();
 }
void addbook()               // function to add a book to the library

{
clrscr();
charch;
int i,n;

Book B;

ofstream fout;
fout.open("book.dat",ios::binary|ios::app);
gotoxy(25,11);
cout<<"Enter how many books you want to add";
cin>>n;
for(i=0;i<n;i++)
{   clrscr();
gotoxy(25,11);
cout<<"ADDING A NEW Book";

gotoxy(25,12);

cout<<"Enter the details of the new book";

gotoxy(25,14);

cout<<"Press any key to continue";

getch();

B.getbook();

fout.write((char*)&B,sizeof(B));

gotoxy(25,16);

cout<<"Book Added";

gotoxy(25,18);

clrscr();

fout.close();

}
voidmainmenu();
mainmenu();

 }


void bookmenu()                        // function to display book menu

{int optionmember;

gotoxy(25,5);

cout<<"1. Add Book";

gotoxy(25,7);

cout<<"2.Display Book";

gotoxy(25,11);
cout<<"3. Search a Book";
gotoxy(25,13);


cout<<"Enter your choice ";

cin>>optionmember;

switch(optionmember)

 {case 1 : addbook();

break;

case 2 : display();
break;
case 3: search();
break;
default: gotoxy(25,15);

cout<<"Invalid choice";

  }

 }


void search()                    // function to search for a book
{ clrscr();
int bookno;
charch;
int p=0;
do
{ gotoxy(25,5);
cout<<"TO SEARCH FOR A Book";
gotoxy(25,7);
cout<<"ENTER THE Book Code";
cin>>bookno;
ifstream fin;
fin.open("book.dat",ios::binary|ios::in);
Book B;
while(fin.read((char*)&B,sizeof(B)))
{ if(bookno==B.bcode)
{ clrscr();
B.showbook();
p=1;
}
}
if(p==0)
{ gotoxy(25,5);
cout<<"Invalid registration number";
}
gotoxy(25,7);
cout<<"Press any key to continue";
getch();
fin.close();
clrscr();
gotoxy(25,9);
cout<<"DO YOU WANT TO SEARCH FOR ANOTHER MEMBER?(Y/N):";
cin>>ch;
} while(ch=='Y');
}

void searchmember();

void searchmember()              // function to search for a member
{ clrscr();
int registerno;
char ch;
int p=0;
do
{ gotoxy(25,5);
cout<<"TO SEARCH FOR A MEMBER";
gotoxy(25,7);
cout<<"ENTER THE REGISTRATION NUMBER OF THE MEMBER";
cin>>registerno;
ifstream fin;
fin.open("members.dat",ios::binary|ios::in);
Member m;
while(fin.read((char*)&m,sizeof(m)))
{ if(registerno==m.ret())
{ clrscr();
m.showmembers();
p=1;
}
}
if(p==0)
{ gotoxy(25,5);
cout<<"Invalid registration number";
}
gotoxy(25,7);
cout<<"Press any key to continue";
getch();
fin.close();
clrscr();
gotoxy(25,9);
cout<<"DO YOU WANT TO SEARCH FOR ANOTHER MEMBER?(Y/N):";
cin>>ch;
} while(ch=='Y');
}


void membermenu()    // function to display member menu

{ clrscr();
int optionmember;

gotoxy(25,5);

cout<<"1. Add Member";

gotoxy(25,7);

cout<<"2.Display members";

gotoxy(25,11);
cout<<"3. Search a member";
gotoxy(25,13);
cout<<"4. Issue a book";
gotoxy(25,15);
cout<<"5.Return a book";

gotoxy(25,17);


cout<<"Enter your choice ";

cin>>optionmember;

switch(optionmember)

 {case 1 : addmember();

break;

case 2 : displaymember();

break;
case 3 : searchmember();
break;
case 4: issuebook();
break;
case 5:bookdeposit();
break;
default: gotoxy(25,15);

cout<<"Invalid choice";

  }

 }


void mainmenu()    // function to display mainmenu

{ clrscr();
int option;

gotoxy(25,5);

cout<<"MAIN MENU";

gotoxy(25,7);

cout<<"1.Member Administration";

gotoxy(25,9);

cout<<"2.Book Administration";

gotoxy(25,11);

cout<<"Enter your option";

cin>>option;

switch(option)

 {case1: membermenu();

break;

case 2: bookmenu();

break;

default: gotoxy(25,13);

cout<<"Invalid Choice!! Better luck next time";

 }
 }

void design()              // design along border
  { int x=0,y=0,i,j,m=100,n=100,p=0,q=0,r=0,s=0;

for(i=0;i<=100;i++)
 {gotoxy(x,y);
cout<<"*";
x++;
gotoxy(m,n);
cout<<"*";
m++;}
for(i=0;i<=100;i++)
{gotoxy(p,q);
cout<<"*";
p++;}
for(j=0;j<=100;j++)
{ gotoxy(r,s);
cout<<"*";
s++;}
 }

void welcome()              // welcome screen

{  char ch;

int i,j=0;

gotoxy(11,3);

cout<<'L';

gotoxy(15,3);

cout<<'L';

gotoxy(11,4);

cout<<'L';

gotoxy(15,4);

cout<<'L';

gotoxy(11,5);

cout<<'L';

gotoxy(15,5);

cout<<'L';

gotoxy(11,6);

cout<<'L';

gotoxy(11,7);

cout<<'L';

gotoxy(13,6);

cout<<'L';

gotoxy(15,6);

cout<<'L';

gotoxy(15,7);

cout<<'L';

gotoxy(12,7);

cout<<'L';

gotoxy(14,7);

cout<<'L';

for(i=18;i<22;i++)

{ gotoxy(18+j,3);

cout<<'I';

j++;

}

j=0;

for(i=18;i<22;i++)

{ gotoxy(18+j,7);

cout<<'I';

j++;

}

j=0;

for(i=19;i<22;i++)

{ gotoxy(19+j,5);

cout<<'I';

j++;

}

j=0;

for(i=3;i<7;i++)

{ gotoxy(23,3+j);

cout<<'B';

j++;

}

j=0;

for(i=23;i<27;i++)

{gotoxy(23+j,7);

cout<<'B';

j++;

}

j=0;

for(i=29;i<33;i++)

{ gotoxy(29+j,3);

cout<<'R';

j++;

}

j=0;

for(i=4;i<7;i++)

{ gotoxy(29,i);

cout<<'R';



}

j=0;

for(i=29;i<33;i++)

{ gotoxy(29+j,7);

cout<<'R';

j++;

}

j=0;

for(i=3;i<7;i++)

{ gotoxy(35+j,3);

cout<<'A';

j++;

}

j=0;

for(i=3;i<8;i++)

{ gotoxy(35,i);

cout<<'A';

j++;

}

for(i=36;i<39;i++)

{ gotoxy(i,7);

cout<<'A';

}

for(i=3;i<8;i++)

{ gotoxy(38,i);

cout<<'A';

}

for(i=3;i<8;i++)

{ gotoxy(41,i);

cout<<'R';

}

for(i=42;i<46;i++)

{ gotoxy(i,3);

cout<<'R';

}

for(i=4;i<8;i++)

{ gotoxy(43,i);

cout<<'R';

}

for(i=4;i<8;i++)

{ gotoxy(45,i);

cout<<'R';

}

j=0;

for (i=48;i<52;i++)

{ gotoxy(48+j,3);

cout<<'Y';

j++;

}

j=0;

for(i=4;i<7;i++)

{ gotoxy(48,j+4);

cout<<'Y';

j++;

}

j=0;

for(i=48;i<52;i++)

{ gotoxy(48+j,7);

cout<<'Y';

j++;

}

j=0;

for(i=48;i<52;i++)

{ gotoxy(48+j,5);

cout<<'Y';

j++;

 }
getch();
mainmenu();
}


void password()   //password for project

{ int m;

char str1[50];

char str2[50];

int k=5;

while(k>0)

{ gotoxy(25,10);

cout<<"Username:";

gets(str1);

gotoxy(25,12);

cout<<"Password:";

for(m=0;m<50;m++)
 {str2[m]=getch();
if(str2[m]=='\b')
  {m-=2;cout<<'\b';
continue;}
if(str2[m]==13)
  {str2[m]='\0';
break;}
cout<<'*';}

if(strcmpi(str1,"Subhayan")==0 &&strcmpi(str2,"csproject")==0)

{clrscr();

gotoxy(25,20);

cout<<"Access Granted ";

gotoxy(25,22);

cout<<"Press any key to continue ";

getch();
welcome();
break;

}

else

{clrscr();

gotoxy(25,20);

cout<<"ACCESS DENIED";

gotoxy(25,22);

cout<<"Please try again";

gotoxy(25,24);

k=k-1;

cout<<"You have"<<k<<" "<<"trials remaining";

}
}
}
void main()
 {
design();
password();
 }
