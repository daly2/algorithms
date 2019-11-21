import numpy as np

def startPos(arr, m, n):
    max=[0, 0, 0]
    if(m%2==0 and n%2==0):
        max[0]=arr[m//2][m//2]
        max[1]=n//2
        max[2]=m//2
        print("j")
        return max
    else:
        """
        I could turn this find best adjecent square into a function
        and use it in mov as well,
        however the added complexity of finding the nearest to center meant 
        I didn't have time
        """
        nearCenterI=n//2-1
        nearCenterJ=m//2-1
        for i in range(2):
            for j in range(2):
                print(i,j)
                if(arr[nearCenterI+i][nearCenterJ+j]>=max[0]):
                    max[0]=arr[nearCenterI+i][nearCenterJ+j]
                    max[1]=nearCenterI+i
                    max[2]=nearCenterJ+i
                    print(max)
        return max

def mov(pos, arr, m, n):
    max = [0, 0, 0]
    for i in range(-1, 2, 2): 
        newP=pos[1]+i
        if(newP>=n or newP<0):          #checking that it is in bounds
            break                       #finding the best square to go to
        if(arr[newP][pos[2]]>max[0]):  #checking up and down
            max[0]=arr[pos[1]+i][pos[2]]
            max[1]=newP
            max[2]=pos[2]
    for j in range(-1, 2, 2):
        newP=pos[2]+j
        #print(newP, n,"   ", pos)
        if(newP>=n or newP<0):
            break                 #checking left and right
        if(arr[pos[1]][newP]>max[0]):
            max[0]=arr[pos[1]][newP]
            max[1]=pos[1]
            max[2]=newP
    arr[max[1]][max[2]]=0
    print("max", max)                   #setting the new square=0
    return max

def main():
    arr=np.array([[5, 7, 8, 6, 3],[0, 0, 7, 0, 4], [4, 6, 3, 4, 9], [3, 1, 0, 5, 8]])
    m,n=arr.shape
    pos=[0,0,0]
    pos=startPos(arr, m, n)
    carrots=pos[0]
    print(arr)
    print(pos)
    while True:
        #print(carrots)
        pos=mov(pos, arr, m, n)
        carrots+=pos[0]
        if(pos[0]==0):
            break
    print("carrots", carrots)
    print(arr)

if __name__ == "__main__":
    main()