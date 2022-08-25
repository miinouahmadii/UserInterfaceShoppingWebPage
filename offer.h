#ifndef OFFER_H
#define OFFER_H
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class offer{
    public:
    offer(int keep_product_id,int keep_product_numbers,float keep_price){
        product_id=keep_product_id;
        product_numbers=keep_product_numbers;
        price = keep_price;
    }
    float return_discount_code(){return discount_codes[0];}
    void set_discount(int d_amount,int d_nums);
    void set_offer_id(int of_id){offer_id = of_id;}
    int return_offer_id(){return offer_id;}
    int return_product_id(){return product_id;}
    int return_product_nums(){return product_numbers;}
    float return_price(){return price;}
    void change_price(float new_price){price=new_price;}
    void change_product_numbers(int new_product_numbers){product_numbers=new_product_numbers;}
    private:
    int offer_id;
    int product_id;
    int product_numbers;
    float price;
    int discount_amount;
    int discount_nums;
    vector<float> discount_codes;
};
#endif