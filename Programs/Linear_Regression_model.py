import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt

np.random.seed(101)
tf.set_random_seed(101)

x = np.linspace(0, 50, 50)
y = np.linspace(0, 50 ,50)

x += np.random.uniform(-4, 4, 50)
y += np.random.uniform(-4, 4, 50)

plt.scatter(x, y)
plt.xlabel('X-axis')
plt.ylabel('Y-axis')
plt.show()

n = len(x)
 
X = tf.placeholder('float')
Y = tf.placeholder('float')

W = tf.Variable(np.random.randn(), name = 'W')
b = tf.Variable(np.random.randn(), name = 'b')

 
learning_rate = 0.01
training_epoch = 5000

y_prediction = tf.add(tf.multiply(X,W), b)
  
cost = tf.reduce_sum(tf.pow(y_prediction-Y, 2))/(2*n)
optimizer = tf.train.GradientDescentOptimizer(learning_rate).minimize(cost)

init = tf.global_variables_initializer()

with tf.Session() as sess:

  sess.run(init)

  for epoch in range(training_epoch):

    for (x1,y1) in zip(x,y):
        sess.run(optimizer, feed_dict = {X : x1, Y : y1})  

    if (epoch+1)%75 == 0:

        c = sess.run(cost, feed_dict = {X : x, Y : y}) 
        print('Epoch: ',(epoch+1), 'Cost: ',c, 'W: ',sess.run(W), 'b: ', sess.run(b))

  training_cost = sess.run(cost, feed_dict = {X : x, Y : y}) 
  weight = sess.run(W)
  bias = sess.run(b)

prediction = weight*x + bias

print('Training Cost:',training_cost, 'Weight: ', weight, 'Bias: ', bias)

plt.plot(x,y,'go',label = 'Original_data')
plt.plot(x,prediction,label = 'Training_data')
plt.title("Learning Linear Regression")

plt.legend()
plt.show()
