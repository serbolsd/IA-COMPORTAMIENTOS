#include "Runner.h"





Runner::Runner(const float& weight, const float& speed , const float& maxSpeed , const float& acceleration , const float& posX, const float& posY)
{
	m_weight = weight;
	m_speed = speed;
	m_maxSpeed = maxSpeed;
	m_acceleration = acceleration;
	setPosition(posX, posY);
	if (!texture.loadFromFile("Resources\\image\\Corredor.png"))
	{
		// error...
	}
	m_sprite.setTexture(texture);
	size = texture.getSize();

	m_sprite.setOrigin(size.x / 2, size.y / 2);

}

Runner::~Runner()
{
}

void Runner::setPosition(const float& posX, const float& posy)
{
	m_position = vector2(posX, posy);
}

void Runner::runingTo(vector2 vec)
{
	Boid running;
	m_position+=running.seek(m_position, vec, 10)*m_speed;

}

void Runner::scapeTo(Runner & runer)
{
	Boid scape;
	m_position += scape.flee(m_position, runer.getPosition(), 200, 500)*m_speed;
}
