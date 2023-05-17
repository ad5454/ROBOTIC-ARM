import cvzone
import cv2

import serial
import time

# ser = serial.Serial("COM6", 9600)  # open serial connection
time.sleep(2);

cap=cv2.VideoCapture(0)
detector=cvzone.HandDetector(maxHands=1,detectionCon=0.7)
mySerial=cvzone.SerialObject("COM7",9600,1)
location=""
while True:
    success,img=cap.read()
    img= detector.findHands(img)
    lmlist,bbox= detector.findPosition(img)
    fingers=[0,0,0,0,0]
    if lmlist:
        fingers=detector.fingersUp()

    try:
        x = bbox[0] + bbox[2] / 2
        y = bbox[1] + bbox[3] / 2

        if (x <= 320):
            if (y <= 240):

                location = "1"

            else:
                location = "3"
        else:
            if (y <= 240):

                location = "2"

            else:
                location = "4"


        if (fingers[0] == 0 and fingers[1] == 0 and fingers[2] == 0 and fingers[3] == 0 and fingers[4] == 0):
            location+= "0"


        else:
            location+= "1"

        if(fingers[0]==0 and fingers[1]==1 and fingers[2]==0 and fingers[3]==0 and fingers[4]==1):
            location = "2"
            break

    except:
        pass
    print(location)

    mySerial.sendData(location)
    location=""

    cv2.imshow("Image",img)
    cv2.waitKey(1)
ser.close()
