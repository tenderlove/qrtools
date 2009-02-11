require 'test/unit'

%w(../lib ../ext).each do |path|
  $LOAD_PATH.unshift(File.expand_path(File.join(File.dirname(__FILE__), path)))
end

require 'qrdecode'

class QRDecodeTestCase < Test::Unit::TestCase
  ASSETS = File.expand_path(File.join(File.dirname(__FILE__), 'assets'))

  unless RUBY_VERSION >= '1.9'
    undef :default_test
  end
end
