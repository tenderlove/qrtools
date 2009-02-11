# -*- ruby -*-

require 'rubygems'
require 'hoe'

kind = Config::CONFIG['DLEXT']
windows = RUBY_PLATFORM =~ /mswin/i ? true : false

EXT = "ext/qrdecode/qrdecode.#{kind}"

Hoe.new('qrdecode', '1.0.0') do |p|
  p.developer('Aaron Patterson', 'aaronp@rubyforge.org')
  p.clean_globs = [
    'ext/qrdecode/Makefile',
    'ext/qrdecode/*.{o,so,bundle,a,log,dll}',
    'ext/qrdecode/conftest.dSYM',
  ]
  p.spec_extras = { :extensions => ["ext/qrdecode/extconf.rb"] }
end

task 'ext/qrdecode/Makefile' do
  Dir.chdir('ext/qrdecode') do
    ruby "extconf.rb #{ENV['EXTOPTS']}"
  end
end

task EXT => 'ext/qrdecode/Makefile' do
  Dir.chdir('ext/qrdecode') do
    sh 'make'
  end
end
task :build => [EXT]

Rake::Task['test'].prerequisites << :build

# vim: syntax=Ruby
