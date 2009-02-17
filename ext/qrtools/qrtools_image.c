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

static VALUE save(VALUE self, VALUE path)
{
  IplImage * src;
  Data_Get_Struct(self, IplImage, src);
  cvSaveImage(StringValuePtr(path), src);
  return self;
}

VALUE QRTools_Wrap_Image(IplImage * image)
{
  return Data_Wrap_Struct(cQRToolsImage, NULL, dealloc, image);
}

VALUE cQRToolsImage;

void init_qrtools_image()
{
  VALUE qrtools  = rb_define_module("QRTools");
  VALUE klass    = rb_define_class_under(qrtools, "Image", rb_cObject);

  cQRToolsImage = klass;

  rb_define_singleton_method(klass, "load", load, 1);
  rb_define_method(klass, "save", save, 1);
}
