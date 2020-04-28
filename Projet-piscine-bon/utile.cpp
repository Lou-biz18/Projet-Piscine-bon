#include <iostream>
#include <vector>
#include <sstream>

std::vector<std::string> split(const std::string &ligne, char delimiteur)
{
    std::vector<std::string> recup;
    std::stringstream ss(ligne);
    std::string temp;//chaine tampon
    while(getline(ss, temp, delimiteur))
    {
        recup.push_back(temp);
    }

    return recup;
}
