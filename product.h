#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>
#include <vector>
#include <string>
#include "comment.h"
using namespace std;
class product{
    public:
    product(int keep_id,string keep_name)
    {
        id = keep_id;
        name = keep_name;
    }
    int return_product_id();
    string return_product_name();
    vector<comment*> return_comments();
    vector<string> return_buyers();
    void add_comment_pr(string cmnt, string user);
    void show_comment_pr();
    void add_buyer(string _buyer);
    private:
    string user;
    vector<string> buyers;
    vector<comment*> cmnts;
    int cmntId = 1;
    string name;
    int id;
};




#endif 