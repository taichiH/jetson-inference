<img src="https://github.com/dusty-nv/jetson-inference/raw/master/docs/images/deep-vision-header.jpg">

# Image Recognition Example

See this part of the tutorial for information about building and running this example:

[**Coding Your Own Image Recognition Program**](../../docs/imagenet-example-2.md)

## install
set model file

`original_cnn.onnx.1.1.GPU.FP16.engine`

`original_cnn.onnx`

## run
```
./my-recognition ../polar_bear.jpg --model=../original_cnn.onnx --labels=../original_label.txt --input_blob=input.1 --output_blob=23
```

`input.1` and `23` params are defined by onnx model.