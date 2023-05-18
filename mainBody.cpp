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
    ShoppingCart cart;
    order order1;
    int LoginTYPEchoice=0;
    cout<<"---Welcome to Jiggly Puff Online Shopping Portal---"<<endl;
    cout<<"---What is your Login type?---"<<endl;
    cout<<"---Please Select your roles---"<<endl; 
    cout<<endl;
    cout<<"choice 1 : Customer"<<endl;
    cout<<"choice 2 : Admin"<<endl;
    cout<<"choice 3 : Vendor"<<endl;
    cout<<"ENTER CHOICE : ";
    cin>>LoginTYPEchoice;
    if (LoginTYPEchoice==1)
    {
        bool registeredusercheck=0;
        cout<<"---Welcome to Customer Mode---"<<endl;
        cout<<"Are you a registered person of this application? "<<endl;
        cout<<"enter '1' for YES or '0' for NO : ";
        cin>>registeredusercheck;
        if (registeredusercheck==1)
        {
            string password;
            int user_id;
            cout<<"Please enter your user id : ";
            cin>>user_id;
            cout<<"Please Enter your Password : ";
            cin>>password;
            int count=0;
            int inVariable=0;
            for (int i = 0; i <users.s.size(); i++)
            {
                if (users.s[i].getUserId()==user_id && users.s[i].getPassword()==password ){
               count++;
               inVariable=i;
                }
            }
            if(count==1){

                cart.PrintMenuForExistingCustomer(users.s[inVariable].getName());
                int choice1=0;
                cin>>choice1;
                if (choice1==1)
                {
                    if (cart.GetNumItemsinCart()==0)
                    {
                        cout<<"please first add items in the cart to place order !!!"<<endl;
                    }
                    else{
                        order1=order(cart.t);
                    }
                    
                }
                else if(choice1==2){
                    for (int i = 0; i <mainInventory.dept.size(); i++)
                    {
                        cout<<i+1<<" "<<mainInventory.dept[i].getName();
                    }
                    cout<<"choose : ";
                    int choosedDepartment=0;
                    cin>>choosedDepartment;
                    for(int i=0;i<mainInventory.dept[choosedDepartment].t.size();i++){
                    cout<<i+1<<" ";

                    mainInventory.dept[choosedDepartment].t[i].displayItemForCustomer();
                    }                       
                    cout<<"choose : ";
                    int choosedItem=0;
                    cin>>choosedItem;
                    cout<<"enter desired quantity : ";
                    int choosedQuantity=0;
                    cin>>choosedQuantity;
                    cart.AddItem(mainInventory.dept[choosedDepartment].t[choosedItem],choosedQuantity);
                    cout<<"Item added to cart successfully !"<<endl;
                    
                     
                }
                 else if(choice1==3){
                    
                }
                 else if(choice1==4){
                    
                }
                 else if(choice1==5){
                    
                }
                 else if(choice1==6){
                    
                }
                 else if(choice1==0){
                    
                }
                
            }
            
        }
        
    }
    else if(LoginTYPEchoice==2){

    }
    else if (LoginTYPEchoice==3){

    }
    else{
        cout<<"wrong choice! please enter again"<<endl;
    }
    
}