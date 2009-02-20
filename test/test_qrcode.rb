require File.expand_path(File.join(File.dirname(__FILE__), "helper"))

class QRCodeTestCase < QRToolsTestCase
  def setup
    @code = QRTools::Encoder.encode('hello world')
  end

  def test_code_has_a_width
    assert @code.width
  end
end
