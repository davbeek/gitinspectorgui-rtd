Frequently Asked Questions
==========================

This document defines a list of some frequently asked questions from users of
gitinspector and gitinspectorgui. If you can't find your question in this list,
there might very well be an issue available at the issue tracker of the original
`gitinspector repo <https://github.com/ejwa/gitinspector/issues>`_, or at the
`gitinspectorgui repo <https://gitlab.tue.nl/grading/gitinspector/-/issues>`_.
The oldest questions added to this list are at the top.

----

In our project, someone accidentally used two different e-mail addresses
when committing and now we have duplicates for the same user shown by the
generated gitinspector statistics.**

This can easily happen. Luckily, git itself (not gitinspector) offers a solution
via the use of a `.mailmap <https://git-scm.com/docs/gitmailmap>`_ file.

This problem is partly solved using the Excel or CSV output format, and is
scheduled to be fully solved in future releases of gitinspectorgui.

----

**Q: My insertions minus deletions in the statistics does not equal the number
of rows that have survived. There must be something wrong with the statistics!**

A: Probably not. The number of surviving rows will usually be different because
the contributions from other authors will interfere with the statistics. Some
other author might for example remove lines that you have written, or maybe you
moved some of their code from one file to another?

Also, an insertion isn't strictly the same thing as the actual number of rows
attributed to an author. When committing code, git will check for duplicates
from other files and also check if a newly added file is a copy of some other
file. If copies are detected; the author might not get the insertions but may
still get some of the rows attributed to him or her.

----

**Q: When showing responsibilities (via the -r flag), gitinspector shows that I
am responsible for rows in a file (or files) that I have never edited. How can
this be?**

A: This is normal and probably means that someone else in the development team
moved (or created) rows in that file from code originally written by you.

----

**Q: When running gitinspector; I get a UnicodeEncodeError exception.**

A: This usually means that your terminal has an incompatible encoding configured
that is unable to print out the characters being sent to it by gitinspector. See
[issue 9](https://github.com/ejwa/gitinspector/issues/9) for more information on
this topic. Redirecting the output of gitinspector to a file should also solve
the issue.

----

**Q: When generating a HTML page with the -r flag, the number of minor authors
in the responsibilities view does not equal the number of minor authors in the
blame view. In fact, there are less minor authors in the responsibilities view.
Strange things happen when generating text and HTML output also; some authors
responsibilities are never shown at all. How is this possible?**

A: Because the responsibilities view filters out any authors that only have
lines inside comments. The responsibilities view calculates responsibilities by
ELOC (Estimated-Lines-Of-Code). You can, in fact, even get a major author
filtered out and not even shown if that author only has lines inside comments.

----

**Q: When running gitinspector, there are authors missing from the report output
that I am absolutely positive should be included. Why are they not being added
as part of the statistical report?**

A: Gitinspector is full of features and does a lot of things in order to remove
data from reports that it considers *"useless"*. One of the things gitinspector
does on each execution is to filter out commits from the statistics based on
file extension (suffix) and content. If your authors are not showing up, they
have probably not committed any files or data that gitinspector considers valid.
By default, gitinspector only considers the file extensions
`java,c,cc,cpp,h,hh,hpp,py,glsl,rb,js,sql`. Use `-l`` to see what file
extensions are used and detected by gitinspector. Use `-f` to modify the list of
scanned/included file extensions. Make sure to read through the documentation and
learn about the configuration options provided. As gitinspector only considers
source code, binary data is never included in statistics. Consequently, pure
binary commits are never counted.
