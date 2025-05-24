#!/usr/bin/env python3

import foo

s = 'hello, world'
sz_foo = foo.bar(s)  # calculate the string length with the extension module
sz_len = len(s)      # calcualte the string length with the builtin len() function
print(f'string:"{s}"  sz_foo:{sz_foo}  sz_len:{sz_len}')
