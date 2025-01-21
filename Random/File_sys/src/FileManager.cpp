#include "FileManager.h"
#include <fstream>

void FileManager::createfile(const std::string &file_name, const std::string &content){
    std::ofstream fout(file_name, std::ios::out);
    fout << content;
    fout.close();
}

void FileManager::readfile(const std::string& file_name){
    std::ofstream fout(file_name);
    
}