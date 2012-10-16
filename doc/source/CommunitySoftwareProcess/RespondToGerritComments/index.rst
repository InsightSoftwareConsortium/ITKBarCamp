.. index:: Gerrit

.. _Respond to Gerrit Comments:

Respond to Gerrit Comments
==========================

Description
-----------
  After `submitting a patch <Submit a Patch to Gerrit>`_ to the ITK
  Gerrit Code Review instance, another community member will `perform a review
  <Perform a Gerrit Review>`_ and usually find issues to address.  In this
  session, we go through an example and tips on how to reply to the reviewer's
  comments and upload a new patch set that addresses those comments.
  The entire `ITK patch submission process`_ is covered concisely on the Wiki.

Workflow tips for responding to code reviews
--------------------------------------------

* While making changes that address a reviewer's comments, add an inline response
  after all inline comments or mark each inline comment *Done*.

* Perform a review that reply's to the reviewers comments and summarizes what
  will be coming in the next patch set before submitting the next patch set.

* Use `git commit -a --amend` to add changes to a commit that address reviewer
  comments.

* Remember to leave the Change-Id in the last line of the commit message.

* Push the new patch set with `git gerrit-push`.

Video
-----

.. youtube:: Ie3STRhq824

See also
--------

* :ref:`Submit a Patch to Gerrit`
* :ref:`Perform a Gerrit Review`

.. _ITK patch submission process: http://www.itk.org/Wiki/ITK/Git/Develop#Revise_a_Topic
