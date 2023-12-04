#include <iostream>
#include "Prekol.h"
#include "Button.h"


using namespace sf;
using namespace std;


// Func for Button
void stText(int a) {
}

int ff(vector<ButtonOnClickFunctionArgument<string>> args) {
    cout << 1;
    return 0;
}

int main()
{
    // Test Button
    sf::Font font;
    font.loadFromFile("MinecraftFont.ttf");
    Vector2f a = { 100, 100 }, b = { 200, 100 };
    OnClickFunction<int, string> func(ff);
    Button <int, string> but(a, b, func);
    Text text;
    text.setFont(font);
    text.setString("HI, GRIFKA");
    text.setFillColor(sf::Color::Red);
    but.setButtonColorUnClick(Color(100, 100, 100));
    but.setButtonColorClick(Color(200, 200, 200));
    but.setText(text);
    int n = 1000;
    sf::RenderWindow window(sf::VideoMode(n, n), "SFML works!");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f point = { (float)event.mouseButton.x, (float)event.mouseButton.y };
                    bool clicked = false;
                    if (but.click(point)) {
                        clicked = true;
                    }
                    if (clicked) {
                        continue;
                    }
                }
                window.clear();
                but.draw(window);
                window.display();
                Sleep(20);
            }
        }
    }
    /*

    // Test IKRAN
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "GRIFACKS 3", sf::Style::Fullscreen, settings);
    sf::View view;
    //view.setCenter
    view.setSize(sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height);
    vector <sf::RectangleShape> rects;
    for (int x = -100; x <= 100; ++x) {
        for (int y = -100; y <= 100; ++y) {
            sf::RectangleShape rect;
            rect.setPosition(5 * x, 5 * y);
            float br = (x + 100) / 200.f;
            rect.setFillColor(Color(x+100,y+100, x+100));
            rect.setSize(sf::Vector2f(5, 5));
            rects.push_back(rect);
        }
    }
    sf::Clock clock;
    clock.restart();
    float curtime = clock.getElapsedTime().asSeconds(), prevtime = curtime;
    while (window.isOpen())
    {
        curtime = clock.getElapsedTime().asSeconds();
        float tm = curtime - prevtime;
        tm *= 1000;
        prevtime = curtime;
        //cout << tm << "\n";
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
            else if (event.type == sf::Event::Resized) {
                view.setSize(sf::Vector2f(event.size.width, event.size.height));
            }
            else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Right) {
                    view.move(tm, 0);
                }
                if (event.key.code == sf::Keyboard::Left) {
                    view.move(-tm, 0);
                }
                if (event.key.code == sf::Keyboard::Up) {
                    view.move(0, -tm);
                }
                if (event.key.code == sf::Keyboard::Down) {
                    view.move(0, tm);
                }
            }
        }
        window.setView(view);
        window.clear();
        for (auto& i : rects) {
            window.draw(i);
        }
        window.display();
    }

    */
}
