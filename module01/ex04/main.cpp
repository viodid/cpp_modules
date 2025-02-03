#include <string>
#include <iostream>
#include <fstream>

std::string replace(const std::string& source, const std::string& s1, const std::string& s2)
{
	std::string result;
	std::size_t pos = 0;

	while (pos < source.length())
	{
		std::size_t found = source.find(s1, pos);
		if (found != std::string::npos)
		{
			result += source.substr(pos, found - pos) + s2;
			pos = found + s1.length();
		}
		else
		{
			result += source.substr(pos);
			break ;
		}
	}
	return result;
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout << "Format: " << argv[0] << " <filename> <str1> <str2>" << std::endl;
		return 1;
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	std::string content;
	std::string buffer;
	std::ifstream fin;
	fin.open(argv[1]);
	if (!fin.is_open())
	{
		std::cerr << "Error: could not open file '" << filename << "'" << std::endl;
		return (1);
	}
	while (getline(fin, buffer))
	{
		content += buffer + "\n";
	}
	fin.close();
	std::string replacedContent = replace(content, s1, s2);
	std::ofstream fout;
	fout.open((filename + ".replace").c_str());
	if (!fout.is_open())
	{
		std::cerr << "Error: could not create file '" << filename << ".replace'" << std::endl;
		return (1);
	}
	fout << replacedContent;
	fout.close();

	return (0);
}
