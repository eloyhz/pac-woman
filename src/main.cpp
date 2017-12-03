#include <iostream>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <SFML/System/String.hpp>

int main()
{
    sf::Time time;
    sf::Clock clock;

    sf::Time time1 = sf::seconds(1.2);
    sf::Time time2 = sf::milliseconds(1200);
    sf::Time time3 = sf::microseconds(1000000);

    time = time1 + time2 - time3;

    auto timeInSeconds = time.asSeconds();
    auto timeInMilliSeconds = time.asMilliseconds();
    auto timeInMicroSeconds = time.asMicroseconds();

    std:: cout << timeInSeconds << std::endl;
    std:: cout << timeInMilliSeconds << std::endl;
    std:: cout << timeInMicroSeconds << std::endl;

    // Represent a 2d-position
    sf::Vector2<int> vector;

    vector.x = 4;
    vector.y = 2;

    vector += sf::Vector2<int>(3, 6); // vector addition
    std::cout << vector.x << ", " << vector.y << std::endl;

    vector *= -1;  // scalar multiplication
    std::cout << vector.x << ", " << vector.y << std::endl;
    
    // vector = direction + magnitude

    sf::Vector2i intVector;
    sf::Vector2u uintVector;
    sf::Vector2f floatVector;

    // a 3d-vector
    sf::Vector3<int> vector3;
    vector3.z = 8;

    sf::String string = L"Приве́т";

    return EXIT_SUCCESS;
}