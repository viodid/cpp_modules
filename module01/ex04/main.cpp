#include <string>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Format: " << argv[0] << " <filename> <str1> <str2>" << std::endl;
		return (1);
	}
	return (0);
}
