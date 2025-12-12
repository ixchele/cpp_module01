#include <fstream>
#include <iostream>
#include <string>

static std::string	readFile(std::ifstream &file) {
	std::string	content;
	std::string	line;

	while (std::getline(file, line)) {
		content += line;
		if (!file.eof())
			content += '\n';
	}
	return content;
}

static size_t	replaceSegment(std::string &content, size_t from, std::string tf, std::string tr) {
	content.erase(from, tf.size());
	content.insert(from, tr);
	return tr.size();
}

void	replaceAll(std::string &content, std::string tf, std::string tr) {
	for (size_t pos = 0; pos < content.size(); ++pos) {
		if (!content.compare(pos, tf.size(), tf, 0, tf.size())) {
			pos += replaceSegment(content, pos, tf, tr);
		}
	}
}

int main (int ac, char **av) {
	if (ac != 4)
		return std::cerr << "USAGE : <file_name> <to_replace> <to_replace_with>" << std::endl, -1;

	std::string	fileName = av[1];
	std::string fileOutput = fileName + ".replace";
	std::string stringToFind = av[2];
	std::string stringToReplace = av[3];

	// NOTE : open the file
	std::ifstream	file(fileName.c_str());
	if (!file.is_open())
		return std::cerr << "Could not open the file : " << fileName << std::endl, -1;
	
	// NOTE:: read the file, and replace all
	std::string content = readFile(file);
	replaceAll(content, stringToFind, stringToReplace);

	// NOTE : output on the ".replace" file
	std::ofstream	outputfiles(fileOutput.c_str());
	outputfiles << content;
	return 0;
}
