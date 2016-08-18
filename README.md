*nix shims 4 Windows [![Unlicensed work](https://raw.githubusercontent.com/unlicense/unlicense.org/master/static/favicon.png)](http://unlicense.org/)
===================

Here is some shims to allow some cross-platform apps using *nix headers (not present in VS, but present in MinGW and cygwin) to be build with Visual Studio.

It contains third-party components, each has own license (sometimes it is unknown). The rest of the code is [unlicensed into public domain](http://unlicense.org/). It is your responsibility to check if you (can) accept the licenses.

How to use
---------
You need cmake to make it work.

#. add git submodule
#. define nixShims4Windows_DIR variable to be a path to this dir
#.
```cmake
	include("${nixShims4Windows_DIR}/CMakesLists.txt")
```
from this dir in your cmake script
#. add ```shimSources``` to sources
#. link ```shimLibs```

At run time make sure that git is found correctly, because it relies on git submodules.