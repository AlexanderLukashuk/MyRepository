import glob
import os
env = Environment()
SOURCES = glob.glob('*.cpp')
INST_PREFIX = '/usr/local/'
INST_DIR_BIN = INST_PREFIX + 'bin'
INST_PREFIX_DATA = INST_PREFIX + 'share'
env.Append(CCFLAGS = ['-g', '-Wall'])
env.Append(LIBS = ['ncurses', 'other-libs'])
mixtestbin = env.Program(target = 'mytest', source = SOURCES)
env.MergeFlags('-DNIX=1')
env.Install(dir = INST_DIR_BIN, source = mytestbin)
env.Alias('install', [INST_DIR_BIN])
