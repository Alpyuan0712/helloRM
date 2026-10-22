#include<opencv2/opencv.hpp>
#include<iostream>
#include<vector>
#include<string>
int main()
{
    //BASE 1
    cv::Mat lena = cv::imread("../assets/lena.jpg");
    if(lena.empty())
    {
        std::cout<<"读取失败"<<std::endl;
        return 0;
    }
    std::cout<<"rows="<<lena.rows
    <<",cols="<<lena.cols
    <<",channels="<<lena.channels()
    <<",step="<<lena.step<<std::endl;
    cv::Mat lena2 = lena.clone();
    cv::Rect rect(200,180,220,240);
    cv::rectangle(lena2,rect,cv::Scalar(0,255,0),2);
    cv::imwrite("../results/lena_marked.png",lena2);
    cv::Mat roi = lena(rect);
    cv::imwrite("../results/lena_roi.png",roi);
    cv::Mat lenacopy1 = lena.clone();
    cv::Mat roicopy1 = lenacopy1(rect);
    cv::Vec3b& a = roicopy1.at<cv::Vec3b>(0,0);
    a = cv::Vec3b(0,0,255);
    cv::Vec3b& a0 = lenacopy1.at<cv::Vec3b>(180,200);
    std::cout<< a <<std::endl<< a0 << std::endl;
    cv::Mat lenacopy2 = lena.clone();
    cv::Mat roicopy2 = lenacopy2(rect).clone();
    cv::Vec3b& b = roicopy2.at<cv::Vec3b>(0,0);
    b = cv::Vec3b(0,0,255);
    cv::Vec3b& b0 = lenacopy2.at<cv::Vec3b>(180,200);
    std::cout<< b <<std::endl<< b0 <<std::endl;
    //BASE 2
    cv::Mat coins = cv::imread("../assets/coins.png");
    cv::Mat gray;
    cv::Mat binary;
    cv::cvtColor(coins,gray,cv::COLOR_BGR2GRAY);
    cv::threshold(gray,binary,135,255,cv::THRESH_BINARY);
    cv::imwrite("../results/coins_binary.png",binary);
    std::vector<std::vector<cv::Point>> contours;
    cv::findContours(binary,contours,cv::RETR_EXTERNAL,cv::CHAIN_APPROX_SIMPLE);
    int count = 0;
    for(int i = 0;i < contours.size();i++)
    {
        double area = cv::contourArea(contours[i]);
        if(area >= 250 && area <= 4000)
        {
            count++;
            cv::Rect box = cv::boundingRect(contours[i]);
            cv::rectangle(coins,box,cv::Scalar(0,255,0),2);
            cv::putText(coins,std::to_string(count),box.tl() + cv::Point(5,15),cv::FONT_HERSHEY_SIMPLEX,0.6,cv::Scalar(0,0,255),2);
        }
    }
    std::cout << count << std::endl;
    cv::imwrite("../results/coins_counted.png",coins);
    //BASE 3
    cv::Mat sudoku = cv::imread("../assets/sudoku.png");
    cv::Mat sudoku1 = sudoku.clone();
    std::vector<cv::Point2f> orin{{74,85},{490,70},{520,520},{36,516}};
    for(int j = 0;j < orin.size();j++)
    {
        cv::circle(sudoku1,orin[j],5,cv::Scalar(0,0,255),-1);
        cv::putText(sudoku1,std::to_string(j+1),orin[j] + cv::Point2f(10,-10),cv::FONT_HERSHEY_COMPLEX,1.0,cv::Scalar(0,0,255),2);
    }
    cv::imwrite("../results/sudoku_points.png",sudoku1);
    std::vector<cv::Point2f> goal{{0,0},{449,0},{449,449},{0,449}};
    cv::Mat change = cv::getPerspectiveTransform(orin,goal);
    cv::Mat sudokuchange;
    cv::warpPerspective(sudoku,sudokuchange,change,cv::Size(450,450));
    cv::imwrite("../results/sudoku_corrected.png",sudokuchange);
    return 0;
}
