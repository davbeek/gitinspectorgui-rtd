Overview
========

Introduction
------------
The Python ``gitinspectorgui`` tool facilitates detailed quantative analysis of
the contribution of each author to selected repositories. The tool comes with a
GUI (Graphical User Interface) and CLI (Command Line Interface) interface.
Executable apps are available for Mac and Windows.

Origin
------
Development of GitinspectorGUI started as an update and extension of the
`gitinspector <https://github.com/ejwa/gitinspector>`_ CLI tool by Adam
Waldenberg. Recently, GitinspectorGUI has been completely rewritten and no
longer uses any code from the gitinspector tool.

Summary of main features
------------------------
GUI and CLI interface
  The GUI and CLI interface have the same options and functionality.

Excel backend
  The Excel backend gives git statistics per author, per author subdivided by
  file, per file subdivided by author, and per file. It also provided detailed
  blame information for each file.

Available as executable app and PyPI package
  Executable apps with GUI interface are available for Mac and Windows. In
  addition, a Python package can be installed from PyPI.

License
-------
GitinspectorGUI is released under the permissive MIT license. The GUI is based
on the PySimpleGUI version from pysimplegui-4-foss at PyPI, which is LGPL
licensed. We are working on an additional GUI interface based on `DearPyGUI
<https://github.com/hoffstadt/DearPyGui>`_, which is MIT licensed.

GitinspectorGUI team
--------------------
For the first few years, all development work based on the GPL3 gitinspector
version from Adam Waldenberg has been done by Jingjing Wang. The rewrite to the
MIT version was done by Bert van Beek. Work on GitinspectorGUI is part of the
TU/e BOOST project `Time and Place Independent Learning
<https://boost.tue.nl/projects/ict-tools-to-support-tpil-in-project-groups/>`_.
