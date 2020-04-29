#pragma once

class Greenhouse
{
public:
    int getTemp() {return Temperature; };
    int getHumidity() {return Humidity; };
    void light(bool on_off);
private:
    float Humidity = 50;
    float Temperature  = 20;
};