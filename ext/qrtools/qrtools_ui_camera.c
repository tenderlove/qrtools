#include <qrtools_ui_camera.h>

static void deallocate(CvCapture * capture)
{
  if(capture) cvReleaseCapture(&capture);
}

static VALUE allocate(VALUE klass)
{
  return Data_Wrap_Struct(klass, NULL, deallocate, NULL);
}

static VALUE start(VALUE self)
{
  VALUE index = rb_iv_get(self, "@camera_number");
  CvCapture * capture = cvCreateCameraCapture(NUM2INT(index));
  DATA_PTR(self) = capture;
  return self;
}

static VALUE stop(VALUE self)
{
  CvCapture * capture;
  Data_Get_Struct(self, CvCapture, capture);
  if(capture) {
    cvReleaseCapture(&capture);
    DATA_PTR(self) = NULL;
  }
  return self;
}

static VALUE capture(VALUE self)
{
  CvCapture * capture;
  Data_Get_Struct(self, CvCapture, capture);

  IplImage * cam = cvQueryFrame(capture);
  if(cam)
    return QRTools_Wrap_Image(cvCloneImage(cam));

  return Qnil;
}

VALUE cQRToolsUICamera;

void init_qrtools_ui_camera()
{
  VALUE qrtools = rb_define_module("QRTools");
  VALUE ui      = rb_define_module_under(qrtools, "UI");
  VALUE klass   = rb_define_class_under(ui, "Camera", rb_cObject);

  cQRToolsUICamera = klass;
  rb_define_alloc_func(klass, allocate);
  rb_define_method(klass, "capture", capture, 0);

  rb_define_private_method(klass, "native_start", start, 0);
  rb_define_private_method(klass, "native_stop", stop, 0);
}
