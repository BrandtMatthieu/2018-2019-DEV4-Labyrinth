#define CATCH_CONFIG_RUNNER
#define CATCH_CONFIG_MAIN

#include "./catch.hpp"

#define RUN_TEST 1

#if RUN_TEST

int main(int argc, char *const argv[]) {
	Catch::Session().run(argc, argv);
}

#else
#include <iostream>

int main() {
	std::cout << "Main" << std::endl;
}
#endif