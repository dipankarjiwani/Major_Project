import cloudinary
from cloudinary import uploader
from os import path
import json
# from firebase import firebase
# firebase=firebase.FirebaseApplication("https://smartdrawer-ff798.firebaseio.com/")
cloudinary.config(cloud_name='dyvley9ig',api_key="168424823976546",api_secret="eAnwhI_5b7GlT3bQI3hJvmKs0Wk")

i=0
j=0
while(True):
	if(path.exists("C:\\Users\\Utkarsh\\Desktop\\ArduinoImageCapture-master\\img\\"+str(i)+".png")):
		print(path.exists("C:\\Users\\Utkarsh\\Desktop\\ArduinoImageCapture-master\\img\\"+str(i)+".png"))
		print(i)
		# cloudinary.uploader.rename('moresexy', 'sexy',overwrite=True)
		try:
			(uploader.upload_image(str(i)+".png",public_id="sexy",invalidate=True,overwrite=True))
			print("uploaded")
			i+=1
		except cloudinary.exceptions.Error:
			print("passs")
		# x=(cloudinary.uploader.rename('sexy', 'moresexy',overwrite=True))
		# firebase.push("id:",{"test":str(x["url"])})
		# print(x)
		# y=json.loads(x)
	if(path.exists("C:\\Users\\Utkarsh\\Desktop\\ArduinoImageCapture-master -2\\img\\"+str(j)+".png")):
		print(path.exists("C:\\Users\\Utkarsh\\Desktop\\ArduinoImageCapture-master -2\\img\\"+str(j)+".png"))
		print(j)
		# cloudinary.uploader.rename('moresexy', 'sexy',overwrite=True)
		try:
			(uploader.upload_image("C:\\Users\\Utkarsh\\Desktop\\ArduinoImageCapture-master -2\\img\\"+str(j)+".png",public_id="moresexy",invalidate=True,overwrite=True))
			print("uploaded")
			j+=1
		except cloudinary.exceptions.Error:
			print("passs")
		# x=(cloudinary.uploader.rename('sexy', 'moresexy',overwrite=True))
		# firebase.push("id:",{"test":str(x["url"])})
		# print(x)
		# y=json.loads(x)
		
		
	

