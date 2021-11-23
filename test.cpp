#include<iostream>
#include<string>
#include<sstream>
#include<opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/videoio.hpp> 
using namespace cv;
using namespace std;

VideoCapture Cam1 ;
const int  weigth = 1920;
const int height = 1080;
static Mat input_image;

void readimg(Mat img){
	//string file_name = "./screen.jpg";
	//Mat img;
	//img = imread(file_name);
	int sum=0;
	int x,y,z;
	for (int i=0;i<img.rows;i++){
		for(int j=0;j<img.cols;j++){
			x = img.at<Vec3b>(i,j)[0];
			y = img.at<Vec3b>(i,j)[1];
			z = img.at<Vec3b>(i,j)[2];
			sum += (x+y+z);
			if (sum) break;
		}
	}
	if (sum) cout<<"not zeros and sum is "<<sum<<endl;
	else cout<<"zeros"<<endl;
}
void SetCam2(int width, int height ,int num){
	/*
	 *test cam on and release repeatly
	 * */

	string a = "0";
	string Error;

	int i = 0;
	while (true){
	

		Cam1.open(0);
		/*设定缓冲区大小*/
		// Cam1.set(CAP_PROP_FRAME_WIDTH, width);
		// Cam1.set(CAP_PROP_FRAME_HEIGHT, height);
		for(auto i=0;i<8;i++) Cam1 >> input_image;//将影像传入图片
		
		Cam1.release();
		readimg(input_image);
		// imshow("video",input_image);
		stringstream ss;
		ss<<i<<"test.jpg";
		//auto name = string(i) + "test.jpg";
		imwrite(ss.str(),input_image);
//                      break;
		waitKey(3000);
		i++;
	
	}
}
void SetCam(int weigth, int height, int num)
{


	string a = "0";
	string Error;
	VideoCapture Cam(0);
	/*设定缓冲区大小*/
	//Cam.set(CAP_PROP_FRAME_WIDTH, weigth);
	//Cam.set(CAP_PROP_FRAME_HEIGHT, height);

	while (!Cam.isOpened())
	{
		
		a = to_string(num);
		Error = "cannot open the camera1!";
		Error = Error.replace(22, 1, a);
		//Error.copy(error, 24, 0);//这里5代表复制几个字符，0代表复制的位置，
	}
	
	//namedWindow("摄像头");//关键一句代码

		//Cam>>input_image;
		//waitKey(1000);
	int i = 0;	
	
	while (true) {
	//	waitKey(1000);
		Cam >> input_image;//将影像传入图片
		//imshow("video",input_image);
	//	waitKey(1);
		stringstream ss;
		ss<<i<<"test.jpg";
		//auto name = string(i) + "test.jpg";
		imwrite(ss.str(),input_image);
//			break;
		waitKey(1000);
		i++;
	}

	Cam.release();
//	return 0;

}



int main()
{
	//char* error = "error";
	SetCam(weigth, height, 10);
	//readimg();
	
	return 0;
}
