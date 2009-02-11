require File.expand_path(File.join(File.dirname(__FILE__), "helper"))

class DecoderTestCase < QRToolsTestCase
  def test_new
    assert decoder = QRTools::Decoder.new
  end
end

