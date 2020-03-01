#include "calculator.h"

//						PUBLIC

						calculator::calculator()
{
	clear();
}

void					calculator::write_symbol(const char &symbol)
{
	is_latent_string = false;
	if (current_string->size() > 11)
		return ;
	if (is_dot and symbol == '.')
		return ;
	else if (symbol == '.')
		is_dot = true;
	*current_string += symbol;
}

void					calculator::write_action(const char &action)
{
	is_latent_string = false;
	if (action == '=')
		evaluate();
	else if (action == '%')
		translate_to_percent();
	else
	{
		this->action = action;
		switch_string();
	}
}

void					calculator::write_sign()
{
	switch_sign();
}

void					calculator::clear()
{
	left = "";
	right = "";
	is_latent_string = true;
	is_dot = false;
	switch_string(&left);
	switch_sign(true);
}

const char				*calculator::read_line()
{
	if (is_latent_string and not is_minus)
		return ("0");
	else if (is_latent_string and is_minus)
		return ("-0");
	else
		return (current_string->c_str());
}

//						PRIVATE

void					calculator::switch_string(std::string *ptr)
{
	if (ptr)
	{
		current_string = ptr;
		return ;
	}
	if (*current_string == left)
		current_string = &right;
	else if (*current_string == right)
		evaluate();
	is_dot = false;
}

void					calculator::switch_sign(const bool &reset)
{
	if (reset)
	{
		is_minus = false;
		return ;
	}
	if (is_minus)
		current_string->erase(current_string->begin());
	else if (not is_minus)
		current_string->insert(0, "-");
	is_minus = not is_minus;
}

void					calculator::evaluate()
{
	float				value_left = calculator::string_to_float(left);
	float				value_right = calculator::string_to_float(right);
	float				result;

	if (*current_string == right)
		result = perform_action(value_left, value_right, action[0]);
	else
		result = value_left;

	left = calculator::float_to_string(result);
	right = "";
	switch_string(&left);
	is_dot = left.find('.') != std::string::npos;
}

void					calculator::translate_to_percent()
{
	if (is_latent_string)
		return ;

	float				value = calculator::string_to_float(*current_string);
	if (value > 1.f)
		*current_string = calculator::float_to_string(value / 100.f);
}

float					calculator::string_to_float(const std::string &string)
{
	try
	{
		return (std::stof(string));
	}
	catch (...)
	{
		return (0);
	}
}

std::string				calculator::float_to_string(const float &value)
{
	std::stringstream	stream;
	std::string			string;

	stream << std::fixed << std::setprecision(4) << value;
	string = stream.str();
	while (not string.empty())
		if (string.back() == '0')
			string.erase(string.size() - 1);
		else if (string.back() == '.')
		{
			string.erase(string.size() - 1);
			break ;
		}
		else
			break ;

	return (string);
}
