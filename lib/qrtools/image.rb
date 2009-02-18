module QRTools
  class Image
    Point = Struct.new(:x, :y)

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
  end
end
