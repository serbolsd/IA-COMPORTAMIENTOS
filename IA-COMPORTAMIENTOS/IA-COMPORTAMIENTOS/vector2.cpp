#include "vector2.h"

//vector2::vector2()
//{
//
//}



vector2::vector2(const vector2 & vec)
{
	*this = vec;
}

vector2::~vector2()
{
}


vector2 vector2::operator+(const vector2 & vec)
{
	vector2 result;
	result.x=x += vec.x; result.y=y += vec.y;
	return *this;
}

vector2  vector2::operator-(const vector2 & vec)
{
	vector2 result;
	result.x=x -= vec.x; result.y=y -= vec.y;
	return result;
}

vector2 vector2::operator-()
{
	vector2 neative(-x,-y);
	return neative;
}

vector2 vector2::operator*(const float & val)
{
	vector2 result;
	result.x=x*val; result.y=y*val;
	return *this;
}

vector2 vector2::operator/(const float & val)
{
	vector2 result;
	result.x=x / val; result.y=y / val;
	return *this;
}

vector2 & vector2::operator=(const vector2 & vec)
{
	x = vec.x;
	y = vec.y;
	return *this;
	// TODO: insertar una instrucción return aquí
}



vector2 vector2::operator+=(const vector2 & vec)
{
	x += vec.x; y += vec.y;
	return *this;
}

vector2 vector2::operator-=(const vector2 & vec)
{
	x -= vec.x; y -= vec.y;
	return *this;
}

vector2 vector2::operator *=(const float & val)
{
	x *= val; y *= val;
	return *this;
}

vector2 vector2::operator/=(const float & val)
{
	x /= val; y /= val;
	return *this;
}



bool vector2::operator==(const vector2 & vec)
{
	if (x == vec.x&&y == vec.y)
	{
		return true;
	}
	return false;
}

bool vector2::operator!=(const vector2 & vec)
{
	if (x == vec.x&&y == vec.y)
	{
		return false;
	}
	return true;
}

float & vector2::operator[](const unsigned int & index)
{
	// TODO: insertar una instrucción return aquí
	if (index == 0)
	{
		return x;
	}
	if (index == 1)
	{
		return y;
	}
	float t = 0.0f;
	return t;
}

float vector2::dot(const vector2 & vec)
{
	return (x*vec.x+y*vec.y);
}

vector2 vector2::normalize()
{
	vector2 vec(0,0);
	if (magnitud()<=0)
	{
		return vec;
	}
	float inverseCarmak = 1 / magnitud();
	vec.x = X * inverseCarmak; vec.y = Y * inverseCarmak;
	//return vector2(x * inverseCarmak, y * inverseCarmak);
	return vec;
}

float vector2::magnitud()
{
	if (squareMagnitud()<=0)
	{
		return 0;
	}
	return std::sqrt(squareMagnitud());
}

float vector2::squareMagnitud()
{
	return (x*x+y*y);
}

vector2 vector2::cross(vector2 vec)
{
	return vector2((x*vec.y,-y*vec.x));
}


