#include <qrtools_image.h>

static void dealloc(IplImage * img)
{
  cvReleaseImage(&img);
}

static VALUE load(VALUE klass, VALUE path)
{
  IplImage *src = cvLoadImage(StringValuePtr(path), 1);
  return Data_Wrap_Struct(klass, NULL, dealloc, src);
}

VALUE cQRToolsImage;

void init_qrtools_image()
{
  VALUE qrtools  = rb_define_module("QRTools");
  VALUE klass    = rb_define_class_under(qrtools, "Image", rb_cObject);

  cQRToolsImage = klass;

  rb_define_singleton_method(klass, "load", load, 1);
}
