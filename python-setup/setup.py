#!/usr/bin/env python

#from setuptools import setup
from distutils.core import setup

setup(name='simmit',
      version='1.0',
      description='Simulation in Mechanics and Materials: Interactive Tools',
      author='Yves Chemisky',
      author_email='yves.chemisky@gmail.com',
      #url=
      packages=['simmit',],
      package_data={'simmit': ['smartplus.so','identify.so']},
      
      #include_package_data=True,
      license='GPL'
      )