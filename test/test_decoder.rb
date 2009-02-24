require File.expand_path(File.join(File.dirname(__FILE__), "helper"))

class DecoderTestCase < QRToolsTestCase
  def test_new
    img = QRTools::Image.load(File.join(ASSETS, '01-1.jpg'))
    assert decoder = QRTools::Decoder.new(img)
    assert decoder.decode
  end

  def test_coderegion_vertexes
    img = QRTools::Image.load(File.join(ASSETS, '01-1.jpg'))
    assert decoder = QRTools::QRCode.decode(img)
    verts = decoder.coderegion_vertexes
    assert_equal 4, verts.length
  end

  def test_draw_vertexes
    img = QRTools::Image.load(File.join(ASSETS, '01-1.jpg'))
    assert decoder = QRTools::Decoder.decode(img)
    verts = decoder.coderegion_vertexes
    from = verts.last
    verts.each do |to|
      img.draw_line :from => from, :to => to, :thickness => 5
      from = to
    end
  end

  def test_cannot_decode
    QRTools::UI::Camera.new(0) do |camera|
      assert ! QRTools::Decoder.new(camera.capture).decode
    end
  end

  def test_binarized_image
    img = QRTools::Image.load(File.join(ASSETS, '01-1.jpg'))
    decoder = QRTools::Decoder.new(img)
    decoder.decode
    QRTools::UI::Window.new("foo") do |window|
      window.display decoder.binarized_image
    end
  end

  def test_set_image
    img = QRTools::Image.load(File.join(ASSETS, '01-1.jpg'))
    assert decoder = QRTools::Decoder.new(img)
    decoder.image = img
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

