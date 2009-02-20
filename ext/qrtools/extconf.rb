ENV["ARCHFLAGS"] = "-arch #{`uname -p` =~ /powerpc/ ? 'ppc' : 'i386'}"

require 'mkmf'

LIBDIR = Config::CONFIG['libdir']
INCLUDEDIR = Config::CONFIG['includedir']

HEADER_DIRS = [
    '/opt/local/include/opencv',
]

LIB_DIRS = [
  LIBDIR,
  '/opt/local/lib',
]

dir_config('opencv', "/opt/local/include/opencv", "/opt/local/lib")
dir_config('qrencode', "/opt/local/include", "/opt/local/lib")
%w{ qrencode cxcore cv highgui }.each do |lib|
  abort "need #{lib}" unless have_library(lib)
end
find_header('qrencode.h')
have_library('stdc++')
create_makefile('qrtools')
