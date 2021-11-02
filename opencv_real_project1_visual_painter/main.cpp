#include"opencv_project1.h"

vector<vector<int>> mycolors{ {97,169,86,179,255,255,},//deep blue
							 {170,79,64,179,255,255,} };//red,��Ҫ������ɫ

vector<Scalar> mycolorvalues{ {255,0,255},//purple
							   {0,255,0} };//green    ��⵽�Ժ���ʾ������ɫ

void find_color(Mat img)
{

	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	for (int i = 0; i < mycolors.size(); i++)
	{
		Scalar lower(mycolors[i][0], mycolors[i][1], mycolors[i][2]);//i=0-1,�൱������������һ���Ǿ���Ԫ����λ����
		Scalar upper(mycolors[i][3], mycolors[i][4], mycolors[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);//һ����ɫ��Ҫһ���ɰ棬��������ﴴ��һ����������򵥵ķ��� 
		imshow(to_string(i), mask);
	}


}


void main()
{
	VideoCapture cap(0);
    Mat img,imgHSV;
	while (true)
	{
		cap.read(img);

		find_color(img);
		imshow("img", img);
		waitKey(1);
	}

}