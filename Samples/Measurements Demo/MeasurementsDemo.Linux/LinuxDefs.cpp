#include "LinuxDefs.h"
#include <string>
double GetTickCount(void)
{
	struct timespec now;
	if (clock_gettime(CLOCK_MONOTONIC, &now))
		return 0;
	return now.tv_sec * 1000.0 + now.tv_nsec / 1000000.0;
}

void getLinuxAppDirectory(char* path)
{
	char result[MAX_PATH];
	ssize_t count = readlink("/proc/self/exe", result, MAX_PATH);
	std::string appPath = std::string(result, (count > 0) ? count : 0);

	std::size_t found = appPath.find_last_of("/\\");

	strcpy(path, appPath.substr(0, found).c_str());
}