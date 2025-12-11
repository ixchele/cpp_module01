#include <fstream>
#include <iostream>
#include <string>


std::string	readFile(std::ifstream &file) {
	std::string	content;
	std::string	line;

	while (std::getline(file, line)) {
		content += line;
		if (!file.eof())
			content += '\n';
	}
	std::cerr << content << "eof\n";
	return content;
}

size_t	replaceSegment(std::string &content, size_t from, std::string tf, std::string tr) {
	content.erase(from, tf.size());
	content.insert(from, tr);
	return tr.size();
}

void	replaceAll(std::string &content, std::string tf, std::string tr) {
	for (size_t pos = 0; pos < content.size(); ++pos) {
		if (!content.compare(pos, tf.size(), tf, 0, tf.size())) {
			std::cout << "occ find here :" << pos << std::endl;
			pos += replaceSegment(content, pos, tf, tr);
		}
	}
	std::cerr << content << "eof\n";
}

int main (int ac, char **av) {
	if (ac != 4)
		return std::cerr << "usage :" << std::endl, -1;

	std::string fileName = av[1];
	std::string stringToFind = av[2];
	std::string stringToReplace = av[3];

	std::ifstream file(fileName.c_str());
	if (!file.is_open())
		return std::cerr << "could not open the file :" << av[1] << std::endl, -1;
	
	// NOTE:: read the file.
	std::string content = readFile(file);
	replaceAll(content, stringToFind, stringToReplace);

	return 0;
}
