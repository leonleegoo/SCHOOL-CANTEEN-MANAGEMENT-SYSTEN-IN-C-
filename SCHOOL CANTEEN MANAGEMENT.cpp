#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<ctype.h>
#include "windows.h"
#include<iostream>
#include<stdlib.h>

using namespace std;
struct order
{
int prodid1;
char pname1[50];
char win1[50];
int qty1;
float price1,dis1;
}o1[50];
int orderk=0;
void middleadminmenu();
void copyme(int k,order order1[],int q1,int &c2);
void intromain();
int getproduct();
int getstudents();
void display_all();
void display_all_stud();
void prod_tabular();
void modify_record(int n);
void delete_record(int n);
void againopenandclose();
void againopenandclosestud();
int search(int p);
void changeqty(int pr1,int q11);


void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}
class student
{
int stud_id;
char sname[25];
char address[35];
char phno[15];
public:
void modifystud_data(int n1,char nm[15],char add[15],char q[15]);
int getstudid()
{return stud_id;}
char *getstudnm()
{ return sname;}
char *getstudadd()
{ return address;}
char *getphno()
{ return phno;}
void stud_input(int studid)
{
 gotoxy(5,7);
 cout<<"======================================================================";
 gotoxy(10,8);
 cout<<"STUD NO:";
 stud_id=studid;
 gotoxy(24,8);
 cout<<stud_id;
 gotoxy(35,8);
 cout<<"NAME OF STUD:";
 gotoxy(54,8);
 cin>>sname;
 gotoxy(10,9);
 cout<<"ADDRESS:";
 gotoxy(22,9);
 cin>>address;
 gotoxy(10,11);
 cout<<"PHONE NO.:";
 gotoxy(25,11);
 cin>>phno;
 gotoxy(5,12);
 cout<<"=====================================================================";
}
void show_stud()
{
gotoxy(5,7);
 cout<<"======================================================================";
 gotoxy(10,8);
 cout<<"STUD NO:";
 gotoxy(25,8);
 cout<<stud_id;
 gotoxy(35,8);
 cout<<"NAME OF STUD:";
 gotoxy(54,8);
 cout<<sname;
 gotoxy(10,9);
 cout<<"ADDRESS:";
 gotoxy(25,9);
 cout<<address;
 gotoxy(10,10);
 cout<<"PHONE NO.:";
 gotoxy(25,10);
 cout<<phno;
 gotoxy(5,12);
 cout<<"=====================================================================";
}
void showallstud(int c)
{
 gotoxy(1,c);
 cout<<stud_id<<setw(17)<<sname<<setw(15)<<address<<setw(30)<<phno;
}
void showstuddatamulti()
{
 gotoxy(5,7);
 cout<<"======================================================================";
 gotoxy(10,8);
 cout<<"STUD NO:";
 gotoxy(30,8);
 cout<<stud_id;
 gotoxy(40,8);
 cout<<"NAME OF STUD:";
 gotoxy(60,8);
 cout<<sname;
 gotoxy(10,9);
 cout<<"ADDRESS:";
 gotoxy(30,9);
 cout<<address;
 gotoxy(10,10);
 cout<<"PHONE NO.:";
 gotoxy(30,10);
 cout<<phno;
 gotoxy(5,11);
 cout<<"=====================================================================";
}
};

void student::modifystud_data(int n1,char nm[15],char add[15],char q[15])
{
char tmpnm[40],tmpnm2[40],tmpnm3[15];
gotoxy(5,14);
 cout<<"===================WANT TO MODIFY ===============================";
 gotoxy(10,15);
 cout<<"STUD NO:";
 stud_id=n1;
 gotoxy(25,15);
 cout<<stud_id;
 gotoxy(40,15);
 strcpy(sname,nm);
 cout<<"NAME OF STUD:";
 gotoxy(60,15);
 cout<<sname;
 gotoxy(10,17);
 cout<<"Want to change the name of student";
 gotoxy(50,17);
 int flag=0;
 while(1)
 {
 gets(tmpnm);
 if(strlen(tmpnm)!=0)
 {
flag=1;
break;
}
 if(strlen(tmpnm)==0)
 { flag=0;
 break;
}
 }
 if(flag==1)
 { strcpy(sname,tmpnm);
 }
 else
 {
 }
 gotoxy(1,18);
 strcpy(address,add);
 
 cout<<"STUDENT ADDRESS:";
 gotoxy(20,18);
 cout<<address;
 gotoxy(45,18);
 cout<<"Want to change the address";
 gotoxy(70,18);
 flag=0;
 while(1)
 {
 gets(tmpnm2);
 if(strlen(tmpnm2)!=0)
 {
flag=1;
break;
}
 if(strlen(tmpnm2)==0)
 { flag=0;
 break;
}
 }
 if(flag==1)
 { strcpy(address,tmpnm2);
 }
 
 gotoxy(5,19);
strcpy(phno,q);
 
 cout<<"STUDENT PHONE NO.:";
 gotoxy(20,18);
 cout<<phno;
 gotoxy(45,18);
 cout<<"Want to change the phone no.";
 gotoxy(70,18);
 flag=0;
 while(1)
 {
 gets(tmpnm3);
 if(strlen(tmpnm3)!=0)
 {
flag=1;
break;
}
 if(strlen(tmpnm3)==0)
 { flag=0;
 break;
}
 }
 if(flag==1)
 { strcpy(phno,tmpnm3);
 }

gotoxy(5,20);
 cout<<"=====================================================================";
}

void write_student()
{
ofstream objoff;
student cobj;
 objoff.open("student.dat",ios::out|ios::app);
 system("cls");
 intromain();
 int r=getstudents();
 if(r>100) 
 {
 r=1; 
 }
 cobj.stud_input(r);
 objoff.write((char*)&cobj,sizeof(student));
 objoff.close();
 gotoxy(10,20);
 cout<<"***************STUDENT RECORD SAVED******************* ";
 cin.ignore();
 getch();
}

int getstudents()
{
ifstream objiff;
student stud;
int count=0;
objiff.open("student.dat",ios::binary);
objiff.seekg(0,ios::beg);
if(!objiff)
{
cout<<"File could not be open !! Press any Key...";
getch();
}

while(objiff.read((char *) &stud, sizeof(student)))
{
 count++;
}

objiff.seekg(count-sizeof(stud),ios::beg);
objiff.read((char *) &stud, sizeof(student));
count=stud.getstudid();
count++;
objiff.close();
return count;
}

void display_stud_sp(int n)
{
 ifstream objfp;
 student stud;
 int flag=0;
 objfp.open("student.dat",ios::binary);
 if(!objfp)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
 while(objfp.read((char*)&stud,sizeof(student)))
{
 if(stud.getstudid()==n)
{
 system("cls");
 intromain();
 stud.show_stud();
 flag=1;
}
}
 objfp.close();
if(flag==0)
cout<<"\n\nrecord not exist";
getch();
}

void stud_tabular()
{
 int r=0,col=10;
student stud;
ifstream inFile;
inFile.open("student.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
display_all_stud();
while(inFile.read((char *) &stud, sizeof(student)))
{
 if(r<=12)
 {
 r++;
 stud.showallstud(col);
 col++;
 }else
 {
 gotoxy(20,30);
 cout<<"--------------press any key------------------------";
 getch();
 system("cls");
 display_all_stud();
 col=10;
 r=0;
}
}
inFile.close();
getch();
}

void display_all_stud()
{
system("cls");
intromain();
gotoxy(1,5);
cout<<" **********************STUDENT DETAILS***************************";
gotoxy(1,6);
cout<<"================================================================================";
gotoxy(1,7);
cout<<"STUD.NO"<<setw(10)<<"NAME"<<setw(15)<<"ADDRESS"<<setw(30)<<"PHONE NO";
gotoxy(1,8);
cout<<"================================================================================";
}

void modify_stud_record(int n)
{
student stud,temp;
char tmpnm[50],tmpaddress[50];
ifstream inFile;
int fpos1=-1;
inFile.open("student.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
int flag=0;
while(inFile.read((char *) &stud, sizeof(student)))
{
if(stud.getstudid()==n)
{ system("cls");
 intromain();
 stud.showstuddatamulti();
 flag=1;
}
}
inFile.close();
if(flag==0)
cout<<"\n\nrecord not exist";
else
{

fstream File;
File.open("student.dat",ios::binary|ios::in|ios::out);
if(!File)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
while(File.read((char *) &stud, sizeof(student)))
{
if(stud.getstudid()==n)
{ fpos1=(int)File.tellg();
 break;
}
 }
File.seekp(fpos1-sizeof(student),ios::beg);
strcpy(tmpnm,stud.getstudnm());
strcpy(tmpaddress,stud.getstudadd());
char q1[15];
strcpy(q1,stud.getphno());
gotoxy(1,12);
cout<<"*****************************************************************************";
gotoxy(1,13);
cout<<"================ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE=================";
temp.modifystud_data(n,tmpnm,tmpaddress,q1);
File.write((char *) &temp, sizeof(student));
File.close();
 }
}

void deletestud_record(int n)
{
 student stud;
ifstream inFile;
inFile.open("student.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
int flag=0;
while(inFile.read((char *) &stud, sizeof(student)))
{
if(stud.getstudid()==n)
{ system("cls");
 intromain();
 stud.showstuddatamulti();
 flag=1;
}
}
inFile.close();
char ch;
if(flag==0)
cout<<"\n\nrecord not exist";
else
{

gotoxy(1,15);
cout<<"*****************************************************************************";
gotoxy(5,16);
cout<<"======DO YOU WANT TO DELETE THE RECORDS GIVEN ABOVE[YES(Y) OR NO (N)========";
gotoxy(2,17);
cin>>ch;
 if (toupper(ch)=='Y')
 {
 ofstream outFile;
 outFile.open("Temp2.dat",ios::binary);
 ifstream objiff("student.dat",ios::binary);
 objiff.seekg(0,ios::beg);
 while(objiff.read((char *) &stud, sizeof(student)))
{
 if(stud.getstudid()!=n)
 {
 outFile.write((char *) &stud, sizeof(student));
 }
}
outFile.close();
objiff.close();
remove("student.dat");
rename("Temp2.dat","student.dat");
againopenandclosestud();
gotoxy(30,20);
cout<<"----------------------------Record Deleted----------------------------------";
}
}
getch();
}

void againopenandclosestud()
{
 ifstream inFile;
 student stud;
inFile.open("student.dat",ios::binary);
if(!inFile)
{
getch();
return;
}
while(inFile.read((char *) &stud, sizeof(student)))
{
}
inFile.close();
}

int searchstud(int p)
{
student stud;
int tmprt=0;
ifstream inFile;
inFile.open("student.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return -1;
}
int flag=0;
while(inFile.read((char *) &stud, sizeof(student)))
{
if(stud.getstudid()==p)
{ system("cls");
 intromain();
 stud.showstuddatamulti();
 flag=1;
 tmprt=(int)inFile.tellg();
 break;
}
}
inFile.close();
if(flag==0)
return 1;
else
{
return tmprt;
}
}

class product
{
int prodid;
char name[50];
char wing[50];
int qty;
float price,dis;
public:
product()
{
qty=0;
price=0;
dis=0;
}
void modifydata(int n1,char snm[15],char wingnm[15],int q);

void showdatamulti()
{
 gotoxy(5,7);
 cout<<"======================================================================";
 gotoxy(10,8);
 cout<<"PROD NO:";
 gotoxy(30,8);
 cout<<prodid;
 gotoxy(40,8);
 cout<<"NAME OF PROD:";
 gotoxy(60,8);
 cout<<name;
 gotoxy(10,9);
 cout<<"WING:";
 gotoxy(30,9);
 cout<<wing;
 gotoxy(40,9);
 cout<<"PROD PRICE:";
 gotoxy(60,9);
 cout<<price;
 gotoxy(10,10);
 cout<<"QUANTITY:";
 gotoxy(30,10);
 cout<<qty;
 gotoxy(40,10);
 cout<<"DISCOUNT";
 gotoxy(60,10);
 cout<<dis;
 gotoxy(5,11);
 cout<<"=====================================================================";
}

void create_prod(int rn1)
{

 gotoxy(5,7);
 cout<<"======================================================================";
 gotoxy(10,8);
 cout<<"PROD NO:";
 prodid=rn1;
 gotoxy(24,8);
 cout<<prodid;
 gotoxy(35,8);
 cout<<"NAME OF PROD:";
 gotoxy(54,8);
 cin>>name;
 gotoxy(10,9);
 cout<<"WING:";
 gotoxy(22,9);
 cin>>wing;
 gotoxy(35,9);
 cout<<"QUANTITY";
 gotoxy(54,9);
 cin>>qty;
 gotoxy(10,11);
 cout<<"PROD PRICE";
 gotoxy(25,11);
 cin>>price;
 gotoxy(35,11);
 cout<<"DISCOUNT";
 gotoxy(45,11);
 cin>>dis;
 gotoxy(5,12);
 cout<<"=====================================================================";
}
void show_prod()
{
 gotoxy(5,7);
 cout<<"======================================================================";
 gotoxy(10,8);
 cout<<"PROD NO:";

 gotoxy(25,8);
 cout<<prodid;
 gotoxy(35,8);
 cout<<"NAME OF PROD:";
 gotoxy(54,8);
 cout<<name;
 gotoxy(10,9);
 cout<<"WING:";
 gotoxy(25,9);
 cout<<wing;
 gotoxy(35,9);
 cout<<"PROD PRICE:";
 gotoxy(54,9);
 cout<<price;
 gotoxy(10,10);
 cout<<"DISCOUNT:";
 gotoxy(25,10);
 cout<<dis<<"%";
 gotoxy(35,10);
 cout<<"QUANTITY:";
 gotoxy(54,10);
 cout<<qty;
 gotoxy(5,11);
 cout<<"=====================================================================";
 }
//showing all products
void showall(int c)
{
 gotoxy(1,c);
cout<<prodid<<setw(17)<<name<<setw(11)<<wing<<setw(10)<<"PHP"<<price<<setw(15)<<qty<<setw(12)<<dis<<"%";
}

 int retpno()
 {return prodid;}
 float retprice()
 {return price;}
char* getwing()
{ return wing;}
 char* getname()
 {return name;}
int getqty()
{ return qty;}
 float retdis()
 {return dis;}
 void setqty(int q21)
 {
 qty=q21;
 }
}; 
//modifying products
void product::modifydata(int n1,char snm[15],char wingnm[15],int q)
{
char tmpnm[40],tmpnm2[40];
gotoxy(5,14);
 cout<<"===================WANT TO MODIFY ===============================";
 gotoxy(10,15);
 cout<<"PROD NO:";
 prodid=n1;
 gotoxy(25,15);
 cout<<prodid;
 gotoxy(40,15);
 strcpy(name,snm);
 cout<<"NAME OF PROD:";
 gotoxy(60,15);
 cout<<name;
 gotoxy(10,17);
 cout<<"Want to change the name of product";
 gotoxy(50,17);
 int flag=0;
 while(1)
 {
 gets(tmpnm);
 if(strlen(tmpnm)!=0)
 {
flag=1;
break;
}
 if(strlen(tmpnm)==0)
 { flag=0;
 break;
}
 }
 if(flag==1)
 { strcpy(name,tmpnm);
 }
 else
 {
 }
 gotoxy(1,18);
 strcpy(wing,wingnm);
 
 cout<<"WING NAME:";
 gotoxy(20,18);
 cout<<wing;
 gotoxy(35,18);
 cout<<"Want to change the WING";
 gotoxy(65,18);
 flag=0;
 while(1)
 {
 gets(tmpnm2);
 if(strlen(tmpnm2)!=0)
 {
flag=1;
break;
}
 if(strlen(tmpnm2)==0)
 { flag=0;
 break;
}
 }
 if(flag==1)
 { strcpy(wing,tmpnm2);
 }
 
 gotoxy(5,19);
 cout<<"********MODIFY**PRODUCT PRICE - QUANTITY - DISCOUNT ***********";

gotoxy(5,20);
cout<<"PRICE:";
gotoxy(15,20);
 float tmppr=0;
flag=-1;
while(1)
 {
cin>>tmppr;
 if(tmppr!=0)
 {
flag=1;
break;
}else
{ flag=0;
 break;
}
 }
 if(flag==1)
 { price=tmppr;
 }
 else
 {
 }

gotoxy(22,20);
cout<<"INCREASE QUANTITY:";
gotoxy(45,20);
int tmpqty=0;
cin>>tmpqty;
qty=q;
qty=qty+tmpqty;

gotoxy(50,20);
cout<<"DISCOUNT:";
gotoxy(63,20);
float tmpdis=0;
cin>>tmpdis;
dis=tmpdis;

gotoxy(5,22);
 cout<<"=====================================================================";
}

fstream fp;
product pr;

void write_book()
{
 fp.open("product.dat",ios::out|ios::app);
 system("cls");
 intromain();
 int rnn=getproduct();
 if(rnn>100)
 {
 rnn=1;
 }
 pr.create_prod(rnn);
 fp.write((char*)&pr,sizeof(product));
 fp.close();
 gotoxy(10,20);
 cout<<"***************PRODUCTS RECORD SAVED******************* ";
 cin.ignore();
 getch();
}

int getproduct()
{
ifstream objiff;
product st;
int count=0;
objiff.open("product.dat",ios::binary);
objiff.seekg(0,ios::beg);
if(!objiff)
{
cout<<"File could not be open !! Press any Key...";
getch();
}

while(objiff.read((char *) &st, sizeof(product)))
{
 count++;
}

objiff.seekg(count-sizeof(st),ios::beg);
objiff.read((char *) &st, sizeof(product));
count=st.retpno();
count++;
objiff.close();
return count;
}

void display_sp(int n)
{
 int flag=0;
 fp.open("product.dat",ios::in);
 if(!fp)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
 while(fp.read((char*)&pr,sizeof(product)))
{
 if(pr.retpno()==n)
{
 system("cls");
 intromain();
 pr.show_prod();
 flag=1;
}
}
 fp.close();
if(flag==0)
cout<<"\n\nrecord not exist";
getch();
}

int before_order()
{ int f=-1,num=0;
 student stud;
 system("cls");
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE CUST ID TO BE SEARCHED:";
gotoxy(55,9);
cin>>num;
ifstream inFile;
inFile.open("student.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return -1;
}
while(inFile.read((char *) &stud, sizeof(student)))
{
if(stud.getstudid()==num)
{ system("cls");
 intromain();
 stud.showstuddatamulti();
 f=1;
 //tmprt=(int)inFile.tellg();
 break;
}
}
inFile.close();
return f;
}

void place_order()
{
 order o1[50];
 int c=0,pr1=0;
 float amt=0,damt=0,total=0,ttaxt=0;
 int k=0,q1;
 char ch='Y';
int value=before_order();
if(value==1)
{
 system("cls");
 prod_tabular();
 system("cls");
 intromain();
 gotoxy(30,4);
 cout<<"============================";
 gotoxy(30,5);
 cout<<" PLACE YOUR ORDER";
 gotoxy(30,6);
 cout<<"============================";
do
{
 system("cls");
 gotoxy(5,10);
 cout<<"ENTER THE PRODUCT NO: ";
 gotoxy(55,10);
 cin>>pr1;
 k=search(pr1);
 if(k>0)
 {
gotoxy(5,12);
cout<<"Enter the Quantity:";
 gotoxy(28,12);
cin>>q1;
changeqty(pr1,q1);
copyme(k,o1,q1,c);
 }else
 {
cout<<"PRODUCT not found";
 }
system("cls");
gotoxy(10,20);
cout<<"Do you want purchase more (Yes[ y or Y ] or NO [n or N])";
gotoxy(10,21);
cin>>ch;
} while(ch=='y' || ch=='Y');

system("cls");
 gotoxy(20,20);
 cout<<"Thank You For Placing The Order..........";
 getch();
 system("cls");
 intromain();
 gotoxy(13,5);
 cout<<"*************************INVOICE************************";
 gotoxy(1,6);

cout<<"PR.No."<<setw(12)<<"NAME"<<setw(10)<<"Qty"<<setw(15)<<"Price"<<setw(13)<<"Amount"<<setw(23)<<"Amount- discount";
 gotoxy(3,7);
 cout<<"----------------------------------------------------------------------------";
 int yy=8;
for(int x=0;x<c;x++)
{
 gotoxy(1,yy);
 cout<<o1[x].prodid1;
 gotoxy(10,yy);
 cout<<o1[x].pname1;
 gotoxy(27,yy);
 cout<<o1[x].qty1;
 gotoxy(40,yy);
 cout<<"PHP"<<o1[x].price1;
 gotoxy(50,yy);
 amt=o1[x].qty1*o1[x].price1;
 cout<<"PHP"<<amt;
 damt=amt-o1[x].dis1;
 gotoxy(65,yy);
 cout<<"PHP"<<damt;
 total+=damt;
 //ttaxt+=o1[x].tax1;
yy++;
 }
 ttaxt=5;
 gotoxy(3,yy);
 cout<<"----------------------------------------------------------------------------";
 yy++;
 gotoxy(25,yy);
 cout<<"TOTAL:";
 gotoxy(35,yy);
 cout<<total;
 yy++;
 gotoxy(25,yy);
 cout<<"TAX%:";
 gotoxy(36,yy);
 cout<<"+"<<ttaxt;
 yy++;
 gotoxy(25,yy);
 cout<<"----------------------------";
 yy++;
 gotoxy(25,yy);
 cout<<"NET TOTAL:";
 gotoxy(35,yy);
 cout<<(total+((ttaxt*total)/100));
 yy++;
 gotoxy(3,yy);
 cout<<"----------------------------------------------------------------------------";
}else
{
 system("cls");
 gotoxy(20,30);
 cout<<"************YOUR ID IS WRONG ************************************";
}

 getch();
}

void copyme(int k2,order order1[50],int q1,int &c2)
{
 ifstream objiff2("product.dat",ios::binary);
 product bk1;
 objiff2.seekg(k2-sizeof(product));
 objiff2.read((char*)&bk1,sizeof(product));
 strcpy(order1[c2].pname1,bk1.getname());
 strcpy(order1[c2].win1,bk1.getwing());
order1[c2].dis1=bk1.retdis();
order1[c2].price1=bk1.retprice();
 //*********************copy record***********************
 order1[c2].qty1=q1;
 c2++;
 objiff2.close();
}

void intro()
{
gotoxy(4,2);
cout<<"SCHOOL-CANTEEN-MANAGEMENT-PROJECT";
getch();
}

void admin_menu1()
{
 system("cls");
 char ch2;
int num;
 
 system("cls");
intromain();
gotoxy(20,6);
cout<<"=================ADMIN MENU====================";
gotoxy(22,7);
cout<<"1.CREATE STUDENT DETAILS";
gotoxy(22,8);
cout<<"2.DISPLAY ALL STUDENTS DETAILS";
gotoxy(22,9);
cout<<"3.SEARCH RECORD";
gotoxy(22,10);
cout<<"4.MODIFY STUDENTS RECORDS";
gotoxy(22,11);
cout<<"5.DELETE STUDENTS RECORDS";
gotoxy(22,12);
cout<<"6.BACK TO MAIN MENU";
gotoxy(18,13);
cout<<"Please Enter Your Choice (1-6) ";
gotoxy(55,13);
 
 ch2=getche();
 switch(ch2)
 {
 case '1': system("cls");
write_student();
break;
 case '2': stud_tabular();
 break;
 case '3':

system("cls");
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE STUD ID TO BE SEARCHED:";
gotoxy(55,9);
cin>>num;
display_stud_sp(num);
 break;
case '4':
system("cls");
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE STUD ID TO BE SEARCHED AND MODIFY:";
gotoxy(55,9);
cin>>num;
modify_stud_record(num);
 break;
case '5':
system("cls");
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE STUD ID TO BE SEARCHED AND TO DELETE:";
gotoxy(55,9);
cin>>num;
 deletestud_record(num);
break;
case '6': break;
default:cout<<"\a";admin_menu1();
}
}

void admin_menu()
{
 system("cls");
 char ch2;
int num;
 system("cls");
intromain();
gotoxy(20,6);
cout<<"=================ADMIN MENU====================";
gotoxy(22,7);
cout<<"1.CREATE PRODUCTS";
gotoxy(22,8);
cout<<"2.DISPLAY ALL PRODUCTS AVAILABLE";
gotoxy(22,9);
cout<<"3.SEARCH PRODUCT ";
gotoxy(22,10);
cout<<"4.MODIFY PRODUCTS";
gotoxy(22,11);
cout<<"5.DELETE PRODUCTS";
gotoxy(22,12);
cout<<"6.BACK TO MAIN MENU";
gotoxy(18,13);
cout<<"Please Enter Your Choice (1-6) ";
gotoxy(55,13);
 ch2=getche();
 switch(ch2)
 {
 case '1': system("cls");
write_book();
break;
 case '2': prod_tabular();//display_all();
 break;
 case '3':

system("cls");
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE PROD ID TO BE SEARCHED:";
gotoxy(55,9);
cin>>num;
display_sp(num);
 break;
case '4':
system("cls");
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE PROD ID TO BE SEARCHED AND MODIFY:";
gotoxy(55,9);
cin>>num;
modify_record(num);
 break;
case '5':
system("cls");
intromain();
gotoxy(10,8);
cout<<"*****ENTER THE PROD ID TO BE SEARCHED AND TO DELETE:";
gotoxy(55,9);
cin>>num;
delete_record(num);
break;
case '6': break;
default:cout<<"\a";admin_menu();
}
}
int main()
{
 char ch;
 intro();
 do
 {
 system("cls");
intromain();
gotoxy(20,6);
cout<<"=================MAIN MENU====================";
gotoxy(28,7);
cout<<"01. ADMINISTRATOR";
gotoxy(28,8);
cout<<"02. EXIT";
gotoxy(20,10);
cout<<"==============================================";
gotoxy(25,12);
cout<<"Please Select Your Option (1-2) ";
gotoxy(30,14);
ch=getche();
 switch(ch)
 {
 case '1': middleadminmenu();
 break;
 case '2':exit(0);
 default :cout<<"\a";
}
 }while(ch!='3');

 return 0;
}
//***************main intro
void intromain()
{ system("cls");
gotoxy(1,2);
cout<<"**********CANTEEN******MANAGEMENT****SYSTEM******PROJECT**********************";
gotoxy(1,3);
cout<<"******************************************************************************";
}

void prod_tabular()
{
 int r=0,col=10;
product st;
ifstream inFile;
inFile.open("product.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
display_all();
while(inFile.read((char *) &st, sizeof(product)))
{
 if(r<=12)
 {
 r++;
 st.showall(col);
 col++;
 }else
 {
 gotoxy(20,30);
 cout<<"--------------press any key------------------------";
 getch();
 system("cls");
 display_all();
 col=10;
 r=0;
}
}
inFile.close();
getch();
}
//displaying records
void display_all()
{
system("cls");
intromain();
gotoxy(1,5);
cout<<" **********************PRODUCTS DETAILS***************************";
gotoxy(1,6);
cout<<"================================================================================";
gotoxy(1,7);
cout<<"PROD.NO"<<setw(10)<<"NAME"<<setw(15)<<"WING"<<setw(15)<<"PRICE"<<setw(15)<<"QUANTITY"<<
setw(10)<<"DISCOUNT";
gotoxy(1,8);
cout<<"================================================================================";
}
//modifying records
void modify_record(int n)
{
product st,temp;
char tmpnm[50],tmpwing[50];
ifstream inFile;
int fpos=-1;
inFile.open("product.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
int flag=0;
while(inFile.read((char *) &st, sizeof(product)))
{
if(st.retpno()==n)
{ system("cls");
 intromain();
 st.showdatamulti();
 flag=1;
}
}
inFile.close();
if(flag==0)
cout<<"\n\nrecord not exist";
else
{

fstream File;
File.open("product.dat",ios::binary|ios::in|ios::out);
if(!File)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
while(File.read((char *) &st, sizeof(product)))
{
if(st.retpno()==n)
{ fpos=(int)File.tellg();
 break;
}
 }
File.seekp(fpos-sizeof(product),ios::beg);
strcpy(tmpnm,st.getname());
strcpy(tmpwing,st.getwing());
int q1=st.getqty();
gotoxy(1,12);
cout<<"*****************************************************************************";
gotoxy(1,13);
cout<<"================ENTER NEW VALUES FOR THE RECORDS GIVEN ABOVE=================";
temp.modifydata(n,tmpnm,tmpwing,q1);
File.write((char *) &temp, sizeof(product));
File.close();
 }
}
//deleteting recordsa
void delete_record(int n)
{
 product st;
ifstream inFile;
inFile.open("product.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
int flag=0;
while(inFile.read((char *) &st, sizeof(product)))
{
if(st.retpno()==n)
{ system("cls");
 intromain();
 st.showdatamulti();
 flag=1;
}
}
inFile.close();
char ch;
if(flag==0)
cout<<"\n\nrecord not exist";
else
{
gotoxy(1,15);
cout<<"*****************************************************************************";
gotoxy(5,16);
cout<<"======DO YOU WANT TO DELETE THE RECORDS GIVEN ABOVE[YES(Y) OR NO (N)========";
gotoxy(2,17);
cin>>ch;
 if (toupper(ch)=='Y')
 {
 ofstream outFile;
 outFile.open("Temp1.dat",ios::binary);
 ifstream objiff("product.dat",ios::binary);
 objiff.seekg(0,ios::beg);
 while(objiff.read((char *) &st, sizeof(product)))
{
 if(st.retpno()!=n)
 {
 outFile.write((char *) &st, sizeof(product));
 }
}
outFile.close();
objiff.close();
remove("product.dat");
rename("Temp1.dat","product.dat");
againopenandclose();
gotoxy(30,20);
cout<<"----------------------------Record Deleted----------------------------------";
}
}
getch();
}
//deleting record ends
void againopenandclose()
{
 ifstream inFile;
 product st;
inFile.open("product.dat",ios::binary);
if(!inFile)
{
getch();
return;
}
while(inFile.read((char *) &st, sizeof(product)))
{
}
inFile.close();
}
//searching the product
int search(int p)
{
product st;
int tmprt=0;
ifstream inFile;
inFile.open("product.dat",ios::binary);
if(!inFile)
{
cout<<"File could not be open !! Press any Key...";
getch();
return -1;
}
int flag=0;
while(inFile.read((char *) &st, sizeof(product)))
{
if(st.retpno()==p)
{ system("cls");
 intromain();
 st.showdatamulti();
 flag=1;
 tmprt=(int)inFile.tellg();
 break;
}
}
inFile.close();
if(flag==0)
return 1;
else
{
return tmprt;
}
}

void changeqty(int pr1,int q11)
{
product st;
int fpos=-1;
fstream File;
File.open("product.dat",ios::binary|ios::in|ios::out);
if(!File)
{
cout<<"File could not be open !! Press any Key...";
getch();
return;
}
while(File.read((char *) &st, sizeof(product)))
{
if(st.retpno()==pr1)
{ fpos=(int)File.tellg();
 break;
}
 }
File.seekp(fpos-sizeof(product),ios::beg);
int q1=st.getqty();
q1=q1-q11;
st.setqty(q1);
File.write((char *) &st, sizeof(product));
File.close();
}
void middleadminmenu()
{
 char ch;
 do
 {
 system("cls");
intromain();
gotoxy(20,6);
cout<<"===========STUDENT'S-PRODUCT'S MENU===========";
gotoxy(28,7);
cout<<"01. STUDENT'S MENU";
gotoxy(28,8);
cout<<"02. PRODUCT'S MENU";
gotoxy(28,9);
cout<<"03. BACK TO MAIN";
gotoxy(20,10);
cout<<"==============================================";
gotoxy(25,12);
cout<<"Please Select Your Option (1-3) ";
gotoxy(30,14);
ch=getche();
 switch(ch)
 {
 case '1': admin_menu1();
break;
 case '2': admin_menu();
 break;
 case '3': break;
 default :cout<<"\a";admin_menu();
}
 }while(ch!='3');
}
