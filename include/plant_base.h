#pragma once

class plantBase
{
    public:
        virtual float getHight() = 0;
        virtual float getMaxHight() = 0;
        virtual int getType() = 0;
        virtual void grow(int days, int fertilizer) = 0;
        virtual void growthRate(int water) = 0;
        virtual int get_num_fruits() = 0;
        virtual void harvestFruits() = 0;
        
    private:
        int type;
        
};
