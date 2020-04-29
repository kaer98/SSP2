#include <water.h>

void water::refill()
{
    amount=100;
}
void water::useWater(int amountUsed)
{
    if (amount > 0)
    {
        amount = amount - amountUsed;
    }
    if (amount < 0)
    {
        amount = 0;
    }    

}