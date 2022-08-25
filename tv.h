#ifndef TV_H
#define TV_H
#include "product.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class tv:public product{
public:
    tv(int keep_id,string keep_name,int keep_screen_size,string keep_screen_type,string  keep_resolution,int keep_three_d,int keep_hdr):product(keep_id,keep_name)
    {
        screen_size= keep_screen_size;
        screen_type = keep_screen_type ;
        resolution = keep_resolution;
        three_d = keep_three_d;
        hdr =  keep_hdr;
    }
 
    int return_tv_screen_size(){return screen_size;}
    string return_tv_screen_type(){return screen_type;}
    string return_tv_resolution(){return resolution;}
    int return_tv_three_d(){return three_d;}
    int return_tv_hdr(){return hdr;}
private:
    int screen_size;
    string screen_type;
    string resolution;
    int three_d;
    int hdr; 
};




#endif 