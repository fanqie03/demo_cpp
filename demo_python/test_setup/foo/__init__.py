# coding:utf-8
import time
from logzero import logger

class Timer:
    def __init__(self):
        self._dict = dict()
        self._list = list()

    def tic(self):
        self._list.append(time.time())
        
    def toc(self, note=None):
        e = time.time()
        s = self._list.pop()
        pad = (e - s) * 1000
        if note:
            logger.info('[{}] cost {:.2f} ms'.format(note, pad))
        return pad


def get_asset(file_path):
    from pathlib import Path
    return str(Path(__file__).parent / 'asset' / file_path)

# description = open(get_asset('resource.txt'), 'r').read()
# print(description)