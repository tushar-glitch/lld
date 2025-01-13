#include <iostream>
#include <fstream>
using namespace std;

bool checkDuplicate(string &key){
   ifstream fin;
   fin.open("db.txt");
   string curr_line;
   while(getline(fin, curr_line)){
       int firstSpace = curr_line.find(' ');
       string curr_key = curr_line.substr(0, firstSpace);
       if(curr_key == key){
           cout<<"Error: Duplicate key found!\n";
           return 0;
       }
   }
   fin.close();
   return 1;
}

void addValue(ofstream &fout){
    string key, value;
    cout<<"Enter key: \n";
    cin>>key;
    cout<<"\nEnter value: \n";
    cin>>value;
    if(checkDuplicate(key)){
        fout<<key<<" : "<<value<<"\n";
        cout<<"\nData inserted successfully!\n";
    }
    fout.flush();
}

int main()
{
   cout<<"Creating a new Database..."<<endl;
   ofstream fout;
   fout.open("db.txt", ios::app);
   cout<<"Database created successfully"<<endl;
   bool quit = false;
   while(!quit){
       cout<<"\n\n";
       cout<<"1. Add value to DB.\n";
       cout<<"2. Get value from DB.\n";
       cout<<"3. Update value to DB.\n";
       cout<<"4. Delete value frop DB.\n";
       cout<<"5. Quit.\n";
       cout<<"Select an operation...\n";
       int op;
       cin>>op;
       switch(op){
           case 1:
            addValue(fout);
            break;
           default:
            quit = true;
            break;
       }
   }
   fout.close();
   return 0;
}