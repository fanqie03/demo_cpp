#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "mat.h"
#include "net.h"
#include <string>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    string img_path = "/home/cmf/Pictures/5a9ee783c3f3a.jpg";
//    cv::Mat img = cv::imread(img_path);
    int sz[] = {100, 100, 3};
    cv::Mat bigCube(3, sz, CV_8U, cv::Scalar::all(0));
    cv::Mat img1 = cv::Mat(3, 3, 3);
//    if (img.data == NULL)
//    {
//        cout << "img is NULL" <<endl;
//    }
//
//    cout<<img.data<<endl;
    cv::Mat img2;
    int input_width = 112;
    int input_height = 112;
//    resize
    cv::resize(img1, img2, cv::Size(input_width, input_height));
//    加载网络
    ncnn::Net net;
    net.load_param("/home/cmf/w_learn/CLionProjects/untitled/model.param");
    net.load_model("/home/cmf/w_learn/CLionProjects/untitled/model.bin");
//    把opencv的mat转换成ncnn的mat
    ncnn::Mat input = ncnn::Mat::from_pixels(img2.data, ncnn::Mat::PIXEL_BGR, img2.cols, img2.rows);
//    ncnn前向计算
    ncnn::Extractor extractor = net.create_extractor();
    extractor.input("data", input);
    ncnn::Mat output;
    extractor.extract("fc1", output);
//    输出预测结果
    ncnn::Mat out_flatterned = output.reshape(output.w * output.h * output.c);
    std::vector<float> scores;
    scores.resize(out_flatterned.w);
    for(int j = 0; j < out_flatterned.w; j++)
    {
        scores[j] = out_flatterned[j];
    }

    cout<< scores[0] << endl;
    cout<<"done" << endl;


    return 0;
}