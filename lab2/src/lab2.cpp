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

public:void pack(string filename);
       void read();
	   void search(string,string);
	   void del();
	   void modifiy();
	   void unpack(string);
};
fstream f1;
int main()
{
	int choice;
	student s;
	string fname,key;
		while (1)
			{
				cout<<"select the choice 1.insert 2.search 3.unpack 4.modifiy";
											cin>>choice;
			switch(choice)
			{
			case 1:s.read();
			cout<<"enter filename";
			cin>>fname;
			        s.pack(fname);
			break;
			case 2:
				cout<<"enter usn to b searched\n";
				cin>>key;
				s.search(key,fname);
					break;
			//case 3:s.unpack();
					//break;//
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
void student::pack(string filename)
{
	string buffer;
	ofstream myf(filename.c_str(),ios::app);
	buffer=usn+'|'+name+'|'+branch+'|'+sem;
	buffer.resize(100,'$');
	myf<<buffer<<endl;
	myf.close();
}
void student::unpack(string fname)
{

	ifstream myf(fname.c_str());
	getline(myf,usn,'|');
	getline(myf,name,'|');
	getline(myf,branch,'|');
	getline(myf,sem,'|');
	myf.close();
}
void student::search(string key,string fname)
{
	student s[10];
	int i=0,count=0;
	ifstream myf(fname.c_str());
	while(!myf.eof())
	{
		cout<<"in search\n";
		s[i].unpack(fname);
	if(key==s[i].usn)
	{
		cout<<"record found\n";
	cout<<s[i].usn<<"\t"<<s[i].name;
	break;
	}
	i++;
	}
myf.close();
}

