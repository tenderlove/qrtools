module QRTools
  class Decoder
    class << self
      def decode image, size = 25, delta = 10
        decoder = new(image)
        25.step(3, -2) { |i|
          return decoder if decoder.decode(size, delta)
        }
        decoder
      end
    end

    def decode size = 25, delta = 10
      native_decode(size, delta)
    end
  end
end
