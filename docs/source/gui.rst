GUI: Graphical User Interface
=============================

GUI overview
------------
Below, a picture of the complete GUI on macOS.

.. figure:: _files/gui.png

  The GUI of gitinspectorgui on macOS.

The two main parts of the GUI are:

1. The input part where the options are defined. This part can
   be scrolled up and down using the top scroll bar at the right.
2. The console output part, where progress output is presented to the user
   while the repositories are analysed. The console has its own scrollbar.

Top row buttons
---------------

Execute
  Start the analysis, using the parameters given in the GUI.

Clear
  Clear the console, the textual output box at the bottom.

Save
  Save all settings specified in the GUI to the currently active settings file,
  as is shown on the last line of the console in the figure of the GUI window.

Save As
  Save the settings specified in the GUI to a file. This file becomes the
  currently active settings file for the :guilabel:`Save` button.

Load
  Open a browse dialog to select a settings file to load. This file becomes the
  currently active settings file.

Reset
  Reset all options to their default values and reset the location of the
  currently active settings file to its default, operating system dependent,
  location.

About
  Opens a dialog with information about the application.

Help
  Prints a few lines op help output in the console.

Exit
  Leave the GUI.

Percentage box
  The percentage box at the far right has small up and down triangles to
  increase or decrease the maximum percentage of the height of the total GUI
  window that is taken up by the input part. The console takes up the remaining
  percentage.

  When the height of the GUI window is changed by dragging the top or bottom
  edges of the window, the height of the input part is kept unchanged while
  dragging. When the window height has become stable after dragging, the height
  of the input part is adjusted to the percentage value.


IO configuration
----------------
Input folder path
  Enter one or more comma separated folder paths in the text box, or select one
  using the :guilabel:`Browse` button.

.. _input-is-repo:

Input folder path is a repository
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. figure:: _files/gui-repo-select.png

If the input folder path is a repository, that repository is analysed and no
search for addtional repositories takes place.

Output file base
  The output filename without extension and without directories, default
  ``gitinspect``. See bottom right of the IO configuration panel.

Output file path
  The output file path depends on the selected output prepostfix (see next
  option). In the example figure, the input folder path is the path of the
  repository gitinspectorgui. Depending on the selected pre or postfix, the
  output file path is:

  * :guilabel:`Postfix with repo`: ``/Users/.../1-repos/grading/gitinspectorgui-gitinspect``.
  * :guilabel:`Prefix with repo`: ``/Users/.../1-repos/grading/gitinspect-gitinspectorgui``.
  * :guilabel:`No prefix or postfix`: ``/Users/.../1-repos/grading/gitinspect``.

Output prepostfix
  Select one of :guilabel:`Postfix with repo`,
  :guilabel:`Prefix with repo`, :guilabel:`No prefix or postfix` (default).

  Note that the output file is not placed inside of the repository, but in
  its parent folder.

Search depth
  Disabled and ignored in this case.


Input folder path is a folder but not a repository
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. figure:: _files/gui-folder-select.png

If the input folder path is not a repository, all folder and subfolders up to
the value of the :guilabel:`Search depth` option are searched for repositories
and the repositories found are analysed. The output file for each repository
found is placed in the parent directory of the repository.

Output file base
  For each repository found, the output file base is as specified for the case
  :ref:`input-is-repo`.

Output file path
  For each repository found, the output file path is as specified for the case
  :ref:`input-is-repo`.

Output prepostfix
  For the values :guilabel:`Postfix with repo` and :guilabel:`Prefix with repo`,
  the output file path for each repository found is as specified for the case
  :ref:`input-is-repo`.

  The value :guilabel:`No prefix or postfix` behaves differently. For this
  option, only a single output file is generated in the input folder path.

  The contents of this file is depends on the output format.

  For output format Excel, the Excel file contains the analysis results for each
  individual repository seperated from the other repositories in a single Excel
  file. Each worksheet has an additional column which specifies the name of the
  repository. No blame worksheets are generated.

Search depth
  Positive integer value that represents the number of levels of subfolders
  that is searched for repositories, *default* ``5``. For depth ``1``, only
  the repository in the input folder path, if present, is analysed.


Output generation and formatting
--------------------------------
.. _output-formats-gui:

Output formats
^^^^^^^^^^^^^^
Selects for which file formats output is generated. Available choices are
:guilabel:`auto`, :guilabel:`html`, :guilabel:`excel` and :guilabel:`text`. For
more information on the output formats, see :doc:`output-formats`.


Options
^^^^^^^
Show renames
  Show previous file names and alternative author names and emails in the
  output.

  Some authors use multiple names and emails in various commits.
  Gitinspectorgui can detect this if there is overlap in either the name or
  email in author-email combinations in commits. If show-renames is active, all
  names and emails of each author are shown. If inactive, only a single name and
  email are shown per author.

  For files that have been renamed at some point in their history, all previous
  names are shown in the output.

Scaled percentages
  For each column with output in percentages, e.g. :guilabel:`Changes %`, add a
  column :guilabel:`Scaled changes %`, which equals the value of
  :guilabel:`Changes %` multiplied by the number of authors in the repository.

Blame omit exclusions
  Blame lines can be excluded for three reasons:

  1. The author of the blame line is excluded by the :guilabel:`Author`
     :guilabel:`Exclusion pattern`.
  2. The blame line is a comment line. By default, comment lines are excluded.
     They can be included by the option :guilabel:`Comments`.
  3. The blame line is an empty line. By default, empty lines are excluded. They
     can be included by the option :guilabel:`Empty lines`.

Excluded lines are not attributed to their author as blame lines. They are shown
in the blame sheets as white, uncolored lines. When the option :guilabel:`Blame
omit exclusions` is active, the blame sheets omit the excluded lines from the
blame output.


Skip blame
  Do not output html blame tabs or Excel blame sheets.

.. _blame-sheets-gui:

.. note::

  A blame worksheet or html blame tab shows the contents of a file and indicates
  for each line in the file in which commit the line was last changed, at which
  date and by which author. The color of the line indicates the author of the
  last change. The blame output is generated for each file that is analysed.


Viewer
  Select :guilabel:`auto` or :guilabel:`none`.

  * :guilabel:`auto`: open the viewer for the selected output format as
    specified in the :ref:`output-formats-gui` section.

  * :guilabel:`none`: never open any viewer.

Debug
  - 0: No debug output (default).
  - 1: Show debug output in the console. Corresponds to the ``-v`` option
    in the CLI.
  - 2: Show more detailed debug output in the console. Corresponds to the
    ``-vv`` option in the CLI.


Dry run
  - 0: Normal analysis and output (default).
  - 1: Perform all required analysis and show the output in the console, but do
    not write any output files and do not open any viewers.
  - 2: Do not perform any analysis and do not produce any file or viewer output,
    but do print output lines to the console.

List extensions
  Output a list of file extensions used in the current branch of the
  repository.


Inclusions and exclusions
-------------------------
N files
  Generate output for the first `N` files with the highest number of insertions
  for each repository. For excel, this results in four worksheets:
  :guilabel:`Authors`, :guilabel:`Authors-Files` and :guilabel:`Files`. The
  worksheet :guilabel:`Authors` combines the results of all files, the worksheet
  :guilabel:`Authors-Files` and :guilabel:`Files-Authors` show results per
  author and per file, and the worksheet :guilabel:`Files` combines the results
  of all authors.

  In addition, for each of the N files, a blame worksheet is generated, unless
  the option :guilabel:`Skip blame` is active, see :ref:`blame-sheets-gui`.

File pattern
  Show only files matching the specified pattern. If a pattern is
  specified, it takes priority over the value of N in option :guilabel:`Show N
  files`, which is then ignored. When a pattern is present, the :guilabel:`Show
  N files` option is disabled.

  To show all files, use the pattern ``.*``.

Subfolder
  Restrict analysis of the files of the repository to the files in this folder
  and its subfolders.

Since
	Enter a date in the text box in the format 31/12/2022, or select one using the
	:guilabel:`.` button. Only show statistics for commits more recent than the
	given date.

Until
	Only show statistics for commits older than the given date.

Extensions
    A comma separated list of file extensions to include when computing
    statistics. The default extensions used are: java, c, cc, cpp, h, hh,
    hpp, py, glsl, rb, js, sql, cif, tooldef.

    Specifying a single ``*`` asterisk character includes files with no extension.
    Specifying two consecutive ``**`` asterisk characters includes all files
    regardless of extension.






Analysis options
----------------
Deletions
  Include a column for Deletions in the output. This does not affect the blame
  output, because deleted lines cannot be shown. The default is not to include
  deletions.

Whitespace
    Include whitespace changes in the statistics. This affects the statics and
    the blame output. The default setting is to ignore whitespace changes.

Empty lines
  Include empty lines in the blame calculations. This affects the color of the
  empty lines in the blame sheets.

  The default is not to include them and show all empty lines in the blame
  sheets as white.

  When this setting is active, empty lines are shown in the color of their
  author.

Comments
  Include whole line comments in the blame calculations. This affects the number
  of lines of each author.

  The default is not to include whole line comments, which means that such lines
  are not attributed to any author and are shown in the blame sheets as white.
  Whole line comments are not counted in the Lines column of the statistics
  output, potentially causing the sum of the Lines column to be less than the
  total number of lines in the file.

  When this setting is active, whole line comments are shown in the color as of
  their author and are counted in the Lines column of the statistics output.

Copy move
  .. include:: opt-hard.inc




.. _exclusion_pattern:

Exclusion patterns
------------------
File/Path
  Filter out files (or paths) containing any of the comma separated strings
  in the text box. E.g. ``myfile, test`` excludes files ``myfile.py`` and
  ``testing.c``.

Author
  Filter out author names containing any of the comma separated strings in
  the text box. E.g. ``John`` excludes author ``John Smith``.

Email
  Filter out email addresses containing any of the comma separated strings
  in the text box. E.g. ``@gmail.com`` excludes all authors with a gmail
  address.

Revision hash
  Filter out revisions containing any of the comma separated hashes/SHAs in the
  text box. When used with short hashes, the caret ``^`` is needed to make sure
  that only hashes starting with the specified string are excluded. E.g.
  ``^8755fb33,^12345678`` excludes revisions that start with ``8755fb33`` or
  ``12345678``.

Commit message
  Filter out commit messages containing any of the comma separated strings in
  the text box. E.g. ``bug, fix`` excludes commits from analysis with commit
  messages such as ``Bugfix`` or ``Fixing issue #15``.

Matches are case insensitive, e.g. ``mary`` matches ``Mary`` and ``mary``, and
``John`` matches ``john`` and ``John``.

Matching is based on `python regular expressions
<https://docs.python.org/3/library/re.html>`_. Some additional examples of
patterns in the File text box:

``^init``
  Filter out statistics from all files starting with ``init``, e.g. ``init.py``.

``init$``
  Filter out statistics from all files ending with ``init``, e.g. ``myinit``.

``^init$``
  Filter out statistics from the file ``init``.

``init``
  Filter out statistics from all files containing ``init``, e.g. ``myinit``,
  ``init.py`` or ``myinit.py``.
