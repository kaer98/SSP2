#include <tomato_plant.h>
#include <cucumber_plant.h>
#include <vector>
#include <iostream>
#include <thread>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include <water.h>
#include <Fertilizer.h>
#include <greenhouse.h>
using namespace std::chrono_literals;
sf::RenderWindow window(sf::VideoMode(800, 600), "Tomato Smiulator");
int  amount_cucumbers_harvested;
int  amount_tomatoes_harvested; 
void simulateOneDay(plantBase &a_plant, water &water, Fertilizer &fertilizer, int numPlants) 
{
    a_plant.grow(1, fertilizer.getAmount(a_plant.getType()));
    water.useWater(numPlants);
    fertilizer.useFertilizer(numPlants,a_plant.getType());
}

void growFruits(int position, std::vector<sf::CircleShape> &vector_fruits, plantBase &a_plant, int numPlants, sf::CircleShape fruit)
{
    for (size_t j = 1; j < numPlants+1; j++)
    {
        for (int i = 0; i < a_plant.getNumFruits()+1; i++)
        {                
            fruit.setPosition(position*j,600-i*a_plant.getMaxHight()/5);
            vector_fruits.push_back(fruit);              
        }
    }
}

void drawFruits(int position, int height){
        sf::RectangleShape fruit{sf::Vector2f(100,height)};
        fruit.setFillColor(sf::Color::Green);
        fruit.setPosition(300,300);  
        window.draw(fruit);
        
}
int countCucumbers(std::vector<CucumberPlant> &a_plant){
    int tot_num_of_fruits = 0;
    for (plantBase &p : a_plant ){
        tot_num_of_fruits = p.getNumFruits() + tot_num_of_fruits;
    }
    return tot_num_of_fruits;
        
}
int countTomatoes(std::vector<tomatoPlant> &a_plant){
    int tot_num_of_fruits = 0;
    for (plantBase &p : a_plant ){
        tot_num_of_fruits = p.getNumFruits() + tot_num_of_fruits;
    }
    return tot_num_of_fruits;
        
}

int main(int argc, char const *argv[])
{

    
    tomatoPlant my_tomato_plant;
    CucumberPlant my_cucumber_plant;
    water my_water_reservoir;
    Fertilizer my_fertilizer;
    Greenhouse my_greenhouse;
    int numCucumberPlants = 1;
    int numTomatoPlants = 1;
    int days = 0;
    float dayLength = 10;
    bool light = false;
    std::vector<tomatoPlant> list_of_tomatos;
    std::vector<CucumberPlant> list_of_cumcumbers;
    for (int i = 0; i < 10; i++){
        list_of_tomatos.push_back(my_tomato_plant);
        list_of_cumcumbers.push_back(my_cucumber_plant);
    }
    
   
    // create the window
    
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);
    sf::Clock deltaClock;
    auto start = std::chrono::high_resolution_clock::now();
    // run the program as long as the window is open
    while (window.isOpen())
    {
        
        //std::this_thread::sleep_for(0.5s); //uncomment to have a delay.
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = now-start;
        std::cout << elapsed.count() << std::endl;
        
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);

            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        
        if (elapsed.count() > dayLength)
        {
            days = days +1;
            start = std::chrono::high_resolution_clock::now();

            //simulate tomato plant
            for (int i = 0; i < numTomatoPlants; i ++){
                simulateOneDay(list_of_tomatos[i],my_water_reservoir,my_fertilizer,numTomatoPlants);
                list_of_tomatos[i].growthRate(my_water_reservoir.getAmount());
            }
            
            //simulateOneDay(list_of_tomatos[0],my_water_reservoir,my_fertilizer,numTomatoPlants);
            //simulate cucumber plant
            for (int i = 0; i < numCucumberPlants; i ++){
                simulateOneDay(list_of_cumcumbers[i],my_water_reservoir,my_fertilizer,numCucumberPlants);
                list_of_cumcumbers[i].growthRate(my_water_reservoir.getAmount());
            }
        }
        



        // create tomato plant visuals
        std::vector<sf::RectangleShape> vector_tomato_stalk;
        std::vector<sf::CircleShape> vector_tomatos;
        sf::CircleShape tomato(5);
        tomato.setFillColor(sf::Color{255,0,0});
        int space = 100;
        for (int i = 0; i < numTomatoPlants; i++)
        {
            sf::RectangleShape tomato_stalk;
            tomato_stalk.setFillColor(sf::Color::Green);
            tomato_stalk.setPosition(space*(i+1),600);
            tomato_stalk.setSize(sf::Vector2f{5.0, -list_of_tomatos[i].getHight()});
            vector_tomato_stalk.push_back(tomato_stalk);
            growFruits(tomato_stalk.getPosition().x, vector_tomatos, list_of_tomatos[i], 1, tomato);              
        }
        
        if (elapsed.count()<(dayLength/2))
        {
            light = true;
        }
        else
        {
            light = false;
        }
        //create light visual
        sf::CircleShape light_visual;
        light_visual.setFillColor(sf::Color::Yellow);
        light_visual.setPosition(300,300);
        light_visual.setRadius(50);

        
        //create cucumber plant visuals
        std::vector<sf::RectangleShape> vector_cucumber_stalk;
        std::vector<sf::CircleShape> vector_cucumbers;
        sf::CircleShape cucumbers(10);
        cucumbers.setFillColor(sf::Color::Yellow);
        
        space = 100;
        for (int i = 0; i < numCucumberPlants; i++)
        {
            sf::RectangleShape cucumber_stalk;
            cucumber_stalk.setFillColor(sf::Color::Green);
            cucumber_stalk.setPosition((space*(i+1))-40,600);
            cucumber_stalk.setSize(sf::Vector2f{10.0, -list_of_cumcumbers[i].getHight()});
            vector_cucumber_stalk.push_back(cucumber_stalk);
            growFruits(cucumber_stalk.getPosition().x,vector_cucumbers,list_of_cumcumbers[i],1,cucumbers);
        }

        
        //vand reservoir visuals
        sf::RectangleShape water_reservoir{sf::Vector2f(100,100)};
        water_reservoir.setFillColor(sf::Color::Blue);
        water_reservoir.setPosition(300,200);                  
        water_reservoir.setSize(sf::Vector2f(50, -my_water_reservoir.getAmount()/6));
        
        //fertilizer visuals
        std::vector<sf::RectangleShape> vector_fertilizer;
        for (size_t i = 1; i <= 2; i++)
        {
            sf::RectangleShape fertilizer_visuals;
            fertilizer_visuals.setFillColor(sf::Color{160,82,45});
            fertilizer_visuals.setPosition(300+(i*55),200);
            fertilizer_visuals.setSize(sf::Vector2f(50,-my_fertilizer.getAmount(i)/6));
            vector_fertilizer.push_back(fertilizer_visuals);
        }

        //UI
        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("water reservoir");
        ImGui::Text("Amount water left: %d", my_water_reservoir.getAmount());
        if(ImGui::Button("Refill"))
        {
            my_water_reservoir.refill();
        }
        ImGui::End();
        

        ImGui::Begin("Fertilizer");
        ImGui::Text("Amount Tomato Fertilizer left: %d", my_fertilizer.getAmount(1));
        if(ImGui::Button("Refill Tomato Fertilizer"))
        {
            my_fertilizer.refill(1);
        }
        ImGui::Text("Amount Tomato Fertilizer left: %d", my_fertilizer.getAmount(2));
        if(ImGui::Button("Refill Cucumber Fertilizer"))
        {
            my_fertilizer.refill(2);
        }
        ImGui::End();


                ImGui::Begin("Plants");
            ImGui::Text("Tomato plants: %d", numTomatoPlants);
            if(ImGui::Button("Add tomato plant") && numTomatoPlants < 7)
            {
                numTomatoPlants = numTomatoPlants + 1;
            }
            ImGui::Text("Cucumber plants: %d", numCucumberPlants);
            if(ImGui::Button("Add cucumber plant")&& numCucumberPlants < 7)
            {
                numCucumberPlants = numCucumberPlants + 1;
            }           
        ImGui::End();


        ImGui::Begin("Harvest");
            if (ImGui::Button("Harvest Tomatoes"))
            {
                amount_tomatoes_harvested += countTomatoes(list_of_tomatos);
                for (tomatoPlant &p : list_of_tomatos){
                    p.harvestFruits();
                }                  //lav en funktion til at høsete fugterne
            }
            ImGui::SameLine();
            ImGui::Text("Number of tomatoes: %d", countTomatoes(list_of_tomatos));
            ImGui::Text("Harvested tomatoes: %d", amount_tomatoes_harvested);
            if (ImGui::Button("Harvest Cucumbers"))
            {
                amount_cucumbers_harvested +=  countCucumbers(list_of_cumcumbers);
                for (CucumberPlant &p : list_of_cumcumbers){
                    p.harvestFruits();
                }               //lav en funktion til at høste frugterne
            }
            ImGui::SameLine();
            
            ImGui::Text("Number of Cucumbers: %d", countCucumbers(list_of_cumcumbers));
            ImGui::Text("Harvested cucumbers: %d", amount_cucumbers_harvested);
            if (ImGui::Button("Remove sideskud"))           // hvad heder sideskud på englesk??
            {
                /* code */
            }
        ImGui::End();

        ImGui::Begin("Time");
            ImGui::SliderFloat("Day Length", &dayLength, 1,15);
            ImGui::Text("Days Simulated: %d", days);
        ImGui::End();

        
        ImGui::Begin("Greenhouse");
            ImGui::Text("Humidety: %d", my_greenhouse.getHumidity());
            ImGui::SameLine();
            ImGui::Text("%%");
            ImGui::Text("Temperature: %d", my_greenhouse.getTemp());
            ImGui::SameLine();
            ImGui::Text("C");
        ImGui::End();
        


            
        

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw tomatoplant and tomatos
        for (std::vector<sf::RectangleShape>::iterator it = vector_tomato_stalk.begin() ; it != vector_tomato_stalk.end(); ++it)
        {
            window.draw(*it);
        }
        for (std::vector<sf::CircleShape>::iterator it = vector_tomatos.begin() ; it != vector_tomatos.end(); ++it)
        {
            window.draw(*it);
        }

        //draw cucumberplant and cucumbers
        for (std::vector<sf::RectangleShape>::iterator it = vector_cucumber_stalk.begin() ; it != vector_cucumber_stalk.end(); ++it)
        {
            window.draw(*it);
        }
        for (std::vector<sf::CircleShape>::iterator it = vector_cucumbers.begin() ; it != vector_cucumbers.end(); ++it)
        {
            window.draw(*it);
        }
        //draw water reservoir
        if(my_water_reservoir.getAmount()>0)
        {
            window.draw(water_reservoir);
        }
        //draw fertilizer
        for (std::vector<sf::RectangleShape>::iterator it = vector_fertilizer.begin() ; it != vector_fertilizer.end(); ++it)
        {
            window.draw(*it);
        }
        if (light == true)
        {
            window.draw(light_visual);
        }


        ImGui::SFML::Render(window);

        // end the current frame
        window.display();
    }

    return 0;
}


