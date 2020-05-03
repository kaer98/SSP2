#include <Fertilizer.h>
//Refill set to 600 units of fertilizer
void Fertilizer::refill(int type)
{
    amount[type]=600;
}
void Fertilizer::useFertilizer(int amount_used, int type)
{
    amount[type] = amount[type] - amount_used;
    //Just making sure that there will not be negative Fertilizer
    amount[type] < 0 ? amount[type] = 0 : amount[type] = amount[type];   
}