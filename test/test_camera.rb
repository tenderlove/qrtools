require File.expand_path(File.join(File.dirname(__FILE__), "helper"))

class CameraTestCase < QRToolsTestCase
  def test_new
    assert camera = QRTools::Camera.new(0)
  end
  
  def test_capture
    frame = nil
    QRTools::Camera.new(0) do |camera|
      frame = camera.capture
    end
    assert frame
  end

  def test_block
    called = false
    cam = QRTools::Camera.new(0) do |camera|
      called = true
    end
    assert called
    assert cam.start
    assert cam.stop
  end

  def test_start_stop
    camera = QRTools::Camera.new(0)
    assert camera.start
    assert camera.stop
  end

  def test_start_locks
    camera = QRTools::Camera.new(0)
    assert camera.start
    assert_raises(ThreadError) {
      camera.start
    }
    assert camera.stop
  end
end
