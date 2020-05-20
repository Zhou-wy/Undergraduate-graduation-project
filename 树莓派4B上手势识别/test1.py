# @Author: zhouzhou
# @Date:   2019-06-24 22:07:51
# @Last Modified by:   zhouzhou
# @Last Modified time: 2020-05-03 15:52:13
#coding:UTF-8
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2' 
from PIL import Image  
from matplotlib.pylab import *  
import numpy as np  
import argparse  
import tensorflow as tf  
import time  
import os
  
w = 28  
h = 28  
classes = ['others','paper','rock','scissors']  

def main(args):  
    
    path = './tsetdata/'  
    model_dir = 'model/model.ckpt'  
    others_count=paper_count=rock_count=scis_count=0
    other_p = []
    paper_P = []
    rock_p = []
    scis_p = []  
    # Restore model  
    saver = tf.train.import_meta_graph(model_dir+".meta")  
      
    with tf.Session() as sess:  
        saver.restore(sess, model_dir)  
        x = tf.get_default_graph().get_tensor_by_name("images:0")  
        keep_prob = tf.get_default_graph().get_tensor_by_name("keep_prob:0")  
        y = tf.get_default_graph().get_tensor_by_name("fc2/output:0")   

        for i in os.listdir(path):
            filename =path+i        
            #filename = cate1.split() 
            # Read image  
            pil_im = array(Image.open(filename).convert('L').resize((w,h)),dtype=float32)  
            pil_im = pil_im/255.0  
            pil_im = pil_im.reshape((1,w*h))  
             
            time1 = time.time()  
            prediction = sess.run(y, feed_dict={x:pil_im,keep_prob: 1.0})  
            index = np.argmax(prediction)  
            time2 = time.time()  
            print("The classes is: %s. (the probability is %g)" % (classes[index], prediction[0][index]))  
            if index == 0:  
                others_count=others_count+1
                other_p.append(prediction[0][index]*100)
                #print("The classes is: %s. (the other_p is %g)  " % (classes[index], prediction[0][index]))
            if index == 1:
                paper_count=paper_count+1
                paper_P.append(prediction[0][index]*100) 
            if index == 2:
                rock_count=rock_count+1
                rock_p.append(prediction[0][index]*100) 
            if index == 3: 
                scis_count=scis_count+1
                scis_p.append(prediction[0][index]*100) 

        x1 = range(0,others_count)
        x2 = range(0,paper_count)
        x3 = range(0,rock_count)
        x4 = range(0,scis_count)
        #折线图
        fig = plt.figure(figsize=(20,8),dpi=100)
        plt.plot(x1,other_p,'s-',markersize=4,color = 'r',label="other_probability",linewidth=2)#s-:方形
        plt.plot(x2,paper_P,'o-',markersize=4,color = 'g',label="paper_probability",linewidth=2)#o-:圆形
        plt.plot(x3,rock_p,'+-',markersize=4,color = 'b',label="rock_probability,",linewidth=2)#s-:方形
        plt.plot(x4,scis_p,'*-',markersize=4,color = 'y',label="scis_probability",linewidth=2)#o-:圆形
        plt.grid(color='k', ls = '-.', lw = 0.25)
        plt.xlabel("the munber of photo")#横坐标名字
        plt.ylabel("probability")#纵坐标名字
        plt.legend(loc = "probability test")#图例
        plt.savefig('./probability.jpg')
        plt.show()




    print('The others is:%g The paper is:%g The rock is:%g The scissors is:%g'%(others_count,paper_count,rock_count,scis_count))
    print("Using time %g" % (time2-time1))  
def parse_arguments(argv):  
    parser = argparse.ArgumentParser()  
  
    parser.add_argument('--filename', type=str,  
                        help="The image name",default="images/paper/image104.jpg")  
    parser.add_argument('--model_dir', type=str,  
                        help="model file", default="model/model.ckpt")  
    return parser.parse_args(argv)  
  
if __name__=="__main__":  
    main(parse_arguments(sys.argv[1:]))  
