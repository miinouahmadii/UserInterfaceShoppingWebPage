#ifndef MOBILE_H
#define MOBILE_H
#include "product.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class mobile:public product{
public:
    mobile(int keep_id,string keep_name,int keep_weight,float keep_CPU_frequency,int  keep_built_in_memory,int keep_RAM,int keep_display_size,int keep_camera_resolution,string keep_operating_system):product(keep_id,keep_name)
    {
        weight = keep_weight;
        CPU_frequency = keep_CPU_frequency ;
        built_in_memory = keep_built_in_memory;
        RAM = keep_RAM;
        display_size = keep_display_size;
        camera_resolution = keep_camera_resolution;
        operating_system = keep_operating_system;
    }
    int return_mobile_weight(){return weight;}
    float return_mobile_CPU_frequency(){return CPU_frequency;}
    int return_mobile_built_in_memory(){return built_in_memory;}
    int return_mobile_RAM(){return RAM;}
    int return_mobile_display_size(){return display_size;}
    int return_mobile_camera_resolution(){return camera_resolution;}
    string return_mobile_operating_system(){return  operating_system;}
private:
    int weight;
    float CPU_frequency;
    int built_in_memory;
    int RAM;
    int display_size; 
    int camera_resolution; 
    string operating_system;  
};




#endif 