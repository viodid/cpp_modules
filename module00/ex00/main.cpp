#include <iostream>
#include <string>

static std::string	capitalize_str(std::string str);
static std::string	aggregate_args(int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	if (argc <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	const std::string str = aggregate_args(argc, argv);
	std::cout << capitalize_str(str) << '\n';
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

static std::string	capitalize_str(std::string str)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = static_cast<char>(str[i] - 32);
		i++;
	}
	return (str);
}
