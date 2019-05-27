#include "faceblur.hpp"

using namespace cv;
using namespace std;

void FaceProcessingLib::BlurFaces(Mat& inputImage, const vector<Rect> &faces) {
    for (auto& faceRect : faces) {
        Mat roi = inputImage(faceRect);
        blur(roi, roi, {50, 50});
    }
}
