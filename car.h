#ifndef CAR_H
#define CAR_H
#include "product.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class car:public product{
public:
    car(int keep_id,string keep_name,int keep_weight,int keep_num_of_seats,int keep_num_of_cylinders,int keep_engine_capacity,int keep_reverse_parking_sensors):product(keep_id,keep_name)
    {
        weight = keep_weight;
        num_of_seats = keep_num_of_seats;
        num_of_cylinders = keep_num_of_cylinders;
        engine_capacity = keep_engine_capacity;
        reverse_parking_sensors = keep_reverse_parking_sensors;
    }
    int return_car_weight(){return  weight;}
    int return_car_num_of_seats(){return  num_of_seats;}
    int return_car_num_of_cylinders(){return  num_of_cylinders;}
    int return_car_engine_capacity(){return  engine_capacity;}
    int return_car_reverse_parking_sensorst(){return  reverse_parking_sensors;}
private:
    int weight;
    int num_of_seats;
    int num_of_cylinders;
    int engine_capacity;
    int reverse_parking_sensors; 

};




#endif 