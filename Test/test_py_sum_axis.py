import numpy as np
D,N=8,7
x=np.random.randn(N,D)
y=np.sum(x,axis=0,keepdims=True)
dy=np.random.randn(1,D)
dx=np.repeat(dy,N,axis=0)
print(x,"\ny=",y)
