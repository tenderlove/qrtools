#include <qrtools_decoder.h>

static VALUE allocate(VALUE klass)
{
  QrDecoderHandle decoder = qr_decoder_open();

  return Data_Wrap_Struct(klass, NULL, qr_decoder_close, decoder);
}

static VALUE decode(VALUE self, VALUE image)
{
  IplImage * src;
  Data_Get_Struct(image, IplImage, src);

  QrDecoderHandle decoder;
  Data_Get_Struct(self, struct QrDecoderHandle, decoder);

  return INT2NUM(qr_decoder_decode_image(decoder, src, DEFAULT_ADAPTIVE_TH_SIZE, DEFAULT_ADAPTIVE_TH_DELTA));
}

VALUE cQRToolsDecoder;
void init_qrtools_decoder()
{
  VALUE qrtools  = rb_define_module("QRTools");
  VALUE klass    = rb_define_class_under(qrtools, "Decoder", rb_cObject);

  cQRToolsDecoder = klass;

  rb_define_alloc_func(klass, allocate);
  rb_define_method(klass, "decode", decode, 1);
}
