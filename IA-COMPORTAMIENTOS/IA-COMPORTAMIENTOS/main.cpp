#include "vector2.h"
#include <Window.hpp>
#include <Graphics.hpp>
#include "Runner.h"
#include "Boid.h"
#include <chrono>
sf::RenderWindow g_window(sf::VideoMode(1920, 1080), "Boids");
std::vector<Boid> Boids;
std::vector<vector2> objetives;
vector2 mousePos;
void display();
void InitBoids();
void update();
void render();
int main()
{	
	g_window.setFramerateLimit(120);
	// run the program as long as the window is open
	InitBoids();
	while (g_window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (g_window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				g_window.close();
		}
		g_window.clear(sf::Color(100, 0, 255, 0));

		mousePos.x = event.mouseMove.x;
		mousePos.y = event.mouseMove.y;
		//run.m_sprite.setPosition(run.getPosition().x, run.getPosition().y);
		//run2.m_sprite.setPosition(run2.getPosition().x, run2.getPosition().y);
		//run3.m_sprite.setPosition(run3.getPosition().x, run3.getPosition().y);
		//
		//
		//run.runingTo(run3.getPosition());
		//run.scapeTo(run2);

		display();

		//g_window.display();
	}

	return 0;
}

void InitBoids()
{
	Boid boid1;
	boid1.init(1, 5, 5, 5, 1000, 550);
	objetives.push_back(vector2(1000, 550));
	Boids.push_back(boid1);
	Boid boid2;
	boid2.init(1, 8, 5, 5, 500, 100);
	objetives.push_back(vector2(500, 100));
	boid2.setBoidRatio(200);
	Boids.push_back(boid2);
	Boid boid3;
	boid3.init(.1, 0, 10, 2, 10, 500);
	boid3.b_Seek = true;
	boid3.SetSeekPos(boid2.getBoidPosition(), 10);
	boid3.m_sprite.setColor(sf::Color(255, 0, 0, 255));
	//boid3.b_flee = true;
	//boid3.SetFleeData(boid2.getBoidPosition(),boid2.getBoidRatio(), 200);
	Boids.push_back(boid3);
	Boid boid4;
	boid4.init(.2, 0, 10, 3, 10, 500);
	boid4.b_Seek = true;
	boid4.SetSeekPos(boid2.getBoidPosition(), 10);
	boid4.m_sprite.setColor(sf::Color(0, 255, 255, 255));
	Boids.push_back(boid4);
	Boid boid5;
	boid5.init(.2, 0, 2, 1, 0, 0);
	//boid5.b_wandeToPoint = true;
	//boid5.b_Seek = true;
	boid5.b_followPath = true;
	boid5.SetFollowPath(objetives[0], objetives[1], 20, 30, 10);
	boid5.m_sprite.setColor(sf::Color(255, 105, 200, 255));
	boid5.m_wamderPos = vector2(1000,1000);
	Boids.push_back(boid5);
}

void update()
{
	Boids[4].m_wamderPos = mousePos;
	//Boids[4].SetSeekPos(mousePos,10);
	for (int i = 0; i < Boids.size(); i++)
	{
		if (Boids[i].b_followPath&&Boids[i].b_follow_arrive)
		{
			if (Boids[i].follow_pathNum >=objetives.size()-1)
			{
				Boids[i].SetFollowPath(objetives[0], objetives[Boids[i].follow_pathNum], 20, 30,10);
				Boids[i].follow_pathNum = 0;
			}
			else
			{
				Boids[i].SetFollowPath(objetives[Boids[i].follow_pathNum], objetives[Boids[i].follow_pathNum +1], 20, 30, 10);
			}
			Boids[i].follow_pathNum++;
		}
	}
	for (int i = 0; i < Boids.size(); i++)
	{
		Boids[i].update();
		if (Boids[i].b_inPoint)
		{
			Boids[i].changeSeekPos(objetives);
		}
	}
}
void render()
{
	for (int i = 0; i < Boids.size(); i++)
	{
		Boids[i].render(g_window);
	}
}
void display()
{
	auto start = std::chrono::steady_clock::now();
	g_window.clear(sf::Color(100, 0, 255, 0));
	update();
	render();
	g_window.display();
	auto end = std::chrono::steady_clock::now();
	float timeTrans= std::chrono::duration_cast<std::chrono::milliseconds>  (end - start).count();
	for (int i = 0; i < Boids.size(); i++)
	{
		Boids[i].m_timeTrans += (timeTrans/1000);
		Boids[i].m_wanderTime += (timeTrans/1000);
	}
}