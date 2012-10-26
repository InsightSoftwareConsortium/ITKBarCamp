set(DOCUMENTATION "This module is for showing ITK module structure purposes.")

# itk_module() defines the module dependencies in ITKExternalTemplate;
# ITKExternalTemplate depends on ITKCommon;
# The testing module in ITKExternalTemplate depends on ITKTestKernel,
# and ITKMetaIO for image IO (besides ITKExternalTemplate itself)

itk_module(ITKExternalTemplate
  DEPENDS
    ITKCommon
  TEST_DEPENDS
    ITKTestKernel
    ITKMetaIO
  DESCRIPTION
    "${DOCUMENTATION}"
)
