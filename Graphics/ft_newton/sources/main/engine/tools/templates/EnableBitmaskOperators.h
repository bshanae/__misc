#pragma once

#include <type_traits>

template <typename T>
struct EnableBitmaskOperators
{
	static const bool enable = false;
};

template <typename T>
typename std::enable_if_t<EnableBitmaskOperators<T>::enable, T>
operator |(T left, T right)
{
	return static_cast<T>(static_cast<std::underlying_type_t<T>>(left) | static_cast<std::underlying_type_t<T>>(right));
}

template <typename T>
typename std::enable_if_t<EnableBitmaskOperators<T>::enable, T>
operator &(T left, T right)
{
	return static_cast<T>(static_cast<std::underlying_type_t<T>>(left) & static_cast<std::underlying_type_t<T>>(right));
}

template <typename T>
typename std::enable_if_t<EnableBitmaskOperators<T>::enable, T>
operator ^(T left, T right)
{
	return static_cast<T>(static_cast<std::underlying_type_t<T>>(left) ^ static_cast<std::underlying_type_t<T>>(right));
}

template <typename T>
typename std::enable_if_t<EnableBitmaskOperators<T>::enable, T>
operator ~(T left)
{
	return static_cast<T>(~static_cast<std::underlying_type_t<T>>(left));
}

template <typename T>
typename std::enable_if_t<EnableBitmaskOperators<T>::enable, T &>
operator |=(T &left, T right)
{
	left = static_cast<T>(static_cast<std::underlying_type_t<T>>(left) | static_cast<std::underlying_type_t<T>>(right));
	return left;
}

template <typename T>
typename std::enable_if_t<EnableBitmaskOperators<T>::enable, T &>
operator &=(T &left, T right)
{
	left = static_cast<T>(static_cast<std::underlying_type_t<T>>(left) & static_cast<std::underlying_type_t<T>>(right));
	return left;
}

template <typename T>
typename std::enable_if_t<EnableBitmaskOperators<T>::enable, T &>
operator ^=(T &left, T right)
{
	left = static_cast<T>(static_cast<std::underlying_type_t<T>>(left) ^ static_cast<std::underlying_type_t<T>>(right));
	return left;
}

template <typename T>
typename std::enable_if_t<EnableBitmaskOperators<T>::enable, bool>
operator ==(T left, std::underlying_type_t<T> right)
{
	return static_cast<std::underlying_type_t<T>>(left) == right;
}

template <typename T>
typename std::enable_if_t<EnableBitmaskOperators<T>::enable, bool>
operator !=(T left, std::underlying_type_t<T> right)
{
	return static_cast<std::underlying_type_t<T>>(left) != right;
}
