#include "user.h"
#include <string>
#include <iostream>

using namespace std;

user::user(int _user_id,string _email,string _username,string _password,string _type,int _loginstatus)
{
    user_id=_user_id;
    email=_email;
    username=_username;
    password=_password;
    type=_type;
    login_status=_loginstatus;
    money=0;
}

void user::add_offer(int offer_id,int offer_nums,float offer_price)
{
    offer* new_offer = new offer(offer_id,offer_nums,offer_price);
    new_offer->set_offer_id(offers.size()+1);
    offers.push_back(new_offer);
}

void user::add_discount_code_offer(int offer_id,float discount_percent,int discount_number)
{
    for(int i=0;i<offers.size();i++)
    {
        if(offers[i]->return_offer_id()==offer_id)
        {
           offers[i]->set_discount(discount_percent,discount_number);
        }
    }

}

void user::change_offer(int offer_id,float offer_price,int offer_nums)
{
    for(int i=0;i<offers.size();i++)
    {
        if(offers[i]->return_offer_id()==offer_id)
        {
           offers[i]->change_price(offer_price);
           offers[i]->change_product_numbers(offer_nums);
        }
    }
}
string user::return_username(){return username;}
string user::return_password(){return password;}
string user::return_type(){return type;}
string user::return_email(){return email;}
bool user::isOnline(){ return online; }
void user::makeOffline(){ online = false; }
void user::makeOnline(){ online = true; }  
int user::return_login_status(){return login_status;}
int user::return_user_id(){return user_id;}

void user::manage_login_status(int _loginstatus)
{
    login_status=_loginstatus;
}

void user::print_offers()
{
    cout<<"productId | offerId | offerUnitPrice| offerAmount"<<endl;
    for(int i=0;i<offers.size();i++)
    {
        cout<<offers[i]->return_product_id()<<" | "<<offers[i]->return_offer_id()<<" | "<<offers[i]->return_price()<<" | "<<offers[i]->return_product_nums()<<endl;
    }
}
void user::change_amount(float _money)
{
    v_money.push_back(0);
    money+=_money;
    v_money.push_back(money);
    cout<<"OK"<<endl;
}
vector<offer*> user::return_offers(){ return offers; }
vector<float> user::return_v_money(){return v_money;}
void user::wallet_user( int num_count)
{
   if(num_count>v_money.size()) 
   {
       for(int i=0;i<v_money.size();i++)
       {
           cout<<v_money[i]<<endl;
       }
   }
   if(num_count<=v_money.size()) 
   {
       for(int i=num_count;i>0;i--)
       {
           cout<<v_money[i]<<endl;
       }

   }
}