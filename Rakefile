# -*- ruby -*-

require 'rubygems'
require 'hoe'

kind = Config::CONFIG['DLEXT']
windows = RUBY_PLATFORM =~ /mswin/i ? true : false

EXT = "ext/qrtools/qrtools.#{kind}"

Hoe.new('qrtools', '1.0.0') do |p|
  p.developer('Aaron Patterson', 'aaronp@rubyforge.org')
  p.clean_globs = [
    'ext/qrtools/Makefile',
    'ext/qrtools/*.{o,so,bundle,a,log,dll}',
    'ext/qrtools/conftest.dSYM',
  ]
  p.spec_extras = { :extensions => ["ext/qrtools/extconf.rb"] }
end

task 'ext/qrtools/Makefile' do
  Dir.chdir('ext/qrtools') do
    ruby "extconf.rb #{ENV['EXTOPTS']}"
  end
end

task EXT => 'ext/qrtools/Makefile' do
  Dir.chdir('ext/qrtools') do
    sh 'make'
  end
end
task :build => [EXT]

Rake::Task['test'].prerequisites << :build

# vim: syntax=Ruby
