import cv2
import imutils
from pygame import mixer

mixer.init()
cam = cv2.VideoCapture(0)
path1 = "haarcascade_frontalface_default.xml"
path2 = "haarcascade_eye.xml"
face_identify = cv2.CascadeClassifier(path1)
eyes_identify = cv2.CascadeClassifier(path2)


def detect(grey_img, image):
    face = face_identify.detectMultiScale(grey_img, 1.3, 6)
    for (x, y, w, h) in face:
        cv2.rectangle(image, (x, y), (x+w, y+h), (0, 255, 0), 2)
        eyes = eyes_identify.detectMultiScale(grey_img, 1.3, 6)
        mixer.music.unpause()
        for (x2, y2, w2, h2) in eyes:
            mixer.music.pause()
            print("Eye was detected")
            cv2.rectangle(grey_img, (x2, y2), (x2+w2, y2+h2), (0, 0, 0), 2)
    return image


mixer.music.load("beepsound.mp3")
mixer.music.play()
while True:
    _, img = cam.read()
    img = imutils.resize(img, width=1000)
    grey = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    result_img = detect(grey, img)
    cv2.imshow("Video", result_img)
    key = cv2.waitKey(1)
    if key == ord('0'):
        break
cam.release()
cv2.destroyAllWindows()
