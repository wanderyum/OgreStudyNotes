# OgreStudyNotes #

## 1. 建立一个Ogre项目 ##

参考教程地址: [Setting up an OGRE project](https://ogrecave.github.io/ogre/api/latest/setup.html#skeleton)

这里采用Makefile来编译，编译系统为`Manjaro`+`gcc`。

编译前注意修改变量`LIB_PATH`，`RPATH`，`INCLUDE`的值。
 - `LIB_PATH`是`libzzip.so`的所在路径，这里的`libzzip.so`是编译安装过程中生成的库文件，默认地址为`ogre-1.12.6/build/Dependencies/lib`。
 - `RPATH`是要传给链接器的参数，这里的地址也是`libzzip.so`的所在路径，因为此库不在标准地址，因此需要显式指明。
 - `INCLUDE`是所需头文件所在地址，在这里包括`/usr/include/OGRE/`、`/usr/include/OGRE/Bites/`和`/usr/include/OGRE/RTShaderSystem/`等三个位置。

 此外，这里已经将`/usr/share/OGRE/`中的`resources.cfg`拷贝到了文件夹中，以免出现找不到`Sinbad.mesh`的错误。
