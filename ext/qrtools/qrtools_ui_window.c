#include <qrtools_ui_window.h>

static VALUE show(VALUE self)
{
  VALUE name = rb_iv_get(self, "@name");
  cvNamedWindow(StringValuePtr(name), 1);
  return self;
}

static VALUE hide(VALUE self)
{
  VALUE name = rb_iv_get(self, "@name");
  cvDestroyWindow(StringValuePtr(name));
  return self;
}

VALUE cQRToolsUIWindow;

void init_qrtools_ui_window()
{
  VALUE qrtools = rb_define_module("QRTools");
  VALUE ui      = rb_define_module_under(qrtools, "UI");
  VALUE klass   = rb_define_class_under(ui, "Window", rb_cObject);

  cQRToolsUIWindow = klass;

  rb_define_method(klass, "show", show, 0);
  rb_define_method(klass, "hide", hide, 0);
}
