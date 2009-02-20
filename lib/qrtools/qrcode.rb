require 'enumerator'
require 'png'

module QRTools
  class QRCode
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

    def to_png scale = 10
      canvas = PNG::Canvas.new(width * scale, width * scale, PNG::Color::White)

      scaled_matrix = []
      to_matrix.each do |row|
        scaled_row = row.map { |bit|
          [bit] * scale
        }.flatten
        scaled_matrix += ([scaled_row] * scale)
      end

      scaled_matrix.each_with_index { |row, i|
        row.each_with_index { |bit, j|
          canvas[i, j] = bit ? PNG::Color::Black : PNG::Color::White 
        }
      }
      PNG.new(canvas).to_blob
    end
  end
end
