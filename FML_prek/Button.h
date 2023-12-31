#pragma once
#include "SFML/Graphics.hpp"
#include <functional>

using namespace sf;
using namespace std;

// type DrawingMode
enum DrawingMode {
	NONE,
	SPRITE,
	TEXT,
	SHAPE
};


// figna dla zapominania funci
template <typename T>
class ButtonOnClickFunctionArgument {
private:
	T value;
public:
	ButtonOnClickFunctionArgument() = default;

	explicit ButtonOnClickFunctionArgument(T a) : value(a) {}

	T getValue() const {
		return value;
	}
};

template<typename T, typename R>
class OnClickFunction {
private:
	function<T(vector<ButtonOnClickFunctionArgument<R>>)> func;
public:
	OnClickFunction() = default;

	explicit OnClickFunction(function<T(vector<ButtonOnClickFunctionArgument<R>>)> f) {
		func = f;
	}

	T operator()(vector<ButtonOnClickFunctionArgument<R>> args) const {
		return func(args);
	}
};

// a prank for f
template <typename T, typename R>
class Button
{
private:
	// show the button
	bool showing = true;
	// Sprite inside the button if drawingMode == SPRITE
	Sprite sprite;
	// text inside the button if drawingMode == TEXT
	sf::Font font;
	sf::Text text;
	// draw text or sprite
	DrawingMode drawingMode= TEXT;
	// a variable that stores the function to be performed when clicked
	OnClickFunction<T, R> onClickFunction;
	// color inside the button if pressed
	Color buttonColorClick = Color(160, 160, 160);
	// color inside the button if not pressed
	Color buttonColorUnClick = Color::White;
	// color of the button outline(border)
	Color borderColor = Color::Black;
	// outline(border) size
	float borderSize = 3;
	// is it pressed
	bool clicked = false;
	// the rectangle stores the position and size
	Rect<float> rect{};
	
public:
	// Constructor (Position, Size, Function(setOnClick))
	explicit Button(Vector2f position, Vector2f size, OnClickFunction<T, R>& s) {
		setSizeButton(size);
		setPositionButton(position);
		setOnClick(s);
	}
	//changing variables
    // show the button
	void show() {
		showing = true;
	}
	// hide the button
	void hide()
	{
		showing = false;
	}
	// change the button sprite
	void setSprite(sf::Sprite sprite1) {
		sprite = sprite1;
		sf::FloatRect rect1 = sprite1.getLocalBounds();
		float swidth = rect1.width;
		float sheight = rect1.height;
		sprite.setScale(rect.width / swidth, rect.height / sheight);
	}
	// change text
	void setText(sf::Text text1) {
		text = text1;
	}
	// change the drawing mode in the button
	void setDrawingMode(DrawingMode mode) {
		drawingMode = mode;
	}
	// change the function when pressed
	void setOnClick(OnClickFunction<T, R>& s) {
		onClickFunction = s;
	}
	// change the color when pressed
	void setButtonColorClick(Color c) {
		buttonColorClick = c;
	}
	// change the color when UnPressed
	void setButtonColorUnClick(Color c) {
		buttonColorClick = c;
	}
	// change the color of Outline
	void setBorderColor(Color c) {
		borderColor = c;
	}
	// change the outline size
	void setBorderSize(float c) {
		borderSize = c;
	}
	// release
	void release() {
		clicked = false;
	}
	// resize the button
	void setSizeButton(Vector2f sz) {
		Vector2f a = rect.getPosition();
		rect = { a, sz };
	}
	// change the button position of the button
	void setPositionButton(Vector2f pos) {
		Vector2f a = rect.getSize();
		rect = { pos, a };
	}
	// Change the position and size of the button (Vector2f)
	void setButton(Vector2f pos, Vector2f sz) {
		rect = { pos, sz };
	}
	// Change the position and size of the button (4 parameters)
	void setButton(float x, float y, float xs, float ys) {
		rect = { x, y, xs, ys };
	}
	// Functions for checking the button's ownership
	// check whether the point is in the button
	bool isin(sf::Vector2f pos) {
		return rect.contains(sf::Vector2f(pos));
	}
	//is pressed
	bool click(sf::Vector2f pos) {
		if (!showing) {
			return false;
		}
		if (isin(sf::Vector2f(pos))) {
			clicked = true;
			return true;
		}
		return false;
	}
	// what else is there...
	// every tick is made by a button
	/*
	void update() {
		if (clicked) {
			f();
		}
	}
	*/
	// draw a button
	void draw(sf::RenderWindow& window) {
		if (!showing) {
			return;
		}
		sf::RectangleShape r;
		sf::Color col = (clicked ? buttonColorClick : buttonColorUnClick);
		r.setFillColor(col);
		r.setPosition(rect.left, rect.top);
		r.setSize(sf::Vector2f(rect.width, rect.height));
		r.setOutlineThickness(borderSize);
		r.setOutlineColor(borderColor);
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

	