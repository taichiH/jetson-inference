#include <jetson-inference/imageNet.h>
#include <jetson-utils/loadImage.h>

int main( int argc, char** argv )
{
  if( argc < 2 )
    {
      printf("my-recognition:  expected image filename as argument\n");
      printf("example usage:   ./my-recognition my_image.jpg\n");
      return 0;
    }

  const char* imgFilename = argv[1];

  float* imgCPU    = NULL;
  float* imgCUDA   = NULL;
  int    imgWidth  = 0;
  int    imgHeight = 0;
		
  if( !loadImageRGBA(imgFilename, (float4**)&imgCPU, (float4**)&imgCUDA, &imgWidth, &imgHeight) )
    {
      printf("failed to load image '%s'\n", imgFilename);
      return 0;
    }


  imageNet* net = imageNet::Create(argc, argv);

  if( !net )
    {
      printf("failed to load image recognition network\n");
      return 0;
    }

  float confidence = 0.0;

  const int classIndex = net->Classify(imgCUDA, imgWidth, imgHeight, &confidence);

  if( classIndex >= 0 )
    {
      const char* classDescription = net->GetClassDesc(classIndex);
      printf("image is recognized as '%s' (class #%i) with %f%% confidence\n", 
             classDescription, classIndex, confidence * 100.0f);
    }
  else
    {
      printf("failed to classify image\n");
    }
	
  delete net;

  return 0;
}

