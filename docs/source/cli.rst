CLI: Command Line Interface
===========================
Synopsis
--------

.. code:: text

  gitinspectorgui
    [-h]
    [--gui | --show | --save | --save-as PATH | --load PATH | --reset | -V | --about]
    [-d DEPTH] [--subfolder SUBFOLDER] [-n [N]] [-f [PATTERNS ...]]
    [-o FILE_BASE] [--fix {prefix,postfix,nofix}]
    [--view | --no-view] [-F [FORMAT ...]]
    [--show-renames | --no-show-renames]
    [--deletions | --no-deletions]
    [--scaled-percentages | --no-scaled-percentages]
    [--blame-history {none,dynamic,static}]
    [--blame-exclusions {hide,show,remove}] [--copy-move N]
    [--blame-skip | --no-blame-skip]
    [--empty-lines | --no-empty-lines] [--comments | --no-comments]
    [--whitespace | --no-whitespace] [--since SINCE] [--until UNTIL]
    [-v] [--dry-run {0,1,2}] [-e [EXTENSIONS ...]]
    [--multithread | --no-multithread] [--multicore | --no-multicore]
    [--ex-files [PATTERNS ...]] [--ex-authors [PATTERNS ...]]
    [--ex-emails [PATTERNS ...]] [--ex-revisions [PATTERNS ...]]
    [--ex-messages [PATTERNS ...]] [--profile N]
    [PATH ...]

Overview
--------
The command line interface (CLI) can be used to start the GUI or to analyze
repositories directly from the command line. GUI and CLI share the same settings
file. They start by loading the settings from the settings file.

``-h`` ``--help``
  Display help and exit. This has priority over the other settings.


General guidelines
------------------
There are eight options where space separated patterns can be entered:

- ``PATH ...``: Path patterns to input repositories or folders
- ``--include-files PATTERNS``: File patterns to include
- ``--extensions EXTENSIONS``: File extensions to include
- ``--ex-... PATTERNS``: Five input fields for exclusion patterns


Multiple patterns
^^^^^^^^^^^^^^^^^
Multiple patterns can be entered in the input fields by separating them with
spaces. For example, to include files with the extensions ``java`` and ``py``,
the pattern can be entered as ``-e java py``. Multiple patterns can also be
specified by repeating the option, e.g. ``-e java -e py``.

Separating options from ``PATH ...``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
When an option can be followed by multiple patterns, the separator ``--`` is
needed when the patterns are followed by the ``PATH ...`` input specification.
For example, to include files with the extensions ``java`` and ``py`` in the
input repository folder ``repo``, the command can be entered as ``python -m
gigui -e java py -- repo``. To avoid the ``--`` separator, the command can be
entered as ``python -m gigui repo -e java py``.

Quotes ``""`` or ``''``
^^^^^^^^^^^^^^^^^^^^^^^
In the input fields, quotes are needed to include spaces in a pattern. For
example, to exclude the authors John Smith and Mary in the Author exclusion
input field, the pattern should be entered as ``"John Smith" Mary``.

Asterisk ``*``
^^^^^^^^^^^^^^^
The asterisk ``*`` is a wildcard character that matches zero or more characters.
To avoid interpretation of the asterisk as a wildcard by the shell, the asterisk
or the entire input pattern can be enclosed in quotes.

Case insensitivity
^^^^^^^^^^^^^^^^^^
Matches are case insensitive, e.g. ``mary`` matches ``Mary`` and ``mary``, and
``John`` matches ``john`` and ``John``.

Abbreviations
^^^^^^^^^^^^^
Option names can be abbreviated as long as the abbreviation is unique and
unambiguous. For example, the option ``--ex-authors`` can be abbreviated as
``--ex-a`` or ``--ex-au``, as there is no other option that starts with
``--ex-a``.


Mutually exclusive options
--------------------------
``--gui``
  Start the GUI with settings loaded from the settings file.

``--show``
  Output the location of the settings file and its values, then exit.

``--save``
  Save the current settings to the settings file.

``--save-as PATH``
  Save the current settings to the specified file. This file becomes the
  currently active settings file.

``--load PATH``
  Load settings from the specified file. This file becomes the currently active
  settings file.

``--reset``
  Reset all settings to their default values and reset the location of the
  currently active settings file to its default, operating system dependent,
  location.

``-V`` ``--version``
  Output version information and exit.

``--about``
  Output information about the program and exit.


Input
-----
``PATH ...``
  The path pattern to the folder(s) containing the repositories to be analyzed.
  Multiple paths can be specified and all paths are searched for repositories.

  IF ``PATH`` is a repository, that repository is analyzed and no search for
  additional repositories takes place.

  If ``PATH`` is a folder, but not a repository, all folder and subfolders up to
  the value of the ``--depth``  option are searched for repositories and the
  repositories found are analyzed. The output file for each repository is placed
  in the parent directory of the repository.

``-d N`` ``--depth N``
  Integer value bigger or equal to zero, that represents the number of levels of
  subfolders that is searched for repositories, *default* ``5``.

  * ``-d 0``: the input folder itself must be a repository.
  * ``-d 1``: only the input folder is searched for repository folders for
    analysis.

``--subfolder SUBFOLDER``
  Restrict analysis of the files of the repository to the files in this folder
  and its subfolders. Remove the subfolder from the path of the files in the
  output.

``-n N`` ``--n-files N``
  Generate output for the ``N`` biggest files for each repository. The number of
  files for which results are generated can be smaller than ``N`` due to files
  being excluded by filters. Leave the field empty or set it to zero to show all
  files. Default is 5.

``-f PATTERNS``, ``--include-files PATTERNS``
  Show only files matching any of the space separated patterns. When the pattern
  is empty (``-f ""``), the ``N`` largest files specified by option ``-n N``
  files are shown.


Output
------
``-o FILEBASE`` ``--output FILEBASE``
  The output filename, without extension and without parents is ``FILEBASE``.
  Default: ``gitinspect``.

``--fix {prefix,postfix,nofix}``

  * ``-f prefix`` output file name is ``REPONAME-FILEBASE``.
  * ``-f postfix`` output file name is ``FILEBASE-REPONAME``.
  * ``-f nofix`` output file name is ``FILEBASE``.

Output generation and viewing
-----------------------------
``--view, --no-view``
  Open a viewer is opened on the analysis results.

.. _output-formats-cli:

``-F FORMAT`` ``--format FORMAT``
  Selects for which file formats output is generated. Available choices are
  ``html``and ``excel``. To select more than one output format separate them by
  spacing or repeat the option, e.g. ``-F html excel`` or ``-F html -F excel``.
  For more information on the output formats, see :doc:`output`.


Statistics output
-----------------
``--show-renames, --no-show-renames``
  Show previous file names and alternative author names and emails in the
  output.

  Some authors use multiple names and emails in various commits. Gitinspectorgui
  can detect this if there is overlap in either the name or email in
  author-email combinations in commits. If show-renames is active, all names and
  emails of each author are shown. If inactive, only a single name and email are
  shown per author.

  For files that have been renamed at some point in their history, all previous
  names are shown in the output.

``--deletions, --no-deletions``
  Include a column for the number of deleted lines in the output. This does not
  affect the blame output, because deleted lines cannot be shown. The default is
  not to include deletions.

``--scaled-percentages, --no-scaled-percentages``
  For each column with output in percentages, e.g. ``Insertions %``, add a
  column ``Scaled insertions %``, which equals the value of ``Insertions %``
  multiplied by the number of authors in the repository.


.. _blame-sheets-cli:

Blame options
-------------

.. note::

  A blame worksheet or html blame tab shows the contents of a file and indicates
  for each line in the file in which commit the line was last changed, at which
  date and by which author. The color of the line indicates the author of the
  last change. The blame output is generated for each file that is analyzed.

``--blame-history {none,dynamic,static}``

  - ``none`` (default). The generated blame sheets show the lines of each file
    as they are in the latest commit.

  - ``dynamic`` and ``static``. The top line of the blame sheet for each file
    shows all commits that have changed the file. The user can select a commit
    from the list to see the file as it was at that commit. The blame sheet then
    shows the file as it was at that commit, with the lines colored according to
    the author of the last change to that line. The differences between the
    ``dynamic`` and ``static`` modes are:

    In the dynamic mode, the blame sheet is generated on the fly when the user
    selects a commit from the list.

    In the static mode, the blame sheets for all commits in the top list are
    generated when the analysis is started and all generated blame sheets are
    embedded in the generated html file. When this mode is selected in the GUI,
    automatically the  output formats html and excel and set to true and false,
    respectively and both are disabled.


``--blame-omit-exclusions, --no-blame-omit-exclusions``
  By means of this option, excluded blame lines can be hidden or shown or
  removed from the blame output. Blame lines can be excluded for three reasons:

  1. The author of the blame line is excluded by the ``--ex-author PATTERNS``
     exclusion pattern.
  2. The blame line is a comment line. By default, comment lines are excluded.
     They can be included by the option ``--comments``.
  3. The blame line is an empty line. By default, empty lines are excluded. They
     can be included by the option ``--empty-lines``.

  Excluded lines are not attributed to their author as blame lines. They are
  shown in the blame sheets as white, uncolored lines. When the option
  ``--blame-omit-exclusions`` is active, the blame sheets omit the excluded
  lines from the blame output.

``--copy-move N``
  .. include:: opt-copy-move.inc

``--blame-skip, --no-blame-skip``
  Do not output html blame tabs or Excel blame sheets.


Blame inclusions
----------------

  The options ``--empty-lines``, ``--comments`` and ``--blame-omit-exclusions``
  affect the blame output. The options ``--empty-lines`` and ``--comments`` are
  used to include empty lines and comment lines in the blame output. The option
  ``--blame-omit-exclusions`` is used to hide or show or remove excluded blame
  lines from the blame output.

``--empty-lines, --no-empty-lines``
  Include empty lines in the blame calculations. This affects the color of the
  empty lines in the blame sheets. The default is not to include them
  (``--no-empty-lines``) and show all empty lines in the blame sheets as white.
  When this setting is active, empty lines are shown in the color of their
  author.

.. _cli-comments:

``--comments, --no-comments``
  Include whole line comments in the blame calculations. This affects the number
  of lines of each author.

  The default is not to include whole line comments, which means that such lines
  are not attributed to any author and are shown in the blame sheets as white.
  Whole line comments are not counted in the Lines column of the statistics
  output, potentially causing the sum of the Lines column to be less than the
  total number of lines in the file.

  When this setting is active, whole line comments are shown in the color as of
  their author and are counted in the Lines column of the statistics output.

  A comment line is either a single or multi comment line. Only full line
  comments are considered comment lines. For instance, for Python, the following
  line is comment line:

  .. code-block:: python

    # Start of variable declarations

  whereas the following line is not a comment line:

  .. code-block:: python

    x = 1  # Initialize x
``--empty-lines, --no-empty-lines``
  Include empty lines in the blame calculations. This affects the color of the
  empty lines in the blame sheets. The default is not to include them
  (``--no-empty-lines``) and show all empty lines in the blame sheets as white.
  When this setting is active, empty lines are shown in the color of their
  author.

``--comments, --no-comments``
  Include whole line comments in the blame calculations. This affects the number
  of lines of each author.

  The default is not to include whole line comments, which means that such lines
  are not attributed to any author and are shown in the blame sheets as white.
  Whole line comments are not counted in the Lines column of the statistics
  output, potentially causing the sum of the Lines column to be less than the
  total number of lines in the file.

  When this setting is active, whole line comments are shown in the color as of
  their author and are counted in the Lines column of the statistics output.

  A comment line is either a single or multi comment line. Only full line
  comments are considered comment lines. For instance, for Python, the following
  line is comment line:

  .. code-block:: python

    # Start of variable declarations

  whereas the following line is not a comment line:

  .. code-block:: python

    x = 1  # Initialize x


General options
---------------
``--whitespace, --no-whitespace``
    Include whitespace changes in the statistics. This affects the statics and
    the blame output. The default setting is to ignore whitespace changes.

``--since DATE``
  Only show statistics for commits more recent than a specific date. The
  ``DATE`` format is YYYY-MM-DD, where leading zeros are optional for month and
  day, e.g. ``--since 2022-1-31`` or ``--since 2022-01-31``.

``--until DATE``
  Only show statistics for commits older than a specific date. See ``--since``
  for the format of ``DATE``.

``-v``, ``--verbosity``
  More verbose output for each ``v``: ``-v``, ``-vv`` or ``-vvv```. The maximum
  value 3 of the verbosity option in the GUI corresponds to ``-vvv`` in the CLI.

  - (default): Show a dot for each file that is analyzed for each repository.
  - ``-v``: Show the file name instead of a dot for each analyzed file.
  - ``-vv``: Show additional debug output in the console.
  - ``-vvv``: Show maximum debug output in the console.

``--dry-run {0,1,2}``

  - 0: Normal analysis and output (default).
  - 1: Perform all required analysis and show the output in the console, but do
    not write any output files and do not open any viewers.
  - 2: Do not perform any analysis and do not produce any file or viewer output,
    but do print output lines to the console.

``-e EXTENSIONS``, ``--extensions EXTENSIONS``
  A comma separated list of file extensions to include when computing
  statistics. The default extensions used are: ``c, cc, cif, cpp, glsl, h, hh,
  hpp, java, js, py, rb, sql``.

  Specifying an asterisk ``*`` includes all files, regardless of extension,
  including files without an extension. For more information, see the
  :doc:`supported`.


Multithread and multicore
-------------------------
  ``--multithread, --no-multithread``
    Analyse multiple files for changes and blames per repository using multiple
    threads.

  ``--multicore, --no-multicore``
    Execute multiple repositories using multiple cores.


Exclusion patterns
------------------
Specify space separated exclusion patterns ``PATTERNS``, describing file paths,
author names or emails, revisions or commit messages that should be excluded
from the statistics.

``--ex-authors PATTERNS``, ``--exclude-authors PATTERNS``
  Filter out author names containing any of the comma separated strings in
  ``PATTERNS``. E.g. ``"John Smith"`` excludes author ``John Smith`` and ``John
  Smith`` excludes author ``John`` and author ``Smith``.  The quotes are needed
  to include spaces in a pattern.

``--ex-emails PATTERNS``, ``--exclude-emails PATTERNS``
  Filter out email addresses containing any of the comma separated strings
  in ``PATTERNS``. E.g. ``--ex-email "*@gmail.com"`` excludes all authors with a
  gmail address. The quotes are needed to avoid interpretation of the asterisk
  as a wildcard by the shell.

``--ex-files PATTERNS``, ``--exclude-files PATTERNS``
  Filter out files (or paths) containing any of the comma separated strings in
  ``PATTERNS``. E.g. ``--ex-file myfile.py "test*"`` excludes files
  ``myfile.py`` and ``testing.c``. The quotes are needed to avoid interpretation
  of the asterisk as a wildcard by the shell.

``--ex-revisions PATTERNS``, ``--exclude-revisions PATTERNS``
  Filter out revisions that start with any of the space separated hashes/SHAs in
  the text box. E.g. ``--ex-revisions 8755fb 1234567`` excludes revisions that
  start with ``8755fb`` or ``1234567``.

``--ex-messages PATTERNS``, ``--exclude-messages PATTERNS``
  Filter out commit messages containing any of the comma separated strings in
  ``PATTERNS``. E.g. ``--ex-message "bug*" fix`` excludes commits from analysis
  with commit messages such as ``Bugfix`` or ``Fixing issue #15``.


Logging
-------
``--profile N``
  Output ``N`` lines of profiling output. Default 0.
