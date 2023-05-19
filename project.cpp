#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<random>
using namespace std;
class Item{
    int SKU;
    string name;
    double sale_price,purchase_price;
    int stock_quantity;
    int cart_quantity;
    int requestQuantity;
    int soldQuantity;
    int itemspurchased;
    public:
  Item(){

  }
  Item(string name1,int x,double sale,double p,int s,int cart,int request,int sold,int purchased){
    name=name1;
    SKU=x;
    sale_price=sale;
    purchase_price=p;
    stock_quantity=s;
    cart_quantity=cart;
    requestQuantity=request;
    soldQuantity=sold;
    itemspurchased=purchased; 
  }
  string getNameOfItem(){
    return name;
  }
  void setrequestQuantity(int x){
    requestQuantity=x;
  }
  int getrequestquantity(){
    return requestQuantity;
  }
  void setCartQuantity(int x){
    cart_quantity=x;
  }
  int getCartQuantity(){
    return cart_quantity;
  }
  void setItemsPurchasedFromVendor(int x){
    itemspurchased=x;
  }
  int getItemsPurchasedFromVendor(){
    return itemspurchased;
  }
  void displayItemForCustomer(){
    cout<<"----------------------------------"<<endl;
    cout<<"NAME : "<<name<<endl;
    cout<<"SKU : "<<SKU<<endl;
    cout<<"sale price : "<<sale_price<<endl;
    cout<<"In stock : "<<stock_quantity<<endl;
    cout<<"----------------------------------"<<endl;
     
    
  }
   void displayItemForAdmin(){
    cout<<"----------------------------------"<<endl;
    cout<<"NAME : "<<name<<endl;
    cout<<"SKU : "<<SKU<<endl;
    cout<<"sale price : "<<sale_price<<endl;
    cout<<"purchase price : "<<purchase_price<<endl;
    cout<<"In stock : "<<stock_quantity<<endl;
    cout<<"requested quantity from vendor : "<<requestQuantity<<endl;
    cout<<"----------------------------------"<<endl;
  }
  void setSoldquantity(int x){
    soldQuantity=x;
  }
  int getSoldquantity(){
    return soldQuantity;
  }
  void setSKU(int x){
    SKU=x;
  }
  int getSKU(){
    return SKU;
  }
  void setSalePrice(double x){
    sale_price=x;
  }
  double getSalePrice(){
    return sale_price;
  }
  void setPurchasePrice(double x){
    purchase_price=x;
  }
  double getPurchasePrice(){
    return purchase_price;
  }
  void setStockQuantity(int x){
    stock_quantity=x;
  }
  int getStockQuantity(){
    return stock_quantity;
  }
  
  
  void ModifyAnyItem(string name1,int x,double sale,double p,int s){
    name=name1;
SKU=x;
sale_price=sale;
purchase_price=p;
stock_quantity=s;
  }
  
};
class department{
    string department_name;
    
    public:
    vector<Item> t;
    department(){

    }
    department(string p){
department_name=p;
    }
    string getdepartmentName(){
        return department_name;
    }
    string getName(){
        return department_name;
    }
    void displayCategory(){
        cout<<department_name<<endl;
    }
    void AddItem(Item p){
    
        t.push_back(p);
}
void RemoveItem(Item p){
    for (int i = 0; i < t.size(); i++)
    {
         if(t[i].getSKU()==p.getSKU()){
        t.erase(t.begin()+i);
         }
    }
    
}

};
class roles{

string name;
int user_id;
string password;
public:
    // Getter and Setter for 'name'
    string getName()  {
        return name;
    }

    void setName( string newName) {
        name = newName;
    }

    // Getter and Setter for 'user_id'
    int getUserId()  {
        return user_id;
    }

    void setUserId(int newUserId) {
        user_id = newUserId;
    }

    // Getter and Setter for 'password'
    string getPassword()  {
        return password;
    }

    void setPassword(string newPassword) {
        password = newPassword;
    }
};
class customer:public roles{
string email;
string address;
double phone_no;
int frequency;
public:
customer(string newname,int newuserid,string newpassword,string newemail,string newaddress,double newphone_no,int newfrequency){
    email=newemail;
    address=newaddress;
    phone_no=newphone_no;
    frequency=newfrequency;
    setName(newname);
    setUserId(newuserid);
    setPassword(newpassword);
}
void setfrequency(int x){
    frequency=x;
}
int getfrequency(){
    return frequency;
}
// Getter and Setter for 'address'
    string getAddress()  {
        return address;
    }

    void setAddress( string newAddress) {
        address = newAddress;
    }
     // Getter and Setter for 'email'
    string getEmail()  {
        return email;
    }

    void setEmail( string newEmail) {
        email = newEmail;
    }
    // Getter and Setter for 'phone_no'
    int getPhoneNo()  {
        return phone_no;
    }

    void setPhoneNo(int newPhoneNo) {
        phone_no = newPhoneNo;
    }
    void displayCustomerInfo(){
        cout<<"-----------------------------------------"<<endl;
        cout<<"name : "<<getName()<<endl;
        cout<<"user ID : "<<getUserId()<<endl;
        cout<<"email : "<<email<<endl;
        cout<<"address : "<<address<<endl;
        cout<<"phone number : "<<phone_no<<endl;
        cout<<"times shopped before : "<<frequency<<endl;
        cout<<"-----------------------------------------"<<endl;
    }
};
class Inventory{
    public:
vector<department> dept;
void loadInventory(Inventory &mainInventory,string departmentFile,string itemfile){
    fstream departments;
    string line;
    departments.open(departmentFile,ios::in);
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
    items.open(itemfile,ios::in);
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
 }
};
class admin:public roles{
 public:
 admin(string name1,int id,string paswword1){
    setName(name1);
    setUserId(id);
    setPassword(paswword1);
 }
 void displayAdminMenu(){
    cout<<"---------------------------------------"<<endl;
    cout<<"               ADMIN MENU              "<<endl;
    cout<<endl;
    cout<<"\n1.add new product "<<endl;
    cout<<"2.display stock "<<endl;
    cout<<"3.refill through vendor "<<endl;
    cout<<"4.remove an item "<<endl;
    cout<<"5.display status of order placed"<<endl;
    cout<<"6.modify an item"<<endl;
    cout<<"7.exit"<<endl;
    cout<<"---------------END OF MENU--------------"<<endl;
 }
 void seeInventory(Inventory &p){
    int choice=0;
    for (int i = 0; i <p.dept.size(); i++)
    {
        cout<<i+1<<" ";
        p.dept[i].displayCategory();
        cout<<endl;
    }
    
    cout<<"enter the department you would like to view : ";
    cin>>choice;
    for(int i=0;i<p.dept[choice].t.size();i++){
    p.dept[choice].t[i].displayItemForAdmin();
    } 
 }
 
 void displayAdminInfo(){
    cout<<"-------------------------------"<<endl;
    cout<<"name : "<<getName()<<endl;
    cout<<"user id : "<<getUserId()<<endl;
    cout<<"-------------------------------"<<endl;
 }
 void ADDItem(Inventory &p){
    string deptartmentName;
    string name;
    int x=0;
    double sale=0.0;
    double purchase=0.0;
    int stock=0;
    int cart=0;
    int requested=0;
    int soldquantity=0;
    int itempurchased=0;
    cout<<"enter department name into which you would like to add ITEM : ";
    cin>>deptartmentName;
    cout<<"enter name of ITEM : ";
    cin>>name;
    cout<<"enter SKU of ITEM : ";
    cin>>x;
    cout<<"enter sale price of ITEM : ";
    cin>>sale;
    cout<<"enter purchase price of ITEM : ";
    cin>>purchase;
    cout<<"enter quantity in stock of ITEM : ";
    cin>>stock;
    cout<<"enter requested quantity of item from vendor";
    cin>>requested;
    cout<<"enter sold quantity of item ";
    cin>>soldquantity;
    cout<<"enter total quantity of  item purchased from vendor ";
    cin>>itempurchased;
    for (int i = 0; i < p.dept.size(); i++)
    {
        
        if(deptartmentName==p.dept[i].getdepartmentName()){
            Item temp;
            temp=Item(name,x,sale,purchase,stock,0,requested,soldquantity,itempurchased);
            p.dept[i].AddItem(temp);
            cout<<"ITEM ADDED SUCCESSFULLY !!"<<endl;
            break;
        
        }
    }
    

 }
 void RemoveItem(Inventory &p){
    int sku=0;
    cout<<"enter Sku of item you would like to remove : ";
    cin>>sku;
    for (int i = 0; i < p.dept.size(); i++)
    {
        for(int j=0;j<p.dept[i].t.size();j++){

        
        if(sku==p.dept[i].t[j].getSKU()){
            
            p.dept[i].RemoveItem(p.dept[i].t[j]);
            cout<<"ITEM REMOVED SUCCESSFULLY !!"<<endl;
            break;
        }
        }
    }

 }
 void requestItemQuantity(Inventory &p){
    int sku,quantity;
       cout<<"enter the sku of the item which you want to request from vendor: ";
       cin>>sku;
       cout<<"enter the quantity of item you want to request : ";
       cin>>quantity;
       for (int i = 0; i <p.dept.size(); i++)
       {
        for (int j = 0; j < p.dept[i].t.size(); j++)
        {
            if(p.dept[i].t[j].getSKU()==sku){
                p.dept[i].t[j].setrequestQuantity(quantity);
                break;
            }
            else{
                cout<<"error, item not found "<<endl;
            }
        }
       }
 }
 void modifyItem(Inventory &p){
     int sku=0;
     cout<<"enter sku of item you want to modify : ";
     cin>>sku;
     for (int i = 0; i <p.dept.size(); i++)
     {
        for (int j = 0; j<p.dept[i].t.size(); j++)
        {
            if (p.dept[i].t[j].getSKU()==sku)
     {
       string name1;
       int x;
       double sale;
       double purchase;
       int s;
       cout<<"enter new name of item : ";
       cin>>name1;
       cout<<"enter new sku of item : ";
       cin>>x;
       cout<<"enter new sale price of item : ";
       cin>>sale;
       cout<<"enter new purchase price of item : ";
       cin>>purchase;
       cout<<"enter new stock quantity of item : ";
       cin>>s;
       p.dept[i].t[j].ModifyAnyItem(name1,x,sale,purchase,s);
       break;
     }
     else{
        cout<<"error,item not found"<<endl;
        break;
     }
        }
        
     }
     
     
 }
};
class vendor:public roles{
public:
vendor(string name1,int id,string paswword1){
    setName(name1);
    setUserId(id);
    setPassword(paswword1);
 }
void seeInventory( Inventory p){
    for (int i = 0; i <p.dept.size(); i++)
    {
        for (int j = 0;  j<p.dept[i].t.size(); j++)
        {
            if (p.dept[i].t[j].getrequestquantity()>0)
            {
                p.dept[i].t[j].displayItemForAdmin();
            }
            
        }
        
    }
}
void displayvendorInfo(){
    cout<<"-------------------------------"<<endl;
    cout<<"name : "<<getName()<<endl;
    cout<<"user id : "<<getUserId()<<endl;
    cout<<"-------------------------------"<<endl;
 }
void updateInventory(Inventory p){
     int sku=0,quantity=0;
     cout<<"enter the sku of item you want to update stock of : ";
     cin>>sku;
     cout<<"enter the quantity of stock you would like to add : ";
     cin>>quantity;
      for (int i = 0; i <p.dept.size(); i++)
    {
        for (int j = 0;  j<p.dept[i].t.size(); j++)
        {
            if (p.dept[i].t[j].getSKU()==sku)
            {
                int temp;
                temp=p.dept[i].t[j].getStockQuantity()+quantity;
                p.dept[i].t[j].setStockQuantity(temp);
                p.dept[i].t[j].setrequestQuantity(0);
                break;
            
            }
            
        }
        
    }
}
};
struct ShoppingCart{
vector<Item> t;
int sizeOfCart;
ShoppingCart(){
    sizeOfCart=0;
}

void AddItem(Item p,int quantity){
    
        t.push_back(p);
    t[t.size()-1].setCartQuantity(quantity);
    sizeOfCart++;
}
void RemoveItem(Item p){
    for (int i = 0; i < sizeOfCart; i++)
    {
         if(t[i].getSKU()==p.getSKU()){
        t.erase(t.begin()+i);
        sizeOfCart--;
         }
    }
}
int GetNumItemsinCart(){
    return t.size();
}
double getCostOfCart(){
    double cost=0.0;
    for (int i = 0; i <t.size(); i++)
    {
        cost=cost+(t[i].getSalePrice()*(t[i].getCartQuantity()));
    }
    return cost;
}
void PrintTotalItems(){
    if(t.size()==0){
        cout<<"\nSHOPPING CART IS EMPTY "<<endl;

    }
    else{
        cout<<" total items in cart are : "<<t.size()<<endl;
    }
}
void PrintItemDescription(){
    for (int i = 0; i < t.size(); i++)
    {
        t[i].displayItemForCustomer();
    }
    
}
void PrintMenuForExistingCustomer(string nameofexistingcustomer){
                cout<<"                        Customer View               "<<endl;
                cout<<"----------------------------------------------------"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                cout<<"Welcome Back Mr/Mrs. "<<nameofexistingcustomer<<endl;
                cout<<endl;
                cout<<"what would like to do from the choices below? "<<endl;
                cout<<"if you want to place order enter 1 "<<endl;
                cout<<"if you want to add item to cart press 2"<<endl;
                cout<<"if you want to display cart press 3"<<endl;
                cout<<"if you want to search item by sku press 4"<<endl;
                cout<<"if you want to remove item from cart press 5"<<endl;
                cout<<"if you want to see total price of your cart press 6"<<endl;
                cout<<"if you want to exit press 0"<<endl;
                cout<<"enter choice : ";
}
void PrintMenuForNon_ExistingCustomer(){
                cout<<"                        Customer View               "<<endl;
                cout<<"----------------------------------------------------"<<endl;
                cout<<"----------------------------------------------------"<<endl;
                cout<<"Welcome Dear Customer"<<endl;
                cout<<endl;
                cout<<"what would like to do from the choices below? "<<endl;
                cout<<"if you want to place order enter 1 "<<endl;
                cout<<"if you want to add item to cart press 2"<<endl;
                cout<<"if you want to display cart press 3"<<endl;
                cout<<"if you want to search item by sku press 4"<<endl;
                cout<<"if you want to remove item from cart press 5"<<endl;
                cout<<"if you want to see total price of your cart press 6"<<endl;
                cout<<"if you want to exit press 0"<<endl;
                cout<<"enter choice : ";
}
};
struct order{
    vector<Item> t;
    order(){

    }
    order(vector<Item> p){
        vector<Item> t(p);
    }
    int getRandomNumber(int min, int max) {
    std::random_device rd;                            // Obtain a random seed from the hardware
    std::mt19937 eng(rd());                           // Seed the random number engine
    std::uniform_int_distribution<int> distr(min, max); // Define the range

    return distr(eng);                                 // Generate and return a random number
}
void printBill(){

}
};
class Report{
vector<order> k;
public:
Report(vector<order> p){
    vector<order> k(p);
}
void GenerateSalesReport(){
    //total amounts of items sold;
    int amountofItemSold=0;
    for (int i = 0; i <k.size(); i++)
    {
        for (int j = 0; j < k[i].t.size(); i++)
        {
            amountofItemSold++;
        }
        
    }
    cout<<" quantity of total items sold is : "<<amountofItemSold<<endl;
    //total quantity of each item sold
    for (int i = 0; i <k.size(); i++)
    {
        for(int j=0;j<k[i].t.size();j++){
        k[i].t[j].displayItemForAdmin();
        cout<<k[i].t[j].getSoldquantity()<<endl;
        }
    }
// total sale amount of each item
for (int i = 0; i <k.size(); i++)
    {
        for(int j=0;j<k[i].t.size();j++){
        k[i].t[j].displayItemForAdmin();
        }
    }
// total revenue collected
double revenue=0.0;
for (int i = 0; i <k.size(); i++)
    {
        for(int j=0;j<k[i].t.size();j++){
        revenue=(k[i].t[j].getSalePrice()*k[i].t[j].getSoldquantity())+revenue;
        }
    }
    cout<<"total revenue generated is :  "<<revenue<<endl;
    // total profit of all sales
    double profit=0.0;
    for (int i = 0; i <k.size(); i++)
    {
        for(int j=0;j<k[i].t.size();j++){
        profit=((k[i].t[j].getSalePrice()-k[i].t[j].getPurchasePrice())*k[i].t[j].getSoldquantity())+profit;
        }
    }
    cout<<"total profit collected is : "<<profit<<endl;
// total cost of all items sold
double cost=0.0;
    for (int i = 0; i <k.size(); i++)
    {
        for(int j=0;j<k[i].t.size();j++){
        cost=(k[i].t[j].getPurchasePrice()*k[i].t[j].getSoldquantity())+cost;
        }
    }
    cout<<"total cost of all items sold is : "<<cost<<endl;
}
void purchaseReport(Inventory p){
    // total items purchased 
    int itemsPurchased=0;
    for (int i = 0; i <p.dept.size(); i++)
    {
        for (int j = 0; j <p.dept[i].t.size(); j++)
        {
           itemsPurchased=itemsPurchased+p.dept[i].t[j].getItemsPurchasedFromVendor();
            
        }
        
    }
    
//cost of each item 
for (int i = 0; i <k.size(); i++)
    {
        for(int j=0;j<k[i].t.size();j++){
        k[i].t[j].displayItemForAdmin();
        }
    }
//total cost of all items 
double cost=0.0;
 for (int i = 0; i <k.size(); i++)
    {
        for(int j=0;j<k[i].t.size();j++){
        cost=(k[i].t[j].getPurchasePrice()*k[i].t[j].getItemsPurchasedFromVendor())+cost;
        }
    }
    cout<<"total cost of all items sold is : "<<cost<<endl;

}
};
class UserDatabase{
public:
vector<customer> s;
vector<admin> d;
vector<vendor> k;
void addcustomer(customer p){
    s.push_back(p);
}
void addAdmin(admin p){
    d.push_back(p);
}
void addVendor(vendor p){
    k.push_back(p);
}
void LoadCustomerDatabase(UserDatabase &users,string customerFileName){
fstream customersFile;
    string line2;
    customersFile.open(customerFileName,ios::in);
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
}
void LoadAdminDatabase(UserDatabase &users,string adminfilename){
    fstream AdminFile;
    string line3;
    AdminFile.open(adminfilename,ios::in);
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
 }
 void LoadVendorDatabase(UserDatabase &users,string vendorfilename){
    fstream VendorFile;
    string line4;
    VendorFile.open(vendorfilename,ios::in);
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
 }
};

class VisaCard{
    double card_number;
    double cvv;
    string expiry_date;
public:
VisaCard(double c,double cv,string expiry){
    card_number=c;
    cvv=cv;
    expiry_date=expiry;
}
string getExpiryDate(){
return expiry_date;
}
double getCardNumber(){
    return card_number;
}
double getCvv(){
    return cvv;
}
bool getPayment(vector<VisaCard> visa){

     double card_number1;
    double cvv1;
    string expiry_date1;
    cout<<"enter card number : ";
    cin>>card_number1;
    cout<<"enter pin code also known as cvv : ";
    cin>>cvv1;
    cout<<"enter expiry date in this format (month-day-year) : ";
    cin>>expiry_date1;
    for (int i = 0; i < visa.size(); i++)
    {
        if (card_number1==visa[i].getCardNumber() && cvv1==visa[i].getCvv() && expiry_date1==visa[i].getExpiryDate())
        {
            return 1;
        }
        
    }
    return 0;
}
void loadPaymentDatabase(vector<VisaCard> &visa,string filename){
     fstream visaFile;
     string line;
     visaFile.open(filename,ios::in);
     while(getline(visaFile,line)){
        stringstream ss(line);
        string card_number1,cvv1;
        string expiry_date1;
        getline(ss,card_number1,',');
        getline(ss,cvv1,',');
        getline(ss,expiry_date1,',');
        double card_number2=stod(card_number1);
        double cvv2=stod(cvv1);
        VisaCard temp(card_number2,cvv2,expiry_date1);
        visa.push_back(temp);
     }
     visaFile.close();
}
};
