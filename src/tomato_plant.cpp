#include <tomato_plant.h>
#include <stdlib.h>
void tomatoPlant::grow(int days, int fertilizer)
{
    age++;
    if (hight < 100) 
    {
        hight = hight + age * growth_rate;
    }
    if (growth_rate > 0)
    {
        fruit_growth = fruit_growth +1; 
    }
        if (fruit_growth > 30)
        {
            num_tomatoes = (fruit_growth-30)/3;
            num_tomatoes > 5 ? num_tomatoes = 5: num_tomatoes = num_tomatoes;
        }
}

void tomatoPlant::harvestFruits()
{
    if (num_tomatoes > 0)
    {
        fruit_growth = 31;
    }
}

void tomatoPlant::growthRate(int water)
{
    float growth_modifier = rand() % 120 + 80;
    growth_modifier = growth_modifier/100;
    growth_rate = 2*growth_modifier;
    if (water < 1)
    {
        growth_rate = -0.5*growth_modifier;
    }
}
