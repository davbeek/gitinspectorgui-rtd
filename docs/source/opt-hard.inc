This option, with values from 0 to 4, affects only the Excel blame worksheets:

0. Do not detect moved or copied lines. This means that the author that moves or
   copies a set of lines becomes the new owner of the lines.
1. Detect moved or copied lines within a file. This means that the author that
   was the owner of the original lines remains the owner of the lines,
   independently of whoever copies or moves the lines.
2. Follow moved or copied lines across files. Consider as potential origin of a
   set of lines only files that were changed in the same commit.
3. Same as 2, but in addition, consider as potential origin of a set of lines
   also the files of the commit that created the file containing the set of
   lines.
4. Same as 3, but consider as potential origin of a set of lines also the files
   of all other commits. This can be a very expensive operation for large
   projects.

For more information, see `git blame <https://www.mankier.com/1/git-blame#-M>`_.
The option corresponds to the ``-M`` and ``-C`` options of the ``git blame``
command:

0. No ``-M`` or ``-C`` options.
1. ``-M`` option.
2. ``-C`` option.
3. ``-C -C`` options.
4. ``-C -C -C`` options.

A file is considered to be a renamed or copied version of another file if they
share 50% or more lines.

Note that the ``--track-cp-mv`` option does not affect the value of insertions
and deletions in the first three Excel worksheets :guilabel:`Authors`,
:guilabel:`Authors-Files` and :guilabel:`Files`.

The problem is that even though ``git log``, which is used to calculate
insertions and deletions, can detect moved or copied lines and show them in
different colors, it cannot use this information for the calculation of
insertions and deletions.
