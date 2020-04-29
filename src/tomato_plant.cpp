#include <tomato_plant.h>

void tomatoPlant::grow(int days, int fertilizer)
{
    age = age +1;
    if (hight < 100) {
    hight = hight + age * growth_rate;
    }

    fruit_growth = fruit_growth +1;
    if (fruit_growth > 30)
    {
        if (hight >= 100)
        {
            num_tomatoes = 5;
        }
        else if (hight > 80)
        {
            num_tomatoes =4;
        }
            else if (hight > 60)
        {
            num_tomatoes =3;
        }
            else if (hight > 40)
        {
            num_tomatoes =2;
        }
            else if (hight > 20)
        {
            num_tomatoes =1;
        }
    }
    else
    {
        num_tomatoes = 0;
    }
    
}
void tomatoPlant::harvestFruits()
{
    fruit_growth = 0;
}

void tomatoPlant::growthRate(int water)
{
    if (water < 1)
    {
        growth_rate = 1;
    }
    else
    {
         growth_rate = 2;
    }
}