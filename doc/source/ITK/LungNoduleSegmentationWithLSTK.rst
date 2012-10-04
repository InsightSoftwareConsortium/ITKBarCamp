.. index:: ! lesion sizing toolkit LSTK

Lung Tumor Segmentation using Lesion Sizing Toolkit
===================================================

Description
-----------
  How to run Lesion Sizing Toolkit (LSTK_) to segment a lung tumor.

Build LSTK with ITK
-------------------
  Versions:
             VTK v5.10
             ITK v4.2
  CMake Configuration :
              Fetch_LesionSizingToolkit = ON
              Module_LesionSizingToolkit = ON;
              LSTK_USE_VTK = ON
              VTK_DIR = your/VTK/build/Path;



Run a segmentaiton example:
----------------------------
[Your/ITK/Build/Tree]/bin/LesionSegmentation  -InputDICOMDir  /path/to/DICOM/folder  -OutputImage  ./outputTumorImage.mha   -Seeds 3 326.2 231.9 172.6
 -MaximumRadius 20  -OutputROI  ./outputROI.mhd   -OutputMesh  ./output.stl -Visualize 1    -Screenshot ./screenShotTumor


The example dataset used in the following video is downloaded from
              http://midas3.kitware.com/midas/item/20902 ,
with the seeds specified here:
              http://midas3.kitware.com/midas/item/22945

Video
-----
.. youtube:: dFtipGL6SEs




.. _LSTK: http://public.kitware.com/LesionSizingKit/index.php/Main_Page

