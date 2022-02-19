#pragma once

#include "engine/tools/Tools.h"

class engine::Color
{
public :

	static Color black;
	static Color white;
	static Color red;
	static Color blue;
	static Color green;

	Color();
	Color(float r, float g, float b);
	Color(float r, float g, float b, float a);

	union
	{
		struct
		{
			float r;
			float g;
			float b;
			float a;
		};

		float channels[4];
	};
};

unsigned hash(const engine::Color &color);

#include "engine/tools/color/YamlCpp+Color.h"