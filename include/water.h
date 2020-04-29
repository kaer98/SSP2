#pragma once

class water
{
public:
    int getAmount() {return amount; };
    void refill();
    void useWater(int amountUsed);
    
private:
    int amount{100*100}; //*100 added so pressing refill is not needed 
};