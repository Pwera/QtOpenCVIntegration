#include "mainwindow.h"
#include <QApplication>
#include <opencv2/videoio.hpp> 
using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
	 VideoCapture inputVideo();  
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
