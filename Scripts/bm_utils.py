# -*- coding: utf-8 -*-
from __future__ import print_function, unicode_literals, with_statement, division, absolute_import

def get_iterable(x):
    try:
        iter(x)
    except TypeError:
        return (x, )
    else:
        return x