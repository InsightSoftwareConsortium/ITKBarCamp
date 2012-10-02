.. index:: ! lesion sizing toolkit LSTK

Lung Tumor Segmentation using Lesion Sizing Toolkit
===================================================

Description
-----------
  How to run Lesion Sizing Toolkit (LSTK_) to segment a lung tumor.

Configure ITK build tree with LSTK
-----------------------------------
  VTK v5.10
  ITK v4.2
  CMake Configuration : Module_LesionSizingToolkit = ON; LSTK_USE_VTK = ON



Run one segmentaiton example
----------------------------
./bin/LesionSegmentation  -InputImage  <./inputImage.mha>  -OutputImage  <./outputTumorImage.mha>   -Seeds 3 326.2 231.9 172.6 
 -MaximumRadius 20  -OutputROI  <./outputROI.mhd>   -OutputMesh  <./output.stl> -Visualize 1    -Screenshot <./screenShotTumor>

Video
-----




.. _LSTK: http://public.kitware.com/LesionSizingKit/index.php/Main_Page

