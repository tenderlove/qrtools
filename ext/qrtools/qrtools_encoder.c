#include <qrtools_encoder.h>

static VALUE encode(int argc, VALUE *argv, VALUE klass)
{
  //extern QRcode *QRcode_encodeString(const char *string, int version, QRecLevel level, QRencodeMode hint, int casesensitive);
  VALUE string, options;
  if(rb_scan_args(argc, argv, "11", &string, &options) == 1) {
    options = rb_hash_new();
  }

  VALUE version = rb_hash_aref(options, rb_intern("version"));
  VALUE level = rb_hash_aref(options, rb_intern("error_correction"));
  VALUE case_sensitive = rb_hash_aref(options, rb_intern("case_sensitive"));
  VALUE mode = rb_hash_aref(options, rb_intern("mode"));

  QRcode_encodeString(
      StringValuePtr(string),
      RTEST(version) ? NUM2INT(version) : 0,
      RTEST(level) ? NUM2INT(level) : 0,
      RTEST(mode) ? NUM2INT(mode) : 1,
      RTEST(case_sensitive) ? NUM2INT(case_sensitive) : 0
  );
  return klass;
}

VALUE cQRToolsEncoder;
void init_qrtools_encoder()
{
  VALUE qrtools = rb_define_module("QRTools");
  VALUE klass   = rb_define_class_under(qrtools, "Encoder", rb_cObject);

  cQRToolsEncoder = klass;
  rb_define_singleton_method(klass, "encode", encode, -1);
}
