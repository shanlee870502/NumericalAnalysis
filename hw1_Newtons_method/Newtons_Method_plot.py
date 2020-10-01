# -*- coding: utf-8 -*-
"""
Created on Sun Sep 29 10:59:25 2019

@author: 001
"""

import matplotlib.pyplot as plt
import numpy as np


figzoom, axzoom = plt.subplots()
axzoom.set(xlim=(-10, 10), ylim=(-10, 10), autoscale_on=False,
           title='Progression Of Root-Finding (Newton\'s Method)\nInitial Point [x,y] = [-5, 10] ')
#axzoom.set(autoscale_on = True)

x = np.arange(-10, 10,0.5)
y = np.arange(-10, 10,0.5)

X, Y = np.meshgrid(x,y)
F = ((X-3)**2/25) + ((Y-4)**2/16) - 1
G = Y - X**2 - 2*X - 1
plt.contour(X,Y,F,[0],colors = "blue")
plt.contour(X,Y,G,[0],colors = "red")

file = open(r"D:\數值分析HW1\Diverge Point.txt", encoding = 'utf-8-sig')

i = 0
for line in file:
    x_list = []
    y_list = []
    xy_list= line.replace("\n","").split(" ")
    x_list.append(float(xy_list[0]))
    y_list.append(float(xy_list[1]))
    if i == 0:
        plt.scatter(x_list, y_list,c='yellow', s = 5) #initial point
    else:
        plt.scatter(x_list, y_list,c='green',s=1) #iteration point
    i+=1
plt.scatter(x_list, y_list,c='black',s=5)  #Converge point(last iteration point)
#plt.plot(xi, yi, "ro")
        
#plt.contour(X,Y,F,[0],colors = "blue")
#plt.contour(X,Y,G,[0],colors = "red")


plt.xlabel("x axis")
plt.ylabel("y axis")
plt.grid(alpha=.4,linestyle='--')
plt.savefig("D:\數值分析圖_發散點.png",figsize=(1000, 1000))
plt.show()

