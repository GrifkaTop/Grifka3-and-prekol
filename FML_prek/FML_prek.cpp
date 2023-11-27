#include <iostream>
#include <SFML/Graphics.hpp>
#include "windows.h"
#include <random>
#include <vector>
#include <cmath>
#include <iomanip>

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
void true_vilka_rand() {
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
        if (k <= 10) {
            f = 1;
        }
        if (k >= 1000) {
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
void true_star_rand() {
    int n = 1000;
    float Gosling = 10 * 2 * M_PI / 360.0;
    int k = 6;
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
        if (k >= 50) {
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
            Vector2f a = vc(p[i], p[(i + (k / 2)) % k]);
            if (k % 2 == 0) {
                a = vc(p[i], p[(i + ((k - 1) / 2)) % k]);
            }
            lines[i * 2].setSize(Vector2f(vc_size(a), fitness));
            lines[i * 2].rotate(atan2(a.y, a.x) / M_PI * 180);
            lines[i * 2].setPosition(p[i]);
            a = vc(p[i], p[(i + (k - (k / 2))) % k]);
            if (k % 2 == 0) {
                a = vc(p[i], p[(i + (k - ((k - 1) / 2))) % k]);
            }
            lines[i * 2 + 1].setSize(Vector2f(vc_size(a), fitness));
            lines[i * 2 + 1].rotate(atan2(a.y, a.x) / M_PI * 180);
            lines[i * 2 + 1].setPosition(p[i]);

        }
        for (auto i : lines) {
            window.draw(i);
        }
        window.display();
        Sleep(10);
    }
}
void true_spiral_rand() {
    int n = 1000;
    float Gosling = 0.1 * 2 * M_PI / 360.0;
    int k = 5;
    int r = 10;
    int fitness = 1;
    sf::RenderWindow window(sf::VideoMode(n, n), "SFML works!");
    int f = 1;
    int a_r = 1;
    int v_r = 0;
    vector<CircleShape> p;
    while (window.isOpen())
    {
        int a = 0;
        v_r += a_r;
        Gosling += 1;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        if (r + v_r <= n / 2)
            for (float i = 0; i < 2 * M_PI && a < k; i += 2 * M_PI / k) {
                float g = i + Gosling;
                float x = (r + v_r) * cos(g) + n / 2;
                float y = (r + v_r) * sin(g) + n / 2;
                CircleShape sh(1);
                sh.setPosition(x, y);
                p.push_back(sh);
                a++;
            }
        for (auto i : p) {
            window.draw(i);
        }
        window.display();
        Sleep(50);
    }
}
void PI_sfml(int lim_dot, int r) {
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
            window.display();
            Sleep(50);
        }
    }
    window.display();
    return;
}
// n - размер экрана, Gos- скорость поворота, r - радиус, max - точек, min - минимум точек
void true_vilka(int n, float Gos, int k, int r,  int max, int min)    {
    float Gosling = Gos * 2 * M_PI / 360.0;
    int fitness = 1;
    sf::RenderWindow window(sf::VideoMode(n, n), "SFML works!");
    int f = 1;
    while (window.isOpen())
    {
        Gosling += 1;
        if (k <= min) {
            f = 1;
        }
        if (k >=max) {
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
// n - размер экрана, Gos- скорость поворота, r - радиус, max - точек, min - минимум точек
void true_star(int n, float Gos, int k, int r,  int max, int min) {
    float Gosling = Gos * 2 * M_PI / 360.0;
    int fitness = 1;
    sf::RenderWindow window(sf::VideoMode(n, n), "SFML works!");
    int f = 1;
    while (window.isOpen())
    {
        Gosling += 1;
        
        if (k <= min) {
            f = 1;
        }
        if (k >= max) {
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
            if (k % 2  == 0) {
                a = vc(p[i], p[(i + ((k - 1) / 2)) % k]);
            }
            lines[i * 2].setSize(Vector2f(vc_size(a), fitness));
            lines[i * 2].rotate(atan2(a.y, a.x) / M_PI * 180);
            lines[i * 2].setPosition(p[i]);
            a = vc(p[i], p[(i + (k - (k / 2))) % k]);
            if (k % 2 == 0) {
                a = vc(p[i], p[(i + (k-((k - 1) / 2))) % k]);
            }
            lines[i * 2 + 1].setSize(Vector2f(vc_size(a), fitness));
            lines[i * 2 + 1].rotate(atan2(a.y, a.x) / M_PI * 180);
            lines[i * 2 + 1].setPosition(p[i]);

        }
        for (auto i : lines) {
            window.draw(i);
        }
        window.display();
        Sleep(10);
    }
}
// n - размер экрана, Gosling- скорость поворота, k - количество точек,r - радиус, a_r -ускорение поворота
void true_spiral(int n, int Gos, int k, int r, int a_r) {
    float Gosling = Gos * 2 * M_PI / 360.0;
    sf::RenderWindow window(sf::VideoMode(n, n), "SFML works!");
    int f = 1;
    int v_r = 0;
    vector<CircleShape> p;
    while (window.isOpen())
    {
        int a = 0;
        v_r += a_r;
        Gosling += 1;
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        if (r + v_r <=n/2)
        for (float i = 0; i < 2 * M_PI && a < k; i += 2 * M_PI / k) {
            float g = i + Gosling;
            float x = (r+v_r) * cos(g) + n / 2;
            float y = (r+v_r) * sin(g) + n / 2;
            CircleShape sh(1);
            sh.setPosition(x, y);
            p.push_back(sh);
            a++;
        }
        for (auto i : p) {
            window.draw(i);
        }
        window.display();
        Sleep(50);
    }
}
void doom() {
    // Обзор
    float fFOV = M_PI / 3; // Угол обзора (поле видимости)
    float fDepth = 30.0f;     // Максимальная дистанция обзора
    //Игрок
    float PlayerX = 1, PlayerY = 1, PlayerA = 0;
    //настрофка размера экрана
    int n_window = 100, m_window = 100;
    sf::RenderWindow window(sf::VideoMode(n_window, m_window), "DOOM");
    //карта
    vector<string> map = { "################",
                           "#..............#",
                           "#..............#",
                           "#..............#",
                           "#..............#",
                           "#..............#",
                           "#..............#",
                           "#..............#",
                           "#..............#",
                           "#..............#",
                           "#..............#",
                           "#..............#",
                           "#..............#",
                           "#..............#",
                           "#..............#",
                           "################" };
    int nMap = map.size();
    int mMap = map[0].size();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        sf::Vertex rectangle[] =
        {
            sf::Vertex({0, 0}, Color(0, 0 , 0)),
            sf::Vertex({0, 100}, Color(255, 255 , 255)),
            sf::Vertex({100, 0}, Color(0, 0 , 0)),
            sf::Vertex({100, 100}, Color(0, 0 , 0))
        };

        window.draw(rectangle, 4, sf::Quads);
    
        //window.draw(i);
        window.display();
        Sleep(50);
    }
}
int main()
{
    true_vilka_rand();
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
