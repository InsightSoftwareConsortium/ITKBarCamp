.. index:: ! dashboard submission

Dashboard Submission
====================

Description
-----------
How to submit your build and test results to ITK dashboards from a Linux machine

Get the dashboard scripts
---------------------------
The dashboard branch contains a dashboard client helper script. Use these commands to track it::

   $ mkdir -p ~/Dashboards/ITKScripts
   $ cd ~/Dashboards/ITKScripts
   $ git init
   $ git remote add -t dashboard origin git://itk.org/ITK.git
   $ git pull origin

The itk_common.cmake script contains setup instructions in its top comments. For more examples, go to the dashboard, click the Advanced View link, then click on the icon that looks like a page next to a Build Name. Update the dashboard branch to get the latest version of this script by simply running::
   $ git pull origin


Write your own ctest script
---------------------------
Create your own ctest script to submit your local build to the ITK dashboard, for example:

*itk_nightly_gentoo_gcc4.6.3_xyj.cmake*:

.. literalinclude:: itk_nightly_gentoo_gcc4.6.3_xyj.cmake
  :language: cmake

You could run the script to submit the build to the ITK nightly dashboard::

   ctest -S itk_nightly_gentoo_gcc4.6.3_xyj.cmake


Set up nightly cron job
-----------------------
You can also add the ctest command ( or multiple commands for multiple builds) into a bash file to run it nightly.

*nighlyScripts.sh*:

.. literalinclude:: nightlyScripts.sh
  :language: cmake

Edit your crontab to set up nightly task on your machine::

   sudo crontab -e

Add the following line to run the script everyday at 2 am::

   # m h  dom mon dow   command
   0 2 * * * /home/xiaoxiao/work/Dashboard/nightlyScript.sh


Video
-----

.. youtube:: cZm5NWMcqZY
