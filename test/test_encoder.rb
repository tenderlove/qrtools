require File.expand_path(File.join(File.dirname(__FILE__), "helper"))

class EncoderTestCase < QRToolsTestCase
  def test_encode
    assert code = QRTools::Encoder.encode('hello world')
  end

  def test_encode_with_mode
    assert code = QRTools::Encoder.encode('元気',
      :mode => QRTools::Encoder::KANJI
    )
  end

  def test_encode_with_version
    assert code = QRTools::Encoder.encode('hello world',
      :version => 1
    )
  end

  def test_encode_with_case_sensitivity_off
    assert code = QRTools::Encoder.encode('hello world',
      :case_sensitive => false
    )
  end

  def test_encode_with_error_correction
    assert code = QRTools::Encoder.encode('hello world',
      :error_correction => QRTools::Encoder::L
    )
  end
end
