#include <cucumber_plant.h>
#include <stdlib.h>
//Grow function for our cucumber plant
void CucumberPlant::grow(int days, int fertilizer)
{ 
    //Checks if height is less than max height. If yes, then grow
    if (height < max_height) 
    {
        height = height + days * growth_rate;
    }
    //Will grow fruits if the plant is growing(or healthy)
    growth_rate > 0 ? fruit_growth ++ : fruit_growth --; 

    if (fruit_growth > 32)
    {
        //Grows one cucumber(max 5) per 4 fruitgrowth more than 32
        num_cucumbers = (fruit_growth-32)/4;
        num_cucumbers > 5 ? num_cucumbers = 5: num_cucumbers = num_cucumbers;
    }
}

void CucumberPlant::harvest_fruits()
{
    //Checks if there are any cucumbers, as to not reset fruit growth if there arent
    //Otherwise set fruit growth to 33
    if (num_cucumbers > 0)
    {
        fruit_growth = 33;
    }
}

void CucumberPlant::growthRate(int water, int fertilizer)
{   
    //Making a growthmodifer to make the plants grow at slightly pseudorandom paces. Will be between 80 and 120 and then divided by 10
    // Giving the growth_rate a multiplier between 0.8 and 1.2
    float growth_modifier = rand() % 120 + 80;
    growth_modifier = growth_modifier/100;
    //If there is no water then the growthrate will be negative, if there is then it will grow as normal
    water < 1 ? growth_rate = -0.5*growth_modifier : growth_rate = 4*growth_modifier;
    //If no fertilizer is left then fruitgrowth is pegged to 33. Below minimum requirement for growing fruits
    fertilizer < 1 ? fruit_growth = 33 : fruit_growth;
}
