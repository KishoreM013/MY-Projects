import cv2
import imutils

video = cv2.VideoCapture(0)
area = 500
Frame1 = None
while True:
    _, img = video.read()
    # .read() return 2 values
    # 1 is true or false which means camara is accessed or not
    # 2nd return image from video
    text = "Normal"
    img = imutils.resize(img, width=1000)
    greyImg = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    gaussianImg = cv2.GaussianBlur(greyImg, (21, 21), 0)
    if Frame1 is None:
        Frame1 = gaussianImg
        continue
    imgdiff = cv2.absdiff(Frame1, gaussianImg)
    trsImg = cv2.threshold(imgdiff, 25, 255, cv2.THRESH_BINARY)[1]
    trsImg = cv2.dilate(trsImg, None, iterations=2)
    cnt = cv2.findContours(trsImg.copy(), cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    cnt = imutils.grab_contours(cnt)

    for c in cnt:
        if cv2.contourArea(c) < area:
            continue
        (x, y, w, h) = cv2.boundingRect(c)
        cv2.rectangle(img, (x, y), (x+w, y+h), (0, 0, 0), 2)
        text = "Moving Object Detected"
#    print(text)
    cv2.putText(img, text, (10, 20), cv2.FONT_ITALIC, 0.5, (0, 0, 255), 2)
    cv2.imshow("Video ", img)

    key = cv2.waitKey(10)
    print(key)
    if key == ord("e"):
        break
video.release()
# to close camara , leave it
cv2.destroyAllWindows()
# close tabs that are opened for video
