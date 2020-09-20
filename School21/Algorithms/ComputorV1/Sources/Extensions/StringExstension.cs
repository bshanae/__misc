using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;

public static class				StringExstension
{
	public static string		RemoveSpaces(this string value)
	{
		return value.Replace(" ", string.Empty);
	}

	public static List<Token>	Tokenize(this string value)
	{
		string[]				strings;

		strings = Regex.Split(value, @"([\*\/\+\-\^=\(\)])");
		return
			(
				from entry in strings
				where entry.Length > 0
				select Token.Parse(entry)
			)
			.ToList();
	}
}
