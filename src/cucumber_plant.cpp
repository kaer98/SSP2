#include <cucumber_plant.h>
#include <stdlib.h>
void CucumberPlant::grow(int days, int fertilizer)
{
    if (hight < 200) 
    {
        hight = hight + days * growth_rate;
    }
    if (growth_rate > 0)
    {
        fruit_growth = fruit_growth +1;
    }
    if (fruit_growth > 32)
    {
        num_cucumbers = (fruit_growth-32)/4;
        num_cucumbers > 5 ? num_cucumbers = 5: num_cucumbers = num_cucumbers;
    }
}

void CucumberPlant::harvestFruits()
{
    if (num_cucumbers > 0)
    {
        fruit_growth = 33;
    }
}

void CucumberPlant::growthRate(int water)
{   
    float growth_modifier = rand() % 120 + 80;
    growth_modifier = growth_modifier/100;
    growth_rate = 4*growth_modifier;
    if (water < 1)
    {
        growth_rate = -0.5*growth_modifier;
    }    
}
