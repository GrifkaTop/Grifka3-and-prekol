#include <iostream>
#include <SFML/Graphics.hpp>
#include "windows.h"
#include <random>
#include <vector>
#include <cmath>
#include <iomanip>
#include "Source.cpp"
using namespace sf;
using namespace std;



/*
void ne_smeshno(int lim_dot, int r) {
    int n = 2 * r + 50;
    int k = 1000;
    float Gosling = 0.1 * 2 * M_PI / 360.0;
    RenderWindow window(sf::VideoMode(2 * r + 50, 2 * r + 50), "Choto IZI!");
    //Прямоугольник
    sf::RectangleShape rectangle(sf::Vector2f(2 * r, 2 * r));
    rectangle.setFillColor(sf::Color::Black);
    rectangle.setOutlineThickness(10.f);
    rectangle.setOutlineColor(sf::Color(250, 150, 100));
    rectangle.setPosition(10, 10);
    //Круг
    sf::CircleShape shape(r);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(10, 10);
    int circle_dot = 0, square_dot = 0;
    window.clear();
    sf::VertexArray array_point(Points, lim_dot);
    //window.draw(rectangle);
    //window.draw(shape);
    window.setFramerateLimit(60);
    for (int i = 0; i < lim_dot; i++) {
        double x = rand() % (r * 2), y = rand() % (r * 2);
        array_point[i].position = Vector2f(x, y);
        array_point[i].color = (sf::Color::Red);
        if (pow((x - r), 2) + pow((y - r), 2) <= pow(r, 2)) {
            array_point[i].color = (sf::Color::White);
            circle_dot++;
        }
        square_dot++;
        if (i % 100 == 0) {
            double a = (double(circle_dot) / double(square_dot)) * 4;
            std::cout << std::setprecision(10) << std::fixed;
            std::cout << i << ' ' << a << '\n';
            window.draw(array_point);
            vector<Vector2f> p(k);
            int a = 0;
            for (float i = 0; i < 2 * M_PI && a < k; i += 2 * M_PI / k) {
                float g = i + Gosling;
                float x = r * cos(g);
                float y = r * sin(g);
                p[a].x = x;
                p[a].y = y;
                a++;
            }
            vector<VertexArray> line(k);
            for (int i = 0; i < k; i++) {
                VertexArray l(LineStrip, 3);
                l[0] = Vector2f(n / 2, n / 2);
                l[1] = Vector2f(p[i].x + n / 2, p[i].y + n / 2);
                l[2] = Vector2f(-p[i].y + p[i].x + n / 2, p[i].y + p[i].x + n / 2);
                line[i] = l;
            }
            for (auto i : line) {
                window.draw(i);
            }
            window.display();
            Sleep(50);
        }
    }
    window.display();
    return;
}
*/
int main()
{
    PI_sfml(1e7,500);
    //circle_Black_White();
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
