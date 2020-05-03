#pragma once
//Class for the plant base. This is the class that will be the foundation for the other plant classes
class plantBase
{
    public:
        virtual float getHeight() = 0;
        virtual float getMaxHeight() = 0;
        virtual int getType() = 0;
        virtual void grow(int days, int fertilizer) = 0;
        virtual void growthRate(int water, int fertilizer) = 0;
        virtual int get_num_fruits() = 0;
        virtual void harvest_fruits() = 0;
        
    private:
        int type;
        
};
