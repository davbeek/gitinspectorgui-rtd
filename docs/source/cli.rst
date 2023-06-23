CLI: Command Line Interface
===========================
Synopsis
--------

.. code:: text

  gitinspectorgui [-h] [-V] [-a] [-v]
                  [-F {html,htmlembedded,json,text,xml,excel,csv}]
                  [--scaled-percentages | --no-scaled-percentages] [-f N]
                  [--merged-repositories | --no-merged-repositories]
                  [-m | --metrics | --no-metrics] [-t | --timeline | --no-timeline]
                  [-l | --extensions-list | --no-extensions-list]
                  [-r | --responsibilities | --no-responsibilities] [-e EXTENSIONS]
                  [-H | --hard | --no-hard]
                  [-L | --localize-output | --no-localize-output]
                  [-w | --weeks | --no-weeks] [--since SINCE] [--until UNTIL]
                  [--ex-file PATTERN] [--ex-author PATTERN] [--ex-email PATTERN]
                  [--ex-revision PATTERN] [--ex-message PATTERN]
                  {gui,repo,folder,folders,urls,settings} ...


Unique for CLI
--------------
``-h`` ``--help``
  Display help and exit.

``--version``
  Output version information and exit.

``--examples``
  Show usage examples.

``-v`` ``--verbose``
  More verbose output for each ``v``, e.g. ``-vv``.


Positional arguments
--------------------

Positional arguments are either for the GUI or the CLI:

* GUI: ``gui``
* CLI: ``repo`` ``folder`` ``folders`` ``urls`` ``settings``

For the CLI, the output files generated depend on the output formats specified
in the ``-F`` or ``--format`` option. By default, output is generated in the
files ``gitinspect.ext``, where ``ext`` is defined by the selected :ref:`output
formats <formats>`.

gui
^^^

``gui``
  Start the GUI.

repo
^^^^
``repo``
  ``[-h --help] [-f --fix {pre,post,none}] [-o --output FILEBASE] REPOPATH``

  Analyze the repository in ``REPOPATH``. Functionality identical to GUI.

``-f {pre,post,none}`` ``--fix {pre,post,none}``

  * ``-f pre`` output file name is ``REPONAME_FILEBASE``.
  * ``-f post`` output file name is ``FILEBASE_REPONAME``.
  * ``-f none`` output file name is ``FILEBASE``.

``-o FILEBASE`` ``--output FILEBASE``
  The output filename, without extension and without parents is ``FILEBASE``.
  Default: ``gitinspect``.

folder
^^^^^^
``folder``
  ``[-h --help] [-o --output FILEBASE] [-d --depth N] [-m --multiple-output-files] PATH``

  Analyze all repositories found in input folder ``PATH``. Functionality
  identical to GUI.

``-o FILEBASE`` ``--output FILEBASE``
  The output filename, without extension and without parents is ``FILEBASE``.
  Default: ``gitinspect``.

``-d N`` ``--depth N``
  Integer value bigger or equal to zero, that represents the number of levels of
  subfolders that is searched for repositories, *default* ``5``.

  * ``-d 0``: the input folder itself must be a repository.
  * ``-d 1``: only the input folder is searched for repository folders for
    analysis.

``--multiple-output-files``
  Splits the output into separate output files, one for each repository.

folders
^^^^^^^
``folders``
  ``[-h --help] [-o --output PATH] [-d --depth N] [-m --multiple-output-files]
  PATHS``

  Analyze all repositories found in the given list of paths (``PATHS``) to input
  folders. Command unique for CLI.

``-o PATH`` ``--output PATH``
  Generate output in file paths ``PATH.ext``, where ``ext`` takes on the
  values belonging to the selected output formats.

  Default: generate output in the current directory in files ``gitinspect.ext``.

``-d N`` ``--depth N``
  Positive integer value that represents the number of levels of subfolders
  that is searched for repositories, *default* ``5``. For depth ``1``, only
  the repository in ``PATH``, if present, is analysed.

``--multiple-ouput-files``
  Splits the output into separate output files, one for each repository.

urls
^^^^
``urls``
  ``[-h --help] [-o --output PATH] URLS``
  Download and analyze repositories specified via URLS.

``-o PATH`` ``--output PATH``
  Output file path without extension is ``PATH``. Default: generate output in
  the file named ``gitinspect`` in the current directory.

settings
^^^^^^^^
``settings``
  ``[-h --help] {reset | show-location | change-location NEWPATH}``

  Reset global GUI settings or show/change settings file location.

.. _formats:

Output formats
--------------
.. ``checkout_tag TAG_ID``
..   Checkout tag ``TAG_ID`` for all repositories found in ``input_folder``.

For more information about the various output formats, see :doc:`output-formats`.

``-F FORMAT`` ``--format FORMAT``
  Defines in which ``FORMAT`` output is generated: ``text`` *default* ``html``
  ``htmlembedded`` ``json`` ``xml`` ``excel`` ``csv``. Format options can be
  specified multiple times, to generated multiple output formats simultaneously.

Output formats excel and csv
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
``--scaled-percentages --no-scaled-percentages``
  For each column with output in percentages, e.g. ``Insertions %``, add a
  column ``Scaled insertions %``, which equals the value of ``Insertions %``
  multiplied by the number of authors in the repository.

``-f N`` ``--show-files N``
  Generate output for the first ``N`` files with the highest number of
  insertions for each repository.

``--merged-repositories`` ``--no-merged-repositories``
  Merge commit information from found repositories as if coming from a single
  repository.

Output formats text ... html
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Note that for these output formats, output from multiple repositories is always
merged. This behavior is equivalent to the ``--merged-repositories`` option for
the output formats excel and csv.

``-m``  ``--metrics`` ``--no-metrics``
  Include checks for certain metrics during the analysis of commits.

``-t`` ``--timeline`` ``--no-timeline``
  Show commit timeline, including author names.

``-l`` ``--extensions-list`` ``--no-extensions-list``
  Show a list of file extensions, used in the current branch of the
  repository, in the output.

``-r``  ``--responsibilities`` ``--no-responsibilities``
  Show which files the different authors seem most responsible for.


General configuration
---------------------
``-e EXTENSIONS`` ``--extensions EXTENSIONS``
  A comma separated list of file extensions to include when computing
  statistics. The default extensions used are: ``java, c, cc, cpp, h, hh,
  hpp, py, glsl, rb, js, sql``.

  For more information, see the :ref:`supported languages table
  <languages_table>` below.

  Specifying a single ``*`` asterisk character includes files with no extension.
  Specifying two consecutive ``**`` asterisk characters includes all files
  regardless of extension.

``-H`` ``--hard`` ``no-hard``
  .. include:: opt-hard.inc

``-L`` ``--localized-output`` ``--no-localized-output``
  By default, the generated statistics are in English. This flag localizes the
  generated output to the selected system language if a translation is
  available.

``-w`` ``--weeks`` ``--no-weeks``
  Show all statistical information in weeks instead of in months.

``--since DATE``
  Only show statistics for commits more recent than a specific date. The
  ``DATE`` format is YYYY-M-D, where leading zeros are optional for month and
  day, e.g.
  ``--since 2022-1-31`` or ``--since 2022-01-31``.

``--until DATE``
  Only show statistics for commits older than a specific date. See ``--since``
  for the format of ``DATE``.


Exclusion patterns
------------------
Specify exclusion patterns ``PATTERN``, describing file paths, author names or
emails, revisions or commit messages that should be excluded from the
statistics. Each exclusion option can be repeated multiple times.

``--ex-file PATTERN``
  Filter out all files (or paths) containing any of the comma separated strings
  in ``PATTERN``. E.g. ``--ex-file myfile,test`` excludes files ``myfile.py``
  and ``testing.c``.

``--ex-author PATTERN``
  Filter out all author names containing any of the comma separated strings in
  ``PATTERN``. E.g. ``--ex-author John`` excludes author ``John Smith``.

``--ex-email PATTERN``
  Filter out all email addresses containing any of the comma separated strings
  in ``PATTERN``. E.g. ``--ex-email @gmail.com`` excludes all authors with a
  gmail address.

``--ex-revision PATTERN``
  Filter out all revisions containing any of the comma separated hashes/SHAs
  in ``PATTERN``. E.g. ``--ex-revision 8755fb33,12345678`` excludes revisions
  that have ``8755fb33`` or ``12345678`` occuring somewhere in their commit
  hash/RSA.

``--ex-message PATTERN``
  Filter out all commit messages containing any of the comma separated strings
  in ``PATTERN``. E.g. ``--ex-message bug,fix`` excludes commits from analysis
  with commit messages such as ``Bugfix`` or ``Fixing issue #15``.


Apart from substring matching, as described above, regular expressions
can also be used as exclusion ``PATTERN``, e.g:

``--ex-author "\^(?!(John Smith))"``
  Only show statistics from author ``John Smith``, by excluding all authors that
  are not John Smith. The backslash is needed to make sure that the CLI
  interpreter (bash) does not interpret the caret ``^``.

``--ex-author "\^(?!([A-C]))"``
  Only show statistics from authors starting with the letters ``A/B/C``.

``--ex-email ".com$"``
  Filter out statistics from all email addresses ending with ``.com``.

.. _languages_table:

Supported languages
-------------------

.. list-table::

  * - Language
    - Comments
    - Metrics
    - File extensions
    - Included in analysis by default
  * - CIF 3
    - Yes
    - No
    - cif
    -  Yes
  * - ToolDef
    -  No
    -  No
    -  tooldef
    -  Yes
  * - ADA
    - Yes
    - No
    - ada, adb, ads
    - No
  * - C
    - Yes
    - Yes
    - c, h
    - Yes
  * - C++
    - Yes
    - Yes
    - cc, h, hh, hpp
    - Yes
  * - C#
    - Yes
    - Yes
    - cs
    - No
  * - GNU Gettext
    - Yes
    - No
    - po, pot
    - No
  * - Haskell
    - Yes
    - No
    - hs
    - No
  * - HTML
    - Yes
    - No
    - html
    - No
  * - Java
    - Yes
    - Yes
    - java
    - Yes
  * - JavaScript
    - Yes
    - Yes
    - js
    - Yes
  * - LaTeX
    - Yes
    - No
    - tex
    - No
  * - OCaml
    - Yes
    - No
    - ml, mli
    - No
  * - OpenGL Shading Language
    - Yes
    - No
    - glsl
    - Yes
  * - Perl
    - Yes
    - No
    - pl
    - No
  * - PHP
    - Yes
    - No
    - php
    - No
  * - Python
    - Yes
    - Yes
    - py
    - Yes
  * - Ruby
    - Yes
    - No
    - rb
    - Yes
  * - Scala
    - Yes
    - No
    - scala
    - No
  * - SQL
    - Yes
    - No
    - sql
    - Yes
  * - XML
    - Yes
    - No
    - xml, jspx
    - No
