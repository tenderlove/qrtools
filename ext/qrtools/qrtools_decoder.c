#include <qrtools_decoder.h>

static VALUE decode(VALUE klass, VALUE image)
{
  IplImage * src;
  Data_Get_Struct(image, IplImage, src);

  QrDecoderHandle decoder = qr_decoder_open();

  short status = qr_decoder_decode_image(
      decoder,
      src,
      DEFAULT_ADAPTIVE_TH_SIZE,
      DEFAULT_ADAPTIVE_TH_DELTA
  );

  VALUE self = Data_Wrap_Struct(klass, NULL, qr_decoder_close, decoder);
  return self;
}

static VALUE header(VALUE self)
{
  QrCodeHeader * header = calloc(1, sizeof(QrCodeHeader));
  QrDecoderHandle decoder;

  Data_Get_Struct(self, struct QrDecoderHandle, decoder);

  qr_decoder_get_header(decoder, header);

  if(header)
    return Data_Wrap_Struct(cQRToolsHeader, NULL, free, header);

  free(header);
  return Qnil;
}

VALUE cQRToolsDecoder;
void init_qrtools_decoder()
{
  VALUE qrtools  = rb_define_module("QRTools");
  VALUE klass    = rb_define_class_under(qrtools, "Decoder", rb_cObject);

  cQRToolsDecoder = klass;

  rb_define_singleton_method(klass, "decode", decode, 1);
  rb_define_method(klass, "header", header, 0);
}
