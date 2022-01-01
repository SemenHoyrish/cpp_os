#include <vector>
#include "utils.hpp"

#define DEBUG

using namespace std;


void print_vector(vector<string> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        color_write(v[i], Bright_Black);
    }
}
void print_vector(vector<int> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        color_write(to_string(v[i]), Bright_Black);
    }
}

void debug(string text)
{
    #ifdef DEBUG
    color_write("[DEBUG] " + text, Bright_Black);
    #endif
}