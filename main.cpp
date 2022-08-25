#include <iostream>
#include"market.h"

using namespace std;

int main()
{
    market* Market=new market;
    Market->run();
    free (Market);
    return 0;
}