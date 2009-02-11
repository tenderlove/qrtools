#include <qrtools_decoder.h>

static VALUE allocate(VALUE klass)
{
  QrDecoderHandle decoder = qr_decoder_open();

  return Data_Wrap_Struct(klass, NULL, qr_decoder_close, decoder);
}

VALUE cQRToolsDecoder;
void init_qrtools_decoder()
{
  VALUE qrtools  = rb_define_module("QRTools");
  VALUE klass    = rb_define_class_under(qrtools, "Decoder", rb_cObject);

  cQRToolsDecoder = klass;

  rb_define_alloc_func(klass, allocate);
}
