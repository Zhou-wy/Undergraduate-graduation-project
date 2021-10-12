# 关于《基于机器视觉的仿生机械手掌》的说明

## 演示视频：【基于机器视觉的仿生机械手掌-哔哩哔哩】https://b23.tv/2SPsUs

## 一、树莓派上的手势分类

首先需安装树莓派官方系统，搭建好opencv和tensorflow开发环境；

opencv安装方法请参考：https://blog.csdn.net/leaves_joe/article/details/67656340?utm_source=app

tensorflow安装方法：

首先安装pip3。

```shell
sudo apt-get install python3-dev
sudo apt-get install python-dev
```

查看python3的版本：

```shell
python3 -v
```

一般树莓派4使用的是python3.7，如果网速可以，直接安装：

```shell
sudo pip3 install tensorflow
```

如若安装失败，则请下载本地安装包，我这使用的是tensorflow-1.13.1-cp37-none-linux_armv7l.whl，在存放这个文件的文件夹下：

```shell
sudo pip3 install tensorflow-1.13.1-cp37-none-linux_armv7l.whl
```

如若报错少了h5py，则请下载h5py-2.7.1-cp37-cp37m-linux_armv7l.whl，先安装h5py，再安装tensorflow:

```shell
sudo pip3 install h5py-2.7.1-cp37-cp37m-linux_armv7l.whl
```

在安装完opencv和tensorflow后在终端输入python3后，键入：

```python
import cv2
import tensorflow as tf
print(cv2.__version__)
print(tf.__version__)
```

如果正常打印出版本信息，则安装正确，会有警告，但无妨；

安装完环境后：

------

---------------------------------------------------------------------------*****************重点*********-------------------------------------------------------------------

------

最好将 树莓派4B上手势识别 这个文件夹重命名为英文，我这命名为：rps ;

在rps文件夹中新建一个文件夹 images。运行cam.py文件，会自动采集照片到images文件夹。文件名为imageX.jpg，其中X为序号。需采集“石头”“剪刀”“布”“干扰手势”，分别保存到“paper”"rock""scissors""others"

model.py: 卷积神经网络模型

read_image.py:将图片读入内存

train.py:训练模型

test.py :测试手势图片识别结果

rps.py：最终完成

test1.py:是一个测试脚本，需首先在当前文件夹中，新建一个文件夹testdata,在此文件夹放置石头剪刀布手势图片各100张，会生成识别结果图。

## 二、STM32舵机控制

没啥好说的，看原理图，本程序主要产生五路PWM信号控制舵机，并接收串口信息。STM32的基础操作请自行学习。

## 三、串口通信

**采用树莓派的ttyAMA0的串口，但此设备默认给了蓝牙，所以需要改变映射规则，具体操作，请百度。**

将 串口通信 文件夹重命名为serial。在serial文件夹中make。会生成libserial.so静态链接库，里面实现了具体的串口通信的方法，源码中有注释。



