#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "offer.h"
#include "car.h"
#include "tv.h"
#include "mobile.h"
#include "cart.h"
using namespace std;
class user{
public:
    user(int _user_id,string _email,string _username,string _password,string _type,int _loginstatus);
    string return_username();
    string return_password();
    string return_type();
    string return_email();
    int return_login_status();  
    void manage_login_status(int _loginstatus);
    int return_user_id();
    bool isOnline();
    void makeOnline();
    void makeOffline(); 
    void add_offer(int offer_id,int offer_nums,float offer_price);
    void print_offers();
    void print_products();
    vector<offer*>return_offers();
    void change_offer(int offer_id,float offer_price,int offer_nums);
    void add_discount_code_offer(int offer_id,float discount_percent,int discount_number);
    void change_amount(float _money);
    void wallet_user(int num_count);
    vector<float> return_v_money();
    void add_to_cart(int _offer_id,int _amount,int _productId,int _sellerId,string _productName,float _price,string _discount_code="")
    {
        cart* new_cart = new cart( _offer_id,_amount,_productId,_sellerId, _productName,_price, _discount_code);
        carts.push_back(new_cart);
    }
    void show_carts()
    {
        cout<<"productId | productName | offerId | sellerId | totalPriceConsideringDiscount | amount"<<endl;
        for(int i=carts.size()-1;i>=0;i--)
        {
            cout<<carts[i]->return_product_id()<<" | "<<carts[i]->return_product_name()<<" | "<<carts[i]->return_offer_id()<<" | "<<carts[i]->return_seller_id()<<" | "<<carts[i]->return_totalPriceConsideringDiscount()<<" | "<<carts[i]->return_amount()<<endl;
        }
    }
    void submitCart()
    {
        int num_of_product=0;
        float price_of_product=0;
        float need_money=0;
        for(int i=0; i<carts.size();i++)
        {
            need_money+= carts[i]->return_price()*carts[i]->return_amount();
        }
        if(need_money>money)
        {
            money=money-need_money;
            cout<<"OK"<<endl;
        }
        if(need_money<money)
        {
            cout<<"Bad Request"<<endl;
        }
    }
protected:
    string email;
    string username;
    string password;
    string type;
    int num_count;
    float money;
    bool online = true;
    int login_status;
    int user_id;
    vector<float>v_money;
    vector<car*>cars;
    vector<car*>tvs;
    vector<car*>mobiles;
    vector<offer*>offers;
    vector<cart*> carts;
};
#endif 