require 'enumerator'
require 'png'

module QRTools
  class QRCode
    class << self
      def decode *args, &block
        Decoder.decode *args, &block
      end

      def encode *args, &block
        Encoder.encode *args, &block
      end
    end

    def to_matrix
      codes = []
      data.unpack("C#{width ** 2}").each_slice(width) { |row|
        codes << row.map { |x| x & 0x1 == 1 }
      }
      codes
    end

    def to_s
      to_matrix.map { |row|
        row.map { |bit| bit ? '#' : ' ' }.join
      }.join("\n")
    end

    def to_png scale = 4, border = 10
      # Add 2 extra rows / columns for white borders
      size = (width + border) * scale
      canvas = PNG::Canvas.new(size, size, PNG::Color::White)

      scaled_matrix = []
      to_matrix.each do |row|
        scaled_row = row.map { |bit|
          [bit] * scale
        }.flatten
        scaled_matrix += ([scaled_row] * scale)
      end

      factor = border / 2 * scale
      scaled_matrix.each_with_index { |row, i|
        x = i + factor
        row.each_with_index { |bit, j|
          y = j + factor
          canvas[x, y] = bit ? PNG::Color::Black : PNG::Color::White 
        }
      }
      PNG.new(canvas).to_blob
    end
  end
end
