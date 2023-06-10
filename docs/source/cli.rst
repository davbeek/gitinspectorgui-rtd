CLI: Command Line Interface
===========================

Mandatory arguments to long options are mandatory for short options too. Boolean
arguments can only be given to long options.


Synopsis
--------

.. code::

  gitinspectorgui [-h] [-V] [-g | --gui-settings | --no-gui-settings] [-a] [-v]
                  [-F {html,htmlembedded,json,text,xml,excel,csv}]
                  [--scaled-percentages | --no-scaled-percentages] [-f NUMBER]
                  [--merged-repositories | --no-merged-repositories]
                  [-m | --metrics | --no-metrics] [-T | --timeline | --no-timeline]
                  [-u | --used-extensions | --no-used-extensions]
                  [-r | --responsibilities | --no-responsibilities] [-e EXTENSIONS]
                  [-H | --hard | --no-hard]
                  [-L | --localize-output | --no-localize-output]
                  [-w | --weeks | --no-weeks] [--since SINCE] [--until UNTIL]
                  [--ex-file PATTERN] [--ex-author PATTERN] [--ex-email PATTERN]
                  [--ex-revision PATTERN] [--ex-message PATTERN]
                  {gui,repo,folder,folders,urls,settings} ...


Unique for CLI
--------------
``-h``, ``--help``
  Display help and exit.

``--version``
  Output version information and exit.

``--examples``
  Show usage examples.

``-g``, ``--gui-settings``, ``--no-gui-settings``
  Use the global GUI settings file as starting point for the command line
  options.

``-v``, ``--verbose``
  More verbose output for each ``v``, e.g. ``-vv``.


Positional arguments
--------------------

Positional arguments are either for the GUI (``gui``) or for the CLI
(``repo``, ``folder``, ``folders``, ``urls`` or ``settings``):

``gui``
  Start the GUI.

``repo``
  ``[-h --help] [-f --fix PRE_POSTFIX] [-o --output FILE_BASE] REPO_PATH``

  Analyze the repository in ``REPO_PATH``. Functionality identical to GUI.

``folder``
  ``[-h --help] [-o --output FILE_BASE] [-d --depth N] [-m --multiple-output-files] PATH``

  Analyze all repositories found in folder ``PATH``. Functionality identical to
  GUI.

``folders``
  ``[-h --help] [-o --output-path O_PATH] [-d --depth N] [-m
  --multiple-output-files] PATHS``

  Analyze all repositories found in the given list of paths (``PATHS``) to input
  folders. Command unique for CLI.

``urls``
  ``[-h --help] [-o --output PATH] URLS``

  Download and analyze repositories specified via URLS.

``settings``
  ``[-h --help] {reset | show-location | change-location}``

  Reset global GUI settings or show/change settings file location.

IO arguments
------------
``checkout_tag TAG_ID``
  Checkout tag ``TAG_ID`` for all repositories found in ``input_folder``.

``-o BASEFILENAME``, ``--output BASEFILENAME``
  Generate output in the current directory in files ``BASEFILENAME.ext``, where
  ``ext`` takes on the values belonging to the selected output formats. Default:
  ``BASEFILENAME=gitinspect``.

``-d DEPTH``, ``--depth DEPTH``
  Number of levels of subfolders of the input_folder that is searched for
  repositories. ``DEPTH=1``, means that only the input_folder_path itself is
  searched. Default value is 5.

``--multiple_output_files``
  Splits the output for the 'Multiple local repositories' option into separate
  output files.

``-F FORMAT``, ``--format FORMAT``
  Defines in which ``FORMAT`` output is generated: ``text`` *default*, ``html``,
  ``htmlembedded``, ``json``, ``xml``. Format options can be specified multiple
  times, to generated multiple output formats simulataneously. See
  :doc:`output-formats`.


Output formats excel and csv
----------------------------
``--scaled-percentages``
  For each column with output in percentages, e.g. ``Insertions %``, add a
  column ``Scaled insertions %``, which equals the value of ``Insertions %``
  multiplied by the number of authors in the repository.

``--show-files NR_OF_FILES``
  Generate output for the first ``NR_OF_FILES`` files with the highest number of
  insertions for each repository.


Output formats text ... html
----------------------------
``-m``,  ``--metrics BOOL``
  Include checks for certain metrics during the analysis of commits.

``-T``, ``--timeline BOOL``
  Show commit timeline, including author names.

``-l``, ``--list-file-types BOOL``
  List all the file extensions available in the current branch of the
  repository.

``-r``,  ``--responsibilities BOOL``
  Show which files the different authors seem most responsible for.


General configuration
---------------------
Mandatory arguments to long options are mandatory for short options too. Boolean
arguments can only be given to long options.

``-f``, ``--file-types EXTENSIONS``
  A comma separated list of file extensions to include when computing
  statistics. The default ``EXTENSIONS`` used are: ``java, c, cc, cpp, h, hh,
  hpp, py, glsl, rb, js, sql``.

  Specifying a single ``*`` asterisk character includes files with no extension.
  Specifying two consecutive ``**`` asterisk characters includes all files
  regardless of extension.

``-H``, ``--hard BOOL``
  .. include:: opt-hard.inc

``-L``, ``--localize-output BOOL``
  By default, the generated statistics are in English. This flag localizes the
  generated output to the selected system language if a translation is
  available.

``-w``, ``--weeks BOOL``
  Show all statistical information in weeks instead of in months.

``--since DATE``
  Only show statistics for commits more recent than a specific date.

``--until DATE``
  Only show statistics for commits older than a specific date.


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
