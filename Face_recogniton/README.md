# Face_recognition

采集训练数据(使用数据集并加入自己的人脸数据)，训练人脸识别模型，进行人脸识别。

数据集下载地址：http://www.cl.cam.ac.uk/research/dtg/attarchive/facedatabase.html

采集自己的人脸数据代码见 ../Capture/camera.cpp 。

预处理自己的人脸图像代码见 face_orl.py 。

将预处理后的人脸数据加入下载的数据集中，存储方式详见数据集格式。

处理训练数据，生成训练数据-标签csv文件 at.txt 在数据集目录下，处理程序代码见 create_csv.py 。

训练人脸识别模型代码见 face_learn.cpp 。

进行人脸识别代码见 face_predict.cpp 。

Collecting training data (Use the data set and add your own face data), training face recognition model, face recognition.

Data set download address: http://www.cl.cam.ac.uk/research/dtg/attarchive/facedatabase.html

Collect your own face data code see ../Capture/camera.cpp.

Preprocess your own face image code see face_orl.py.

The preprocessed face data is added to the downloaded data set. For details, see the dataset format.

Processing training data, generating training data - tag csv file at.txt In the dataset directory, see the program code see create_csv.py.

Training Face Recognition Model Code See face_learn.cpp.

See face_predict.cpp for face recognition code.
