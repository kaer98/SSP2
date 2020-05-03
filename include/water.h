#pragma once
//Class for water. Responsible for keeping tabs on the water amount left,and refills and usage of water.
class water
{
public:
    int getAmount() {return amount; };
    void refill();
    void useWater(int amount_used);
    
private:
    int amount{600}; //*100 added so pressing refill is not needed 
};
