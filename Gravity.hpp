#ifndef GRAVITY_HPP
#define GRAVITY_HPP
#include <SFML/Graphics.hpp>
#endif // GRAVITY_HPP

class Programm{
public:
    Programm(){
        sf::VideoMode video({1000,1000});
        sf::RenderWindow window(video,"Gravity App");
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                    window.close();
            }

            window.clear();
            window.display();
        }
    }

    class RectShape:sf::RectangleShape{
        RectShape(sf::Vector2f size, float velocity_x, float velocity_y):velocity_x(velocity_x), velocity_y(velocity_y){
            sf::RectangleShape();
        }
    private:
        float velocity_x, velocity_y, velocity_z;
    };
};
