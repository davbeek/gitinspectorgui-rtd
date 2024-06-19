CLI: Command Line Interface
===========================
Synopsis
--------

.. code:: text

  gitinspectorgui
    [-h] [--gui] [--gui-from-cli] [-V] [--profile] [-d DEPTH]
    [-o FILEBASE] [--fix {pre,post,none}] [-F {text,excel}]
    [--scaled-percentages | --no-scaled-percentages]
    [--skip-blame | --no-skip-blame] [--subfolder SUBFOLDER]
    [-n N | -f PATTERN]
    [-l | --extensions-list | --no-extensions-list] [-e EXTENSIONS]
    [-M | --months | --no-months] [--since SINCE] [--until UNTIL]
    [--deletions | --no-deletions] [--whitespace | --no-whitespace]
    [--empty-lines | --no-empty-lines] [--comments | --no-comments]
    [--copy-move N] [--ex-file PATTERN] [--ex-author PATTERN]
    [--ex-email PATTERN] [--ex-revision PATTERN]
    [--ex-message PATTERN]
    [--settings-show-location | --settings-reset | --settings-change-location PATH]
    [-v]
    [PATH ...]

Overview
--------
The command line interface (CLI) can be used to start the GUI and provide it
with starting values for its options, or to analyze repositories directly from
the command line.

Unique for GUI
--------------
The GUI can be started in two ways:

-  Via option ``--gui``: this starts the GUI with settings loaded from the
   settings file.
-  Via option ``--gui-from-cli``: this starts the GUI by first loading the
   settings from the settings file and then overwriting some of the settings with the
   options provided on the command line.

Unique for CLI
--------------
Without options ``--gui`` or ``--gui-from-cli``, the CLI is used to analyse
repositories.

``-h`` ``--help``
  Display help and exit.

``--version``
  Output version information and exit.

``--profile``
  Output profiling information.

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
formats <formats>`.

``-o FILEBASE`` ``--output FILEBASE``
  The output filename, without extension and without parents is ``FILEBASE``.
  Default: ``gitinspect``.

``--fix {pre,post,none}``

  * ``-f pre`` output file name is ``REPONAME-FILEBASE``.
  * ``-f post`` output file name is ``FILEBASE-REPONAME``.
  * ``-f none`` output file name is ``FILEBASE``.

.. _formats:

``-F FORMAT`` ``--format FORMAT``
  Defines in which ``FORMAT`` output is generated: ``text`` *default* or
  ``excel``. Format options can be specified multiple times, to generated
  multiple output formats simultaneously. For more information about the various
  output formats, see :doc:`output-formats`.

Output format excel
-------------------
Options
^^^^^^^
``--scaled-percentages --no-scaled-percentages``
  For each column with output in percentages, e.g. ``Insertions %``, add a
  column ``Scaled insertions %``, which equals the value of ``Insertions %``
  multiplied by the number of authors in the repository.

``--skip-blame``
  Do not output Excel blame sheets, as explained below.

``--subfolder``
  Restrict analysis of the files of the repository to the files in this folder
  and its subfolders.

File selection
^^^^^^^^^^^^^^
``-f N`` ``--show-files N``
  Generate output for the first ``N`` files with the highest number of
  insertions for each repository. For excel, this results in four worksheets:
  :guilabel:`Authors`, :guilabel:`Authors-Files` and :guilabel:`Files`. The
  worksheet :guilabel:`Authors` combines the results of all files, the
  worksheets :guilabel:`Authors-Files` and :guilabel:`Files-Authors` show
  results per author and per file, and the worksheet :guilabel:`Files` combines
  the results of all authors.

  In addition, for each of the N files, a blame worksheet is generated, unless
  the option :guilabel:`Skip blame` is active, see :ref:`blame-sheets-cli`.

``-f PATTERN``, ``--show-files PATTERN``
  Show only those files matching the specified pattern. If a pattern is
  specified, it takes priority over the value of ``N`` in option
  ``--show-n-files``, which is then ignored.

  If options ``--show-files`` and ``--show-files-pattern`` are both missing, a
  deault value of ``--show-n-files 5`` is used.

.. _blame-sheets-cli:

Excel blame worksheets
^^^^^^^^^^^^^^^^^^^^^^
A blame worksheet shows the contents of each file and indicates for each line
in the file in which commit the line was last changed, at which date and by
which author.

Output format text
------------------
For this output format, output from multiple repositories is always merged as if
coming from a single repository.

``-l`` ``--extensions-list`` ``--no-extensions-list``
  Output a list of file extensions used in the current branch of the
  repository.


General configuration
---------------------
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

``--months`` ``--no-months``
  Show all statistical information in months instead of in weeks.

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

``--ex-author "^(?!(John Smith))"``
  Only show statistics from author ``John Smith``, by excluding all authors that
  are not John Smith. The backslash is needed to make sure that the CLI
  interpreter (bash) does not interpret the caret ``^``.

``--ex-author "^(?!([A-C]))"``
  Only show statistics from authors starting with the letters ``A/B/C``.

``--ex-email ".com$"``
  Filter out statistics from all email addresses ending with ``.com``.

Saved GUI settings
------------------
``--settings-reset``
  Reset the saved GUI settings to their default values.

``--settings-show-location``
  Print the location of the GUI settings file.

``--settings-change-location PATH``
  Change the location of the GUI settings file to ``PATH``.

Debugging
---------
``-v``, ``--verbose``
  More verbose output for each ``v``, e.g. ``-vv``.


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
