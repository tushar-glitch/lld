#include <iostream>
#include <string>
class FileManager{
    private:
        std::string _filePath;

    public:
        void createfile(const std::string &file_name, const std::string &content = "");
        void readfile(const std::string &file_name);
        void deletefile(const std::string &file_name);
        void updatefile(const std::string &file_name, const std::string content = "");
        void listfile();
};