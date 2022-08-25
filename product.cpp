#include "product.h"
vector<comment*> product::return_comments(){ return cmnts; }
vector<string> product::return_buyers(){return buyers;}
void product::add_buyer(string _buyer)
{
    buyers.push_back(_buyer);
}
int product::return_product_id(){return id;}
string product::return_product_name(){return name;}
void product::add_comment_pr(string cmnt, string user){
    comment *c = new comment(cmnt,user);
    cmnts.push_back(c);
}
void product::show_comment_pr()
{
for(int i=0;i<cmnts.size();i++)
cout<<cmnts[i]->return_user()<<" | "<< cmnts[i]->return_comment()<<endl;
}