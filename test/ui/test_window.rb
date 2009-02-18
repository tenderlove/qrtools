require File.expand_path(File.join(File.dirname(__FILE__), '..', 'helper'))

class WindowTestCase < QRToolsTestCase
  def test_new
    assert camera = QRTools::UI::Window.new("foo")
  end

  def test_show
    assert camera = QRTools::UI::Window.new("foo")
    assert camera.show
  end

  def test_hide
    assert camera = QRTools::UI::Window.new("foo")
    assert camera.hide
  end

  def test_show_image
    QRTools::UI::Window.new("foo") do |window|
      QRTools::UI::Camera.new(0) do |camera|
        window.display camera.capture
      end
    end
  end

  def test_new_takes_block
    called = false
    QRTools::UI::Window.new("foo") do |window|
      assert window
      called = true
    end
    assert called
  end
end
