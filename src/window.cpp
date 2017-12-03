#include <SFML/Window.hpp>
#include <iostream>


void setBestFullScreenMode(sf::Window& window);
void setDefaultScreenMode(sf::Window& window, int width, int height);
void changeVideoMode(sf::Window& window);

int main()
{
    sf::Window window;
    int cont = 0;

    changeVideoMode(window);

    while (window.isOpen())  // ome iteration of the loop is called a tick or frame
    {
        sf::Event event; // information about an event
        while (window.pollEvent(event)) // iteration over all events
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                std::cout << event.mouseButton.x << ", " << event.mouseButton.y << std::endl;
                if (event.mouseButton.button == sf::Mouse::Left) 
                    std::cout << "Left button" << std::endl;
                else if (event.mouseButton.button == sf::Mouse::Right)
                    std::cout << "Right button" << std::endl;
            }
        }
        // draw here...
        window.display();
        window.setFramerateLimit(60);
        sf::sleep(sf::seconds(1.f/60.f));
    }
    return EXIT_SUCCESS;
}


void fullscreenModes()
{
    auto fullscreenModes = sf::VideoMode::getFullscreenModes();

    for (auto & videoMode : fullscreenModes) {
        std::cout << "Size: " << videoMode.width 
                    << " & " << videoMode.height
                    << " bpp: " << videoMode.bitsPerPixel
                    << std::endl;
    }
}

void desktopMode()
{
    auto desktopMode = sf::VideoMode::getDesktopMode();
    std::cout << desktopMode.width << std::endl;
    std::cout << desktopMode.height << std::endl;
    std::cout << desktopMode.bitsPerPixel << std::endl;
}

void changeVideoMode(sf::Window& window)
{
    sf::VideoMode videoMode;
    videoMode.width = 640;
    videoMode.height = 480;
    videoMode.bitsPerPixel = 32;
    window.create(videoMode, "Building games with SFML");
}  

void setBestFullScreenMode(sf::Window& window)
{
    int style = sf::Style::Fullscreen;
    window.create(sf::VideoMode::getFullscreenModes().front(), "Pac-Woman", style);
}

void setDefaultScreenMode(sf::Window& window, int width, int height)
{
    int style = sf::Style::Close 
                | sf::Style::Titlebar
                | sf::Style::Resize; 
    window.create(sf::VideoMode(width, height), "Pac-Woman");
}
