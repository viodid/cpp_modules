#include "Harl.hpp"

int display_usage_err(const std::string& program_name)
{
	std::cerr << "Usage: " << program_name << " <DEBUG, INFO, WARNING, ERROR>" << std::endl;
	return (1);
}

int hash_level(const std::string& level)
{
	if (level == "DEBUG")
		return 1;
	if (level == "INFO")
		return 2;
	if (level == "WARNING")
		return 3;
	if (level == "ERROR")
		return 4;
	return -1;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
		return display_usage_err(argv[0]);
	const std::string& level = static_cast<std::string>(argv[1]);
	if (level != "DEBUG"
		|| level != "INFO"
		|| level != "WARNING"
		|| level != "ERROR")
		return display_usage_err(argv[0]);

	Harl harl = Harl();
	switch (hash_level(level))
	{
	case 0:
		harl.complain("DEBUG");
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		break;
	case 1:
		harl.complain("INFO");
		harl.complain("WARNING");
		harl.complain("ERROR");
		break;
	case 2:
		harl.complain("WARNING");
		harl.complain("ERROR");
		break;
	case 3:
		harl.complain("ERROR");
		break;
	}
	return (0);
}
