#include <qrtools_header.h>

static VALUE model(VALUE self)
{
  QrCodeHeader * header;
  Data_Get_Struct(self, QrCodeHeader, header);
  return INT2NUM(header->model);
}

static VALUE version(VALUE self)
{
  QrCodeHeader * header;
  Data_Get_Struct(self, QrCodeHeader, header);
  return INT2NUM(header->version);
}

static VALUE level(VALUE self)
{
  QrCodeHeader * header;
  Data_Get_Struct(self, QrCodeHeader, header);
  return INT2NUM(header->level);
}

static VALUE character_size(VALUE self)
{
  QrCodeHeader * header;
  Data_Get_Struct(self, QrCodeHeader, header);
  return INT2NUM(header->charactor_size);
}

static VALUE byte_size(VALUE self)
{
  QrCodeHeader * header;
  Data_Get_Struct(self, QrCodeHeader, header);
  return INT2NUM(header->byte_size);
}

VALUE cQRToolsHeader;
void init_qrtools_header()
{
  VALUE qrtools  = rb_define_module("QRTools");
  VALUE klass    = rb_define_class_under(qrtools, "Header", rb_cObject);

  cQRToolsHeader = klass;

  rb_define_method(klass, "model", model, 0);
  rb_define_method(klass, "version", version, 0);
  rb_define_method(klass, "level", level, 0);
  rb_define_method(klass, "character_size", character_size, 0);
  rb_define_method(klass, "byte_size", byte_size, 0);
}
