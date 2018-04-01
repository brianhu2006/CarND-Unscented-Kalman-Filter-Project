#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  /**
  TODO:
    * Calculate the RMSE here.
  */

    VectorXd rmse(4);
    rmse << 0,0,0,0;

    // TODO: YOUR CODE HERE

    // check the validity of the following inputs:
    //  * the estimation vector size should not be zero
    //  * the estimation vector size should equal ground truth vector size
    // ... your code here
    if(estimations.size()==0)
    {
        std::cout<<"estimation size should not be zero"<<std::endl;
        return rmse;
    }
    if(estimations.size()!=ground_truth.size())
    {
        std::cout<<"estimation size should equal to ground_truth size"<<std::endl;
        return rmse;
    }

    //accumulate squared residuals
    VectorXd s(4);
    s<<0,0,0,0;
    for(int i=0; i < estimations.size(); ++i){
        // ... your code here
        VectorXd resid=estimations[i]-ground_truth[i];
        // cout<<"resid"<<resid<<endl;
        //cout<<"resid array"<<resid.array()<<endl;


        resid=resid.array()*resid.array();
        s+=resid;

    }

    //calculate the mean
    // ... your code here
    VectorXd mean=s/estimations.size();
    //calculate the squared root
    // ... your code here
    rmse=mean.array().sqrt();
    //return the result
    return rmse;
}

float normalize(float angle) {
    while (angle> M_PI) angle-=2.*M_PI;
    while (angle<-M_PI) angle+=2.*M_PI;
    return angle;
}