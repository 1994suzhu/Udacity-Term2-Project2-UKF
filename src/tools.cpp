#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {

	//I think I need to change dimensions here to calculate the rmse
	using std::cout;
	
	VectorXd rmse(4);
	rmse << 0, 0, 0, 0;
	if (estimations.size() != ground_truth.size() && estimations.size() == 0) {
		cout << "Invalid estimation or ground_truth data" << endl;
		return rmse;
	}
	//cout << "accumulate squared residuals" << endl;
	//accumulate squared residuals
	for (unsigned int i = 0; i < estimations.size(); ++i) {
		// ... your code here
		VectorXd r;
		r = estimations[i] - ground_truth[i];
		r = r.array()*r.array();
		rmse = rmse + r;
	}
	//cout << "calculate the mean " << endl;
	//calculate the mean
	// ... your code here
	rmse = rmse / estimations.size();

	//calculate the squared root
	// ... your code here
	//cout << "squared root calculation " << endl;
	rmse = rmse.array().sqrt();
	//return the result
	cout << rmse << endl;
	return rmse;
}
