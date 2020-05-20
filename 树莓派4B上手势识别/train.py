# @Author: zhouzhou
# @Date:   2019-06-24 22:07:51
# @Last Modified by:   zhouzhou
# @Last Modified time: 2020-05-03 15:53:00
#coding:UTF-8
from __future__ import absolute_import  
from __future__ import division  
from __future__ import print_function  
import os
os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2' 
import tensorflow as tf  
import argparse  
import sys  
import model  
import read_image  
import numpy as np 
import matplotlib.pyplot as plt 

w = 28  
h = 28  
  
def main(args):  
    lr = args.learning_rate  
    batch_size = args.batch_size  
    epoches = args.epoches  
    keep_prob_value = args.keep_prob  
    train(lr,batch_size, epoches, keep_prob_value)  
      
  
def train(lr, batch_size, epoches, keep_prob_value):  
    # 读入图片  
    path = 'images/'  
    x_train, y_train, x_val, y_val = read_image.read_img(path)  
    x_train = x_train/255.0 # 图片预处理  
    x_val = x_val/255.0  
  
    x = tf.placeholder(tf.float32, [None, w*h], name="images")  
    y_ = tf.placeholder(tf.float32, [None, 4], name="labels")  
    keep_prob = tf.placeholder(tf.float32,name="keep_prob")  
    y = model.model(x, keep_prob)  
      
    # Cost function  
    cross_entropy = tf.reduce_mean(-tf.reduce_sum(y_*tf.log(y),  
                                                  reduction_indices=[1]),name="corss_entropy")  
    train_step = tf.train.AdamOptimizer(lr).minimize(cross_entropy)  
    correct_prediction = tf.equal(tf.argmax(y,1), tf.argmax(y_,1))  
    accuracy = tf.reduce_mean(tf.cast(correct_prediction, tf.float32), name="accuracy")  
    saver = tf.train.Saver()  
    #draw data
    x_lable=[]
    y1_lable=[]
    y2_lable=[]
    # Start training  
    with tf.Session() as sess:  
        sess.run(tf.global_variables_initializer())  
        for i in range(epoches+1):  
            iters = np.int32(len(x_train)/batch_size)+1  
            for j in range(iters):  
                if j==iters-1:  
                    batch0 = x_train[j*batch_size:]  
                    batch1 = y_train[j*batch_size:]
                    #print(x_train,y_train)  
                else:  
                    batch0 = x_train[j*batch_size:(j+1)*batch_size]  
                    batch1 = y_train[j*batch_size:(j+1)*batch_size]  
                if i%25==0 and j==1:  
                    train_accuracy, cross_ent = sess.run([accuracy, cross_entropy],  
                                              feed_dict={x:batch0, y_:batch1,  
                                              keep_prob: keep_prob_value})  
                    print("step %d, training accuracy %g, cross_entropy %g" % (i, train_accuracy, cross_ent))   
                    x_lable.append(i)
                    y1_lable.append(train_accuracy)
                    y2_lable.append(cross_ent)

                    # Save model  
                    saver_path = saver.save(sess,"model/model.ckpt")  
                    print("Model saved in file:", saver_path)  
                    test_accuracy = sess.run(accuracy, feed_dict={x:x_val,  
                                                      y_:y_val,  
                                                      keep_prob: 1.0})  
                    print("test accuracy %g" % test_accuracy)  
                sess.run(train_step, feed_dict={x:batch0, y_:batch1,  
                                                keep_prob:keep_prob_value})  
  
        test_accuracy = sess.run(accuracy, feed_dict={x:x_val,  
                                                      y_:y_val,  
                                                      keep_prob: 1.0})  
        #print("test accuracy %g" % test_accuracy)
        fig = plt.figure(figsize=(20,8),dpi=100)
        plt.plot(x_lable,y1_lable,'s-',markersize=4,color = 'r',label="train_accuracy",linewidth=2)#s-:方形
        plt.plot(x_lable,y2_lable,'o-',markersize=4,color = 'g',label="cross_ent",linewidth=2)#o-:圆形
        plt.xlabel("thr number of training")#横坐标名字
        plt.ylabel("percentage")#纵坐标名字
        plt.legend(loc = "percentage test")#图例
        plt.grid(color='b', ls = '-.', lw = 0.25)        
        plt.show() 
        plt.savefig('./percentage.jpg')

      
  
def parse_arguments(argv):  
    parser = argparse.ArgumentParser()  
  
    parser.add_argument('--learning_rate', type=float,  
                        help="learning rate", default=1e-4)  
    parser.add_argument('--batch_size', type=float,  
                        help="batch_size", default=50)  
    parser.add_argument('--epoches', type=float,  
                        help="epoches", default=100)  
    parser.add_argument('--keep_prob', type=float,  
                        help="keep prob", default=0.5)  
    return parser.parse_args(argv)  
  
if __name__=="__main__":  
    main(parse_arguments(sys.argv[1:]))  
