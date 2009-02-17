module QRTools
  module UI
    class Window
      ###
      # Create a new window with +name+
      def initialize name
        @name = name
        if block_given?
          show
          yield self
          hide
        end
      end
    end
  end
end
