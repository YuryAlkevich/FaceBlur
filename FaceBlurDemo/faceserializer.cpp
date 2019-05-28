#include "faceserializer.hpp"

#include <boost/property_tree/json_parser.hpp>

using namespace boost::property_tree;

FaceSerializer::FaceSerializer(const std::string &path) : _filePath(path) {

}

void FaceSerializer::AddFaces(const std::string &imagePath, const std::string& blurredImagePath, std::vector<cv::Rect> &faces) {
    ptree child;
    child.put(_sourceImageKey, imagePath);
    child.put(_resultImageKey, blurredImagePath);

    ptree facesArray;

    for(auto& face : faces){
        std::stringstream ss;
        ss << "(" << face.x << "," << face.y << "," << face.width << "," << face.height << ")";

        ptree faceNode;
        faceNode.put("", ss.str());

        facesArray.push_back(std::make_pair("", faceNode));
    }

    child.add_child(_facesKey, facesArray);

    _array.push_back(std::make_pair("", child));
}

void FaceSerializer::WriteToFile() {
    boost::property_tree::ptree _root;
    _root.add_child(_rootKey, _array);
    write_json(_filePath, _root);
}
