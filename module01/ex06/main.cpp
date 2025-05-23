#include "Harl.hpp"

int display_usage_err(const std::string& program_name)
{
	std::cerr << "Usage: " << program_name << " <DEBUG, INFO, WARNING, ERROR>" << std::endl;
	return (1);
}

int match_level(const std::string& level)
{
	if (level == "DEBUG")
		return 0;
	if (level == "INFO")
		return 1;
	if (level == "WARNING")
		return 2;
	if (level == "ERROR")
		return 3;
	return -1;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
		return display_usage_err(argv[0]);
	const std::string& level = argv[1];
	if (level != "DEBUG"
		&& level != "INFO"
		&& level != "WARNING"
		&& level != "ERROR")
		return display_usage_err(argv[0]);

	Harl harl = Harl();
	switch (match_level(level))
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
    default:
		harl.complain("ERROR");
		break;
	}
	return (0);
}
