#include <iostream>
#include "OS.hpp"
#include "core.hpp"
#include "utils.hpp"
#include "global.hpp"
// #include "apps/ls.hpp"

int main()
{

	load_data("test.data", global::storage);

	OS os = *new OS();
	// os.add_app(*new ls());
	os.start();

	return 0;
}