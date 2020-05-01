#pragma once

class Fertilizer
{
public:
    int getAmount(int type) {return amount[type]; };
    void refill(int type);
    void useFertilizer(int amountUsed, int type);
    
private:
    int amount[3] {600,600,600}; //*100 added so pressing refill is not needed 
};
