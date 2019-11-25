import random

ls = [random.randrange(1,5000,1) for i in range(1000)]

def merge(ls1:[], ls2:[]) -> []:
    comb = []
    i = j = 0
    for k in range(len(ls1)+len(ls2)):
        if(len(ls2)-1<j):
            comb.append(ls1[i])
            i+=1
        elif(len(ls1)-1<i):
            comb.append(ls2[j])
            j+=1
        elif(ls1[i]>ls2[j]):
            comb.append(ls2[j])
            j+=1
        else:
            comb.append(ls1[i])
            i+=1
    return comb

def merge_sort2(ls: [], count) -> []:
    if(count>17):
        return [-2]
    if(len(ls)>1):
        mid = len(ls)//2
        left = merge_sort2(ls[:mid], count+1)
        right = merge_sort2(ls[mid:], count+1)
        return merge(left, right)
    else:
        return ls

print(merge_sort2(ls, 0))