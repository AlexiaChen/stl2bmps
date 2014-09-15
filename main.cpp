// stl2svg.cpp : Defines the entry point for the console application.
//

#include<QApplication>
#include<QString>
#include<QImage>
#include<QColor>
#include "stl2bmp.h" // an interface used to stl file convert into bmp files

//#pragma comment(lib, "CORE_RL_wand_.lib")
//#pragma comment(lib, "X11.lib")
//#pragma comment(lib, "CORE_RL_magick_.lib")
#//pragma comment(lib, "CORE_RL_Magick++_.lib")

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	
	
	
	QString input_stl = "C:\\Users\\Yajun Dou\\Desktop\\Qt_Test\\QtTest\\QtTest\\temp\\mypistol.stl";
	QString output_slc = "C:\\Users\\Yajun Dou\\Desktop\\Qt_Test\\QtTest\\QtTest\\temp\\output.slc";
	
	if(!stl2slc(input_stl,output_slc,0.25))
	{
	    printf("stl2slc failed\n");
	}

	if(slc2bmps(output_slc,"D:\\temp"))
	{
		printf("Exporting Bmps Completely!\n");
	}
	

	return app.exec();
}

