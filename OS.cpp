#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include "OS.hpp"
#include "utils.hpp"
#include "core.hpp"
#include "global.hpp"
#include "debug.hpp"
// #include "apps/ls.hpp"

#define DEBUG


// std::vector<app> apps;
folder root = *new folder();
folder &current_folder = root;

std::stack<folder> path;

OS::OS()
{
	// std::cout << "TEST" << std::endl;
	// apps.push_back(*new ls());

	folder &r = *new folder();
	r.name = "ROOT";
	folder fl = *new folder();
	fl.name = "test";
	r.folders.push_back(fl);
	fl = *new folder();
	fl.name = "test2";
	r.folders.push_back(fl);
	fl = *new folder();
	fl.name = "static";
	file fil = *new file();
	fil.name = "sadsa";
	fil.content = "sadsa";
	fl.files.push_back(fil);
	folder ttt = *new folder();
	ttt.name = "test";
	fl.folders.push_back(ttt);
	r.folders.push_back(fl);
	debug("!!!");
	debug(r.folders[2].name);
	debug(r.folders[2].files[0].name);

	file test_file = *new file();
	test_file.name = "test.ex";
	test_file.content = "___F!";
	r.files.push_back(test_file);

	root = r;
	current_folder = root;
	path.push(current_folder);
	debug(current_folder.folders[2].files[0].name);

}

// void OS::add_app(app _app)
// {
// 	apps.push_back(_app);
// }

void OS::ls(folder &fldr)
{

	color_write("Content of: " + fldr.name, White);
	color_write("Count: " + std::to_string(fldr.folders.size() + fldr.files.size()), White);
	for( auto &&f : fldr.folders)
	{
		color_write(f.name, Bright_Blue);
	}
	for( auto &&f : fldr.files)
	{
		color_write(f.name, White);
	}
}
void OS::cd(std::string folder_name)
{
	debug(folder_name);
	if (folder_name == "/")
	{
		current_folder = root;
		return;
	}
	if (folder_name == "..")
	{
		if (path.size() == 1)
		{
			color_write("You are in the root!", Yellow);
			return;
		}
		path.pop();
		current_folder = path.top();
		return;
	}
	for(auto fldr : current_folder.folders)
	{
		debug("Current: " + fldr.name);
		if (fldr.name == folder_name)
		{
			current_folder = fldr;
			path.push(fldr);
			return;
		}
	}
	color_write("Folder not found!", Yellow);
}

std::string OS::get_string_path()
{
	std::stack<folder> tmp = path;
	std::stack<std::string> res;
	while (!tmp.empty())
	{
		res.push(tmp.top().name);
		tmp.pop();
	}
	std::string result;
	while (!res.empty())
	{
		result += "/" + res.top();
		res.pop();
	}
	
	return result;
}

void OS::terminal()
{
	std::string input = "";
	while(input != "exit")
	{
		// write( current_folder.name + "> " );
		write( get_string_path() + "> " );
		// std::cin >> input;
		std::getline(std::cin, input);
		if (input == "exit") break;

		bool run = false;

		// for(auto &app : apps)
		// {
		// 	write_line(app.name);
		// 	if ( app.name == input )
		// 	{
		// 		app.run();
		// 		run = true;
		// 		break;
		// 	}
		// }

		if ( input == "ls" )
		{
			ls(current_folder);
			continue;
		}

		if ( is_str_in_str(input, "cd") && input.substr(0, 2) == "cd" )
		{
			debug("[bef] " + input);
			input.replace(0, 3, "");
			debug("[aft] " + input);
			cd(input);
			continue;
		}

		if ( input == "clear" )
		{
			clear();
			continue;
		}


		if (!run)
			color_write("Binary not found!", Red);
	}
	color_write("Shutdowning system!", Yellow, italic);
}

void OS::auth()
{
	std::string login, password;
	write("Enter login: ");
	std::cin >> login;
	write("Enter password: ");
	std::cin >> password;
	std::system("clear");

	if ( login != global::storage["main_os__login"] ||
		 password != global::storage["main_os__password"] )
	{
		color_write("Wrong creds!", Red, bold);
		sleep_ms(300);
		auth();
		return;
	}

	color_write("You entered the system!", Green, bold);
	sleep_ms(300);
	terminal();
}

void OS::boot()
{
#ifndef DEBUG
	sleep_ms(100);
	write_line("Boot started");
	sleep_ms(1000);
	write_line("Boot in progress [0 / 100]");
	int prog = 0;
	while (prog < 100)
	{
		prog += get_random_int(2, 11);
		if (prog > 100) prog = 100;
		write_line("Boot in progress [" + std::to_string(prog) + " / 100]");
		sleep_ms(get_random_int(200, 800));
	}
	write_line("Boot success!");
	sleep_ms(500);
#endif

	auth();
}

void OS::start ()
{
	clear();
	boot();

	// sleep_ms(1000);
	// std::cout << "You started an os!" << std::endl;
}