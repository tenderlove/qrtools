require File.expand_path(File.join(File.dirname(__FILE__), "helper"))

class ImageTestCase < QRToolsTestCase
  def test_load
    assert img = QRTools::Image.load(File.join(ASSETS, '01-1.jpg'))
  end
end
