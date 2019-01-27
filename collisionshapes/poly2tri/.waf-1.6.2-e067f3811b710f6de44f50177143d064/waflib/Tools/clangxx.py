#! /usr/bin/env python
# encoding: utf-8
# WARNING! All changes made to this file will be lost!

import os,sys
from waflib import Configure,Options,Utils
from waflib.Tools import ccroot,ar
from waflib.Configure import conf
def find_clangxx(conf):
	cxx=conf.find_program(['clang++'],var='CXX')
	cxx=conf.cmd_to_list(cxx)
	conf.get_cc_version(cxx,gcc=True)
	conf.env.CXX_NAME='clang'
	conf.env.CXX=cxx
def clangxx_common_flags(conf):
	v=conf.env
	v['CXX_SRC_F']=[]
	v['CXX_TGT_F']=['-c','-o']
	if not v['LINK_CXX']:v['LINK_CXX']=v['CXX']
	v['CXXLNK_SRC_F']=[]
	v['CXXLNK_TGT_F']=['-o']
	v['CPPPATH_ST']='-I%s'
	v['DEFINES_ST']='-D%s'
	v['LIB_ST']='-l%s'
	v['LIBPATH_ST']='-L%s'
	v['STLIB_ST']='-l%s'
	v['STLIBPATH_ST']='-L%s'
	v['RPATH_ST']='-Wl,-rpath,%s'
	v['SONAME_ST']='-Wl,-h,%s'
	v['SHLIB_MARKER']='-Wl,-Bdynamic'
	v['STLIB_MARKER']='-Wl,-Bstatic'
	v['cxxprogram_PATTERN']='%s'
	v['CXXFLAGS_cxxshlib']=['-fPIC']
	v['LINKFLAGS_cxxshlib']=['-shared']
	v['cxxshlib_PATTERN']='lib%s.so'
	v['LINKFLAGS_cxxstlib']=['-Wl,-Bstatic']
	v['cxxstlib_PATTERN']='lib%s.a'
	v['LINKFLAGS_MACBUNDLE']=['-bundle','-undefined','dynamic_lookup']
	v['CXXFLAGS_MACBUNDLE']=['-fPIC']
	v['macbundle_PATTERN']='%s.bundle'
def clangxx_modifier_win32(conf):
	v=conf.env
	v['cxxprogram_PATTERN']='%s.exe'
	v['cxxshlib_PATTERN']='%s.dll'
	v['implib_PATTERN']='lib%s.dll.a'
	v['IMPLIB_ST']='-Wl,--out-implib,%s'
	v['CXXFLAGS_cxxshlib']=[]
	v.append_value('CXXFLAGS_cxxshlib',['-DDLL_EXPORT'])
	v.append_value('LINKFLAGS',['-Wl,--enable-auto-import'])
def clangxx_modifier_cygwin(conf):
	clangxx_modifier_win32(conf)
	v=conf.env
	v['cxxshlib_PATTERN']='cyg%s.dll'
	v.append_value('LINKFLAGS_cxxshlib',['-Wl,--enable-auto-image-base'])
	v['CXXFLAGS_cxxshlib']=[]
def clangxx_modifier_darwin(conf):
	v=conf.env
	v['CXXFLAGS_cxxshlib']=['-fPIC','-compatibility_version','1','-current_version','1']
	v['LINKFLAGS_cxxshlib']=['-dynamiclib']
	v['cxxshlib_PATTERN']='lib%s.dylib'
	v['FRAMEWORKPATH_ST']='-F%s'
	v['FRAMEWORK_ST']='-framework %s'
	v['LINKFLAGS_cxxstlib']=[]
	v['SHLIB_MARKER']=[]
	v['STLIB_MARKER']=[]
	v['SONAME_ST']=[]
def clangxx_modifier_aix(conf):
	v=conf.env
	v['LINKFLAGS_cxxprogram']=['-Wl,-brtl']
	v['LINKFLAGS_cxxshlib']=['-shared','-Wl,-brtl,-bexpfull']
	v['SHLIB_MARKER']=[]
def clangxx_modifier_hpux(conf):
	v=conf.env
	v['SHLIB_MARKER']=[]
	v['CFLAGS_cxxshlib']=['-fPIC','-DPIC']
	v['cxxshlib_PATTERN']='lib%s.sl'
def clangxx_modifier_platform(conf):
	clangxx_modifier_func=getattr(conf,'clangxx_modifier_'+conf.env.DEST_OS,None)
	if clangxx_modifier_func:
		clangxx_modifier_func()
def configure(conf):
	conf.find_clangxx()
	conf.find_ar()
	conf.clangxx_common_flags()
	conf.clangxx_modifier_platform()
	conf.cxx_load_tools()
	conf.cxx_add_flags()
	conf.link_add_flags()

conf(find_clangxx)
conf(clangxx_common_flags)
conf(clangxx_modifier_win32)
conf(clangxx_modifier_cygwin)
conf(clangxx_modifier_darwin)
conf(clangxx_modifier_aix)
conf(clangxx_modifier_hpux)
conf(clangxx_modifier_platform)