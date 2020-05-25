# coding:utf-8
from setuptools import setup, find_packages


setup(
    name='foo',
    version='0.1',
    author='mengfu188',
    author_email='mengfu188@foxmail.com',
    description='this is short desctiption',
    include_package_data=True,
    long_description=open('README.md', 'r').read(),
    packages=find_packages()
)