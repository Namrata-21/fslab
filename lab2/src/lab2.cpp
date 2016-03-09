#include <iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
using namespace std;
class student{
private:string name;
        string usn;
        string branch;
        string sem;
public:void pack(string fname);
       void unpack(string);
       void unpack(ifstream &);
       void modify(string);
      int search(string,string);
       void read();
       //void write();
};

void student::read()
{


    cout<<"in read";
    cout<<"enter name";
    cin>>name;
    cout<<"enter usn";
    cin>>usn;
    cout<<"enter branch";
    cin>>branch;
    cout<<"enter sem";
    cin>>sem;

}
void student::pack(string fname)
{

     string temp;
     temp=usn+'|'+name+'|'+branch+'|'+sem;
     temp.resize(100,'$');
     ofstream f1(fname.c_str(),ios::app);
     f1<<temp<<endl;
     f1.close();

}
int student::search(string key,string fname)
{
    student s[10];
    int i=0,pos=0;
    ifstream f1(fname.c_str());
    while(!f1.eof())
    {
        cout<<"in search";
        s[i].unpack(f1);
        if(key==s[i].usn)
        {
            cout<<"record found\n";
             pos=f1.tellg();
            cout<<s[i].usn<<"\t"<<s[i].name;
            break;

        }
        i++;
    }

    f1.close();
cout<<endl<<"pos is  "<<pos;
return pos;
}

void student::unpack(string fname)
{
    string temp;
    ifstream f1(fname.c_str());
    getline(f1,usn,'|');
    getline(f1,name,'|');
    getline(f1,branch,'|');
    getline(f1,sem,'$');
    f1.close();
}
void student::unpack(ifstream &f1)
{
        string temp;
    getline(f1,usn,'|');
    getline(f1,name,'|');
    getline(f1,branch,'|');
    getline(f1,sem,'$');
        getline(f1,temp);
}

//void student::modify(string fname)
//{
   // string buffer,key;
    //fstream file;
    //int choice,pos;
    //cout<<"Enter the usn to be searched\n";
   // cin>>key;
    //cout<<"enter the filename";
           // cin>>fname;
    //pos=search(key,filename);
    //pos=pos-100;
    //if(pos){
    //cout<<"\n What to modify?";
    //cin>>choice;

   // switch(choice)
    //{
        //case 1: cout<<"\nUSN:"; cin>>usn; break;
        //case 2:    cout<<"\nName:";cin>>name;break;
        //case 3:    cout<<"\nBranch:";cin>>branch;break;
        //case 4:    cout<<"\nSemster:";cin>>sem;break;
        //default: cout <<"Wrong Choice";
    //}


    //file.open(filename.c_str(),ios::out);
    //pos-=101;//skip $\n
    //file.seekp(pos,ios::beg);
    //pack(filename);
    //file.close();
   /// }
    //else
        //exit(0);
    //return 0;
//}

int main()
{
    student s;
    string fname,key;
    int choice;
    while(1)
    {
         cout<<endl<<"1.insert 2.search 3.modify\n";
         cout<<"enter ur choice";
         cin>>choice;
        cout<<"enter the filename";
               cin>>fname;
         switch(choice)
         {
         case 1:


               s.read();
              s.pack(fname);
               break;
        case 2:cout<<"enter usn to be searched\n";
               cin>>key;
               s.search(key,fname);
               break;


        //case 3:s.modify(fname);
           //   break;
        //default:exit(0);

        }
    }
               return 0;
}
