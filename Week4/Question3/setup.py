from setuptools import setup
from pybind11.setup_helpers import Pybind11Extension

# define extension
ext_modules = [
    Pybind11Extension("concat_module", ["concat_module.cpp"]),
]

# setup
setup(
    name="concat_module",
    ext_modules=ext_modules,
)