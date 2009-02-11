require File.expand_path(File.join(File.dirname(__FILE__), "helper"))

class ImageTestCase < QRDecodeTestCase
  def test_load
    assert img = QRDecode::Image.load(File.join(ASSETS, '01-1.jpg'))
  end
end
