require File.expand_path(File.join(File.dirname(__FILE__), "helper"))

class HeaderTestCase < QRToolsTestCase
  def setup
    img = QRTools::Image.load(File.join(ASSETS, '01-1.jpg'))
    decoder = QRTools::Decoder.decode(img)
    @header = decoder.header
  end
  %w{ model version level character_size byte_size }.each do |m|
    define_method(:"test_#{m}") do
      assert @header.send(:"#{m}")
    end
  end
end
