#pragma once
//Defining class for fertilizer
class Fertilizer
{
public:
    int getAmount(int type) {return amount[type]; };
    void refill(int type);
    void useFertilizer(int amount_used, int type);
    
private:
    int amount[3] {600,600,600}; 
};
