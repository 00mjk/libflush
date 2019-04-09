project(
    'libflush',
    'c',
    version: '0.0.1-alpha',
    license: 'MIT',
    default_options: [
        'c_std=c11',
    ],
)


compiler = meson.get_compiler('c')

src = ['libflush.c', 'eviction.c', 'main.c']

incdirs = include_directories('include')

executable('init', src, include_directories: incdirs, c_args: '-DHAVE_PAGEMAP_ACCESS=1')


