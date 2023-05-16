#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include"project.cpp"
using namespace std;
int main(){
    Inventory mainInventory;
    fstream inventory;
    string line;
    inventory.open("departments1.txt",ios::in);
    while(getline(inventory,line)){
        getline(inventory,line);
    department dept(line);
    mainInventory.dept.push_back(dept);
    }
     for (int i = 0; i <mainInventory.dept.size(); i++)
    {
       cout<<mainInventory.dept[i].getName()<<endl;
    }
   
    inventory.close();
    
}