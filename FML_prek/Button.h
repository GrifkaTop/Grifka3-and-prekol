#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

using namespace sf;
using namespace std;

// прикол для f
template <typename ...args>
class Button
{
private:
	// показывать кнопку
	bool showing = true;
	// нажата ли
	bool clicked = false;
	// рисунок внутри кнопки если drawingMode == 0
	Sprite sprite;
	// текст внутри кнопки если drawingMode == 1
	Text text;
	// рисуем текст или спрайт
	bool drawingMode = 0;

	//переменная хранящия функцию которую надо выполнить при клике
	function<void(args...)> f;
	RectangleShape but;
	//размер, позиция
	Vector2f size, position;
	//цвет внутри конпки, цвет обводки
	Color buttonColor, borderColor;
	//размер обводки
	float borderSize = 0;

public:
	// конструктор класса
	Button(Vector2f buttonSize, Vector2f buttonPosition, Color bColor = Color::White, Color borColor = Color::Green, float borSize = 0) {
		setButton(buttonSize, buttonPosition, bColor, borColor, borSize);
	}
	void setButton(Vector2f buttonSize, Vector2f buttonPosition, Color bColor = Color::White, Color borColor = Color::Green, float borSize = 0) {
		size = buttonSize;
		position = buttonPosition;
		buttonColor = bColor;
		borderColor = borColor;
		borderSize = borSize;
	}
	
	void drawTo(sf::RenderWindow& window) {
		window.draw(button	);
	}
};

