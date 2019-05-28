#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/algorithm/string.hpp>
#include <string>

#include "faceblur.hpp"
#include "facedetector.hpp"
#include "faceserializer.hpp"

using namespace boost;
using namespace boost::filesystem;
using namespace FaceProcessingLib;

bool ValidateArgs(int argc, char *argv[]){

    if(argc < 2){
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

bool IsImage(const path& filePath){
    auto extensnion = filePath.extension().string();
    return iequals(extensnion, ".jpg") || iequals(extensnion, ".png");
}

int main(int argc, char *argv[]){

    if(ValidateArgs(argc, argv) == false){
        PrintHelp();
        exit(1);
    }

    path sourceFolder{argv[1]};

    const char* p = argc > 2 ? argv[2] : "./result";
    path resultFolder {p};

    create_directory(resultFolder);

    FaceDetector faceDetector;
    FaceSerializer faceSerializer((resultFolder / "result.json").string());


    for(auto& entry : boost::make_iterator_range(recursive_directory_iterator(sourceFolder), {})){

        if(!IsImage(entry.path()))
            continue;

        auto faces = faceDetector.DetectFaces(entry.path().string());

        cv::Mat img = cv::imread(entry.path().string());
        BlurFaces(img, faces);
        cv::resize(img, img, {img.cols / 2, img.rows / 2});

        auto resultImgPath = (resultFolder / entry.path().filename()).string();
        cv::imwrite(resultImgPath, img);


        faceSerializer.AddFaces(entry.path().string(), entry.path().filename().string(), faces);
    }

    faceSerializer.WriteToFile();
}
