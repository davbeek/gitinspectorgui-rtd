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


Excel columns
-------------

Default columns
^^^^^^^^^^^^^^^

:guilabel:`Repository`
  Name of the repisotry folder

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

:guilabel:`Commits`
  Number of commits in :guilabel:`Repository` done by :guilabel:`Author`.

:guilabel:`Insertions`
  Total number of insertions in in :guilabel:`Repository` done by
  :guilabel:`Author`.

:guilabel:`Deletions`
  Total number of deletions in in :guilabel:`Repository` done by
  :guilabel:`Author`.

:guilabel:`LOC`
  Total number of Lines Of Code that the :guilabel:`Author` `owns`. An
  :guilabel:`Author` is said to `own` a line of a file, when that
  :guilabel:`Author` is the one who made the last change to that line. The
  `owner` of each line in a file is shown by `Git Blame
  <https://git-scm.com/docs/git-blame>`_.

:guilabel:`Insertions %`
  Percentage of insertions done by this author.

  :guilabel:`Insertions %` = 100 :guilabel:`Insertions` / :guilabel:`SumInsertions`

  Where :guilabel:`SumInsertions` is the sum of the values of the
  :guilabel:`Insertions` for each of the :guilabel:`NrAuthors` authors of the
  repository.

  The sum of :guilabel:`Insertions %` of the :guilabel:`NrAuthors` authors
  equals 100%.

:guilabel:`Changes %`
  Percentage of changes done by this author.

  :guilabel:`Changes` = :guilabel:`Insertions` + :guilabel:`Deletions`.

  :guilabel:`Changes %` = 100 :guilabel:`Changes` / :guilabel:`SumChanges`

  Where :guilabel:`SumChanges` is defined similar to :guilabel:`SumInsertions`.

:guilabel:`LOC %`
  Percentage of lines of code `owned` by this author.

  :guilabel:`LOC %` = 100 :guilabel:`LOC` / :guilabel:`SumLOC`

  Where :guilabel:`SumLOC` is the sum the values of :guilabel:`LOC` for each of
  the :guilabel:`NrAuthors` authors of the repository.


:guilabel:`Stability %`
  :guilabel:`Stability %` = 100 :guilabel:`LOC` / :guilabel:`Insertions`.

  For example:

  1. When :guilabel:`Insertions` = :guilabel:`LOC`, we get maximum stability of
     100%.
  2. When on average each line is changed once, then

    :guilabel:`Insertions` = 2 :guilabel:`LOC`

    since for the initial version of the file :guilabel:`Insertions` =
    :guilabel:`LOC`. Then

    :guilabel:`Stability` = 100 :guilabel:`LOC` / 2 :guilabel:`LOC` = 50%.


:guilabel:`Age`
  The average of the ages of the lines `owned` by :guilabel:`Author`.
  :guilabel:`Age` is expressed in either weeks or months, depending on the value
  of option :guilabel:`Weeks` in :ref:`general_config`.

1. The :guilabel:`Age` of a line is the difference between the current time and
   the time of the commit of the last change of that line.
2. The :guilabel:`Age` of a file, with :guilabel:`n` lines, is the average of
   the ages :guilabel:`Age_i` of each line :guilabel:`i`:

   (:guilabel:`Age_1` + ... + :guilabel:`Age_n`)/:guilabel:`n`.

3. The :guilabel:`Age` of an author is the average of all lines `owned` by that
   author, so the average of the ages of all lines last changed by that author.
4. In general, the :guilabel:`Age` of a combination of authors or files, is the
   average of the ages of the lines belonging to that combination of authors or
   files. The number of lines belonging to a specific combination of files or
   authors is the :guilabel:`LOC` value, so to calculate the average of the
   ages of each line, we have the formula:

   :guilabel:`Age` = (:guilabel:`Age_1` + ... +
   :guilabel:`Age_LOC`)/:guilabel:`LOC`.

:guilabel:`Comments %`
  Percentage of comment lines in the :guilabel:`LOC` lines `owned` by author. A
  comment line is either a single or multi comment line. Only full line comments
  are considered comment lines. For instance, for Python, the following line is
  comment line:

  .. code-block:: python

    # Start of variable declarations

  wheras the following line is not a comment line:

  .. code-block:: python

    x = 1  # Initialize x

  If we define :guilabel:`Comments` as the number of comment lines, then:

  :guilabel:`Comments %` = :guilabel:`Comments` / :guilabel:`LOC`




Additional columns
^^^^^^^^^^^^^^^^^^

The option :guilabel:`Scaled percentages` inserts for each :guilabel:`%` column,
a :guilabel:`Scaled %` column. The average value in each :guilabel:`Scaled %`
column for the authors in the repository is always 100, independently of the
number of authors. This is achieved by multiplying the :guilabel:`%` column by
:guilabel:`NrAuthors` in each repository to get the :guilabel:`Scaled %` column.

:guilabel:`Scaled insertions %`
  Scaled percentage of :guilabel:`Insertions %`.

:guilabel:`Scaled changes %`
  Scaled percentage of :guilabel:`Changes %`.

:guilabel:`Scaled LOC %`
  Scaled percentage of :guilabel:`LOC %`.
