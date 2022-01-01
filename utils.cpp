#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <random>
#include <fstream>
#include <vector>

#include "utils.hpp"


void sleep_ms(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void sleep_s(int s)
{
    sleep_ms(s * 1000);
}

int get_random_int(int min, int max)
{
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
    std::uniform_int_distribution<int> uni(min,max); // guaranteed unbiased

    auto random_integer = uni(rng);

    return random_integer;
}

void write_line(std::string text)
{
    std::cout << text << std::endl;
}
void write(std::string text)
{
    std::cout << text;
}


void color_write(std::string text, colors fg, styles style)
{
// //normal fg
// printf("\x1B[31mTexting\033[0m\t\t");

// // italic fg bg
// printf("\033[3;47;35mTexting\033[0m\t\t");

// //normal fg bg
// printf("\033[2;47;35mTexting\033[0m\t\t");

// // bold fg bg
// printf("\033[1;47;35mTexting\033[0m\t\t");

    write_line("\033[" + std::to_string(font_styles.at(style)) + ";" + fg_colors.at(fg) + "m"+ text +"\033[0m");

}
void color_write(std::string text, colors fg, colors bg, styles style)
{
    write_line("\033[" + std::to_string(font_styles.at(style)) + ";" + fg_colors.at(fg) + ";" + bg_colors.at(bg) + "m"+ text +"\033[0m");
}

void clear()
{
    std::system("clear");
}

void write_file(std::string filename, std::string text)
{
    std::ofstream myfile(filename);
    if (myfile.is_open())
    {
        myfile << text;
        myfile.close();
    }
}

void write_file(std::string filename, std::vector<std::string> lines)
{
    std::ofstream myfile(filename);
    if (myfile.is_open())
    {
        for (auto &&line : lines)
        {
            myfile << line << "\n";
        }
        
        myfile.close();
    }
}


std::string read_file(std::string filename)
{
    std::string text;
    std::string line;
    std::ifstream myfile (filename);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            text += line;
        }
        myfile.close();
    }
    return text;
}
std::vector<std::string> read_file_to_vector(std::string filename)
{
    std::vector<std::string> lines;
    std::string line;
    std::ifstream myfile (filename);
    if (myfile.is_open())
    {
        while ( getline (myfile,line) )
        {
            lines.push_back(line);
        }
        myfile.close();
    }
    return lines;
}



std::vector<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}


bool is_str_in_str(const std::string haystack, std::string needle)
{
    if (haystack.find(needle) != std::string::npos)
        return true;
    return false;
}