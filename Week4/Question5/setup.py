from setuptools import setup, Extension

# define extension
module = Extension('array_module', sources=['array_module.c'])

# setup
setup(
    name='array_module',
    version='1.0',
    ext_modules=[module]
)