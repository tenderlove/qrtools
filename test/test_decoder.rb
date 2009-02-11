require File.expand_path(File.join(File.dirname(__FILE__), "helper"))

class DecoderTestCase < QRToolsTestCase
  def test_new
    assert decoder = QRTools::Decoder.new
  end

  def test_decode
    decoder = QRTools::Decoder.new
    img = QRTools::Image.load(File.join(ASSETS, '01-1.jpg'))
    assert val = decoder.decode(img)
  end
end

