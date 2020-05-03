#pragma once
#include <Plant_base.h>

//Defining class for cucumberplant using baseclass plant base
class CucumberPlant : public plantBase
{
    public:
        
        float getHeight() override {return height; };
        float getMaxHeight() override {return max_height; };
        int getType() override {return type; };
        void grow(int days, int fertilizer) override;
        void growthRate(int water, int fertilizer) override;
        int get_num_fruits() override { return num_cucumbers; };
        void harvest_fruits() override;
        int get_days_without_water(){return days_without_water;};
        void set_days_without_water(){days_without_water++;};
        void reset_days_without_water(){days_without_water=0;};
        void kill(){alive = false;};
    private:
        int height{0};
        float max_height{200};
        int num_cucumbers{0};
        float growth_rate{4.0};
        int type = 2;
        int fruit_growth{1};
        int days_without_water;
        bool alive = true;
};
