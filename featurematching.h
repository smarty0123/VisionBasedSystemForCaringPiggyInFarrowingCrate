#ifndef FEATUREMATCHING_H
#define FEATUREMATCHING_H

#include "opencv2/xfeatures2d.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/highgui/highgui.hpp>
#undef max
#include <vector>
#include <tuple>
#include <algorithm>

#include <bits/stdc++.h>
#include <utility>

#include "settingdialog.h"

class FeatureMatching
{
public:
    FeatureMatching();
    FeatureMatching(std::vector<cv::Point> points);
    cv::Mat process(cv::Mat cvFrame,long int frameCount, bool isShowMaskRegion, SettingDialog *settingDialog, int fps);
    cv::Mat maskImage(const cv::Mat cvFrame);

    void saveToAllSnapshot(cv::Mat frame);
    void saveToAlertSnapshot(cv::Mat frame);
    void saveToKeypointSnapshot(cv::Mat frame);

    bool isAlert();


private:

    cv::Mat img, cvFrame, previous_image_frame, new_kp_image;

    cv::Ptr<cv::xfeatures2d::SIFT> sift;

    std::vector<cv::KeyPoint> kpSift, previous_kp_list, current_kp_list;

    cv::Mat model_des_list, previous_des_list, current_des_list;

    std::vector<cv::Point2f> previous_pos_list, present_pos_list;

    std::vector<std::tuple<unsigned int, cv::Point2f, long int, cv::KeyPoint>> current_pos_list;

    long int previous_time, present_time;

    std::vector<long int> current_time_list;

    std::vector<unsigned int> current_index_list;

    std::vector<cv::DMatch> previous_good_feature_list = {};

    std::vector<cv::DMatch> present_good_feature_list = {};

    std::vector<cv::DMatch> model_good_feature_list = {};

    std::vector<cv::KeyPoint> new_kp_list;

    bool alert = false;

    cv::Ptr<cv::DescriptorMatcher> flann;

    int sleepCount = 0;

    std::vector<cv::Point> maskedPoints;

    SettingDialog *settingDialog;

    int ct = 0;

    std::vector<cv::KeyPoint> alert_list;

    int total_alert = 0;
};

#endif // FEATUREMATCHING_H
