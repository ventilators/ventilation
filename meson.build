project('ventilation', 'cpp', version : '0.1.0', default_options : ['warning_level=3', 'cpp_std=c++20'])

includes      = include_directories('include')
dependencies  = []

ventilation_dep = declare_dependency(
  include_directories   : includes
  , dependencies        : dependencies
  )

if not meson.is_subproject()
  subdir('tests')
endif
