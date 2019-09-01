#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

template <typename _t>
void LBP(inputarry _src,outputarry _dst)
{
  Mat src = _src.getMat();
  _dst.creat(src.rows-2,src.cols-2,CV_8UC1);
  Mat dst = _dst.getMat();
  dst.setTo(0);
  for (int i = 1; i < src.rows - 1; i++)
	{
		for (int j = 1; j < src.cols - 1; j++)
		{
			_tp center = src.at<_tp>(i, j);
			unsigned char lbpCode = 0;
			lbpCode |= (src.at<_tp>(i - 1, j - 1) > center) << 7;
			lbpCode |= (src.at<_tp>(i - 1, j) > center) << 6;
			lbpCode |= (src.at<_tp>(i - 1, j + 1) > center) << 5;
			lbpCode |= (src.at<_tp>(i, j + 1) > center) << 4;
			lbpCode |= (src.at<_tp>(i + 1, j + 1) > center) << 3;
			lbpCode |= (src.at<_tp>(i + 1, j) > center) << 2;
			lbpCode |= (src.at<_tp>(i + 1, j - 1) > center) << 1;
			lbpCode |= (src.at<_tp>(i, j - 1) > center) << 0;
			dst.at<uchar>(i - 1, j - 1) = lbpCode;
		}
	}
}
