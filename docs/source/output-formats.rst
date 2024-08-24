Output formats
==============
Multiple output formats can be selected, resulting in a separate output file for
every selected format. See the :ref:`GUI documentation <output-formats-gui>` or
:ref:`CLI documentation <output-formats-cli>` for information on this option.

Available output formats
------------------------
:guilabel:`html` and :guilabel:`excel`
  Output is generated in the form of tables and saved in a file per repository.

  :guilabel:`html` output is suitable for viewing in a web browser. For single
  repositories and for ten or fewer multiple repositories, the output is shown
  in a single window in the system web browser. For multiple repositories, each
  repository is shown in a separate tab.

  :guilabel:`Excel` tables are similar to :guilabel:`html` tables, but have
  more options. Each column header in an excel table has a triangle button which
  activates a dropdown menu for sorting and filtering. For single repositories,
  the output is opened in Excel for viewing.

:guilabel:`auto`
  The output for option :guilabel:`auto` (default for CLI) is always
  :guilabel:`html`. The exact form depends on the number of repositories
  analysed:

  - For single repositories, the :guilabel:`auto` option  is the only case where
    no file output is generated. The generated html output is shown in a web
    viewer.
  - For multiple repositories, the :guilabel:`auto` option generates
    :guilabel:`html` output which is saved in a file and shown in the default
    system browser.

  Multiple output formats can be selected at the same time, resulting for each
  repository in a separate output file for every selected format. In such a
  case, no output viewers are opened after analysis.

  When :guilabel:`auto` is selected, the other output formats are automatically
  deselected.

:guilabel:`text`
	Plain text with some very simple ANSI formatting.


Output tabs and sheets
----------------------
For html and excel, output is generated in tables. Tables are divided in two
parts: numerical analysis tables and blame tables. The format of the tables is
described in more detail in the next sections.

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
  :guilabel:`Skip blame` is active, see :ref:`blame-sheets-cli`.


Output columns numerical analysis tables
----------------------------------------

Default columns
^^^^^^^^^^^^^^^
The default columns in the text output and in the Authors sheet of the Excel
output follow below.

.. :guilabel:`Repository`
..   Name of the repository folder. Present only when multiple repositories are
..   analysed simultaneously and results are combined in one output file.

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
   authors and files over the complete lifetime of the files, inclusing
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


Output columns blame tables
---------------------------
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
