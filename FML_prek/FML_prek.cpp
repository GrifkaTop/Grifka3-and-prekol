#include <iostream>
#include <SFML/Graphics.hpp>
#include "windows.h"
#include <random>
#include <vector>


using namespace sf;
using namespace std;


void circle_random() {
    int r = 100;
    sf::RenderWindow window(sf::VideoMode(r * 2, r * 2), "SFML works!");
    sf::CircleShape shape(r);
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color(250, 150, 100));
    shape.setPosition(r, r);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int i = 1; i < r; i++) {
            shape.setRadius(i);
            shape.setPosition(r - i, r - i);
            shape.setOutlineColor(Color(rand() % 256, rand() % 256, rand() % 256));
            window.clear();
            window.draw(shape);
            window.display();
            //Sleep(5);
        }
        window.display();
    }
}
void circle_Black_White() {
    int r = 500;
    sf::RenderWindow window(sf::VideoMode(r * 2, r * 2), "SFML works!");
    sf::CircleShape shape(r);
    shape.setFillColor(sf::Color::Black);
    shape.setOutlineThickness(10.f);
    shape.setOutlineColor(sf::Color(250, 150, 100));
    shape.setPosition(r, r);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int i = 1; i < r; i++) {
            shape.setRadius(i);
            shape.setPosition(r - i, r - i);
            if (r % 2==0) {
                shape.setOutlineColor(Color::White);
            }
            else {
                shape.setOutlineColor(Color::Black);
            }
            window.clear();
            window.draw(shape);
            window.display();
            //Sleep(5);
        }
        window.display();
    }
}
int main()
{
    circle_Black_White();
    vect
    //circle_random();
    /*
    int r = 200, n = 3;
    sf::RenderWindow window(sf::VideoMode(r * 2, r * 2), "SFML works!");
    vector<CircleShape> vec_shape(n);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        for (int i = 0; i < n; i++) {
            vec_shape[i]
        }
        window.display();
    }
    return 0;
    */
}
