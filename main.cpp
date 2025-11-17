#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <cstring>

std::string input;
char in[256];
int out[16] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
int running = 0;

int main(int argc, char **argv) {
	if (argc == 2) {
		running = 1;
		std::ifstream file(argv[1]);
		if (file.is_open()) {
				std::getline(file,input);
				std::strncpy(in, input.c_str(), sizeof(in));
				in[255] = '\0';
		}
	} else if (argc < 2) printf("too few args!");
	else if (argc > 2) printf("too many args!");
	if(running) {
		int i = 0;
		int instruction = 0;
		while(i <= 15) {
			if (in[instruction] == '+') out[i]++;
			else if (in[instruction] == '-') out[i]--;
			else if(in[instruction] == '>') i++;
			else if(in[instruction] == '<') i--;
			else break;
			instruction++;
		}
		int o = 0;
		while(o < 16) {
			printf("%i", out[o]);
			o++;
		}
	}
	printf("\n");
	return 0;
}
