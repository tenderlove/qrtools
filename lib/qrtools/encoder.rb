module QRTools
  class Encoder
    NULL        = -1 # Terminator (NUL character)
    NUMERIC     = 0  # Numeric mode
    ALPHA_NUM   = 1  # Alphabet-numeric mode
    EIGHT_BIT   = 2  # 8-bit data mode
    KANJI       = 3  # Kanji (shift-jis) mode

    L = 0 # Error Correction L (Lowest)
    M = 1 # Error Correction M
    Q = 2 # Error Corretion Q
    H = 3 # Error Corretion H (highest)
  end
end
