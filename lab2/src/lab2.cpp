//============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : prg2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string>
#include<fstream>
using namespace std;
class student
	{
private:string name;
        string usn;
        string branch;
        string sem;

public:void pack();
       void read();
	   void search();
	   void del();
	   void modifiy();
	   void unpack();
};
fstream f1;
int main()
{
	int choice;
	student s;

			while (1)

			{
				cout<<"select the choice 1.insert 2.search 3.del 4.modifiy";
											cin>>choice;
			switch(choice)
			{
			case 1:s.read();
			        s.pack();
			break;
			//case 2:search();
				//	break;
			//case 3:del();
				//	break;
			//case 4:modifiy();
					//break;
			}
			}
}
void student::read()
{
				cout<<"enter name"<<endl;
				cin>>name;
				cout<<"enter  usn"<<endl;
				cin>>usn;
				cout<<"enter branch"<<endl;
				cin>>branch;
				cout<<"enter sem"<<endl;
				cin>>sem;
}
void student::pack()
{
	string temp,i;
	temp=usn+'|'+name+'|'+branch+'|'+sem;
	temp.resize(100,'$');
	f1.open("data.txt",ios::out|ios::app);
	f1<<temp<<endl;
	f1.close();
}


