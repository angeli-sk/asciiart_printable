#include <fstream>
#include <string.h>
#include <iostream>

int line_count(std::string file_name)
{
    std::ifstream file(file_name);
    std::string line;
    int i = 0;

    while (getline (file, line))
        i++;
    file.close(); 
    return (i);
}

int    ascii_checkor(char argv[])
{
    char escapeybois[] = {'\\', '\'', '\"'};
    std::string line;
    std::ifstream file(argv);
    int i = 0;
    std::ofstream outfile("ascii.txt");
    if(file.fail())
        return (-1);
    while(getline (file, line))
    {
        for (int j = 0; j < line.length(); j++)
        {
            for (int x = 0; x < strlen(escapeybois); x++)
            {
                if (line[j] == escapeybois[x])
                    outfile << '\\';
            }
            outfile << line[j];
        }
        if (!file.eof())   
            outfile << "\\n\\\n";
    }
    file.close();
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "No input loser." << std::endl;
        return(-1);
    }
    if (ascii_checkor(argv[1]) == -1)
    {
        return (-1);
    }
     
    return(0);
}