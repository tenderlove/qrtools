require 'thread'

module QRTools
  module UI
    class Camera
      @@locks = Hash.new { |h,k| h[k] = Mutex.new }

      def initialize camera_number
        @camera_number = camera_number
        if block_given?
          start
          yield self
          stop
        end
      end

      def start
        @@locks[@camera_number].lock
        native_start
      end

      def stop
        @@locks[@camera_number].unlock
        native_stop
      end
    end
  end
end
