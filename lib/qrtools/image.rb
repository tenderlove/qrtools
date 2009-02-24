require 'tempfile'

module QRTools
  class Image
    Point = Struct.new(:x, :y)

    ###
    # Draw a line on this image:
    #
    #   draw_line :from => 0, :to => 100, :thickness => 5
    def draw_line options
      raise ArgumentError unless options.key?(:from)
      raise ArgumentError unless options.key?(:to)
      options = {
        :r => 255,
        :g => 0,
        :b => 0,
        :thickness => 1,
        :type => 8,
        :shift => 0,
      }.merge(options)
      native_draw_line(
        options[:from],
        options[:to],
        options[:r],
        options[:g],
        options[:b],
        options[:thickness],
        options[:type],
        options[:shift]
      )
    end

    ###
    # Convert this Image to an OSX::NSImage
    def to_nsimage
      require 'osx/cocoa'
      filename = File.join(Dir::tmpdir, 'out.jpg')
      save(filename)
      OSX::NSImage.alloc.initWithContentsOfFile filename
    end
  end
end
