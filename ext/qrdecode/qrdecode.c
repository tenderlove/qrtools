#include <qrdecode.h>

VALUE mQRDecode;

void Init_qrdecode()
{
  VALUE qrdecode = rb_define_module("QRDecode");
  mQRDecode = qrdecode;

  init_qrdecode_image();
}
