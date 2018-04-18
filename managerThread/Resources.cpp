
#include <iostream>
#include <fstream>

int main(){
	system("echo $(cat -E /proc/meminfo) >meminfo.txt");
	system("echo $(cat -E /proc/cpuinfo) >cpuinfo.txt");
	system("echo $(cat -E /proc/swaps)   >swaps.txt");
	system("echo $(cat -E /proc/version) >version.txt");

	

	return 0;
}	
