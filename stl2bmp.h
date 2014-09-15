/*******************************************************
E-mail:brainfvck@foxmail.com
Author:chenshaohan




********************************************************/


#ifndef STL2BMP_H
#define STL2BMP_H

#ifdef stl2bmp_EXPORTS //cbs.dll export function  
#define STL2BMP_API __declspec(dllexport)
#else
#define STL2BMP_API
#endif

#ifdef __cplusplus
extern "C" {
#endif
	

	class stl2bmp{
	public:
		stl2bmp(const char* fileName,int width,int height,double pixelsize_um,double stepZ);
		~stl2bmp();
		char* get_one_bmp();

	private:
		bool stl2slc(const char* input, char* output, int width,int height,
			double pixelsize_um,double height_layer);
		bool slc2bmps(const char* input,int width,int height,
			double pixelsize_um);

	private:

		void * pEdit;
		
		
		unsigned char* pImageData;
	};


#ifdef __cplusplus
}
#endif

#endif //STL2BMP_H