#include <SFML/Graphics.hpp>
#include <iostream>

/*
- Drawing shapes
- Drawing images
- Drawing text
- Applying transformations
*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Building Games with SFML");

    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2<float>(200,100));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setOutlineThickness(2);
    rectangle.setOutlineColor(sf::Color::Red);

    sf::CircleShape circle;
    circle.setRadius(20);
    circle.setFillColor(sf::Color::Blue);
    circle.setOutlineThickness(4);
    circle.setOutlineColor(sf::Color::Yellow);

    sf::ConvexShape customShape;
    customShape.setPointCount(3);
    customShape.setPoint(0, sf::Vector2<float>(0, 0));
    customShape.setPoint(1, sf::Vector2<float>(150, 30));
    customShape.setPoint(2, sf::Vector2<float>(0, 60));
    customShape.setFillColor(sf::Color::Magenta);

    sf::Image image;
    // transparency https://goo.gl/r3eYuc
    image.loadFromFile("../assets/smiley.png");

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite(texture);
    sf::Sprite sprite2(texture);

    sf::Font font;
    // downloaded from dafont.com
    font.loadFromFile("../assets/font.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("Hello-SFML");
    //text.setColor(sf::Color::Red);
    text.setPosition(200, 150);
    text.setCharacterSize(62);

    sprite.setPosition(10,10);
    sprite.setScale(sf::Vector2<float>(.5,.5));

    sprite2.setPosition(300, 300);
    sprite2.setRotation(45);
    sprite2.setScale(.5f, .5f);

    rectangle.setPosition(10, 10);
    circle.setPosition(400, 50);
    customShape.setPosition(250, 250);


    while (window.isOpen())  // ome iteration of the loop is called a tick or frame
    {
        sf::Event event; // information about an event
        while (window.pollEvent(event)) // iteration over all events
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(rectangle);
        window.draw(circle);
        window.draw(customShape);
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(text);
        window.display();

        window.setFramerateLimit(60);
        sf::sleep(sf::seconds(1.f/60.f));
    }
    return EXIT_SUCCESS;
}
