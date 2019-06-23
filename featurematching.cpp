#include "featurematching.h"

#include "QtDebug"
#include <list>
#include <iostream>

#include<sstream>

using namespace cv;
using namespace cv::xfeatures2d;
using namespace std;

FeatureMatching::FeatureMatching()
{
    try {
        settingDialog = new SettingDialog(true);
        int nFeatures = settingDialog->getNfeatures();
        int nOctaveLayers = settingDialog->getNOctaveLayers();
        double contrastThreshold = settingDialog->getContrastThreshold();
        double edgeThreshold = settingDialog->getEdgeThreshold();
        double sigma = settingDialog->getSigma();
        img = imread(settingDialog->getFileName().toStdString());
        if(!img.empty()){
            cvtColor(img, img, COLOR_BGR2GRAY);
            sift = SIFT::create(nFeatures, nOctaveLayers, contrastThreshold, edgeThreshold, sigma);
            sift->detectAndCompute(img, noArray(),kpSift, model_des_list);
            flann = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
        }
    } catch (...) {
        if(img.empty()){
            cout << "Can not read feature image file.\n";
        }
    }
}

FeatureMatching::FeatureMatching(const vector<Point> points)
{
    try {
        settingDialog = new SettingDialog(true);
        int nFeatures = settingDialog->getNfeatures();
        int nOctaveLayers = settingDialog->getNOctaveLayers();
        double contrastThreshold = settingDialog->getContrastThreshold();
        double edgeThreshold = settingDialog->getEdgeThreshold();
        double sigma = settingDialog->getSigma();
        maskedPoints = points;
        img = imread(settingDialog->getFileName().toStdString());
        if(!img.empty()){
            cvtColor(img, img, COLOR_BGR2GRAY);
            sift = SIFT::create(nFeatures, nOctaveLayers, contrastThreshold, edgeThreshold, sigma);
            sift->detectAndCompute(img, noArray(), kpSift, model_des_list);
            flann = DescriptorMatcher::create(DescriptorMatcher::FLANNBASED);
        }
    } catch (...) {
        if(img.empty()){
            cout << "Can not read feature image file.\n";
        }
    }
}

Mat FeatureMatching::process(Mat cvFrame,long int frameCount, bool isShowMaskRegion, SettingDialog *settingDialog, int fps){

    if(settingDialog->getIsSaveSnapshot()){
        saveToAllSnapshot(cvFrame);
    }
    Mat image_frame = cvFrame.clone();
    Mat image_crop;

    alert = false;

    if(!maskedPoints.empty()){
        image_crop = maskImage(image_frame);
    }else{
        image_crop = cvFrame.clone();
        cvtColor(image_crop, image_crop, COLOR_BGR2GRAY);
    }

    if(isShowMaskRegion){
        imshow("Masked Region", image_crop);
    }

    vector<cv::KeyPoint> present_kp_list;
    cv::Mat present_des_list;

    if(frameCount == 0){
        previous_image_frame = image_crop.clone();
    }

    try {
        sift->detectAndCompute(image_crop, noArray(), present_kp_list, present_des_list);
    } catch (...) {
        cout << "Can't Detect Present Frame.";
    }

    vector< vector<DMatch> > present_matches;
    if(frameCount != 0){
        if(!previous_des_list.empty()){
            try {
                flann->knnMatch( previous_des_list, present_des_list, present_matches, 2);
            } catch (...) {
                cout << "Can't knn match between previous_des and present_des";
            }
        }
    }

    Mat image_alert = cvFrame.clone();
    try {
        for (unsigned int i = 0; i < present_matches.size(); i++){
            DMatch m = present_matches[i][0];
            DMatch n = present_matches[i][1];

            KeyPoint present_kp_m = present_kp_list[m.trainIdx];
            KeyPoint present_kp_n = present_kp_list[n.trainIdx];

            Mat present_des_m = present_des_list.row(m.trainIdx);
            Mat present_des_n = present_des_list.row(n.trainIdx);

            Point2f present_pos_m = present_kp_m.pt;
            Point2f present_pos_n = present_kp_n.pt;

            long int present_time = frameCount;

            present_good_feature_list.push_back(m);

            try {
                vector<unsigned int>::iterator it_m = find(current_index_list.begin(), current_index_list.end(), m.trainIdx);
                vector<unsigned int>::iterator it_n = find(current_index_list.begin(), current_index_list.end(), n.trainIdx);
                if(it_m != current_index_list.end()){
                    for(auto &i : current_pos_list){
                        if(get<0>(i) == m.trainIdx){
                            if(abs(get<1>(i).x-present_pos_m.x) > settingDialog->getMoveThreshold() || abs(get<1>(i).y - present_pos_m.y) > settingDialog->getMoveThreshold()){
                                for (unsigned int index = 0; index < current_kp_list.size(); index++) {
                                    if(get<3>(i).pt == current_kp_list[index].pt){
                                        current_kp_list[index] = present_kp_m;
                                        present_kp_list[m.trainIdx].pt = present_kp_list[m.trainIdx].pt;

                                        get<1>(i) = present_kp_list[m.trainIdx].pt;
                                        get<2>(i) = present_time;
                                    }
                                }
                            }else{
                                if(settingDialog->getIsUsingFrame()){
                                    if(abs(get<2>(i) - present_time) >= settingDialog->getFrameSleep()){
                                        sleepCount++;
                                        int tempCount = 0;
                                        for (unsigned int index=0;index<alert_list.size();index++) {
                                            if(alert_list[index].pt == present_kp_list[m.trainIdx].pt){
                                                tempCount++;
                                            }
                                        }
                                        if(tempCount != 0){
                                            total_alert++;
                                        }else{
                                            alert_list.push_back(present_kp_m);
                                            total_alert++;
                                            sleepCount++;
                                        }
                                    }
                                }
                                if(settingDialog->getIsUsingTime()){
                                    if(ceil((abs(get<2>(i) - present_time)/fps)/60) >= settingDialog->getTimeSleep()){
                                        sleepCount++;
                                        int tempCount = 0;
                                        for (unsigned int index=0;index<alert_list.size();index++) {
                                            if(alert_list[index].pt == present_kp_list[m.trainIdx].pt){
                                                tempCount++;
                                            }
                                        }
                                        if(tempCount != 0){
                                            total_alert++;
                                        }else{
                                            alert_list.push_back(present_kp_m);
                                            total_alert++;
                                            sleepCount++;
                                        }
                                    }
                                }

                            }

                        }
                    }

                }
                if(it_n != current_index_list.end()){
                    for(auto &i : current_pos_list){
                        if(get<0>(i) == n.trainIdx){
                            if(abs(get<1>(i).x-present_pos_n.x) > settingDialog->getMoveThreshold() || abs(get<1>(i).y - present_pos_n.y) > settingDialog->getMoveThreshold()){
                                for (unsigned int index = 0; index < current_kp_list.size(); index++) {
                                    if(get<3>(i).pt == current_kp_list[index].pt){
                                        current_kp_list[index] = present_kp_n;
                                        present_kp_list[n.trainIdx].pt = present_kp_list[n.trainIdx].pt;

                                        get<1>(i) = present_kp_list[n.trainIdx].pt;
                                        get<2>(i) = present_time;
                                    }
                                }
                            }else{
                                if(settingDialog->getIsUsingFrame()){
                                    if(abs(get<2>(i) - present_time) >= settingDialog->getFrameSleep()){
                                        sleepCount++;
                                        int tempCount = 0;
                                        for (unsigned int index=0;index<alert_list.size();index++) {
                                            if(alert_list[index].pt == present_kp_list[n.trainIdx].pt){
                                                tempCount++;
                                            }
                                        }
                                        if(tempCount != 0){
                                            total_alert++;
                                        }else{
                                            alert_list.push_back(present_kp_n);
                                            total_alert++;
                                            sleepCount++;
                                        }
                                    }
                                }
                                if(settingDialog->getIsUsingTime()){
                                    if(ceil((abs(get<2>(i) - present_time)/fps)/60) >= settingDialog->getTimeSleep()){
                                        sleepCount++;
                                        int tempCount = 0;
                                        for (unsigned int index=0;index<alert_list.size();index++) {
                                            if(alert_list[index].pt == present_kp_list[n.trainIdx].pt){
                                                tempCount++;
                                            }
                                        }
                                        if(tempCount != 0){
                                            total_alert++;
                                        }else{
                                            alert_list.push_back(present_kp_n);
                                            total_alert++;
                                            sleepCount++;
                                        }
                                    }
                                }
                            }

                        }
                    }
                }
                if(it_m == current_index_list.end()){
                    current_index_list.push_back(m.trainIdx);
                    current_kp_list.push_back(present_kp_list[m.trainIdx]);
                    current_pos_list.push_back(make_tuple(m.trainIdx, present_pos_m, present_time, present_kp_m));
                }
                if(it_n == current_index_list.end()){
                    current_index_list.push_back(n.trainIdx);
                    current_kp_list.push_back(present_kp_list[n.trainIdx]);
                    current_pos_list.push_back(make_tuple(n.trainIdx, present_pos_n, present_time, present_kp_n));
                }
            } catch (...) {
                cout << "Sad!!!!";
            }

        }
    } catch (...) {
        cout<<"\nException occur.1";
    }
    if(sleepCount >= settingDialog->getSleepThreshold() && alert_list.size() >= settingDialog->getSleepThreshold()){
        Mat alertImg = imread("./alert image/alertpic.png");
        if(!alertImg.empty()){
            cv::Rect myROI(170, image_alert.size().height/2-90, 350, 200);
            resize(alertImg, alertImg, Size(350, 200));
            alertImg.copyTo(image_alert(myROI));
        }

        alert = true;
        if(settingDialog->getIsSaveAlertSnapshot()){
            saveToAlertSnapshot(image_alert);
        }
        cvFrame = image_alert.clone();
    }
    sleepCount = 0;

    alert_list.clear();

    std::vector< std::vector<DMatch> > model_matches;
    try {
        if(!model_des_list.empty() && !present_des_list.empty()){
            flann->knnMatch( model_des_list, present_des_list, model_matches, 2);
        }

    } catch (...) {
        cout<<"\nException occur.2";
    }

    try {

        for(unsigned int i=0; i<model_matches.size();i++ ){
            DMatch m = model_matches[i][0];
            DMatch n = model_matches[i][1];

            KeyPoint present_kp_m = present_kp_list[m.trainIdx];
            KeyPoint present_kp_n = present_kp_list[n.trainIdx];

            Mat present_des_m = present_des_list.row(m.trainIdx);
            Mat present_des_n = present_des_list.row(n.trainIdx);

            Point2f present_pos_m = present_kp_m.pt;
            Point2f present_pos_n = present_kp_n.pt;

            long int present_time = frameCount;

            try {
                vector<unsigned int>::iterator it_m = find(current_index_list.begin(), current_index_list.end(), m.trainIdx);
                vector<unsigned int>::iterator it_n = find(current_index_list.begin(), current_index_list.end(), n.trainIdx);

                if(it_m != current_index_list.end() && it_n != current_index_list.end()){
                    continue;
                }
                if(it_m == current_index_list.end()){
                    new_kp_list.push_back(present_kp_m);
                    current_index_list.push_back(m.trainIdx);
                    current_kp_list.push_back(present_kp_list[m.trainIdx]);

                    current_pos_list.push_back(make_tuple(m.trainIdx, present_pos_m, present_time, present_kp_list[m.trainIdx]));
                }
                if(it_n == current_index_list.end()){
                    new_kp_list.push_back(present_kp_n);
                    current_index_list.push_back(n.trainIdx);
                    current_kp_list.push_back(present_kp_list[n.trainIdx]);

                    current_pos_list.push_back(make_tuple(n.trainIdx, present_pos_n, present_time, present_kp_list[n.trainIdx]));
                }
            } catch (...) {
                cout << "Can't Iterator to check element is in list";
            }
        }

    } catch (...) {
        cout<<"\nException occur.3";
    }

    Mat draw_new_found_kp_image = image_frame.clone();
    Mat draw_all_kp_image = image_frame.clone();
    new_kp_image = image_frame;

    try {
        drawKeypoints(image_frame, present_kp_list, draw_new_found_kp_image, Scalar(0,0,255));
        if(settingDialog->getIsShowFeatureDetected()){
            imshow("Feature Detected", draw_new_found_kp_image);
        }
        if(settingDialog->getIsSaveKeypointSanpshot()){
            saveToKeypointSnapshot(draw_new_found_kp_image);
        }
    } catch (...) {
        cout << "Can't draw all kp image";
    }

    if(settingDialog->getIsShowFeatureMatchingResult()){
        Mat img_matches;
        try {
            drawMatches( img, kpSift, image_crop, present_kp_list, present_good_feature_list, img_matches, Scalar::all(-1),
                         Scalar::all(-1), std::vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );
            imshow("Matches Image", img_matches);
        } catch (...) {
            cout << "Can't draw matches.";
        }
    }

    try {
        present_good_feature_list.clear();


        model_matches.clear();
        present_matches.clear();

        previous_kp_list = present_kp_list;
        previous_des_list = present_des_list;

        previous_time = present_time;

        present_kp_list.clear();
        present_pos_list.clear();

        ct++;
    } catch (...) {
        cout<<"\nException occur.8";
    }

    putText(cvFrame, std::to_string(frameCount), Point(cvFrame.size().width-60,40), FONT_HERSHEY_COMPLEX, 0.5, Scalar(0, 255, 0), 0);

    return cvFrame;
}

Mat FeatureMatching::maskImage(Mat frame)
{
    cvtColor(frame, frame, COLOR_BGR2GRAY);

    Mat mask(frame.size(),CV_8UC1);
    mask = 0;

    vector<vector<Point> > contours;
    contours.push_back(maskedPoints);

    drawContours(mask,contours,0,Scalar(255),-1);

    cv::bitwise_and(frame, mask, frame);

    Mat maskedFrame = frame.clone();

    return maskedFrame;
}

void FeatureMatching::saveToAllSnapshot(Mat frame)
{
    stringstream ss;

    string name = "frame_";
    string type = ".png";

    ss<<name<<(ct + 1)<<type;

    string filename = ss.str();
    ss.str("");

    string folderName = "all snapshot";

    ss<<folderName<<"/"<<name<<(ct + 1)<<type;

    string fullPath = ss.str();
    ss.str("");

    imwrite(fullPath, frame);
}

void FeatureMatching::saveToAlertSnapshot(Mat frame)
{
    stringstream ss;

    string name = "frame_";
    string type = ".png";

    ss<<name<<(ct + 1)<<type;

    string filename = ss.str();
    ss.str("");

    string folderName = "alert snapshot";

    ss<<folderName<<"/"<<name<<(ct + 1)<<type;

    string fullPath = ss.str();
    ss.str("");

    imwrite(fullPath, frame);
}

void FeatureMatching::saveToKeypointSnapshot(Mat frame)
{
    stringstream ss;

    string name = "frame_";
    string type = ".png";

    ss<<name<<(ct + 1)<<type;

    string filename = ss.str();
    ss.str("");

    string folderName = "keypoint snapshot";

    ss<<folderName<<"/"<<name<<(ct + 1)<<type;

    string fullPath = ss.str();
    ss.str("");

    imwrite(fullPath, frame);
}

bool FeatureMatching::isAlert()
{
    if(alert){
        return true;
    }
    return false;

}
