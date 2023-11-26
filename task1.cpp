#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void print();
void login();
void reg();
struct data  //make struct to carry user data
{
    string user_name;
    string password;
};
int main()
{
    int key ;

    while (1)
    {
        print();
        cout << "Enter your number : ";
        cin>>key;
        if (key==1)
            reg();
        else if (key==2)
            login();
        else if (key==3)
            break;
        else cout << "Wrong choice \n ";
    }

    return 0;
}
void print() // fun to make choise
{
    cout << "1- regester :\n";
    cout << "2- login : \n";
    cout << "3- exit now :\n";
}
void login ()
{
    data d; // indix to struct
    int counter=0;
    cout <<"Enter your user name : ";
    cin >> d.user_name;
    ifstream datauser("data.txt");
    string temp;
    while (datauser>>temp) // check this user exist or not
    {
        if (d.user_name==temp)
        {
            counter++;
            break;
        }
    }
    datauser.close();
    if(counter==1)
    {
        cout <<"Enter your passowrd : ";
        cin >> d.password;
        ifstream pass("pass.txt");
        string p;
        while (pass>>p) // check this password exist or not
        {
            if (p==d.password)
            {
                cout << "welcome "<<d.user_name<<endl;
                break;
            }
            else
            {
                cout << "wrong password \n";
                break;
            }
        }
        pass.close();
    }
    else cout << "this account does'nt exist : \n ";
}
void reg()
{
    data d;
    int counter=0;
    cout <<"Enter your user name : ";
    cin >>d.user_name;
    ifstream datauser ("data.txt");
    string temp ;
    while (datauser>>temp) //check this user exist or not
    {
        if(temp==d.user_name)
        {
            counter++;
            break;
        }
    }
    datauser.close();
    if (counter==1)
    {
        cout << "this account already exist : ";
    }
    else
    {
        ofstream datauser ("data.txt"); //put this new user name
        datauser << d.user_name;
        cout << "Enter your password : ";
        cin>>d.password;
        ofstream pass("pass.txt"); // put this new password
        pass<<d.password;
        pass.close();
        datauser.close();
    }

}
