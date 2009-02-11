ENV["ARCHFLAGS"] = "-arch #{`uname -p` =~ /powerpc/ ? 'ppc' : 'i386'}"

require 'mkmf'

LIBDIR = Config::CONFIG['libdir']
INCLUDEDIR = Config::CONFIG['includedir']

use_macports = !(defined?(RUBY_ENGINE) && RUBY_ENGINE != 'ruby')
$LIBPATH << "/opt/local/lib" if use_macports

HEADER_DIRS = [
    '/opt/local/include/opencv',
]

LIB_DIRS = [
  LIBDIR,
  '/opt/local/lib',
]

dir_config('opencv', "/opt/local/include/opencv", "/opt/local/lib")
%w{ cxcore cv highgui }.each do |lib|
  abort "need #{lib}" unless have_library(lib)
end
have_library('stdc++')
create_makefile('qrtools')
