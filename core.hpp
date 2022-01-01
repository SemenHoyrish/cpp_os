#include <string>
#include <map>

void load_data(std::string filename, 
            std::map<
                std::string,
                std::string> &storage);

void save_data(std::string filename, 
            std::map<
                std::string,
                std::string> &storage);


