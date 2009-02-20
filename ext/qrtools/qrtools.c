#include <qrtools.h>

VALUE mQRTools;

void Init_qrtools()
{
  VALUE qrtools = rb_define_module("QRTools");
  mQRTools = qrtools;

  init_qrtools_image();
  init_qrtools_decoder();
  init_qrtools_header();
  init_qrtools_ui_camera();
  init_qrtools_ui_window();
  init_qrtools_encoder();
}
