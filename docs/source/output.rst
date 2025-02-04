Output
======
Multiple output formats can be selected, resulting in a separate output file for
every selected format. See the :ref:`GUI documentation <output-formats-gui>` or
:ref:`CLI documentation <output-formats-cli>` for information on this option.

Output formats and viewer options
---------------------------------
File output formats
^^^^^^^^^^^^^^^^^^^
:guilabel:`html`, :guilabel:`html blame history` and :guilabel:`excel`
  Output is generated in the form of tables and saved in a file per repository.

  :guilabel:`html` output is suitable for viewing in a web browser. For single
  repositories the output is shown in a single window in the system web browser.
  For multiple repositories, each repository is shown in a separate tab.

  :guilabel:`html blame history` output is similar to :guilabel:`html` output,
  but it includes blame information tables for each relevant commit in the
  repository. The option can lead to very large output files.

  :guilabel:`Excel` tables are similar to :guilabel:`html` tables, but have
  more options. Each column header in an excel table has a triangle button which
  activates a dropdown menu for sorting and filtering. For single repositories,
  the output is opened in Excel for viewing.

View option :guilabel:`auto`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
- In the case of file output, the output file is opened in the default viewer
  for the file type.

- If no file output format is selected, the output is shown in the system web
  browser. The address is of the form
  ``localhost:8080/?v=reponame-2d0c4e242077``, where ``reponame`` is the name of
  the repository and ``2d0c4e242077`` is a random unique 12-character string.
  When the user no longer needs the generated page(s), the page(s) should be
  closed, or the web browser can be closed, so that the server can be stopped
  and gitinspectorgui is ready for analysis of another repository.

View option :guilabel:`dynamic blame history`
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
- This option is allowed only when no file output formats are selected. The
  output pages that are displayed in the system web browser are similar to the
  pages generated for view option :guilabel:`auto` with no file output. The only
  difference is that additional blame information tables can be generated and
  displayed for each relevant commit in the repository.

  The output is also very similar to the output for the file format
  :guilabel:`html blame history`. The only difference is that where the
  additional blame tables for each relevant commit are allready present in the
  html output file generated with option :guilabel:`html blame history`, these
  tables are generated on the fly for the view option :guilabel:`dynamic blame
  history`.

More info on blame history output
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  For the output format :guilabel:`html blame history` and view option
  :guilabel:`dynamic blame history`, the blame pages generated for the web
  browser have and additional top line with a list of commits that have changed
  the file. The user can select a commit from the list to see the file as it was
  at that commit with the lines colored according to the author of the last change to that
  line.


Output tables
-------------
For html and excel, output is generated in tables. Html tables are show in a
browser window.

There are two kinds of tables: numerical analysis tables and blame tables. The
format of the tables is described in more detail in the next sections.

Numerical analysis tables
  Shown in four tables, each table in a separate tab (html) or worksheet:
  :guilabel:`Authors`, :guilabel:`Authors-Files` :guilabel:`Files-Authors` and
  :guilabel:`Files`. The worksheet :guilabel:`Authors` combines the results of
  all files, the worksheets :guilabel:`Authors-Files` and
  :guilabel:`Files-Authors` show results per author and per file, and the
  worksheet :guilabel:`Files` combines the results of all authors. The tables
  show among others the total number of insertions per author, per file, or per
  author-file combination. Also shown is the number of lines per author in the
  final version of each file.

Blame tables
  The options :guilabel:`N files` (``--n-files``) or :guilabel:`File pattern`
  (``--include-files``) select the files for analysis. For each of the selected
  files, a blame tab or worksheet is generated, unless the option
  :guilabel:`Blame skip` is active, see :ref:`Blame options GUI
  <blame-sheets-gui>` or :ref:`Blame options CLI <blame-sheets-cli>`.


Numerical analysis tables
-------------------------

Default columns
^^^^^^^^^^^^^^^
The default columns in the text output and in the Authors sheet of the Excel
output follow below.

.. :guilabel:`Repository`
..   Name of the repository folder. Present only when multiple repositories are
..   analyzed simultaneously and results are combined in one output file.

:guilabel:`Author`
  Author name(s). If the same author uses multiple names, they are
  separated by the ``|`` symbol.

  We define :guilabel:`NrAuthors` as the number of authors that have done
  commits in the considered repository, excluding any authors matching the
  :guilabel:`Author` :ref:`exclusion pattern <exclusion_pattern>`. The value of
  :guilabel:`NrAuthors` is used in several formulas that are given below.

:guilabel:`Email`
  Email address(es) of :guilabel:`Author`. If the same author uses multiple
  email addresses, they are separated by the ``|`` symbol.

:guilabel:`Lines %`
  Percentage of lines of code of this author. The author of a line
  is the author who last changed the line.

  :guilabel:`Lines %` = 100 :guilabel:`Lines` / :guilabel:`SumLines`

  Where :guilabel:`SumLines` is the sum the values of :guilabel:`Lines` for each
  of the :guilabel:`NrAuthors` authors of the repository.

:guilabel:`Insertions %`
  Percentage of insertions done by this author.

  :guilabel:`Insertions %` = 100 :guilabel:`Insertions` / :guilabel:`SumInsertions`

  Where :guilabel:`SumInsertions` is the sum of the values of the
  :guilabel:`Insertions` for each of the :guilabel:`NrAuthors` authors of the
  repository.

  The sum of :guilabel:`Insertions %` of the :guilabel:`NrAuthors` authors
  equals 100%.

:guilabel:`Lines`
  Total number of Lines of the :guilabel:`Author`. The :guilabel:`Author` of a
  line in a file is the one who made the last change to that line. The author of
  each line in a file is shown by `Git Blame
  <https://git-scm.com/docs/git-blame>`_.

:guilabel:`Insertions`
  Total number of insertions in in :guilabel:`Repository` done by
  :guilabel:`Author`.

:guilabel:`Stability %`
  :guilabel:`Stability %` = 100 :guilabel:`Lines` / :guilabel:`Insertions`.

  For example:

  1. When :guilabel:`Insertions` = :guilabel:`Lines`, we get maximum stability
     of 100%.
  2. When on average each line is changed once, then

    :guilabel:`Insertions` = 2 :guilabel:`Lines`

    since for the initial version of the file :guilabel:`Insertions` =
    :guilabel:`Lines`. Then

    :guilabel:`Stability` = 100 :guilabel:`Lines` / 2 :guilabel:`Lines` = 50%.

:guilabel:`Commits`
  Number of commits in :guilabel:`Repository` done by :guilabel:`Author`.

:guilabel:`Deletions`
  Total number of deletions in in :guilabel:`Repository` done by
  :guilabel:`Author`.

:guilabel:`Age`
  The average of the ages of the lines inserted by :guilabel:`Author`.
  :guilabel:`Age` is expressed as ``Y-M-D``, as in ``1-4-20`` meaning one year,
  4 months and 20 days old.

1. The :guilabel:`Age` of an inserted line is the difference between the current
   time and the time of the commit of the insertion.
2. The :guilabel:`Age` of a file is the average of
   the ages :guilabel:`Age_i` of each line inserted in the file over the
   lifetime of the file.

3. The :guilabel:`Age` of an author is the average of the ages of all lines
   inserted by that author.
4. In general, the :guilabel:`Age` of a combination of authors or files, is the
   average of the ages of each inserted line by that combination of authors
   or files:

   :guilabel:`Age` = (:guilabel:`Age_1` + ... +
   :guilabel:`Age_n`)/:guilabel:`n`

   where :guilabel:`n` is the total of all lines inserted by the combination of
   authors and files over the complete lifetime of the files, including
   insertions in previous versions of the file in the case of file renames.


Additional columns
^^^^^^^^^^^^^^^^^^

The option :guilabel:`Scaled percentages` inserts for each :guilabel:`%` column,
a :guilabel:`Scaled %` column. The average value in each :guilabel:`Scaled %`
column for the authors in the repository is always 100, independently of the
number of authors. This is achieved by multiplying the :guilabel:`%` column by
:guilabel:`NrAuthors` in each repository to get the :guilabel:`Scaled %` column.

:guilabel:`Scaled Lines %`
  Scaled percentage of :guilabel:`Lines %`.

:guilabel:`Scaled insertions %`
  Scaled percentage of :guilabel:`Insertions %`.


Blame tables
------------
HTML and Excel
^^^^^^^^^^^^^^
:guilabel:`ID`
  ID of the author shown in the second column. The author with ID 1 is the
  author of the most lines in the file. The author with ID 2 is the author of
  the second most lines in the file, and so on. The author of a line in the file
  in a blame tab or blame sheet is the author who last changed the line. All
  lines of the same author in the file have the same color. The first six
  authors have unique colors, the other authors share the same color.

:guilabel:`Author`
  The name of the author of the line.

:guilabel:`Date`
  Date of the commit.

:guilabel:`Message`
  Commit message.

:guilabel:`SHA`
  Short, seven character version of the commit hash.

:guilabel:`Commit number`
  Number of the commit in the repository, starting with number 1 for the initial
  commit. The commits or order by the time of the commit.

:guilabel:`Line`
  Line number in the file.

:guilabel:`Code`
  Code of the line.


HTML only
^^^^^^^^^
For HTML blame output, the Code column has three additional toggle buttons:

:guilabel:`Hide blame exclusions`
  The initial state of this button corresponds to the value of the Blame option
  :guilabel:`Exclude` (``--exclude-blame`` in ``{hide, show, remove}``).

  For the value :guilabel:`hide` (default), the button is initially active. For
  the value of :guilabel:`show`, the button is initially inactive and for the
  value of :guilabel:`remove`, the button itself is removed.

  When the button is active, the lines that are excluded from the blame analysis
  as a result of the exclude pattern options, such as ``--exclude-files`` and
  ``--exclude-authors`` are not displayed.

:guilabel:`Hide empty lines`
  The initial state of this button corresponds to the value of the Blame
  inclusions option :guilabel:`Empty lines` (``--empty-lines`` or
  ``--no-empty-lines``).

  For option ``--no-empty-lines``, the :guilabel:`Hide empty lines` button is
  initially active. For option ``--empty-lines``, the button is initially
  inactive.

  When the button is active, empty lines in the blame output are hidden. When
  the button is inactive and option ``exclude-blame`` is not set to ``remove``
  and button :guilabel:`Hide blame exclusions` is inactive, the empty lines are
  shown. When the value of option ``--exclude-blame`` is set tot ``remove``,
  the button is removed.

:guilabel:`Hide colors`
  Removes all colors from the blame lines and shows all lines in white.


Excel only
^^^^^^^^^^
For Excel blame output, the values ``hide`` and ``show`` of option
``--exclude-blame`` have no effect. The value ``remove``, removes the excluded
blame lines from the Excel blame output sheets.
