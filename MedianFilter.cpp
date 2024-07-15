#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/features2d.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;


void median(const Mat &src, Mat &dst, int window){
    vector<float> neighbors;
    float tmp;
   
    int windowSize = ((window*2)+1)* ((window * 2) + 1);
    for (auto y = 0; y < dst.rows; y++)for (auto x = 0; x < dst.cols; x++) {
       
        for (auto s = -window; s <= window; s++)for (auto t = -window; t <= window; t++) {
            tmp = src.at<float>(min(dst.rows - 1, max(0, y + t)), min(dst.cols - 1, max(0, x + s)));       
            neighbors.push_back(tmp);
        }

        sort(neighbors.begin(), neighbors.end());
        dst.at<float>(y, x) = neighbors[neighbors.size() / 2];
        neighbors.clear();
       
    }
}

int main()
{
    Mat f = imread("C:\\Users\\rkdxo\\OneDrive\\바탕 화면\\HW\\MedianFilterInput.png",IMREAD_GRAYSCALE);
    f.convertTo(f, CV_32F, 1 / 255.f);
    Mat g1(f.size(), CV_32FC1);
    Mat g2(f.size(), CV_32FC1);
    Mat g3(f.size(), CV_32FC1);
    Mat g4(f.size(), CV_32FC1);
    Mat g5(f.size(), CV_32FC1);

    median(f, g1, 1);
    median(f, g2, 2);
    median(f, g3, 3);
    median(f, g4, 4);
    median(f, g5, 5);

    imshow("Image1", g1);
    waitKey();
    imshow("Image2", g2);
    waitKey();
    imshow("Image3", g3);
    waitKey();
    imshow("Image4", g4);
    waitKey();
    imshow("Image5", g5);
    waitKey();
    
    
    return 0;
}
