#include <gtest/gtest.h>

#include "facedetector.hpp"

class FaceDetectorTest : public ::testing::Test {
protected:
    FaceProcessingLib::FaceDetector detector;
};

TEST_F(FaceDetectorTest, TruePositive){
    std::string imgPath = "./testdata/sixfaces.jpg";

    auto faces = detector.DetectFaces(imgPath);

    EXPECT_EQ(faces.size(), 6);
}

TEST_F(FaceDetectorTest, TrueNegative){
    std::string imgPath = "./testdata/nofaces.jpg";

    auto faces = detector.DetectFaces(imgPath);

    EXPECT_EQ(faces.size(), 0);
}