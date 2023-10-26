#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

namespace INI {
    class Loader {
        public:
            Loader(std::string filename);

            void printAll();
            void print(std::string option = nullptr);

            std::string getValue(std::string key = nullptr) {
                return options[key];
            }

            std::vector<std::string> getValues(std::string section = nullptr) {
                std::vector<std::string> values;
                for (const auto &pair : options) {
                    std::string key = pair.first;
                    key.erase(0, key.find_first_of("."));
                    if (key == section) {
                        values.push_back(pair.second);
                    }
                }
                return values;
            }

        protected:
            void readINI(std::ifstream &iniFile) {
                if (iniFile.is_open()) {
                    std::string line;
                    std::string currentSection;
                    while (std::getline(iniFile, line)) {
                        removeComments(&line);
                        removeWhitespace(&line);
                        
                        // Ignore empty line
                        if (line.empty()) {
                            continue;
                        }
                        
                        if (line.front() == '[' && line.back() == ']') {
                            currentSection = line.substr(1, line.size() - 2);
                        } else {
                            insertToOptions(line, currentSection);
                        }
                    }

                    iniFile.close();
                } else {
                    printFileError();
                }
            }

            void insertToOptions(std::string line, std::string currentSection) {
                std::istringstream lineStream(line);
                std::string key, value;
                std::getline(lineStream, key, '=');
                std::getline(lineStream, value);
                removeWhitespace(&key);
                removeWhitespace(&value);
                options[currentSection + "." + key] = value;
            }
        
            virtual void printFileError();

        private:
            std::map<std::string, std::string> options;

            void removeComments(std::string *line) {
                size_t commentPos = line->find(';');
                if (commentPos != std::string::npos) {
                    *line = line->substr(0, commentPos);
                }
            }

            void removeWhitespace(std::string *line) {
                line->erase(0, line->find_first_not_of(" \t\r\n"));
                line->erase(line->find_last_not_of(" \t\r\n") + 1);
            }
    };
}
