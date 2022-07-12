#pragma once

#include <opencv2/core.hpp>
#include "kalman_filter.h"

class Track {
public:
    // Constructor
    Track();

    // Destructor
    ~Track() = default;

    void Init(const cv::Vec6i& bbox);
    void Predict();
    void Update(const cv::Rect& bbox);
    cv::Rect GetStateAsBbox() const;
    float GetNIS() const;

    int coast_cycles_ = 0, hit_streak_ = 0;
    int confidence = -1;
    int obj_type = -1;

private:
    Eigen::VectorXd ConvertBboxToObservation(const cv::Rect& bbox) const;
    cv::Rect ConvertStateToBbox(const Eigen::VectorXd &state) const;

    KalmanFilter kf_;
};

cv::Rect convert_single_rect(const cv::Vec6i& detail_detections);