from distutils.core import setup, Extension

module1 = Extension('foo',
    sources = ['foomodule.cpp'])

setup (name = 'Foo',
    version = '1.0',
    description = 'This is the Foo package',
    ext_modules = [module1])
