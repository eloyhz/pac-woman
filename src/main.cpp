#include <SFML/Window.hpp>

int main()
{
    sf::Window window(sf::VideoMode(800, 600), "SFML window");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
        sf::sleep(sf::seconds(1.f/60.f));
    }
    return EXIT_SUCCESS;
}