// I got bored during vacation
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include "JakselMappings.cpp" // Include the mappings header

struct Jaksel{
    // Helper function to convert a string to lowercase
    std::string toLower(const std::string &str) {
        std::string lowerStr = str;
        std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                       [](unsigned char c) { return std::tolower(c); });
        return lowerStr;
    }

    // Function to replace all occurrences of 'from' with 'to' in a case-insensitive manner using transform
    std::string replaceAll(std::string str, const std::string &from, const std::string &to) {
        // Create lowercase copies for searching
        std::string lowerStr = toLower(str);
        std::string lowerFrom = toLower(from);
        size_t start_pos = 0;
        while ((start_pos = lowerStr.find(lowerFrom, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            // Update the lowercase copy accordingly
            lowerStr.replace(start_pos, from.length(), to);
            start_pos += to.length(); // Advance to prevent infinite loop if 'to' contains 'from'
        }
        return str;
    }

    // Function that translates a line of Jaksel slang to valid C++ code
    std::string interpret(const std::string& input) {
        // Mapping of Jaksel slang words to C++ tokens
        std::map<std::string, std::string> slangMapping = jakselKeywords;

        std::string result = input;
        // Create a vector of pairs and sort by key length descending
        std::vector<std::pair<std::string, std::string>> mapping(slangMapping.begin(), slangMapping.end());
        std::sort(mapping.begin(), mapping.end(), [](const auto &a, const auto &b) {
            return a.first.size() > b.first.size();
        });

        for (const auto &pair: mapping) {
            result = replaceAll(result, pair.first, pair.second);
        }
        return result;
    }
};


int main() {
    // Open the input file (custom .jaksel file)
    std::ifstream inputFile("main.jaksel");
    if (!inputFile) {
        std::cerr << "Error: Could not open input.jaksel for reading." << std::endl;
        return 1;
    }

    // Create the output C++ file
    std::ofstream outputFile("output.cpp");
    if (!outputFile) {
        std::cerr << "Error: Could not create output.cpp for writing." << std::endl;
        return 1;
    }

    // Process each line from the input file
    Jaksel jaksel;
    std::string line;
    while (std::getline(inputFile, line)) {
        // Convert each line using our Jaksel interpreter
        std::string cppLine = jaksel.interpret(line);
        // Indent the code inside main and write to output file
        outputFile << cppLine << "\n";
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Conversion complete. Generated output.cpp." << std::endl;

    #ifdef _WIN32
        int compileResult = system("g++ -o output.exe output.cpp");
        if (compileResult != 0) {
            std::cerr << "Compilation failed on Windows!" << std::endl;
            return 1;
        }
        std::cout << "Program output:" << std::endl;
        std::cout << "======================" << std::endl;
        int runResult = system("output.exe");
        if (runResult != 0) {
            std::cerr << "Execution failed on Windows!" << std::endl;
            return 1;
        }
    #else
        int compileResult = system("g++ -o output output.cpp");
        if (compileResult != 0) {
            std::cerr << "Compilation failed on Unix-like system!" << std::endl;
            return 1;
        }
        std::cout << "Program output:" << std::endl;
        std::cout << "======================" << std::endl;
        int runResult = system("./output");
        if (runResult != 0) {
            std::cerr << "Execution failed on Unix-like system!" << std::endl;
            return 1;
        }
    #endif
    std::cout << "======================" << std::endl;

    return 0;
}