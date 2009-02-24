#include <qrtools_encoder.h>

static VALUE encode(int argc, VALUE *argv, VALUE klass)
{
  //extern QRcode *QRcode_encodeString(const char *string, int version, QRecLevel level, QRencodeMode hint, int casesensitive);
  VALUE string, options;
  if(rb_scan_args(argc, argv, "11", &string, &options) == 1) {
    options = rb_hash_new();
  }

  VALUE version = rb_hash_aref(options, ID2SYM(rb_intern("version")));
  VALUE level = rb_hash_aref(options, ID2SYM(rb_intern("error_correction")));
  VALUE case_sensitive = rb_hash_aref(options, ID2SYM(rb_intern("case_sensitive")));
  VALUE mode = rb_hash_aref(options, ID2SYM(rb_intern("mode")));

  int cs = 0;
  if(RTEST(case_sensitive) && case_sensitive == Qtrue) cs = 1;

  QRcode * code = QRcode_encodeString(
      StringValuePtr(string),
      RTEST(version) ? NUM2INT(version) : 0,
      RTEST(level) ? NUM2INT(level) : 0,
      RTEST(mode) ? NUM2INT(mode) : 2,
      cs
  );
  if(NULL == code) rb_raise(rb_eRuntimeError, "could not create code");
  return Data_Wrap_Struct(cQRToolsQRCode, NULL, QRcode_free, code);
}

static VALUE version(VALUE self)
{
  QRinput * input;
  Data_Get_Struct(self, QRinput, input);
  return INT2NUM(QRinput_getVersion(input));
}

static VALUE set_version(VALUE self, VALUE version)
{
  QRinput * input;
  Data_Get_Struct(self, QRinput, input);
  QRinput_setVersion(input, NUM2INT(version));

  return self;
}

static VALUE allocate(VALUE klass)
{
  return Data_Wrap_Struct(klass, NULL, QRinput_free, QRinput_new());
}

VALUE cQRToolsEncoder;
void init_qrtools_encoder()
{
  VALUE qrtools = rb_define_module("QRTools");
  VALUE klass   = rb_define_class_under(qrtools, "Encoder", rb_cObject);

  cQRToolsEncoder = klass;

  rb_define_alloc_func(klass, allocate);
  rb_define_singleton_method(klass, "encode", encode, -1);
  rb_define_method(klass, "version", version, 0);
  rb_define_method(klass, "version=", set_version, 1);
}
