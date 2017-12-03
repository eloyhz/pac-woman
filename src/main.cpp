#include <iostream>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

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

    return EXIT_SUCCESS;
}