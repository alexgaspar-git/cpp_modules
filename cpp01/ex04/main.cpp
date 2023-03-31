#include <string>
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv) {

	if (argc != 4) {
		std::cout << "Required arguments: Filename, string 1, string 2" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string original = argv[2];
	std::string replace = argv[3];

	std::ifstream input(filename);

	if (!input.is_open()) {
		std::cout << "Unable to open file" << std::endl;
		return 1;
	}

	std::ofstream output(filename + ".replace");
	if (!output.is_open()) {
		std::cout << "Error creating .replace file" << std::endl;
		return 1;
	}

	std::string line;

	while (std::getline(input, line)) {
		size_t	og_len = original.size();
		size_t	pos = line.find(original);
		while (pos != std::string::npos) {
			std::string before = line.substr(0, pos);
			std::string after = line.substr(pos + og_len);
			line = before + replace + after;
			pos = line.find(original, pos + replace.size());
		}
		output.write(line.c_str(), line.length());
		output.put('\n');
	}

	input.close();
	output.close();

	return 0;
}