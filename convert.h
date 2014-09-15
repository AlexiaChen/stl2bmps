#ifndef CONVERT_H
#define CONVERT_H
#include <QImage>

void convert2gray_8bit(QImage* input, char* pOut);
void convert2gray_16bit(QImage* input, short* pOut);

#endif