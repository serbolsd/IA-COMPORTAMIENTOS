#pragma once
#include <math.h>
#include <iostream>
class vector2
{
public:
	//vector2();
	explicit vector2(const float& _X = 0.0f, const float& _Y = 0.0f) :X(_X), Y(_Y) {};
	vector2(const vector2& vec);
	~vector2();
public:
	union
	{
		struct
		{
			float X, Y;
		};
		struct
		{
			float a, b;
		};
		struct
		{
			float x, y;
		};
		float Vector[2];
	};

	float dot(const vector2& vec);
	vector2 normalize();
	float magnitud();
	float squareMagnitud();
	vector2 cross(vector2 vec);
	/************************************************************************/
	/* Sobrecarga de operadores                                             */
	/************************************************************************/
public:
										/*!< Igualacion binaria */

	vector2 operator+	(const vector2& vec);								/*!< Suma entre el valor por eje */
	vector2 operator-	(const vector2& vec);								/*!< Resta entre el valor por eje */
	vector2 operator-	();															/*!< niega el valor por eje */
	vector2 operator*	(const float& val);										/*!< Multiplicacion de el valor de cada eje por un floatante */
	vector2 operator/	(const float& val);										/*!< Divicion de el valor de cada eje por un floatante */
	vector2& operator=(const vector2& vec);

	vector2 operator+=	(const vector2& vec);										/*!< Suma entre el valor por eje */
	vector2 operator-=	(const vector2& vec);										/*!< Resta entre el valor por eje */
	vector2 operator*=	(const float& val);												/*!< Multiplicacion de el valor de cada eje por un floatante */
	vector2 operator/=	(const float& val);												/*!< Multiplicacion de el valor de cada eje por un floatante */

	bool operator==			(const vector2& vec);								/*!< Comparacion afirmativa entre el valor por eje */
	bool operator!=			(const vector2& vec);								/*!< Comparacion negativa entre el valor por eje */

	float& operator[] (const unsigned int& index);										/*!< Retorna el flotante en el lugar correspondiente */

	
};


