#ifndef FACEBLUR_FACESERIALIZER_HPP
#define FACEBLUR_FACESERIALIZER_HPP

#include <string>
#include <boost/property_tree/ptree.hpp>
#include <opencv2/opencv.hpp>



class FaceSerializer {
public:
    FaceSerializer(const std::string& path);
    void AddFaces(const std::string& imagePath, const std::string& blurredImagePath, std::vector<cv::Rect>& faces);
    void WriteToFile();

private:
    std::string _filePath;
    boost::property_tree::ptree _array;

    const std::string _rootKey = "detection_result";
    const std::string _sourceImageKey = "source_image";
    const std::string _resultImageKey = "blurred_image";
    const std::string _facesKey = "faces";
};


#endif //FACEBLUR_FACESERIALIZER_HPP
