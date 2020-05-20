# @Author: zhouzhou
# @Date:   2019-06-24 22:07:51
# @Last Modified by:   zhouzhou
# @Last Modified time: 2020-05-01 10:18:52
#coding:UTF-8
import cv2  


width = 100  #设置宽度
height = 100 #设置高度

clicked = False  #鼠标点击
def onMouse(event, x, y, flags, param):  #定义鼠标事件
    global clicked  
    if event == cv2.EVENT_LBUTTONUP:  
        clicked = True  
  
cameraCapture = cv2.VideoCapture(0) #采集摄像头的视频流 
cv2.namedWindow('MyWindow')  #创建窗口
cv2.setMouseCallback('MyWindow', onMouse) 
print('showing camera feed. Click window or press and key to stop.')  
success, frame = cameraCapture.read()  
print(success)  
count = 0  
while success and cv2.waitKey(1)==-1 and not clicked:  
    cv2.imshow('MyWindow', cv2.flip(frame,0))  
    success, frame = cameraCapture.read() 
    new_img = cv2.resize(frame,(width,height)) 
    name = 'images/image'+str(count)+'.jpg'  
    cv2.imwrite(name,new_img)  
    count+=1
    print('name')  
  
cv2.destroyWindow('MyWindow')  
cameraCapture.release()  





