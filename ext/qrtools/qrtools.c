#include <qrtools.h>

VALUE mQRTools;

void Init_qrtools()
{
  VALUE qrtools = rb_define_module("QRTools");
  mQRTools = qrtools;

  init_qrtools_image();
  init_qrtools_decoder();
}
