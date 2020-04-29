#include <cucumber_plant.h>

void CucumberPlant::grow(int days, int fertilizer)
{
    if (fertilizer > 0)
    {
        if (hight < 200) 
        {
            hight = hight + days * growth_rate;
        }
    }

    fruit_growth = fruit_growth +1;
    if (fruit_growth > 40)
    {
        if (hight >= 200)
        {
            num_cucumbers = 5;
        }
        else if (hight > 160)
        {
            num_cucumbers = 4;
        }
        else if (hight > 120)
        {
            num_cucumbers =3;
        }
        else if (hight > 80)
        {
            num_cucumbers =2;
        }
        else if (hight > 40)
        {
            num_cucumbers =1;
        }
    }
    else
    {
        num_cucumbers = 0;
    }
    
}

void CucumberPlant::harvestFruits()
{
    fruit_growth = 0;
}

void CucumberPlant::growthRate(int water)
{   
    if (water < 1)
    {
        growth_rate = 1;
    }
    else
    {
        growth_rate = 4;
    }
    
}
