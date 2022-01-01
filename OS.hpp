#include <map>
#include <string>
#include <vector>
// #include "app.hpp"


struct file
{
	std::string name;
	std::string content;
};


struct folder
{
	std::string name;
	std::vector<folder> folders;
	std::vector<file> files;
};


class OS
{
public:
	// OS(std::map<std::string, std::string> &storage);
	OS();
	void start();
	// void add_app(app _app);
	
private:
	// std::map<std::string, std::string> storage;
	// std::map<std::string, std::string> storage;
	// std::vector<app> apps;

	folder root;

	void boot();
	void auth();
	void terminal();
	void ls(folder &folder);
	void cd(std::string folder_name);
	std::string get_string_path();
};