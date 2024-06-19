This option, with values from 0 to 4, affects only the Excel blame worksheets:

0. Do not detect moved or copied lines. This means that the author that moves or
   copies a set of lines becomes the new author of the lines.
1. Detect moved or copied lines within a file. This means that the (original)
   author of the lines that are moved or copied remains the author of the
   lines, independently of whoever copies or moves the lines.
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

The ``--copy-move`` option does not affect the value of insertions and deletions
in the statistics worksheets :guilabel:`Authors`,
:guilabel:`Authors-Files`, :guilabel:`Files-Authors` and :guilabel:`Files`.

The problem is that even tough ``git log --follow``, which is used by
gitinspectorgui to calculate insertions and deletions, does detect file
rename and copy operations, it does not detect moved or copied lines. Insertions
and deletions are always attributed to the author who does the change, even if
the lines are moved or copied from another file.
