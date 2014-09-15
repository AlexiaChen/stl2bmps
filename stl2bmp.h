/*******************************************************

 Copyright (C) 2013-2014 by AlexiaChen at Michgen State University
 All rights reserved 
 
 Redistribution and use in source and binary forms, with or without modification, 
 are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright
	notice, this list of conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice, 
    this list of conditions and the following disclaimer in the documentation and/or other 
     materials provided with the distribution.
 
 3. Neither the name of the project nor the names of its contributors may be used to endorse or promote products derived from this software
    without specific prior written permission.
		   
		   
  THIS SOFTWARE IS PROVIDED BY THE PROJECT AND CONTRIBUTORS ``AS IS'' AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED.  IN NO EVENT SHALL THE PROJECT OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
  OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
			  
  HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
  OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
			     
		
@author:AlexiaChen

@brief:This file is an interface of the library.




********************************************************/


#ifndef STL2BMP_H
#define STL2BMP_H

#ifdef stl2bmp_EXPORTS //dll export function  
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
