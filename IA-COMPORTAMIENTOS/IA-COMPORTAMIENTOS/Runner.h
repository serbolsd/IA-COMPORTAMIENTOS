#pragma once
#include "vector2.h"
#include "Boid.h"
#include <Graphics.hpp>
class Runner
{
public:
	//Runner();
	explicit Runner(const float& weight = 1.0f, const float& speed = 2, const float& maxSpeed = 2, const float& acceleration = 1.0f, const float& posX = 0.0f, const float& posY = 0.0f);
	~Runner();
private:
	float m_weight;
	float m_speed;
	float m_maxSpeed;
	float m_acceleration;
	vector2 m_position;
	void setPosition(const float& posX, const float& posy);
	sf::Texture texture;
	sf::Vector2u size;
public:
	void runingTo(vector2 vec);
	void scapeTo(Runner & runer);
	int getSpeed; 
	sf::Sprite m_sprite;
	vector2 getPosition() { return m_position; };
	float getRatio() { return size.x / 2; };

};

