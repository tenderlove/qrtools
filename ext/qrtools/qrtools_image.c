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

/*
 * call-seq:
 *  native_draw_line(from, to, r, g, b, thickness, type, shift)
 *
 * Draw line from +from+ vertex to +to+ vertex
 */
static VALUE native_draw_line(
    VALUE self,
    VALUE _from,
    VALUE _to,
    VALUE _r,
    VALUE _g,
    VALUE _b,
    VALUE _thickness,
    VALUE _type,
    VALUE _shift
) {
  IplImage * src;
  Data_Get_Struct(self, IplImage, src);
  cvLine(
      src,
      cvPoint(
        NUM2INT(rb_funcall(_from, rb_intern("x"), 0)),
        NUM2INT(rb_funcall(_from, rb_intern("y"), 0))
      ),
      cvPoint(
        NUM2INT(rb_funcall(_to, rb_intern("x"), 0)),
        NUM2INT(rb_funcall(_to, rb_intern("y"), 0))
      ),
      CV_RGB(
        NUM2INT(_r),
        NUM2INT(_g),
        NUM2INT(_b)
      ),
      NUM2INT(_thickness),
      NUM2INT(_type),
      NUM2INT(_shift)
  );
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
  rb_define_method(klass, "native_draw_line", native_draw_line, 8);
}
