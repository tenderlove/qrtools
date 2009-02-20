require File.expand_path(File.join(File.dirname(__FILE__), "helper"))

class QRCodeTestCase < QRToolsTestCase
  def setup
    @code = QRTools::Encoder.encode('http://tenderlovemaking.com/')
  end

  def test_code_has_a_width
    assert @code.width
  end

  def test_code_has_a_version
    assert @code.version
  end

  def test_code_has_data
    assert @code.data
  end
end
