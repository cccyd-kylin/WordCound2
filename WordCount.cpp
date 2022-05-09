#include <fstream>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <string>
#include<string.h>
#include <cstdlib>


int countCharacters(std::string fileName);

int countWords(std::string fileName);

int main(int argc, char **argv) {


    if (argc < 2) {
        std::cerr << "Usage: count_words <infile>\n";
        return EXIT_FAILURE;
    }


    if (strcmp("-w", argv[1]) == 0 || strcmp("-W", argv[1]) == 0) {
        countWords(argv[2]);

    }
    if (strcmp("-c", argv[1]) == 0 || strcmp("-C", argv[1]) == 0) {
        countCharacters(argv[2]);
    }

    return 0;
}

int countWords(std::string fileName) {

    std::ifstream infile(fileName);

    std::istream_iterator<std::string> in{infile}, end;

    std::cout << "Word Count: " << std::distance(in, end) << std::endl;


    return std::distance(in, end);


}

int countCharacters(std::string fileName) {
    std::string line;
    std::ifstream inMyStream(fileName);
    int c;
    if (inMyStream.is_open()) {
        while (std::getline(inMyStream, line)) {
            c += line.length();
        }
    }
    inMyStream.close();
    std::cout << "Character Count: " << c << std::endl;

    return c;
}

