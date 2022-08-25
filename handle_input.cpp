#include "handle_input.h"
#include <iostream>

using namespace std;

void handle_input::signup(string _email,string  _username,string _password,string _type,int _loginstatus)
{
    if(_type=="seller")
    {
        user *p=new user(v_users.size()+1,_email,_username,_password,"seller",1);
        v_users.push_back(p);
    }
    else
        v_users.push_back(new user(v_users.size()+1,_email,_username,_password,"buyer",1)); 
    cout << "OK" << endl;   
}

void handle_input::login(string _email,string _password)
{
    for(int i = 0; i < v_users.size(); i++)
    {
        if(v_users[i]->return_email() == _email && v_users[i]->return_password() == _password){
            v_users[i]->manage_login_status(1);
            v_users[i]->makeOnline();
            cout << "OK" << endl;
            return;
        }
    }
    cout << "Bad Request" << endl;
}

user* handle_input::find_user_by_user_id(int _user_id)
{
    for(int i=0;i<v_users.size();i++)
    {
        if(v_users[i]->return_user_id()==_user_id)
            return v_users[i];
    }
    return nullptr;
}

int handle_input::find_user_id_by_username(string username)
{
    for(int i = 0; i < v_users.size(); i++)
    {
        if(v_users[i]->return_username() == username)
            return v_users[i]->return_user_id();
    }
}
bool handle_input::is_admin(){return admin;};
void handle_input::login_admin(){admin=true;};
void handle_input::logout_admin(){admin=false;};