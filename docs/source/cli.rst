CLI: Command Line Interface
===========================
Synopsis
--------

.. code:: text

  gitinspectorgui
    [-h]
    [--gui | -V | --show-settings | --save | --save-as PATH | --load PATH | --reset]
    [-d DEPTH] [-o FILEBASE] [--fix {prefix,postfix,nofix}]
    [-F {auto,html,excel,text}] [--show-renames | --no-show-renames]
    [--scaled-percentages | --no-scaled-percentages]
    [--blame-omit-exclusions | --no-blame-omit-exclusions]
    [--skip-blame | --no-skip-blame] [--viewer {auto,none}] [-v]
    [--dry-run {0,1,2}]
    [-l | --list-extensions | --no-list-extensions]
    [-n N | -f PATTERN] [--subfolder SUBFOLDER] [--since SINCE]
    [--until UNTIL] [-e EXTENSIONS] [--deletions | --no-deletions]
    [--whitespace | --no-whitespace]
    [--empty-lines | --no-empty-lines] [--comments | --no-comments]
    [--copy-move N] [--multi-thread | --no-multi-thread]
    [--multi-core | --no-multi-core] [--ex-file PATTERN]
    [--ex-author PATTERN] [--ex-email PATTERN]
    [--ex-revision PATTERN] [--ex-message PATTERN] [--profile N]
    [PATH ...]

Overview
--------
The command line interface (CLI) can be used to start the GUI or to analyse
repositories directly from the command line. GUI and CLI share the same settings
file. They start by loading the settings from the settings file.

``-h`` ``--help``
  Display help and exit.


Mutually exclusive options
--------------------------

``--gui``
  Start the GUI with settings loaded from the settings file.

``-V`` ``--version``
  Output version information and exit.

``--show-settings``
  Output the location of the settings file and its values, then exit.

``--save``
  Save the current settings to the settings file.

``--save-as PATH``
  Save the current settings to the specified file.

``--load PATH``
  Load settings from the specified file.

``--reset``
  Reset the settings to their default values.


Input
-----
``PATH ...``
  The path to the folder containing the repositories to be analysed. Multiple
  paths can be specified and all paths are searched for repositories.

  IF ``PATH`` is a repository, that repository is analyzed.

  If ``PATH`` is a folder, but not a repository, all folder and subfolders up to
  the value of the ``--depth``  option are searched for repositories and the
  repositories found are analysed. The output file for each repository is placed
  in the parent directory of the repository.

``-d N`` ``--depth N``
  Integer value bigger or equal to zero, that represents the number of levels of
  subfolders that is searched for repositories, *default* ``5``.

  * ``-d 0``: the input folder itself must be a repository.
  * ``-d 1``: only the input folder is searched for repository folders for
    analysis.

Output
------
For the CLI, the output files generated depend on the output formats specified
in the ``-F`` or ``--format`` option. By default, output is generated in the
file ``gitinspect.ext``, where ``ext`` is defined by the selected :ref:`output
formats <output-formats-cli>`.

``-o FILEBASE`` ``--output FILEBASE``
  The output filename, without extension and without parents is ``FILEBASE``.
  Default: ``gitinspect``.

``--fix {pre,post,none}``

  * ``-f pre`` output file name is ``REPONAME-FILEBASE``.
  * ``-f post`` output file name is ``FILEBASE-REPONAME``.
  * ``-f none`` output file name is ``FILEBASE``.



Output generation and formatting
--------------------------------
.. _output-formats-cli:

Output formats
^^^^^^^^^^^^^^
``-F FORMAT`` ``--format FORMAT``
  Selects for which file formats output is generated. Available choices are
  ``auto``, ``html``, ``excel`` and ``text``.
  For more information on the output formats, see :doc:`output-formats`.

.. _blame-sheets-cli:

Options
^^^^^^^
.. note::

  A blame worksheet or html blame tab shows the contents of a file and indicates
  for each line in the file in which commit the line was last changed, at which
  date and by which author. The color of the line indicates the author of the
  last change. The blame output is generated for each file that is analysed.

``--show-renames``
  Show previous file names and alternative author names and emails in the
  output.

  Some authors use multiple names and emails in various commits.
  Gitinspectorgui can detect this if there is overlap in either the name or
  email in author-email combinations in commits. If show-renames is active, all
  names and emails of each author are shown. If inactive, only a single name and
  email are shown per author.

  For files that have been renamed at some point in their history, all previous
  names are shown in the output.

``--scaled-percentages``
  For each column with output in percentages, e.g. ``Insertions %``, add a
  column ``Scaled insertions %``, which equals the value of ``Insertions %``
  multiplied by the number of authors in the repository.

``--blame-omit-exclusions``
  Blame lines can be excluded for three reasons:

  1. The author of the blame line is excluded by the ``--ex-author PATTERN``
     exclusion pattern.
  2. The blame line is a comment line. By default, comment lines are excluded.
     They can be included by the option ``--comments``.
  3. The blame line is an empty line. By default, empty lines are excluded. They
     can be included by the option ``--empty-lines``.

Excluded lines are not attributed to their author as blame lines. They are shown
in the blame sheets as white, uncolored lines. When the option
``--blame-omit-exclusions`` is active, the blame sheets omit the excluded lines
from the blame output.

``--skip-blame``
  Do not output Excel blame sheets, as explained below.



``--viewer {auto,none}``

  * ``auto``: open the viewer for the selected output format as
    specified in the :ref:`output-formats-cli` section.

  * ``none``: never open any viewer.

``-v``, ``--verbosity``
  More verbose output for each ``v``, e.g. ``-vv``.

``--dry-run {0,1,2}``
  Do not perform the analysis, but output the commands that would be executed.
  The value of ``0`` means no dry run, ``1`` means a dry run with the commands
  that would be executed

``-l`` ``--extensions-list`` ``--no-extensions-list``
  Output a list of file extensions used in the current branch of the
  repository.



Inclusions and exclusions
^^^^^^^^^^^^^^^^^^^^^^^^^
``-n N`` ``--n-files N``
  Generate output for the first ``N`` files with the highest number of
  insertions for each repository. For excel, this results in four worksheets:
  :guilabel:`Authors`, :guilabel:`Authors-Files` and :guilabel:`Files`. The
  worksheet :guilabel:`Authors` combines the results of all files, the
  worksheets :guilabel:`Authors-Files` and :guilabel:`Files-Authors` show
  results per author and per file, and the worksheet :guilabel:`Files` combines
  the results of all authors.

  In addition, for each of the N files, a blame worksheet is generated, unless
  the option :guilabel:`Skip blame` is active, see :ref:`blame-sheets-cli`.

``-f PATTERN``, ``--file-pattern PATTERN``
  Show only files matching the specified pattern. If a pattern is specified, it
  takes priority over the default value of ``N`` in option ``--show-n-files``.
  The options ``--show-files`` and ``--show-files-pattern`` are mutually
  exclusive.

  If options ``-n-files N`` and ``--file-pattern PATTERN`` are both missing, a
  default value of ``--n-files 5`` is used.

  To show all files, use the pattern ``.*``.

``--subfolder``
  Restrict analysis of the files of the repository to the files in this folder
  and its subfolders.

``--since DATE``
  Only show statistics for commits more recent than a specific date. The
  ``DATE`` format is YYYY-M-D, where leading zeros are optional for month and
  day, e.g.
  ``--since 2022-1-31`` or ``--since 2022-01-31``.

``--until DATE``
  Only show statistics for commits older than a specific date. See ``--since``
  for the format of ``DATE``.

``-e EXTENSIONS`` ``--extensions EXTENSIONS``
  A comma separated list of file extensions to include when computing
  statistics. The default extensions used are: ``java, c, cc, cpp, h, hh,
  hpp, py, glsl, rb, js, sql, cif, tooldef``.

  For more information, see the :ref:`supported languages table
  <languages_table>` below.

  Specifying a single ``*`` asterisk character includes files with no extension.
  Specifying two consecutive ``**`` asterisk characters includes all files
  regardless of extension.


Analysis options
----------------
``--deletions``
  Include a column for Deletions in the output. This does not affect the blame
  output, because deleted lines cannot be shown. The default is not to include
  deletions.

``--whitespace``
    Include whitespace changes in the statistics. This affects the statics and
    the blame output. The default setting is to ignore whitespace changes.

``--empty-lines``
  Include empty lines in the blame calculations. This affects the color of the
  empty lines in the blame sheets.

  The default is not to include them and show all empty lines in the blame
  sheets as white.

  When this setting is active, empty lines are shown in the color of their
  author.

``--comments``
  Include whole line comments in the blame calculations. This affects the number
  of lines of each author.

  The default is not to include whole line comments, which means that such lines
  are not attributed to any author and are shown in the blame sheets as white.
  Whole line coments are not counted in the Lines column of the statistics
  output, potentially causing the sum of the Lines column to be less than the
  total number of lines in the file.

  When this setting is active, whole line comments are shown in the color as of
  their author and are counted in the Lines column of the statistics output.

``--copy-move N``
  .. include:: opt-hard.inc



Exclusion patterns
------------------
Specify exclusion patterns ``PATTERN``, describing file paths, author names or
emails, revisions or commit messages that should be excluded from the
statistics. Each exclusion option can be repeated multiple times.

``--ex-file PATTERN``
  Filter out files (or paths) containing any of the comma separated strings
  in ``PATTERN``. E.g. ``--ex-file myfile,test`` excludes files ``myfile.py``
  and ``testing.c``.

``--ex-author PATTERN``
  Filter out author names containing any of the comma separated strings in
  ``PATTERN``. E.g. ``--ex-author John`` excludes author ``John Smith``.

``--ex-email PATTERN``
  Filter out email addresses containing any of the comma separated strings
  in ``PATTERN``. E.g. ``--ex-email @gmail.com`` excludes all authors with a
  gmail address.

``--ex-revision PATTERN``
  Filter out revisions containing any of the comma separated hashes/SHAs
  in ``PATTERN``. When used with short hashes, the caret ``^`` is needed to make
  sure that only hashes starting with the specified string are excluded. E.g.
  ``--ex-revision ^8755fb33,^12345678`` excludes revisions
  that start with ``8755fb33`` or ``12345678``.

``--ex-message PATTERN``
  Filter out commit messages containing any of the comma separated strings
  in ``PATTERN``. E.g. ``--ex-message bug,fix`` excludes commits from analysis
  with commit messages such as ``Bugfix`` or ``Fixing issue #15``.

Matches are case insensitive, e.g. ``mary`` matches ``Mary`` and ``mary``, and
``John`` matches ``john`` and ``John``.

Matching is based on `python regular expressions
<https://docs.python.org/3/library/re.html>`_. Some additional examples of
patterns for ``--ex-file``:

``^init``
  Filter out statistics from all files starting with ``init``, e.g. ``init.py``.

``init$``
  Filter out statistics from all files ending with ``init``, e.g. ``myinit``.

``^init$``
  Filter out statistics from the file ``init``.

``init``
  Filter out statistics from all files containing ``init``, e.g. ``myinit``,
  ``init.py`` or ``myinit.py``.

Logging
-------
``--profile``
  Output profiling information.


.. _languages_table:

Supported languages
-------------------

To be defined.

.. .. list-table::

..   * - Language
..     - Comments
..     - Metrics
..     - File extensions
..     - Included in analysis by default
..   * - CIF
..     - Yes
..     - No
..     - cif
..     -  Yes
..   * - ToolDef
..     -  No
..     -  No
..     -  tooldef
..     -  Yes
..   * - ADA
..     - Yes
..     - No
..     - ada, adb, ads
..     - No
..   * - C
..     - Yes
..     - Yes
..     - c, h
..     - Yes
..   * - C++
..     - Yes
..     - Yes
..     - cc, h, hh, hpp
..     - Yes
..   * - C#
..     - Yes
..     - Yes
..     - cs
..     - No
..   * - GNU Gettext
..     - Yes
..     - No
..     - po, pot
..     - No
..   * - Haskell
..     - Yes
..     - No
..     - hs
..     - No
..   * - HTML
..     - Yes
..     - No
..     - html
..     - No
..   * - Java
..     - Yes
..     - Yes
..     - java
..     - Yes
..   * - JavaScript
..     - Yes
..     - Yes
..     - js
..     - Yes
..   * - LaTeX
..     - Yes
..     - No
..     - tex
..     - No
..   * - OCaml
..     - Yes
..     - No
..     - ml, mli
..     - No
..   * - OpenGL Shading Language
..     - Yes
..     - No
..     - glsl
..     - Yes
..   * - Perl
..     - Yes
..     - No
..     - pl
..     - No
..   * - PHP
..     - Yes
..     - No
..     - php
..     - No
..   * - Python
..     - Yes
..     - Yes
..     - py
..     - Yes
..   * - Ruby
..     - Yes
..     - No
..     - rb
..     - Yes
..   * - Scala
..     - Yes
..     - No
..     - scala
..     - No
..   * - SQL
..     - Yes
..     - No
..     - sql
..     - Yes
..   * - XML
..     - Yes
..     - No
..     - xml, jspx
..     - No
