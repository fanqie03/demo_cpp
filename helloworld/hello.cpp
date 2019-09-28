#include <string>
#include <iostream>

int main()
{
    std::string fileName(__FILE__);
    std::cout << fileName.substr(0, fileName.find("."))<< std::endl;
    return 0;
}