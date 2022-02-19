#pragma once

#include "engine/tools/Tools.h"

#include "engine/tools/external/std/io.h"

class engine::ColorModifier final
{
public :

	static inline ColorModifier Red()
	{
		return ColorModifier(31);
	}

	static inline ColorModifier Green()
	{
		return ColorModifier(32);
	}

	static inline ColorModifier Yellow()
	{
		return ColorModifier(33);
	}

	static inline ColorModifier Blue()
	{
		return ColorModifier(34);
	}

	static inline ColorModifier Default()
	{
		return ColorModifier(39);
	}

	friend ostream &operator << (ostream &out, const ColorModifier &modifier)
	{
		return out << "\033[" << modifier._code << "m";
	}

private :

	const int _code;

	ColorModifier(int code) : _code(code)
	{}
};