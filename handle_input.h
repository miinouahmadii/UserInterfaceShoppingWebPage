#ifndef HANDLE_INPUT_H
#define HANDLE_INPUT_H

#include <string>
#include <vector>
#include "user.h"

using namespace std;

class handle_input{
public:
    vector<user*> return_v_users(){return v_users;}
    user* find_user_by_user_id(int _user_id);
    int find_user_id_by_username(string username);
    void signup(string _email,string  _username,string _password,string _type="buyer",int _loginstatus=1);
    void login(string _email,string _password);
    bool is_admin();
    void login_admin();
    void logout_admin();
private:
    vector<user*> v_users;
    bool admin;
};
#endif
