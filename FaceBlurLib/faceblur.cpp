#include "faceblur.hpp"

#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

vector<Rect> FaceBlurLib::DetectFaces(const string& imagePath){
    string faceCascadePath = "haarcascade_frontalface_alt2.xml";
    CascadeClassifier faceCascade;
    faceCascade.load(faceCascadePath);

    Mat img = imread(imagePath);

    vector<Rect> detectedFaces;
    faceCascade.detectMultiScale(img, detectedFaces);

    if(detectedFaces.empty()){
        cout << "Image: " << imagePath << ". No faces detected" << endl;
        return detectedFaces;
    }

    cout << "Image: " << imagePath << ". Total faces detected: " << detectedFaces.size() <<  endl;
    return detectedFaces;
}

void FaceBlurLib::BlurFaces(Mat& inputImage, const vector<Rect> &faces) {
    for (auto& faceRect : faces) {
        Mat roi = inputImage(faceRect);
        blur(roi, roi, {50, 50});
    }
}
