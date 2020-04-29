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
    int getNumFruits() override {return num_tomatoes; };
    void harvestFruits() override;
    
private:
    int hight{0};
    int age = 0;
    float maxHight{100};
    int num_tomatoes{0};
    float growth_rate{2.0};
    int type = 1;
    int fruit_growth{1};
};