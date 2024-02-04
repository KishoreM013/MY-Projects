# Face Detection
import cv2

algo = "haarcascade_frontalface_default.xml"
har_cascas = cv2.CascadeClassifier(algo)
cam = cv2.VideoCapture(0)

while True:
    _, img = cam.read()
    greyImg = cv2.cvtColor(img, cv2.COLOR_BGRA2BGR)
    face = har_cascas.detectMultiScale(greyImg, 1.3, 8)
    for (x, y, w, h) in face:
        cv2.rectangle(img, (x, y), (x+w, y+h), (0, 0, 0), 2)
    cv2.imshow("FaceDetection", img)
    key = cv2.waitKey(10)
    if key == ord('e'):
        break
cam.release()
cv2.destroyAllWindows()
print("Successful")
