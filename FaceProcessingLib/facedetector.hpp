#ifndef FACEBLUR_FACEDETECTOR_HPP
#define FACEBLUR_FACEDETECTOR_HPP

#include <opencv2/objdetect.hpp>

#include "libdefines.hpp"

namespace FaceProcessingLib{
    class EXPORT FaceDetector{
    public:
        FaceDetector();
        std::vector<cv::Rect> DetectFaces(const std::string& imagePath);

    private:
        const std::string _cascadePath = "resources/haarcascade_frontalface_alt2.xml";
        cv::CascadeClassifier _faceCascade;

    };
}

#endif //FACEBLUR_FACEDETECTOR_HPP
