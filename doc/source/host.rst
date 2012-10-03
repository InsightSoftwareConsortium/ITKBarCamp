How to host an ITK Bar Camp
===========================

.. image:: images/marshmallow.jpg

This document describes how to host an ITK Bar Camp session.  It is a
work-in-progress.

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

Next, commit and push the built HTML:

.. code-block:: bash

  cd build/html
  git add *
  git commit -m "Build on $(date) of $(cd ..; git rev-parse --short HEAD)."
  git push

Uploading videos to Midas
-------------------------

Videos that are posted in the `ITKBarCamp YouTube Channel`_ should be archived
in the `ITKBarCamp Midas archive`_.  To upload to the Midas archive, `create a
Midas account`_ and join the `ITK Midas Community`_.  

Videos can be manually downloaded from YouTube and uploaded to
*ITK/Public/BarCamp/* Midas folder through the web interface.  Alternatively,
the download/upload process can be automated with the **youtube-to-midas**
Python script in the *utilities* directory of the Git repository.  To use the
script, first install the latest youtube-dl_:

.. code-block:: bash

  wget https://github.com/rg3/youtube-dl/raw/13e69f546c26bf35688929d36450b26da6b8d9ee/youtube-dl
  chmod +x youtube-dl
  mv youtube-dl /usr/local/bin/

Next, install pydas_:

.. code-block:: bash

  pip install pydas

To use *utilities/youtube-to-midas*::

  usage: youtube-to-midas [-h] [--api-key-file API_KEY_FILE] [--email EMAIL]
                          youtube_url

  Download ITK video from YouTube and upload to Midas.

  positional arguments:
    youtube_url           A YouTube URL with the video. Tip: surround with
                          quotes in the shell!

  optional arguments:
    -h, --help            show this help message and exit
    --api-key-file API_KEY_FILE, -k API_KEY_FILE
                          A file that contains your Midas user's API key.
    --email EMAIL, -e EMAIL
                          Email address associated with your Midas account.

.. _create a Midas account: http://midas3.kitware.com/midas/#
.. _ITKBarCamp Midas archive: http://midas3.kitware.com/midas/folder/7556
.. _ITKBarCamp YouTube Channel: http://www.youtube.com/user/ITKBarCamp?feature=watch
.. _ITK Midas Community: http://midas3.kitware.com/midas/community/12
.. _Sphinx: http://sphinx.pocoo.org
.. _youtube-dl: http://rg3.github.com/youtube-dl/
.. _pydas: http://github.com/midasplatform/pydas
