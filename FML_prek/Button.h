#pragma once
#include "SFML/Graphics.hpp"
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
	// ������� ������ ������ ���� drawingMode == 0
	Sprite sprite;
	// ����� ������ ������ ���� drawingMode == 1
	Text text = "Hi, Grifka!";
	// ������ ����� ��� ������
	bool drawingMode = 1;
	//���������� �������� ������� ������� ���� ��������� ��� �����
	function<void(args...)> f;
	//���� ������ ������ ���� ������ ������, ���� �������
	Color buttonColorClick = Color(Grey);
	//���� ������ ���� �� ������
	Color buttonColorUnClick = Color(White);
	// ���� ������� ������
	Color borderColor = Color(Black);
	//������ �������
	float borderSize = 0;
	// ������ ��
	bool clicked = false;
	//������������� ������ ������� � ������
	Rect<float> rect{};
	
public:
	//��������� ����������
	// �������� ������
	void show() {
		showing = true;
	}
	// �������� ������
	void hide() {
		showing = false;
	}
	// �������� ������ ������
	void setSprite(sf::Sprite sprite1) {
		sprite = sprite1;
		sf::FloatRect rect1 = sprite1.getLocalBounds();
		float swidth = rect1.width;
		float sheight = rect1.height;
		sprite.setScale(rect.width / swidth, rect.height / sheight);
	}
	//�������� �����
	void setText(sf::Text text1) {
		text = text1;
	}
	// �������� ����� ��������� � ������
	void setDrawingMode(DrawingMode mode) {
		drawingMode = mode;
	}
	// �������� ������� ��� �������
	void setOnClick(std::function<void(args...)> function) {
		f = function;
	}
	//�������� ���� ��� �������
	void setButtonColorClick(Color c) {
		buttonColorClick = c;
	}
	//�������� ���� ��� �������
	void setButtonColorUnClick(Color c) {
		buttonColorClick = c;
	}
	//�������� ���� ������� ������
	void borderColor(Color c) {
		borderColor = c;
	}
	//�������� ������ �������
	void borderSize(Color c) {
		borderSize = c;
	}
	// ���������
	void release() {
		clicked = false;
	}
	// �������� ������ ������
	void setSizeButton(Vector2f sz) {
		Vector2f a = rect.getPosition;
		rect = { a, sz };
	}
	// �������� ������� ������ ������
	void setPositionButton(Vector2f pos) {
		Vector2f a = rect.getSize;
		rect = { pos, a };
	}
	// �������� ������� � ������ ������ (Vector2f)
	void setButton(Vector2f pos, Vector2f sz) {
		rec = {pos, sz}
	}
	// �������� ������� � ������ ������ (4 ���������)
	void setButton(float x, float y, float xs, float ys) {
		rec = { x, y, xs, yz };
	}
	//������� �������� �������������� ������
	// ��������� ��������� �� ����� � ������
	bool isin(sf::Vector2f pos) {
		return rect.contains(sf::Vector2i(pos));
	}
	//������ ��
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
	//�� �� ��� ���...
	// ������ ��� ������ ������
	void update(args... a) {
		if (clicked) {
			f(a...);
		}
	}
	// �������� ������
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

