#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

void loadDB(unordered_map<string, string> &db){
  ifstream fin;
  fin.open("db.txt");
  string curr_line;
  while(getline(fin, curr_line)){
      int firstSpace = curr_line.find(" : ");
      string curr_key = curr_line.substr(0, firstSpace);
      string curr_value = curr_line.substr(firstSpace+3, curr_line.length());
      db[curr_key] = curr_value;
  }
  fin.close();
}

bool keyNotPresentInDb(string &key, unordered_map<string, string> &db){
    return (db.find(key) == db.end());
}

void addValue(ofstream &fout, unordered_map<string, string> &db){
    string key, value;
    cout<<"Enter key: \n";
    cin>>key;
    cout<<"\nEnter value: \n";
    cin>>value;
    if(keyNotPresentInDb(key, db)){
        fout<<key<<" : "<<value<<"\n";
        db[key] = value;
        cout<<"\nData inserted successfully!\n";
    }
    else{
        cout<<"Error: Duplicate key found!\n";
    }
    fout.flush();
}

void getValue(unordered_map<string, string> &db){
    cout<<"Enter key : ";
    string key;
    cin>>key;
    if(keyNotPresentInDb(key, db)){
        cout<<"Sorry, no key found!\n";
    }
    else{
        cout<<db[key]<<endl;
    }
}

void updateValue(unordered_map<string, string> &db){
    cout<<"Enter key: ";
    string key;
    cin>>key;
    if(keyNotPresentInDb(key, db)){
        cout<<"Sorry, no key found!\n";
    }
    else{
        string value;
        cout<<"Enter value: ";
        cin>>value;
        db[key] = value;
        ofstream fout;
        fout.open("db.txt", ios::trunc);
        for(auto i:db){
            fout<<i.first<<" : "<<i.second<<"\n";
        }
        cout<<"Value updated!\n";
        fout.flush();
        fout.close();
    }
}

void deleteValue(unordered_map<string, string> &db){
    cout<<"Enter key: ";
    string key;
    cin>>key;
    if(keyNotPresentInDb(key, db)){
        cout<<"Sorry, no key found!\n";
    }
    else{
        cout<<"Do you really want to delete permanently?(Y/N): ";
        char cmd;
        cin>>cmd;
        if(cmd == 'Y' || cmd == 'y'){
            db.erase(key);
            ofstream fout;
            fout.open("db.txt", ios::trunc);
            for(auto i:db){
                fout<<i.first<<" : "<<i.second<<"\n";
            }
            cout<<"Value deleted!\n";
            fout.flush();
            fout.close();
        }
        else{
            cout<<"Key deletion terminated.\n";
        }
    }
}

int main()
{
   unordered_map<string, string> database_map;
   cout<<"Loading the database..."<<endl;
   ofstream fout;
   fout.open("db.txt", ios::app);
   loadDB(database_map);
   cout<<"Database loaded successfully"<<endl;
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
            addValue(fout, database_map);
            break;
           case 2:
            getValue(database_map);
            break;
           case 3:
            updateValue(database_map);
            break;
           case 4:
            deleteValue(database_map);
            break;
           default:
            quit = true;
            break;
       }
   }
   fout.close();
   return 0;
}