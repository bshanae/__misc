using System.Linq;
using System.Text.RegularExpressions;

public static class			StringExstension
{
	public static string	RemoveSpaces(this string value)
	{
		return value.Replace(" ", string.Empty);
	}

	public static Token[]	Tokenize(this string value)
	{
		string[]			strings = Regex.Split(value, @"([\*\\\+\-\^\=])");
		Token[]				tokens = strings.Select(x => TokenParser.Parse(x)).ToArray();

		return tokens;
	}	
}
