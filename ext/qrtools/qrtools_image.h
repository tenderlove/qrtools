#ifndef QRTOOLS_IMAGE
#define QRTOOLS_IMAGE

#include <qrtools.h>

extern VALUE cQRToolsImage;

void init_qrtools_image();
VALUE QRTools_Wrap_Image(IplImage * image);

#endif
