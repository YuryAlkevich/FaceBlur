#include "facedetector.hpp"

#include <stdexcept>
#include <opencv2/opencv.hpp>

using namespace FaceProcessingLib;
using namespace cv;
using namespace std;

FaceDetector::FaceDetector() {
    if(_faceCascade.load(_cascadePath) == false){
        throw std::runtime_error{"Failed to initialize FaceDetector. Check resources folder"};
    }
}

std::vector<cv::Rect> FaceDetector::DetectFaces(const std::string &imagePath) {
    Mat img = imread(imagePath);

    vector<Rect> detectedFaces;
    _faceCascade.detectMultiScale(img, detectedFaces);

    if(detectedFaces.empty()){
        cout << "Image: " << imagePath << ". No faces detected" << endl;
        return detectedFaces;
    }

    cout << "Image: " << imagePath << ". Total faces detected: " << detectedFaces.size() <<  endl;
    return detectedFaces;
}
