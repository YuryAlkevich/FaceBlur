#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

#include "faceblur.hpp"

using namespace boost::filesystem;

bool ValidateArgs(int argc, char *argv[]){

    if(argc != 2){
        return false;
    }

    path p{argv[1]};

    if(!is_directory(p)){
        std::cerr << p << " is not a directory" << std::endl;
        return false;
    }

    return true;
}

void PrintHelp(){
    std::cout << "Usage: ./FaceBlurDemo pathToImagesFolder" << std::endl;
}

int main(int argc, char *argv[]){

    if(ValidateArgs(argc, argv) == false){
        PrintHelp();
        exit(1);
    }

    path p{argv[1]};

    for(auto& entry : boost::make_iterator_range(recursive_directory_iterator(p), {})){
        auto faces = FaceBlurLib::DetectFaces(entry.path().string());

        cv::Mat img = cv::imread(entry.path().string());
        FaceBlurLib::BlurFaces(img, faces);
        cv::resize(img, img, {img.cols / 2, img.rows / 2});

        cv::imshow("result", img);
        cv::waitKey(0);
    }
}
