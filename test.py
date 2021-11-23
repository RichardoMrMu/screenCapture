import cv2
print(cv2.__version__)
cap = cv2.VideoCapture(0)
#cap.set(cv2.CAP_PROP_FRAME_WIDTH, 1280)
#cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 720)
#cap.set(cv2.CAP_PROP_FOURCC, cv2.VideoWriter_fourcc(*'MJPG'))
#cap.set(cv2.CAP_PROP_FPS, 30)
i = 0
dir = "./png/"
while (cap.isOpened()):
	success, img = cap.read()
	if success:
		#cv2.imshow("asf",img)
                cv2.imwrite(dir+str(i)+"test.png",img)
                i+=1
cap.release()
cv2.destroyAllWindows()
