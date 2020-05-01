#pragma once
#include <Plant_base.h>

class tomatoPlant : public plantBase
{
public:
    float getHight() override {return hight; };
    //Test
    float getAge() {return age; };
    float getMaxHight() override {return maxHight; };
    int getType() override {return type; };
    void grow(int days, int fertilizer) override;
    void growthRate(int water) override;
    int get_num_fruits() override {return num_tomatoes; };
    void harvestFruits() override;
    int get_days_without_water(){return days_without_water;};
    void set_days_without_water(){days_without_water++;};
    void reset_days_without_water(){days_without_water=0;};
    void kill(){alive = false;};
private:
    int days_without_water;
    int hight{0};
    int age = 0;
    float maxHight{100};
    int num_tomatoes{0};
    float growth_rate{2.0};
    int type = 1;
    int fruit_growth{1};
    bool alive = true;
};
