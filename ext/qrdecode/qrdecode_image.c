#include <qrdecode_image.h>

static void dealloc(IplImage * img)
{
  cvReleaseImage(&img);
}

static VALUE load(VALUE klass, VALUE path)
{
  IplImage *src = cvLoadImage(StringValuePtr(path), 1);
  return Data_Wrap_Struct(klass, NULL, dealloc, src);
}

void init_qrdecode_image()
{
  VALUE qrdecode  = rb_define_module("QRDecode");
  VALUE image     = rb_define_class_under(qrdecode, "Image", rb_cObject);

  rb_define_singleton_method(image, "load", load, 1);
}
