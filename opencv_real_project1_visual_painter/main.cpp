#include"opencv_project1.h"

vector<vector<int>> mycolors{ {97,169,86,179,255,255,},//deep blue
							 {170,79,64,179,255,255,} };//red,需要检测的颜色

vector<Scalar> mycolorvalues{ {255,0,255},//purple
							   {0,255,0} };//green    检测到以后显示出的颜色

void find_color(Mat img)
{

	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	for (int i = 0; i < mycolors.size(); i++)
	{
		Scalar lower(mycolors[i][0], mycolors[i][1], mycolors[i][2]);//i=0-1,相当于行数，后面一个是具体元素中位置数
		Scalar upper(mycolors[i][3], mycolors[i][4], mycolors[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);//一个颜色需要一个蒙版，因此在这里创建一个向量是最简单的方法 
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