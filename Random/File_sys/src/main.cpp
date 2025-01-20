#include <iostream>
#include <stdio.h>
#include "FileManager.h"

int main(int argc, char **argv){
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    std::string command = argv[1];
    std::string file_name = argv[2];
    
    // Create file command
    if(command == "cr"){
        std::string content = "";
        if(argc > 3){
            for (int i = 3; i < argc;++i){
                content += argv[i];
                content += " ";
            }
        }
        FileManager fobj;
        fobj.createfile(file_name, content);
    }

    return 0;
}

// g++ main.cpp FileManager.cpp -o file_manager
// .\file_manager.exe