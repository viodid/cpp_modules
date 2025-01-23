#include <iostream>
#include <string>
#include <cctype>

static std::string	capitalize_str(const std::string& str);
static std::string	aggregate_args(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	const std::string str = aggregate_args(argc, argv);
	capitalize_str(str);
	return (0);
}

static std::string	aggregate_args(const int argc, char *argv[])
{
	std::string output;

	int	i = 1;
	while (i < argc)
	{
		output += argv[i];
		i++;
	}
	return (output);
}

static std::string	capitalize_str(const std::string& str)
{
	int	i = 0;
	while (str[i])
	{
		std::cout << static_cast<char>(std::toupper(str[i]));
		i++;
	}
	std::cout << std::endl;
	return (str);
}
