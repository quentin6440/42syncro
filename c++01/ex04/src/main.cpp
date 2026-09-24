#include "../include/replace.h"

#include <fstream>
#include <iostream>
#include <string>

std::string replaceInLine(const std::string &line, const std::string &s1, const std::string &s2)
{
    std::string result;
    std::size_t pos = 0;
    std::size_t last = 0;

    while ((pos = line.find(s1, last)) != std::string::npos)
    {
        result += line.substr(last, pos - last);
        result += s2;
        last = pos + s1.length();
    }
    result += line.substr(last);

    return result;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "Usage: ./replace <filename> <s1> <s2>\n";
        return 1;
    }

    if ((std::string(argv[2])).empty())
    {
        std::cout << "Error: s1 cannot be empty\n";
        return 1;
    }
    
    std::ifstream ifs(argv[1]);
	if (!ifs.is_open())
	{
		std::cout   << "Error: cannot open file \"" 
                    << argv[1] << "\"\n";
		return 1;
	}

    std::ofstream ofs((std::string(argv[1]) + ".replace").c_str());
    if (!ofs.is_open())
    {
        std::cout << "Error: cannot create output file\n";
        ifs.close();
        return 1;
    }

    std::string line;

    while (std::getline(ifs, line))
    {
        std::string replacedLine = replaceInLine(line, argv[2], argv[3]);
        ofs << replacedLine << '\n';
    }

    ifs.close();
    ofs.close();

    return 0;
}