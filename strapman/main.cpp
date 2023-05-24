#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
	Game g("config.txt");
	g.run();
}





//int main()
//{
//    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
//    sf::CircleShape shape(50.f);
//    shape.setOrigin(sf::Vector2f(50.f, 50.f));
//    shape.setPosition(500.f, 500.f);
//    shape.setFillColor(sf::Color::Yellow);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//
//    return 0;
//}
