Background information
======================

The gitinspector algorithm is based on the output from ``git log``, see the
`git-log manual pages <https://www.mankier.com/1/git-log>`_. Some options on how
``git log`` analyses the repositories cannot be changed by the user. These are:

Ignore changes in whitespace are ignored ``git log --ignore-all-space``
  Ignore whitespace when comparing lines. This ignores differences even if one
  line has whitespace where the other line has none.

Ignore changes in empty lines ``git log --ignore-blank-lines``
  Ignore changes whose lines are all blank.

Ignore spacing for move detection ``git log --color-moved-ws=igore-all-space``
  The algorithm tries to detect moved blocks of code, so that they do not show
  up as changes. This option also ignores whitespace when comparing lines and
  thus ignores differences even if one line has whitespace where the other line
  has none.
