Output formats
==============
Multiple output formats can be selected, resulting in a separate output
file for every selected format. See the :ref:`CLI documentation <formats>` for
information on this option.

Available output formats
------------------------
:guilabel:`excel`
  Excel output is generated in the form of a table. Tables are suited for
  sorting and filtering the analysis results. Each column header in the table
  has a triangle button, which activates a dropdown menu for sorting and
  filtering.

  When multiple repositories are analysed simultaneously, excel presents the
  data for each repository separately from the other repositories, using an
  additional column for the repository name. This is unlike the text, html, json
  and xml options, where the results for all repositories are merged.

:guilabel:`text`
	Plain text with some very simple ANSI formatting, suitable for console output.
	This is the default output format of the CLI.


Output columns
--------------

Default columns
^^^^^^^^^^^^^^^

We discuss the columns that are present in the output by default in the text
output and in the Authors sheet of the Excel output.

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

  Where :guilabel:`SumLines` is the sum the values of :guilabel:`Lines` for each of
  the :guilabel:`NrAuthors` authors of the repository.

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

  1. When :guilabel:`Insertions` = :guilabel:`Lines`, we get maximum stability of
     100%.
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
  :guilabel:`Age` is expressed in either weeks or months, depending on the value
  of option :guilabel:`Weeks` in :ref:`general_config`.

1. The :guilabel:`Age` of an inserted line is the difference between the current time and
   the time of the commit of the insertion.
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
   authors and files over the complete lifetime of the files, inclusing insertions in previous versions of the file
   in the case of file renames.

:guilabel:`Comments %`
  Percentage of comment lines in the :guilabel:`Lines` owned by an author. A
  comment line is either a single or multi comment line. Only full line comments
  are considered comment lines. For instance, for Python, the following line is
  comment line:

  .. code-block:: python

    # Start of variable declarations

  wheras the following line is not a comment line:

  .. code-block:: python

    x = 1  # Initialize x

  If we define :guilabel:`Comments` as the number of comment lines, then:

  :guilabel:`Comments %` = 100 * :guilabel:`Comments` / :guilabel:`Lines`


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
