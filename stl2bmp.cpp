#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

#include <QDebug>
#include <QFile>
#include <QString>

#include "stl2bmp.h"
#include "b9layoutprojectdata.h"
#include "b9edit.h"



//B9Edit edit_obj;
//B9Edit* pEdit;

 bool stl2bmp::stl2slc(const char* input, char* output, int width,int height,double pixelsize_um,double height_layer)
{
	

	
	B9Layout layout;
	B9ModelInstance* pInst= NULL;

	pInst = layout.AddModel(QString(QLatin1String(input)),false);

	if(pInst == NULL)
	{
	   printf("cannot AddModel!\n");
	   return false;
	}


	
	 B9LayoutProjectData proj_data(&layout);
	
	proj_data.Save("D:\\temp.b9l",width,height,pixelsize_um);
	
	if(!proj_data.Open("D:\\temp.b9l",false))
	{
	   printf("Open failed!\n");
	   return false;
	}

	if(!layout.SliceWorld(QString(QLatin1String(output)),height_layer))
	{
		printf("SliceWorld failed!\n");
		return false;
	}

	return true;
}

 bool stl2bmp::slc2bmps(const char* input,int width,int height,double pixelsize_um)
{
	
	
	//B9Edit edit_obj;

	pEdit = new B9Edit;

	((B9Edit*)(pEdit))->setImageSize(width,height);

	((B9Edit*)(pEdit))->importSlices(QString(QLatin1String(input)),pixelsize_um);

	//((B9Edit*)(pEdit))->ExportToFolder(QString(QLatin1String(output)));


	return true;
}

stl2bmp::stl2bmp(const char* fileName,int width,int height,double pixelsize_um,double stepZ){

	//pEdit = new B9Edit;
	//pImageData = NULL;
	
	if(!stl2slc(fileName,"D:\\output.slc",width,height,pixelsize_um,stepZ))
	{
		printf("stl2slc failed\n");
	}

	if(slc2bmps("D:\\output.slc",width,height,pixelsize_um))
	{
		printf("Exporting Bmps Completely!\n");
	}

}


stl2bmp::~stl2bmp(){
	
	delete pEdit;
}

char* stl2bmp::get_one_bmp(){

	char* pRet = NULL;
	
	pRet = (char*)((B9Edit*)(pEdit)) ->get_one_bmp_private();
	
	if(pRet == NULL)
	  return NULL;

	return (char*)pRet;
	

}


