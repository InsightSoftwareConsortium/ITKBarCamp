#include <iostream>

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <itkImage.h>
#include <itkCastImageFilter.h>
#include <itkCannyEdgeDetectionImageFilter.h>
#include <itkRescaleIntensityImageFilter.h>
#include <itkOpenCVImageBridge.h>

// Process a single frame of video and return the resulting frame
cv::Mat processFrame( const cv::Mat& inputImage )
{
  const unsigned int Dimension = 2;
  typedef unsigned char                            InputPixelType;
  typedef float                                    RealPixelType;
  typedef unsigned char                            OutputPixelType;
  typedef itk::Image< InputPixelType,  Dimension > InputImageType;
  typedef itk::Image< RealPixelType,   Dimension > RealImageType;
  typedef itk::Image< OutputPixelType, Dimension > OutputImageType;
  typedef itk::OpenCVImageBridge                   BridgeType;
  typedef itk::CastImageFilter< InputImageType, RealImageType >
                                                   CastFilterType;
  typedef itk::CannyEdgeDetectionImageFilter< RealImageType, RealImageType >
                                                   FilterType;
  typedef itk::RescaleIntensityImageFilter< RealImageType, OutputImageType >
                                                   RescaleFilterType;

  CastFilterType::Pointer caster = CastFilterType::New();
  FilterType::Pointer canny = FilterType::New();
  RescaleFilterType::Pointer rescaler = RescaleFilterType::New();

  InputImageType::Pointer itkFrame =
    itk::OpenCVImageBridge::CVMatToITKImage< InputImageType >( inputImage );
  caster->SetInput( itkFrame );
  canny->SetInput( caster->GetOutput() );
  rescaler->SetInput( canny->GetOutput() );

  canny->SetVariance( 6 );
  canny->SetLowerThreshold( 1 );
  canny->SetUpperThreshold( 8 );

  rescaler->Update();

  cv::Mat frameOut =
    BridgeType::ITKImageToCVMat< OutputImageType >(rescaler->GetOutput(),true);

  frameOut.convertTo( frameOut, CV_8U );

  return frameOut;
}

// Iterate through a video, process each frame, and display the result in a GUI.
void processAndDisplayVideo(cv::VideoCapture& vidCap)
{
  const double frameRate = vidCap.get( CV_CAP_PROP_FPS );
  const int width = vidCap.get( CV_CAP_PROP_FRAME_WIDTH );
  const int height = vidCap.get( CV_CAP_PROP_FRAME_HEIGHT );

  const std::string windowName = "Exercise 2: Basic Video Filtering in OpenCV";
  cv::namedWindow( windowName, CV_WINDOW_FREERATIO);
  cvResizeWindow( windowName.c_str(), width, height+50 );

  const unsigned int delay = 1000 / frameRate;

  cv::Mat frame;
  while( vidCap.read(frame) )
    {
    cv::Mat outputFrame = processFrame( frame );
    cv::imshow( windowName, outputFrame );

    if( cv::waitKey(delay) >= 0 )
      {
      break;
      }
    }
}

// Iterate through a video, process each frame, and save the processed video.
void processAndSaveVideo(cv::VideoCapture& vidCap, const std::string& filename)
{
  const double frameRate = vidCap.get( CV_CAP_PROP_FPS );
  const int width = vidCap.get( CV_CAP_PROP_FRAME_WIDTH );
  const int height = vidCap.get( CV_CAP_PROP_FRAME_HEIGHT );

  const int fourcc = CV_FOURCC('X','V','I','D');

  cv::VideoWriter writer( filename, fourcc, frameRate,
                          cv::Size(width, height) );

  cv::Mat frame;
  while( vidCap.read(frame) )
    {
    cv::Mat outputFrame = processFrame( frame );
    writer << outputFrame;
    }
}

int main ( int argc, char **argv )
{
  if( argc < 2 )
    {
    std::cout << "Usage: " << argv[0] <<" input_video [output_video]" << std::endl;
    return EXIT_FAILURE;
    }

  cv::VideoCapture vidCap( argv[1] );
  if( !vidCap.isOpened() )
    {
    std::cerr << "Unable to open video file: "<< argv[1] << std::endl;
    return EXIT_FAILURE;
    }

  if( argc < 3 )
    {
    try
      {
      processAndDisplayVideo( vidCap );
      }
    catch( itk::ExceptionObject & err )
      {
      std::cerr << "Error: " << err << std::endl;
      return EXIT_FAILURE;
      }
    }
  else
    {
    try
      {
      processAndSaveVideo( vidCap, argv[2] );
      }
    catch( itk::ExceptionObject & err )
      {
      std::cerr << "Error: " << err << std::endl;
      return EXIT_FAILURE;
      }
    }

  return EXIT_SUCCESS;
}

