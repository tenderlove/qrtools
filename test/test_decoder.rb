require File.expand_path(File.join(File.dirname(__FILE__), "helper"))

class DecoderTestCase < QRToolsTestCase
  def test_new
    img = QRTools::Image.load(File.join(ASSETS, '01-1.jpg'))
    assert decoder = QRTools::Decoder.new(img)
    assert decoder.decode
  end

  def test_decode
    img = QRTools::Image.load(File.join(ASSETS, '01-1.jpg'))
    assert decoder = QRTools::Decoder.decode(img)
  end

  def test_header
    img = QRTools::Image.load(File.join(ASSETS, '01-1.jpg'))
    assert decoder = QRTools::Decoder.decode(img)
    assert decoder.header
  end

  def test_body
    img = QRTools::Image.load(File.join(ASSETS, '01-1.jpg'))
    assert decoder = QRTools::Decoder.decode(img)
    assert decoder.body
    assert_match 'amazon', decoder.body
  end
end

