#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

constexpr std::size_t size = 16;
int out[size] = {0};

std::string readEntireFile(std::ifstream& file) {
	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

int wrappingAdd(int i) {
	if (++i == size) {
		return 0;
	} else {
		return i;
	}
}

int wrappingSub(int i) {
	if (--i == -1) {
		return size - 1;
	} else {
		return i;
	}
}

int main(int argc, char **argv) {
	if (argc < 2) {
		printf("too few args!\n");
		exit(1);
	} else if (argc > 2) {
		printf("too many args!\n");
		exit(1);
	}

	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		printf("failed to open file %s\n", argv[1]);
		exit(1);
	}

	std::string input = readEntireFile(file);

	int i = 0;
	for (char c : input) {
		if (c == '+') {
			out[i]++;
		} else if (c == '-') {
			out[i]--;
		} else if (c == '>') {
			i = wrappingAdd(i);
		} else if (c == '<') {
			i = wrappingSub(i);
		} else if(c == '?') {
			out[i] *= -1;
		} else if(c == '!') {
			out[i] *= 2;
		}
	}

	int o = 0;
	while(o < 16) {
		printf("%i", out[o]);
		o++;
	}
	printf("\n");
	return 0;
}
