#include <qrtools_qrcode.h>

static width(VALUE self)
{
  QRcode * code;
  Data_Get_Struct(self, QRcode, code);
  return NUM2INT(code->width);
}

VALUE cQRToolsQRCode;
void init_qrtools_qrcode()
{
  VALUE qrtools = rb_define_module("QRTools");
  VALUE klass   = rb_define_class_under(qrtools, "QRCode", rb_cObject);

  cQRToolsQRCode = klass;

  rb_define_method(klass, "width", width, 0);
}
