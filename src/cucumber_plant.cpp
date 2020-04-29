#include <cucumber_plant.h>

void CucumberPlant::grow(int days, int fertilizer)
{
        if (hight < 200) 
        {
            hight = hight + days * growth_rate;
        }

    fruit_growth = fruit_growth +1;
    if (fruit_growth > 32)
    {
        num_cucumbers = (fruit_growth-32)/4;
        num_cucumbers > 5 ? num_cucumbers = 5: num_cucumbers = num_cucumbers;
    }
    
}

void CucumberPlant::harvestFruits()
{
    if (num_cucumbers > 0){
    fruit_growth = 33;
    }
    
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
