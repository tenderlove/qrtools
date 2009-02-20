#include <qrtools_qrcode.h>

static VALUE width(VALUE self)
{
  QRcode * code;
  Data_Get_Struct(self, QRcode, code);
  return INT2NUM(code->width);
}

static VALUE version(VALUE self)
{
  QRcode * code;
  Data_Get_Struct(self, QRcode, code);
  return INT2NUM(code->version);
}

static VALUE data(VALUE self)
{
  QRcode * code;
  Data_Get_Struct(self, QRcode, code);

  return rb_str_new(code->data, code->width * code->width);
}

VALUE cQRToolsQRCode;
void init_qrtools_qrcode()
{
  VALUE qrtools = rb_define_module("QRTools");
  VALUE klass   = rb_define_class_under(qrtools, "QRCode", rb_cObject);

  cQRToolsQRCode = klass;

  rb_define_method(klass, "width", width, 0);
  rb_define_method(klass, "version", version, 0);
  rb_define_method(klass, "data", data, 0);
}
