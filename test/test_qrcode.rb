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

  def test_to_matrix
    assert @code.to_matrix
  end

  def test_to_s
    assert @code.to_s
  end

  def test_to_png
    filename = File.join(Dir::tmpdir, 'out.png')
    File.open(filename, 'wb') { |f|
      f.write @code.to_png
    }
    img = QRTools::Image.load(filename)
    assert decoder = QRTools::Decoder.decode(img)
    assert_equal 'http://tenderlovemaking.com/', decoder.body.downcase
  end
end
