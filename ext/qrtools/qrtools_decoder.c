#include <qrtools_decoder.h>

static VALUE decode(int argc, VALUE *argv, VALUE klass)
{
  VALUE image, th_size, th_delta;

  IplImage * src;

  QrDecoderHandle decoder = qr_decoder_open();

  rb_scan_args(argc, argv, "12", &image, &th_size, &th_delta);

  Data_Get_Struct(image, IplImage, src);

  int c_size = DEFAULT_ADAPTIVE_TH_SIZE;
  int c_delta = DEFAULT_ADAPTIVE_TH_DELTA;

  if(RTEST(th_size)) c_size = NUM2INT(th_size);
  if(RTEST(th_delta)) c_delta = NUM2INT(th_delta);

  short status = qr_decoder_decode_image(
      decoder,
      src,
      c_size,
      c_delta
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

static VALUE body(VALUE self)
{
  QrDecoderHandle decoder;
  QrCodeHeader * head;

  VALUE _header = rb_funcall(self, rb_intern("header"), 0);
  if(Qnil == _header) return Qnil;

  Data_Get_Struct(self, struct QrDecoderHandle, decoder);
  Data_Get_Struct(_header, QrCodeHeader, head);

  char *buf = calloc(head->byte_size + 1, sizeof(char));
  VALUE b = Qnil;

  if(qr_decoder_get_body(decoder, (unsigned char *)buf, head->byte_size + 1))
    b = rb_str_new(buf, head->byte_size);

  free(buf);
  return b;
}

VALUE cQRToolsDecoder;
void init_qrtools_decoder()
{
  VALUE qrtools  = rb_define_module("QRTools");
  VALUE klass    = rb_define_class_under(qrtools, "Decoder", rb_cObject);

  cQRToolsDecoder = klass;

  rb_define_singleton_method(klass, "decode", decode, -1);
  rb_define_method(klass, "header", header, 0);
  rb_define_method(klass, "body", body, 0);
}
