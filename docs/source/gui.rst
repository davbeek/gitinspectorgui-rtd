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
   while the repositories are analyzed. The console has its own scrollbar.

Top row buttons
---------------

Execute
  Start the analysis, using the parameters given in the GUI.

Clear
  Clear the console, the textual output box at the bottom.

Help
  Prints a few lines op help output in the console.

About
  Opens a dialog with information about the application.

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


General guidelines
------------------
There are seven input fields in the GUI where space separated patterns can be
entered:

- Input folder path
- Include files: File patterns
- Five input fields for exclusion patterns



Quotes ``""`` or ``''``
^^^^^^^^^^^^^^^^^^^^^^^
In the input fields, quotes are needed to include spaces in a pattern. For
example, to exclude the authors John Smith and Mary in the Author exclusion
input field, the pattern should be entered as ``"John Smith" Mary``.

Asterisk ``*``
^^^^^^^^^^^^^^^
The asterisk ``*`` is a wildcard character that matches zero or more characters,
just like in the shell. For example, to exclude all files with the extension
``.py``, the pattern should be entered as ``*.py``.



IO configuration
----------------
Input folder path
  Enter one or more comma separated folder paths in the text box, or select one
  using the :guilabel:`Browse` button. The paths are searched for repositories.

.. _input-is-repo:

Input folder path is a repository
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. figure:: _files/gui-repo-select.png

If the input folder path is a repository, that repository is analyzed and no
search for additional repositories takes place.

Output file path
  The output file path depends on the selected output prepostfix (see next
  option). In the example figure, the input folder path is the path of the
  repository ``1dh``. Depending on the selected pre or postfix, the
  output file path is:

  * :guilabel:`Postfix with repo`: ``/Users/.../1-repos/grading/1dh-gitinspect``.
  * :guilabel:`Prefix with repo`: ``/Users/.../1-repos/grading/gitinspect-1dh``.
  * :guilabel:`No prefix or postfix`: ``/Users/.../1-repos/grading/gitinspect``.

Output prepostfix
  Select one of :guilabel:`Postfix with repo`,
  :guilabel:`Prefix with repo`, :guilabel:`No prefix or postfix` (default).

  Note that the output file is not placed inside of the repository, but in
  its parent folder.

Search depth
  Disabled and ignored in this case.

Output file base
  The output filename without extension and without directories, default
  ``gitinspect``.

Subfolder
  Restrict analysis of the files of the repository to the files in this folder
  and its subfolders. Remove the subfolder from the path of the files in the
  output.

N files
  Generate output for the `N` biggest files for each repository. The number of
  files for which results are generated can be smaller than `N` due to files
  being excluded by filters. Leave the field empty or set it to zero to show all
  files.

File patterns
  Show only files matching any of the space separated patterns. When the pattern
  is empty, the N largest files specified by option N files are shown.


Input folder path is a folder but not a repository
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. figure:: _files/gui-folder-select.png

If the input folder path is not a repository, all folder and subfolders up to
the value of the :guilabel:`Search depth` option are searched for repositories
and the repositories found are analyzed. The output file for each repository
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
  :ref:`input-is-repo`. The value :guilabel:`No prefix or postfix` is disabled
  in this case.

Search depth
  Positive integer value that represents the number of levels of subfolders
  that is searched for repositories, *default* ``5``. For depth ``1``, only
  the repository in the input folder path, if present, is analyzed.

The remaining options are as specified for the case :ref:`input-is-repo`.


Output generation and formatting
--------------------------------
.. _output-formats-gui:

Output formats
^^^^^^^^^^^^^^
Tick box :guilabel:`view` defines whether a viewer is opened on the analysis
results. The other tick boxes define for which file formats output is generated.
Available output formats are :guilabel:`html` and :guilabel:`excel`. For more
information on the output formats, see :doc:`output`.

Statistic output
^^^^^^^^^^^^^^^^
These options define the columns that are shown in the output of the four first
tables: Authors, Authors-Files, Files-Authors and Files.

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

Deletions
  Include a column for number of deleted lines in the output. This does not
  affect the blame output, because deleted lines cannot be shown. The default is
  not to include deletions.

Scaled %
  For each column with output in percentages, e.g. :guilabel:`% Insertions`, add
  a column :guilabel:`% Scaled insertions`, which equals the value of
  :guilabel:`% Insertions` multiplied by the number of authors in the
  repository.


.. _blame-sheets-gui:

Blame options
^^^^^^^^^^^^^
.. note::

  A blame worksheet or html blame tab shows the contents of a file and indicates
  for each line in the file in which commit the line was last changed, at which
  date and by which author. The color of the line indicates the author of the
  last change. The blame output is generated for each file that is analyzed.

History
  Values for the history option are:

  - :guilabel:`none` (default). The generated blame sheets show the lines of
    each file as they are in the latest commit.

  - :guilabel:`dynamic` and :guilabel:`static`. The top line of the blame sheet
    for each file shows all commits that have changed the file. The user can
    select a commit from the list to see the file as it was at that commit. The
    blame sheet then shows the file as it was at that commit, with the lines
    colored according to the author of the last change to that line. The
    differences between the :guilabel:`dynamic` and :guilabel:`static` modes
    are:

    In the dynamic mode, the blame sheet is generated on the fly when the user
    selects a commit from the list. When this mode is selected in the GUI,
    automatically the view option is set to true and the output formats html and
    excel are set the false. These options are then also disabled. Although the
    dynamic mode cannot be used in the GUI, it can be selected and saved, and
    then used in the CLI.

    In the static mode, the blame sheets for all commits in the top list are
    generated when the analysis is started and all generated blame sheets are
    embedded in the generated html file. When this mode is selected in the GUI,
    automatically the  output formats html and excel and set to true and false,
    respectively and both are disabled.

    When the blame history option is reset to :guilabel:`none`, the options
    view, html and excel are enabled.

Exclusions
  By means of this option, excluded blame lines can be hidden or shown or
  removed from the blame output.

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

Copy move
  .. include:: opt-copy-move.inc

Blame skip
  Do not output html blame tabs or Excel blame sheets.

Blame inclusions
^^^^^^^^^^^^^^^^

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
Whitespace
    Include whitespace changes in the statistics. This affects the statics and
    the blame output. The default setting is to ignore whitespace changes.

Multithread
    Use multiple threads to analyze the repositories. The default is to use a
    single thread.

Since
  Enter a date in the text box in the format YYYY-MM-DD, where leading zeros are
  optional for month and day, or select one using the :guilabel:`.` button. Only
  show statistics for commits more recent than the given date.

Until
	Only show statistics for commits older than the given date. See Since for the
	date format.

Verbosity
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

Extensions
  A comma separated list of file extensions to include when computing
  statistics. The default extensions used are: c, cc, cif, cpp, glsl, h, hh,
  hpp, java, js, py, rb, sql.
  Specifying a single ``*`` asterisk character includes files with no extension.
  Specifying two consecutive ``**`` asterisk characters includes all files
  regardless of extension.


Settings
--------
Save
  Save all settings specified in the GUI to the currently active settings file
  and print this file name to the console, see the above figure.

Save As
  Save the settings specified in the GUI to another file. This file becomes the
  currently active settings file.

Load
  Open a browse dialog to select a settings file to load. This file becomes the
  currently active settings file.

Reset
  Reset all settings to their default values and reset the location of the
  currently active settings file to its default, operating system dependent,
  location.

Toggle
  Toggle the representation of the settings file between the name and the full
  path.

.. _exclusion_pattern:

Exclusion patterns
------------------
Files/Paths
  Filter out files that match containing any of the space separated strings
  in the text box. E.g. ``myfile.py test*`` excludes files ``myfile.py`` and
  ``testing.c``.

Authors
  Filter out author names that match any of the space separated strings in
  the text box. E.g. ``"John Smith"`` excludes author ``John Smith`` and ``John
  Smith`` excludes author ``John`` and author ``Smith``.  The quotes are needed
  to include spaces in a pattern.

Emails
  Filter out email addresses taht match any of the space separated strings
  in the text box. E.g. ``*@gmail.com`` excludes all authors with a gmail
  address.

Revision hashes
  Filter out revisions that start with any of the space separated hashes/SHAs in
  the text box. E.g. ``8755fb 1234567`` excludes revisions that start with
  ``8755fb`` or ``1234567``.

Commit messages
  Filter out commit messages that match any of the space separated strings in
  the text box. E.g. ``bug* fix`` excludes commits from analysis with commit
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
