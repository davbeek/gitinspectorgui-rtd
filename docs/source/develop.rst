Developer info
==============

Working with TestPyPI
---------------------
Before publishing to PyPI, the code and publishing scripts can be tested via TestPyPI.

Publish to TestPyPI via poetry
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code:: bash

  poetry publish --repository testpypi --username __token__ --password AUTHENTICATIONTOKEN

Download gitinspectorgui from TestPyPI
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The problem with downloading gitinspectorgui from TestPyPI is that pip will also
try to download the required dependencies from TestPYPI, whereas the
dependencies should be downloaded from PyPI. Therefore, instead of the command
``pip install -i https://test.pypi.org/simple/ gitinspectorgui`` shown at
TestPyPI, use the following command:

.. code:: bash

  pip install --index-url https://test.pypi.org/simple/ --extra-index-url https://pypi.org/simple/ gitinspectorgui
