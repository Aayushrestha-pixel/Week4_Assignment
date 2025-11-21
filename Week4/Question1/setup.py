from setuptools import setup, Extension

# define the extension
module = Extension('square_module', sources=['square_module.c'])

# setup
setup(
    name='square_module',
    version='1.0',
    ext_modules=[module]
)