project(
    'libflush',
    'c',
    version: '0.0.1-alpha',
    license: 'MIT',
    default_options: [
        
    ],
)


compiler = meson.get_compiler('c')

thread_dep = compiler.find_library('pthread', required: true)
test_dep = compiler.find_library('check', required: true)
math_dep = compiler.find_library('m', required: true)
shm_dep = compiler.find_library('rt', required: true)
crypto_dep = compiler.find_library('crypto', required: true)

src = ['libflush.c', 'eviction.c', 'timing.c', 'utils.c', 'main.c']
x86_src = ['arch/x86/memory.c', 'arch/x86/timing.c', 'arch/x86/flush.c']
tests_src = ['tests/test_libflush.c', 'tests/test_eviction.c', 'tests/test_memory.c', 'tests/test_timing.c', 'tests/test_runner.c']
sample_et_src = ['test-suite/evict-time/evict_time.c']
sample_pp_src = ['test-suite/prime-probe/prime_probe.c']
aes_attacker_src = ['test-suite/aes/attacker.c', 'test-suite/aes/one_round.c']
aes_daemon_src = ['test-suite/aes/daemon.c']

incdirs = include_directories('include')
archdirs = include_directories('arch')
aes_incdirs = include_directories('test-suite/aes/include')

executable('init', [src, x86_src], include_directories: [incdirs, archdirs], dependencies: thread_dep, c_args: ['-DHAVE_PAGEMAP_ACCESS=1', '-D__x86__', '-DTIME_SOURCE=TIME_SOURCE_PERF'])

libflush = shared_library('flush', [src, x86_src], include_directories: [incdirs, archdirs], dependencies: thread_dep,
  c_args: ['-DHAVE_PAGEMAP_ACCESS=1', '-D__x86__', '-DTIME_SOURCE=TIME_SOURCE_PERF'], install: true)

exec_test = executable('exec_test', tests_src, dependencies: test_dep, include_directories: [incdirs, archdirs], 
  link_with: libflush)

test('libflush test', exec_test)

executable('evict_time', [sample_et_src], include_directories: [incdirs, archdirs], link_with: libflush)
executable('prime_probe', [sample_pp_src], include_directories: [incdirs, archdirs], dependencies: math_dep, link_with: libflush)
executable('attacker', [aes_attacker_src], include_directories: [aes_incdirs, incdirs, archdirs], dependencies: shm_dep, link_with: libflush)
executable('daemon', [aes_daemon_src], dependencies: [shm_dep, crypto_dep]) 
