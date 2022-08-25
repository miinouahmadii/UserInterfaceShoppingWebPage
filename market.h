#ifndef MARKET
#define MARKET
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include "handle_input.h"
#include <fstream>
#include <stdlib.h>
#include "car.h"
#include "comment.h"

using namespace std;

class market{
public:
vector<string> removeDupWord(string str);
map<string, string> seperate_input();
user* online_user();
bool does_exist(string user_name);
void signup();
void signup_command();
void post_commands();
void login_command();
void post_logout_command();
void post_logout();
bool check_exceptions();
void importProducts();
void add_cars(vector<string> name,vector<int> weight, vector<int> num_of_seats, vector<int> num_of_cylinders, vector<int> engine_capacity, vector<int> reverse_parking_sensors);
void offer_command();
void get_commands();
void myoffer_command();
void change_offer_command();
void add_tvs(vector<string> name,vector<int>screen_size, vector<string> screen_type, vector<string> resolution, vector<int>three_d, vector<int> hdr);
void add_mobiles(vector<string> name,vector<int> weight, vector<int>CPU_frequency, vector<int>built_in_memory, vector<int>RAM, vector<int>display_size,vector<int> &camera_resolution,vector<string>operating_system);
void generate_discount_code_command();
void get_products_command();
void print_product_detail();
void product_detail_command();
void run();
void post_comments();
void get_comments();
void post_comment_command();
void get_comment_command();
void add_comment(string _comment,int productId,string name);
void show_comment(string _comment,int productId,string name);
void get_compare_command();
void get_compare();
void post_amount();
void post_amount_command();
void get_offersOnProduct();
void get_offersOnProduct_command();
void get_wallet_command();
void get_wallet();
offer* find_offer_by_offerid(int offerid);
user* find_user_by_offerid(int offerid);
void post_addtocart();
void get_cart_command();
void get_cart();
void post_addtocart_command();
product* find_product_by_productid(int productid);
void post_submitcart();
void post_submitcart_command();


private:
    vector<string> line;
    map<string,string> info;
    string str;
    handle_input* HandleInput= new handle_input();
    vector<car*>cars;
    vector<tv*>tvs;
    vector<mobile*>mobiles;
};
#endif