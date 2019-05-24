#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>


bool ValidateArgs(int argc, char *argv[]){

    if(argc != 2){
        return false;
    }

    char* path = argv[1];
    struct stat fileInfo;

    if(stat(path, &fileInfo) != 0){
        std::cerr << "Cannot access " << path << std::endl;
        return false;
    }
    else if((fileInfo.st_mode & S_IFDIR) == 0){
        std::cerr << path << " is not a directory" << std::endl;
        return false;
    }

    return true;
}

void PrintHelp(){
    std::cout << "Usage: FaceBlurDemo pathToImagesFolder" << std::endl;
}

int main(int argc, char *argv[]){

    if(ValidateArgs(argc, argv) == false){
        PrintHelp();
        exit(1);
    }
}
