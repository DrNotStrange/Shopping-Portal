#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include"project.cpp"
using namespace std;
int main(){
    Inventory mainInventory;
    fstream departments;
    string line;
    departments.open("departments.csv",ios::in);
    while(getline(departments,line))
    {
        stringstream ss(line);
        getline(ss,line,',');
        department dept(line);
        mainInventory.dept.push_back(dept);
    }
     for (int i = 0; i <mainInventory.dept.size(); i++)
    {
       cout<<mainInventory.dept[i].getName()<<endl;
    }
    departments.close();
    fstream items;
    string line1;
    items.open("items.csv",ios::in);
    while(getline(items,line1)){
stringstream ss1(line1);
string sku,department_name1,name,sale_price,purchase_price,stock_quantity,cart_quantity,request_quantity,sold_quantity,itemspurchased;
getline(ss1,sku,',');
getline(ss1,department_name1,',');
getline(ss1,name,',');
getline(ss1,sale_price,',');
getline(ss1,purchase_price,',');
getline(ss1,stock_quantity,',');
getline(ss1,cart_quantity,',');
getline(ss1,request_quantity,',');
getline(ss1,sold_quantity,',');
getline(ss1,itemspurchased,',');
int sku1=stoi(sku);
double sale_price1=stoi(sale_price);
double purchase_price1=stod(purchase_price);
int stock_quantity1=stoi(stock_quantity);
int cart_quantity1=stoi(cart_quantity);
int request_quantity1=stoi(request_quantity);
int sold_quantity1=stoi(sold_quantity);
int itemspurchased1=stoi(itemspurchased);
Item temp(name,sku1,sale_price1,purchase_price1,stock_quantity1,cart_quantity1,request_quantity1,sold_quantity1,itemspurchased1);
for (int i = 0; i < mainInventory.dept.size(); i++)
{
    if (mainInventory.dept[i].getName()==department_name1)
    {
        mainInventory.dept[i].AddItem(temp);
    }
    
}
    }
    items.close();
    for (int i = 0; i <mainInventory.dept.size(); i++)
    {
        for (int j = 0; j < mainInventory.dept[i].t.size(); j++)
        {
             mainInventory.dept[i].t[j].displayItemForAdmin();
             cout<<endl;
        }
    }
    UserDatabase users;
    fstream customersFile;
    string line2;
    customersFile.open("customers1.csv",ios::in);
    while(getline(customersFile,line2)){
        stringstream ss2(line2);
        string name,customer_id,password,email,address,frequency,phone_no;
        getline(ss2,name,',');
        getline(ss2,customer_id,',');
        getline(ss2,password,',');
        getline(ss2,email,',');
        getline(ss2,address,',');
        getline(ss2,frequency,',');
        getline(ss2,phone_no,',');
        double phone_no1=stoi(phone_no);
        int customer_id1=stoi(customer_id);
        int frequency1=stoi(frequency);
        customer temp(name,customer_id1,password,email,address,phone_no1,frequency1);
        users.addcustomer(temp);
    }
    customersFile.close();

    for (int i = 0; i <users.s.size(); i++)
    {
        users.s[i].displayCustomerInfo();
    }
    fstream AdminFile;
    string line3;
    AdminFile.open("admin.csv",ios::in);
    while(getline(AdminFile,line3)){
        stringstream ss3(line3);
        string name,id,password;

            getline(ss3,name,',');
            getline(ss3,id,',');
            getline(ss3,password,',');
            int id1=stoi(id);
            admin temp(name,id1,password);
            users.addAdmin(temp);
    }
    AdminFile.close();
    for (int i = 0; i <users.d.size(); i++)
    {
        users.d[i].displayAdminInfo();
    }
    fstream VendorFile;
    string line4;
    VendorFile.open("vendor.csv",ios::in);
    while(getline(VendorFile,line4)){
        stringstream ss4(line4);
        string name,id,password;

            getline(ss4,name,',');
            getline(ss4,id,',');
            getline(ss4,password,',');
            int id1=stoi(id);
            vendor temp(name,id1,password);
            users.addVendor(temp);
    }
    VendorFile.close();
     for (int i = 0; i <users.k.size(); i++)
    {
        users.k[i].displayvendorInfo();
    }
    
}