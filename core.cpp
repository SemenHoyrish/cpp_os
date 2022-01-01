#include <string>
#include <vector>
#include "core.hpp"
#include "utils.hpp"

void load_data(std::string filename, 
            std::map<
                std::string,
                std::string> &storage)
{
    std::vector<std::string> vect = read_file_to_vector(filename);

    for(int i = 0; i < vect.size(); ++i)
    {
        auto tmp = split(vect[i], "=");
        storage[tmp[0]] = tmp[1];
    }
}

void save_data(std::string filename, 
            std::map<
                std::string,
                std::string> &storage)
{
    std::vector<std::string> vect;

    for (const auto& kv : storage) {
        vect.push_back(kv.first + "=" + kv.second);
    }

    write_file(filename, vect);
}