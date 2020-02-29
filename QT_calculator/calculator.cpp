#include "calculator.h"

//						PUBLIC

						calculator::calculator()
{
	clear();
}

void					calculator::write_symbol(const char &symbol)
{
	is_latent_string = false;
	*current_string += symbol;
}

void					calculator::write_action(const char &action)
{
	is_latent_string = false;
	if (action == '=')
		evaluate();
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
	float				value_left = std::stof(left);
	float				value_right = right.empty() ? 0 : std::stof(right);
	float				result;
	std::stringstream	stream;
	std::string			string;

	if (*current_string == right)
		result = perform_action(value_left, value_right, action[0]);
	else
		result = value_left;

	stream << std::fixed << std::setprecision(4) << result;
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

	left = string;
	right = "";
	switch_string(&left);
}
