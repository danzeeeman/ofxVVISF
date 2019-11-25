ofxVVISF
=====================================


Introduction
------------
This openFrameworks addon wraps the [VVISF-GL](https://github.com/mrRay/VVISF-GL) library from [VidVox](http://vidvox.com).  

### VVGL
ISF stands for "Interactive Shader Format", and is a file format that describes a GLSL fragment shader, as well as how to execute and interact with it (the official specification can be found here). VVISF is a cross-platform c++ library that implements the ISF protocol with support for a number of common SDKs (OS X, iOS, GLFW, and Qt) and GL environments (most versions of GL- both ES and desktop- are supported).

### VVGL
VVGL is a small library that performs rudimentary GL rendering, focusing mainly on texture generation/pooling and render-to-texture operations. Its primary purpose is to provide a simple consistent interface for performing these basic GL operations while obfuscating any platform-specific or environment-specific GL implementation details. VVISF is built on top of VVGL, but you don't need to be intimately familiar with VVGL to use VVISF.

License
-------
See [License](/license.md)

Installation
------------
 - clone the addon into the `openFrameworks/addons/` folder
 - setup the submodule by running 
    
    ```git submodule init``` 
    
    ```git submodule update```
 - Create a project with the project generator or create the projects for the examples
 - When creating a project you need to add preprocessor defines to enable the `VVGL_SDK_GLFW` flag.

 ![](images\VVGL_SDK_GLFW.PNG)
 - Edit the command line options to add `/bigobj`
 ![](images\bigobj.PNG)
 - ESnjoy!
Examples
------------
### example-grabber
![header](images\example-grabber.PNG)


Compatibility
------------
tested with 0.10+ 

Known issues
------------
None

Version history
------------





