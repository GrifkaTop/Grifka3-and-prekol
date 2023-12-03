#pragma once
#include "SFML/Graphics.hpp"
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
	// рисунок внутри кнопки если drawingMode == 0
	Sprite sprite;
	// текст внутри кнопки если drawingMode == 1
	Text text = "Hi, Grifka!";
	// рисуем текст или спрайт
	bool drawingMode = 1;
	//переменная хранящия функцию которую надо выполнить при клике
	function<void(args...)> f;
	//цвет внутри конпки если кнопка нажата, цвет обводки
	Color buttonColorClick = Color(Grey);
	//цвет кнопки если не нажата
	Color buttonColorUnClick = Color(White);
	// цвет контура кнопки
	Color borderColor = Color(Black);
	//размер обводки
	float borderSize = 0;
	// нажата ли
	bool clicked = false;
	//прямоугольник хранит позицию и размер
	Rect<float> rect{};
	
public:
	//изменение переменных
	// показать кнопку
	void show() {
		showing = true;
	}
	// спрятать кнопку
	void hide() {
		showing = false;
	}
	// изменить спрайт кнопки
	void setSprite(sf::Sprite sprite1) {
		sprite = sprite1;
		sf::FloatRect rect1 = sprite1.getLocalBounds();
		float swidth = rect1.width;
		float sheight = rect1.height;
		sprite.setScale(rect.width / swidth, rect.height / sheight);
	}
	//изменить текст
	void setText(sf::Text text1) {
		text = text1;
	}
	// изменить Режим рисования в кнопке
	void setDrawingMode(DrawingMode mode) {
		drawingMode = mode;
	}
	// изменить функцию при нажатии
	void setOnClick(std::function<void(args...)> function) {
		f = function;
	}
	//изменить цвет при нажатии
	void setButtonColorClick(Color c) {
		buttonColorClick = c;
	}
	//изменить цвет без нажатия
	void setButtonColorUnClick(Color c) {
		buttonColorClick = c;
	}
	//изменить цвет Обводки кнопки
	void borderColor(Color c) {
		borderColor = c;
	}
	//изменить размер обводки
	void borderSize(Color c) {
		borderSize = c;
	}
	// отпустить
	void release() {
		clicked = false;
	}
	// изменить размер кнопки
	void setSizeButton(Vector2f sz) {
		Vector2f a = rect.getPosition;
		rect = { a, sz };
	}
	// изменить позицию кнопки кнопки
	void setPositionButton(Vector2f pos) {
		Vector2f a = rect.getSize;
		rect = { pos, a };
	}
	// Изменить позицию и размер кнопки (Vector2f)
	void setButton(Vector2f pos, Vector2f sz) {
		rec = {pos, sz}
	}
	// Изменить позицию и размер кнопки (4 параметра)
	void setButton(float x, float y, float xs, float ys) {
		rec = { x, y, xs, yz };
	}
	//Функции проверки принадлежности кнопки
	// проверить находится ли точка в кнопке
	bool isin(sf::Vector2f pos) {
		return rect.contains(sf::Vector2i(pos));
	}
	//нажата ли
	bool click(sf::Vector2f pos) {
		if (!showing) {
			return false;
		}
		if (isin(sf::Vector2i(pos))) {
			clicked = true;
			return true;
		}
		return false;
	}
	//че то еще там...
	// каждый тик делает кнопка
	void update(args... a) {
		if (clicked) {
			f(a...);
		}
	}
	// рисовать кнопку
	void draw(sf::RenderWindow& window) {
		if (!showing) {
			return;
		}
		sf::RectangleShape r;
		sf::Color col = (clicked ? buttonColorClick : buttonColorUnClick);
		r.setFillColor(col);
		r.setPosition(rect.left, rect.top);
		r.setSize(sf::Vector2f(rect.width, rect.height));
		r.setOutlineThickness(3);
		r.setOutlineColor(sf::Color(100, 100, 100));
		window.draw(r);

		if (drawingMode == TEXT) {
			text.setPosition(r.getPosition());
			window.draw(text);
		}
		else if (drawingMode == SPRITE) {
			sprite.setPosition(r.getPosition());
			window.draw(sprite);
		}

	}
};

