#pragma once
//Class for greenhouse
class Greenhouse
{
public:
    int getTemp() {return Temperature; };
    int getHumidity() {return Humidity; };
private:
    float Humidity = 50;
    float Temperature  = 20;
};
