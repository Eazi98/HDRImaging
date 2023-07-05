from PIL import Image
import os

def getImage(file):
    orig_image = Image.open(file)
    width, height = orig_image.size
    mode = orig_image.mode
    return (orig_image,(width,height),mode)

def getPerc(lis):
    tot = 0
    for i in lis:
        if i ==0:
            tot+=1
    return tot/len(lis)*100

print(os.getcwd())
orig = getImage("MATLABImplementationOfImageTMO/LDRim/mpi_office.png")
cap = getImage("MATLABImplementationOfImageTMO/LDRim/PhoneOutput/mpi_office.png")

origimage = orig[0].load()
capimage = cap[0].load()
r = []
g = []
b = []
if orig[1] == cap[1]:
    for x in range(orig[1][0]):
        for y in range(orig[1][1]):
            pixel = orig[0]
            val = [origimage[x,y][i] - capimage[x,y][i] for i in range(3)]
            r.append(val[0])
            g.append(val[1])
            b.append(val[2])
            #print(val,end = " ")
        #print()

print(f"MAX R :{max(r)}")
print(f"MAX G :{max(g)}")
print(f"MAX B :{max(b)}")
print(f"MIN R :{min(r)}")
print(f"MIN G :{min(g)}")
print(f"MIN B :{min(b)}")
print(f"PER R :{getPerc(r)}%")
print(f"PER G :{getPerc(g)}%")
print(f"PER B :{getPerc(b)}%")
