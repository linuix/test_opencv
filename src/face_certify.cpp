//
// Created by linuix on 2020/12/10.
//

#include <stdlib.h>
#include <stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>
#include "log_util.h"

using namespace cv;
using namespace std;

int main(int argc, char const *argv[]) {


    string face_config = "/home/linuix/workspace/opencv/data/haarcascades/haarcascade_frontalface_default.xml";
    Mat mat;
    VideoCapture videoCapture(-1);
    if (!videoCapture.isOpened()) {
        LOGE("open camera failed !!");
        return -1;
    }
    CascadeClassifier cascadeClassifier1;
    if (!cascadeClassifier1.load(face_config)) {
        LOGE("无法加载配置文件");
        return -1;
    }

    vector<Rect> faces;

    char k;
    while (true) {
        videoCapture >> mat;

        Mat img_gray;
        cvtColor(mat, img_gray, COLOR_BGR2GRAY);
        equalizeHist(img_gray, img_gray);

        cascadeClassifier1.detectMultiScale(mat, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30),Size(500, 500));
        for (vector<Rect>::const_iterator iter = faces.begin(); iter != faces.end(); iter++) {
            rectangle(mat, *iter, Scalar(0, 0, 255), 2, 8);
        }
        imshow("camera", mat);

        k = waitKey(30);
        if (k == 27) {
            break;
        }
    }
    return 0;
}