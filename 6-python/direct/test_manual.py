#!/usr/bin/env python3

import os
import sys
# Extend python's module search path to the location where foo was built so python can find foo when it is imported.
# You may have to adjust this directory, depending on where the module was built.
sys.path.append(os.path.join(os.path.abspath(os.path.dirname(__file__)), 'build/lib.macosx-13-arm64-cpython-311'))
import foo

s = 'hello, world'
sz_foo = foo.bar(s)  # calculate the string length with the extension module
sz_len = len(s)      # calcualte the string length with the builtin len() function
print(f'string:"{s}"  sz_foo:{sz_foo}  sz_len:{sz_len}')
