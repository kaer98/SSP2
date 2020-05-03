#include <water.h>
//Refill set to 600 units of water
void water::refill()
{
    amount=600;
}
void water::useWater(int amount_used)
{
    amount = amount - amount_used;
    //Just making sure that there will not be negative water
    amount < 0 ? amount = 0 : amount = amount;  
}
