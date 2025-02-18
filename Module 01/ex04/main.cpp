#include <iostream>
#include <fstream>

std::string ft_replace(std::string oldStr, std::string newStr, std::string line)
{
    size_t pos = 0;
    while (true)
    {
        pos = line.find(oldStr, pos);
        if (pos == std::string::npos)
            break ;
        line.erase(pos, oldStr.length());
        line.insert(pos, newStr);
        pos += newStr.length();
    }
    return line; 
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        std::cout << "Wrong number of arguments!\n";
        return (1);
    }
    
    std::fstream infile;
    std::fstream outfile;
    std::string  outfileName = argv[1];

    infile.open(argv[1], std::ios::in);
    if (!infile.is_open()) {
        std::cout << "Error opening infile\n";
        return (1);
    }

    outfile.open(outfileName.append(".replace"), std::ios::out | std::ios::trunc);
    if (!outfile.is_open()) {
        infile.close();
        std::cout << "Error opening outfile\n";
        return (1);
    }

    std::string  line;
    while (getline(infile, line)) {
        std::string newLine = ft_replace(argv[2], argv[3], line);
        newLine += "\n";
        outfile << newLine;
    }
    infile.close();
    outfile.close();
    return 0;
}
