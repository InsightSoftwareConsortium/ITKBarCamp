How to host an ITK Bar Camp
===========================

.. image:: images/marshmallow.jpg

Sphinx documentation
--------------------

First, install Sphinx_.

Clone the sources::

  git clone git@github.com:InsightSoftwareConsortium/ITKBarCamp.git
  cd ITKBarCamp/doc
  git clone -b gh-pages git@github.com:InsightSoftwareConsortium/ITKBarCamp-doc.git build/html

Checkout a topic branch, rant, commit, etc.  Please do not add images or other
large files to the repository -- use images already used by the other examples
repositories.  Make sure the project builds, looks good, there are no speling
errors::

  make html

Merge into master with::

  git merge --no-ff branchName
  git push

Next, commit and push the built HTML::

  cd build/html
  git add *
  git commit -m "Build on $(date) of $(cd ..; git rev-parse --short HEAD)."
  git push

.. _Sphinx: http://sphinx.pocoo.org
