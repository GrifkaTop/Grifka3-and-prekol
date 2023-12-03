#pragma once
#include <SFML/Graphics.hpp>
#include <functional>

using namespace sf;
using namespace std;

// ������ ��� f
template <typename ...args>
class Button
{
private:
	// ���������� ������
	bool showing = true;
	// ������ ��
	bool clicked = false;
	// ������� ������ ������ ���� drawingMode == 0
	Sprite sprite;
	// ����� ������ ������ ���� drawingMode == 1
	Text text;
	// ������ ����� ��� ������
	bool drawingMode = 0;

	//���������� �������� ������� ������� ���� ��������� ��� �����
	function<void(args...)> f;
	RectangleShape but;
	//������, �������
	Vector2f size, position;
	//���� ������ ������, ���� �������
	Color buttonColor, borderColor;
	//������ �������
	float borderSize = 0;

public:
	// ����������� ������
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

