#include <tomato_plant.h>

void tomatoPlant::grow(int days, int fertilizer)
{
    age++;
    if (hight < 100) {
    hight = hight + age * growth_rate;
    }

    fruit_growth = fruit_growth +1;

    
        if (fruit_growth > 30)
        {
            num_tomatoes = (fruit_growth-30)/3;
            num_tomatoes > 5 ? num_tomatoes = 5: num_tomatoes = num_tomatoes;
        }
}
void tomatoPlant::harvestFruits()
{
    if (num_tomatoes > 0){
        fruit_growth = 31;
    }
}
void tomatoPlant::growthRate(int water)
{
    growth_rate = 2;
    if (water < 1)
    {
        growth_rate = 1;
    }

}
