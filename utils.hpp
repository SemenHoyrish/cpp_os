#include <string>
#include <vector>
#include <map>

void sleep_ms(int ms);
void sleep_s(int s);

// from min to max (all inclusive)
int get_random_int(int min, int max);

void write_line(std::string text);
void write(std::string text);

enum colors
{
    Black,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White,
    Bright_Black,
    Bright_Red,
    Bright_Green,
    Bright_Yellow,
    Bright_Blue,
    Bright_Magenta,
    Bright_Cyan,
    Bright_White
};
const std::map<colors, std::string> fg_colors = {
    {Black, "30"},
    {Red, "31"},
    {Green, "32"},
    {Yellow, "33"},
    {Blue, "34"},
    {Magenta, "35"},
    {Cyan, "36"},
    {White, "37"},
    {Bright_Black, "90"},
    {Bright_Red, "91"},
    {Bright_Green, "92"},
    {Bright_Yellow, "93"},
    {Bright_Blue, "94"},
    {Bright_Magenta, "95"},
    {Bright_Cyan, "96"},
    {Bright_White, "97"}
};
const std::map<colors, std::string> bg_colors = {
    {Black, "40"},
    {Red, "41"},
    {Green, "42"},
    {Yellow, "43"},
    {Blue, "44"},
    {Magenta, "45"},
    {Cyan, "46"},
    {White, "47"},
    {Bright_Black, "100"},
    {Bright_Red, "101"},
    {Bright_Green, "102"},
    {Bright_Yellow, "103"},
    {Bright_Blue, "104"},
    {Bright_Magenta, "105"},
    {Bright_Cyan, "106"},
    {Bright_White, "107"}
};
enum styles
{
    normal,
    bold,
    italic,
    dark
};
const std::map<styles, int> font_styles = {
    {normal, 0},
    {bold, 1},
    {dark, 2},
    {italic, 3}
};
void color_write(std::string text, colors fg, styles style=normal);
void color_write(std::string text, colors fg, colors bg, styles style=normal);

void clear();

void write_file(std::string filename, std::vector<std::string> lines);
void write_file(std::string filename, std::string text);

std::string read_file(std::string filename);
std::vector<std::string> read_file_to_vector(std::string filename);


std::vector<std::string> split (std::string s, std::string delimiter);

bool is_str_in_str(std::string haystack, std::string needle);