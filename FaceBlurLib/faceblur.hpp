#ifndef FACEBLUR_FACEBLUR_HPP
#define FACEBLUR_FACEBLUR_HPP

#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

namespace FaceBlurLib{

    std::vector<cv::Rect> DetectFaces(const std::string& imagePath);
    void BlurFaces(cv::Mat& inputImage, const std::vector<cv::Rect>& faces);
}


#endif //FACEBLUR_FACEBLUR_HPP
