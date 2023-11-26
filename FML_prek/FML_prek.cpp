#include <iostream>
#include <SFML/Graphics.hpp>
#include "windows.h"
#include <random>
#include <vector>
#include <cmath>


using namespace sf;
using namespace std;


const double M_PI = acos(-1);
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

Vector2f vc(Vector2f b, Vector2f a) {
    return Vector2f(a.x - b.x, a.y - b.y);
}
Vector2f vcSMEX(Vector2f a, Vector2f b) {
    return Vector2f(a.x - b.x, a.y - b.y);
}
float vc_size(Vector2f a) {
    return sqrt(a.x * a.x + a.y * a.y);
}
void true_vilka()    {
    int n = 1000;
    float Gosling = 10 * 2 * M_PI / 360.0;
    int k = 5;
    int r = 100;
    int fitness = 1;
    sf::RenderWindow window(sf::VideoMode(n, n), "SFML works!");
    int f = 1;
    while (window.isOpen())
    {
        Gosling += 1;
        if (k <= 3) {
            f = 1;
        }
        if (k >= 100) {
            f = 0;
        }
        if (f == 1) {
            k++;
        }
        if (f == 0) {
            k--;
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        vector<Vector2f> p(k);
        int a = 0;
        for (float i = 0; i < 2 * M_PI && a < k; i += 2 * M_PI / k) {
            float g = i + Gosling;
            float x = r * cos(g) + n / 2;
            float y = r * sin(g) + n / 2;
            p[a].x = x;
            p[a].y = y;
            a++;
        }
        vector<RectangleShape> lines(k * 2);
        for (int i = 0; i < k; i++) {
            Vector2f a = vcSMEX(p[i], p[(i + (k / 2)) % k]);
            lines[i * 2].setSize(Vector2f(vc_size(a), fitness));
            lines[i * 2].rotate(atan2(a.y, a.x) / M_PI * 180);
            lines[i * 2].setPosition(p[i]);
            a = vcSMEX(p[i], p[(i + (k - (k / 2))) % k]);
            lines[i * 2 + 1].setSize(Vector2f(vc_size(a), fitness));
            lines[i * 2 + 1].rotate(atan2(a.y, a.x) / M_PI * 180);
            lines[i * 2 + 1].setPosition(p[i]);

        }
        for (auto i : lines) {
            window.draw(i);
        }
        window.display();
        Sleep(5);
    }
}
void true_star() {
    int n = 1000;
    float Gosling = 10 * 2 * M_PI / 360.0;
    int k = 5;
    int r = 350;
    int fitness = 1;
    sf::RenderWindow window(sf::VideoMode(n, n), "SFML works!");
    int f = 1;
    while (window.isOpen())
    {
        Gosling += 1;
        if (k <= 3) {
            f = 1;
        }
        if (k >= 100) {
            f = 0;
        }
        if (f == 1){
            k++;
        }
        if (f == 0) {
            k--;
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        vector<Vector2f> p(k);
        int a = 0;
        for (float i = 0; i < 2 * M_PI && a < k; i += 2 * M_PI / k) {
            float g = i + Gosling;
            float x = r * cos(g) + n / 2;
            float y = r * sin(g) + n / 2;
            p[a].x = x;
            p[a].y = y;
            a++;
        }
        vector<RectangleShape> lines(k * 2);
        for (int i = 0; i < k; i++) {
            Vector2f a = vc(p[i], p[(i + (k / 2)) % k]);
            lines[i * 2].setSize(Vector2f(vc_size(a), fitness));
            lines[i * 2].rotate(atan2(a.y, a.x) / M_PI * 180);
            lines[i * 2].setPosition(p[i]);
            a = vc(p[i], p[(i + (k - (k / 2))) % k]);
            lines[i * 2 + 1].setSize(Vector2f(vc_size(a), fitness));
            lines[i * 2 + 1].rotate(atan2(a.y, a.x) / M_PI * 180);
            lines[i * 2 + 1].setPosition(p[i]);

        }
        for (auto i : lines) {
            window.draw(i);
        }
        window.display();
        Sleep(5);
    }
}
int main()
{
    true_vilka();
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
