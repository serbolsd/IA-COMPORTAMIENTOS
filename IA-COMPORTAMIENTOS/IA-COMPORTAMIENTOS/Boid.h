#pragma once
#include "vector2.h"
#include <vector>
#include <Graphics.hpp>
#include <Window.hpp>
class Boid
{
public:
	Boid();
	~Boid();
private:
	float m_weight;
	float m_speed;
	float m_maxSpeed;
	float m_acceleration;
	float m_ratio;
	vector2 m_position;
	vector2 m_direccion;
	
	void setPosition(const float& posX, const float& posy);
	sf::Texture texture;
	sf::Vector2u size;
	//seek data
	vector2 m_seekObjetivePos;
	float m_seekMangitude;
	//flee data
	vector2 m_fleeObjetPos;
	float m_fleeRatio;
	float m_fleeMangitude;
	//arrive data
	vector2 m_arrivePos;
	float m_arriveRatio;
	float m_arriveMangitude;
	//pursue Data
	vector2 m_objetivePos;
	vector2 m_objetiveDir;
	float m_pursueMangitude;
	float m_objetiveSpeed;
	//evade data
	vector2 m_predatorPos;
	vector2 m_predatorDir;
	float m_evadeMangitude;
	float m_predatorSpeed;
	//obstacle
	vector2 m_obstaclePos;
	float m_obstacleRatio;
	float m_obstacleMagnitud;
	//Wander
	//follow Path
	vector2 follow_pointA;
	vector2 follow_pointB;
	float follow_PathRatio;
	float follow_PointRatio;
	float follow_Magnitud;

	float m_acelartionTime = 0;
	int vec2ArrayCount = 0;
public:
	int follow_pathNum = 0;
	vector2 m_wamderPos;
	sf::Sprite m_sprite;
	bool b_inPoint;
	bool b_Seek=false;
	bool b_flee=false;
	bool b_arrive=false;
	bool b_pursue=false;
	bool b_evade = false;
	bool b_obstacle = false;
	bool b_wandeRam = false;
	bool b_wandeRamTime = false;
	bool b_wandeToPoint = false;
	bool b_followPath = false;
	void SetSeekPos(const vector2& objetivePos,const float & magnitud);
	void SetFleeData(const vector2& objetPos, const float & ratio, const float & magnitud);
	void SetArriveData(const vector2& arrivePos, const float & ratio, const float & magnitud);
	void SetPursueData(const vector2& objetivePos, const vector2& objetiveDir, const float & objetiveSpeed, const float & magnitud);
	void SetEvadeData(const vector2 & predatorPos, const vector2 & predatorDir, const float & predatorSpeed, const float & magnitud);
	void SetobstacleData(const vector2& objetPos, const float & ratio, const float & magnitud);
	void SetFollowPath(const vector2& pointA, const vector2& pointB,const float & pathRatio, const float & pointRatio, const float & magnitud);
	void setBoidRatio(const float &ratio) { m_ratio =ratio; };
	vector2 getBoidPosition() { return m_position; };
	vector2 getBoidDirection() { return m_direccion; };
	float getBoidRatio() { return m_ratio; };
	float getBoidSpeed() { return m_speed; };
public:
	void init(const float& weight = 1.0f, const float& speed = 2, const float& maxSpeed = 2, const float& acceleration = 1.0f, const float& posX = 0.0f, const float& posY = 0.0f);
	void destroy();
	void update();
	void render( sf::RenderWindow &window);
	static vector2 seek(const vector2& posI, const vector2 & posF, const float& magnitud);
	static vector2 flee(const vector2& posI,const vector2 & posF, const float & ratio, const float& magnitud);
	static vector2 arrive(const vector2& posI, const vector2 & posF, const float & magnitud, const float &ratio);
	static vector2 pursue(const vector2& posI, const vector2 & posF, const vector2 & dirOb, const float & timePredic, const float &vel, const float & magnitud);
	static vector2 evade(const vector2& posI, const vector2 & posF, const vector2 & dirOb, const float & timePredic, const float &vel, const float & magnitud);
	static vector2 obstacle(const vector2& posI, const vector2 & posF,const float & ratio, const float & magnitud);
	static vector2 wanderRam(const vector2& posI, const float & rangeX, const float & rangeY, const float & magnitud);
	static vector2 wanderRamwhitTime(const vector2& posI, vector2& posF, const float & rangeX, const float & rangeY, float & timeTrans,const float & timeToChange, const float & magnitud);
	static vector2 wanderToPoint(const vector2& posI, const vector2& posF, const float & ratio,const float& angle, const float & magnitud);
	static vector2 followPaht(const vector2& pointA, const vector2& pointB, const vector2& pos,const float & pathRatio, const float & pointRatio, const float & magnitud,bool&arrivepoint);
	static bool bf_arrive(const vector2& posI, const vector2 & posF, const float & ratio);
	void changeSeekPos(const std::vector<vector2>& vec);

	bool b_follow_arrive = false;
	float m_timeTrans=0;
	float m_wanderTime = 0;
};

