#include <Fertilizer.h>

void Fertilizer::refill(int type)
{
    amount[type]=600;
}
void Fertilizer::useFertilizer(int amountUsed, int type)
{
    if (amount[type] > 0)
    {
        amount[type] = amount[type] - amountUsed;
    }
    if (amount[type] < 0)
    {
        amount[type] = 0;
    }
}
