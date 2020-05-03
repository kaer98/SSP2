#include <tomato_plant.h>
#include <stdlib.h>
void tomatoPlant::grow(int days, int fertilizer)
{
    if (height < 100) 
    {
        height = height + growth_rate;
    }
    //Will grow fruits if the plant is growing(or healthy)
    growth_rate > 0 ? fruit_growth ++ : fruit_growth --;  
    
        if (fruit_growth > 20)
        {
            //Grows one tomato(max 5) per 3 fruitgrowth more than 20
            num_tomatoes = (fruit_growth-20)/3;
            num_tomatoes > 5 ? num_tomatoes = 5: num_tomatoes = num_tomatoes;
        }
}

void tomatoPlant::harvest_fruits()
{
    //Checks if there are any tomatoes, as to not reset fruit growth if there arent
    //Otherwise set fruit growth to 33
    if (num_tomatoes > 0)
    {
        fruit_growth = 20;
    }
}

void tomatoPlant::growthRate(int water, int fertilizer)
{
    //Making a growthmodifer to make the plants grow at slightly pseudorandom paces. Will be between 80 and 120 and then divided by 10
    // Giving the growth_rate a multiplier between 0.8 and 1.2
    float growth_modifier = rand() % 120 + 80;
    growth_modifier = growth_modifier/100;
    //If there is no water then the growthrate will be negative, if there is then it will grow as normal
    water < 1 ? growth_rate = -0.5*growth_modifier : growth_rate = 3*growth_modifier;
    //If no fertilizer is left then fruitgrowth is pegged to 20. Below minimum requirement for growing fruits
    fertilizer < 1 ? fruit_growth = 20 : fruit_growth;
}