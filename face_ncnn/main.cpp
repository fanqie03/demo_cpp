#include <iostream>
//#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "mat.h"
#include "net.h"
#include <string>

#include "arcface/interface.h"

#define FACE_DETECT_SIZEH   448
using namespace std;


vector<float> detect_single_img(cv::Mat img) {
    ncnn::Mat in = ncnn::Mat::from_pixels(img.data, ncnn::Mat::PIXEL_BGR, img.cols, img.rows);
    vector<FaceInfo> faceinfo = face_detect(in);
    vector<float> feature = face_exactfeature(in, faceinfo[0]);
    return feature;

}


int main(int args, char **argv) {
    string img_path = argv[1];

    cv::Mat img = cv::imread(img_path);
    vector<float> my_feature = detect_single_img(img);
    cv::VideoCapture capture(0);
    int src_width = capture.get(cv::CAP_PROP_FRAME_WIDTH);
    int src_height = capture.get(cv::CAP_PROP_FRAME_HEIGHT);
    printf("%d, %d\n", src_width, src_height);

    int sizew = FACE_DETECT_SIZEH;
    int sizeh = FACE_DETECT_SIZEH * src_height / src_width;
    while (true) {
        cv::Mat frame;
        capture >> frame;
//        检查
        if (frame.empty()) {
            printf("播放完成\r\n");
            break;
        }
        cv::Mat resize_frame;
        cv::resize(frame, resize_frame, cv::Size(sizew, sizeh));

//      检测人脸
        ncnn::Mat in = ncnn::Mat::from_pixels(resize_frame.data, ncnn::Mat::PIXEL_BGR, sizew, sizeh);
//        in.substract_mean_normalize(mean_vals,norm_vals);
        vector<FaceInfo> faceinfo = face_detect(in);
//        printf("%d", faceinfo.size());
        for (int i = 0; i < faceinfo.size(); i++) {
            FaceInfo face = faceinfo[i];
//            cout << face.score << endl;
            cv::rectangle(resize_frame, cv::Point(face.x[0], face.y[0]), cv::Point(face.x[1], face.y[1]),
                          cv::Scalar(0, 255, 0));
            vector<float> feature = face_exactfeature(in, face);
//            cout << feature[0] << endl;
            float sim = face_calcSimilar(feature, my_feature);
            printf("sim is %f\r\n", sim);
            cv::putText(resize_frame, to_string(sim), cv::Point(face.x[0], face.y[0]), cv::FONT_HERSHEY_SIMPLEX, 1,
                        cv::Scalar(0, 255, 0));
        }

//        show
        cv::imshow("read video", resize_frame);
        if (cv::waitKey(1) == 'q') {
            break;
        }
    }
}