#include <INI/Loader.h>

#include <iostream>

namespace INI {
    void Loader::printFileError() {
        std::cout << "Error: Unable to open the file" << std::endl;
    }

    void Loader::print(std::string option) {
        std::cout << option << "=" << options[option] << std::endl;
    }

    void Loader::printAll() {
        for (const auto &pair : options) {
            std::cout << pair.first << "=" << pair.second << std::endl;
        }
    }
}
