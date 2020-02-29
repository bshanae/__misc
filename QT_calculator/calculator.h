#ifndef CALCULATOR_H
# define CALCULATOR_H

# include <string>
# include <sstream>
# include <iomanip>
# include <exception>

class				calculator
{
public:
					calculator();
					~calculator() = default;

	void			write_symbol(const char &symbol);
	void			write_action(const char &action);
	void			write_sign();

	const char		*read_line();

	void			clear();

private :

	bool			is_latent_string;
	std::string		*current_string;
	void			switch_string(std::string *ptr = nullptr);

	bool			is_minus;
	void			switch_sign(const bool &reset = false);

	std::string		left;
	std::string		right;
	std::string		action;

	void			evaluate();

	template		<typename type>
	static type		perform_action(const type &a, const type &b, const char &action)
	{
		switch (action)
		{
			case '+' :
				return (a + b);
			case '-' :
				return (a - b);
			case '*' :
				return (a * b);
			case '/' :
				return (a / b);
			default :
				throw ("Unknwon action");
		}
	}
};


#endif
