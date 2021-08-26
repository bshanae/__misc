#pragma once

#include <vector>

namespace Engine
{
	class VectorTools;
}

class Engine::VectorTools
{
public :

	VectorTools() = delete;

	template <typename T>
	static std::vector<T> merge(const std::vector<T> &a, const std::vector<T> &b)
	{
		std::vector<T> ab;

		ab.reserve(a.size() + b.size());
		ab.insert(ab.end(), a.begin(), a.end());
		ab.insert(ab.end(), b.begin(), b.end());

		return ab;
	}

	template <typename T>
	static void pushBack(std::vector<T> &to, const std::vector<T> &from)
	{
		to.reserve(to.size() + from.size());
		to.insert(to.end(), from.begin(), from.end());
	}
};