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
        int get_num_fruits() override { return num_cucumbers; };
        void harvestFruits() override;
        int get_days_without_water(){return days_without_water;};
        void set_days_without_water(){days_without_water++;};
        void reset_days_without_water(){days_without_water=0;};
        void kill(){alive = false;};
    private:
        int hight{0};
        float maxHight{200};
        int num_cucumbers{0};
        float growth_rate{4.0};
        int type = 2;
        int fruit_growth{1};
        int days_without_water;
        bool alive = true;
};
