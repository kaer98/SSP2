#pragma once
#include <Plant_base.h>


class CucumberPlant : public plantBase
{
    public:
        
        float getHight() override {return hight; };
        float getMaxHight() override {return maxHight; };
        int getType() override {return type; };
        void grow(int days, int fertilizer) override;
        void growthRate(int water) override;
        int getNumFruits() override { return num_cucumbers; };
        void harvestFruits() override;

    private:
        int hight{0};
        float maxHight{200};
        int num_cucumbers{0};
        float growth_rate{4.0};
        int type = 2;
        int fruit_growth{1};
};