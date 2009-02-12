# -*- ruby -*-

require 'rubygems'
require 'hoe'

kind = Config::CONFIG['DLEXT']
windows = RUBY_PLATFORM =~ /mswin/i ? true : false

EXT = "ext/qrtools/qrtools.#{kind}"

require './lib/qrtools/version'

HOE = Hoe.new('qrtools', QRTools::VERSION) do |p|
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

namespace :gem do
  namespace :dev do
    task :spec do
      File.open("#{HOE.name}.gemspec", 'w') do |f|
        HOE.spec.version = "#{HOE.version}.#{Time.now.strftime("%Y%m%d%H%M%S")}"
        f.write(HOE.spec.to_ruby)
      end
    end
  end
end

# vim: syntax=Ruby
