.. index:: Git

Development Repository Setup
============================

Description
-----------
  We describe how to setup your local Git repository for development with ITK.
  This is a pre-requisite for testing patches, submitting patches, etc.

How
---

In a bash shell with Git_

.. code-block:: bash

  git clone git://itk.org/ITK.git
  cd ITK
  ./Utilities/SetupForDevelopment.sh

and follow the interactive prompt.

Why
---

With the Git repository setup, it is possible to create and submit patches
through Gerrit_, review patches on Gerrit.  The *SetupForDevelopment.sh* does
many nice things, such as

* Make sure your Git user and email are configured, so you get credit for your
  work.
* Setup hooks to check for ITK style-compliance, prevent large file commits,
  etc.
* Setup the Gerrit_ hooks, remote, and aliases, so a topic branch can be pushed
  with `git gerrit-push`.
* Provide generally useful tips configuring Git.

Video
-----

.. youtube:: YRZCjY4yOx4

.. _Git: http://git-scm.org/
.. _Gerrit: http://review.source.kitware.com/
