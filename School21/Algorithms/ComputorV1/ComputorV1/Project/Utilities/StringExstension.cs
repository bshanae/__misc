using System.Collections.Generic;
using System.Text.RegularExpressions;

public static class				StringExstension
{
	public static string		RemoveSpaces(this string value)
	{
		return value.Replace(" ", string.Empty);
	}

	public static List<Token>	Tokenize(this string value)
	{
		string[]				strings = null;
		List<Token>				tokens = new List<Token>();

		strings = Regex.Split(value, @"([\*\/\+\-\^\=])");
		foreach (var entry in strings)
			tokens.Add(TokenParser.Parse(entry));
		return tokens;
	}	
}
